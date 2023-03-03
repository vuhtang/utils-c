
#include "from_bmp.h"

static enum read_status read_header(FILE *const file,
                                    struct bmp_header *const header) {
  size_t result = fread(header, sizeof(struct bmp_header), 1, file);
  if (result != 1) {
    return READ_INVALID_HEADER;
  }
  return READ_OK;
}

static enum read_status read_pixels(FILE *const file,
                                    struct image *const image) {
  size_t width = image->width;
  struct pixel *pointer = image->data;

  uint8_t padding = get_padding(image);

  for (size_t i = 0; i < image->height; i++) {
    size_t read_res =
        fread(pointer + i * width, sizeof(struct pixel), width, file);
    if (read_res != width)
      return READ_INVALID_SIGNATURE;
    int seek_res = fseek(file, padding, SEEK_CUR);
    if (seek_res) {
      return READ_INVALID_BITS;
    }
  }
  return READ_OK;
}

enum read_status from_bmp(FILE *const file, struct image *const image) {
  struct bmp_header header = {0};
  enum read_status header_status = read_header(file, &header);
  if (header_status != READ_OK)
    return header_status;
  *image = initialize_image(header.biWidth, header.biHeight);
  enum read_status pixels_status = read_pixels(file, image);
  if (pixels_status != READ_OK) {
    free_image(*image);
  }
  return pixels_status;
}
