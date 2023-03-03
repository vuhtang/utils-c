#include "to_bmp.h"
#define TYPE 0x4d42
#define RESERVED 0
#define HEADER_SIZE 40
#define PLANES 1
#define BIT_PER_COLOR 24
#define COMPRESSION 0
#define SOME_MAGIC_CONSTANT 2835
#define COLOR_USED 0
#define COLOR_IMPORTANT 0

static enum write_status write_bmp_header(FILE *const file,
                                          struct bmp_header *const header) {
  size_t result = fwrite(header, sizeof(struct bmp_header), 1, file);
  if (result != 1) {
    return WRITE_ERROR_HEADER;
  }
  return WRITE_OK;
}

static enum write_status write_bmp_pixels(FILE *const file,
                                          struct image *const image) {
  size_t width = image->width;
  struct pixel *pointer = image->data;
  uint8_t padding = get_padding(image);
  uint32_t padding_unit = 0;

  for (size_t i = 0; i < image->height; i++) {
    size_t write_res =
        fwrite(pointer + width * i, sizeof(struct pixel), width, file);
    if (write_res != width) {
      return WRITE_ERROR_PIXELS;
    }
    size_t padding_res = fwrite(&padding_unit, 1, padding, file);
    if (padding_res != padding) {
      return WRITE_ERROR_PIXELS;
    }
  }
  return WRITE_OK;
}

static struct bmp_header create_bmp_header(struct image *const image) {
  uint32_t bmp_header_size = sizeof(struct bmp_header);
  uint32_t bmp_image_size = sizeof(struct pixel) * image->width * image->height;
  return (struct bmp_header){.bfType = TYPE,
                             .bfileSize = bmp_header_size + bmp_image_size,
                             .bfReserved = RESERVED,
                             .bOffBits = bmp_header_size,
                             .biSize = HEADER_SIZE,
                             .biWidth = image->width,
                             .biHeight = image->height,
                             .biPlanes = PLANES,
                             .biBitCount = BIT_PER_COLOR,
                             .biCompression = COMPRESSION,
                             .biSizeImage = bmp_image_size,
                             .biXPelsPerMeter = SOME_MAGIC_CONSTANT,
                             .biYPelsPerMeter = SOME_MAGIC_CONSTANT,
                             .biClrUsed = COLOR_USED,
                             .biClrImportant = COLOR_IMPORTANT};
}

enum write_status to_bmp(FILE *const file, struct image *const image) {
  struct bmp_header header = create_bmp_header(image);
  enum write_status header_status = write_bmp_header(file, &header);
  if (header_status != WRITE_OK) {
    return header_status;
  }
  return write_bmp_pixels(file, image);
}
