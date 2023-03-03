#include "image_actions.h"

enum read_status read_image(enum read_status(from)(FILE *, struct image *image),
                            const char *filename, struct image *image) {
  FILE *file = NULL;
  enum open_status open = open_file(&file, filename, "r");
  if (open == OPEN_FAILED) {
    return READ_OPEN_FAILED;
  }
  enum read_status image_status = from(file, image);
  if (image_status != READ_OK) {
    return image_status;
  }
  enum close_status close = close_file(file);
  if (close != CLOSE_OK) {
    return READ_CLOSE_FAILED;
  }
  return READ_OK;
}

enum write_status write_image(enum write_status(to)(FILE *,
                                                    struct image *image),
                              const char *filename, struct image *image) {
  FILE *file = NULL;
  enum open_status open = open_file(&file, filename, "w");
  if (open == OPEN_FAILED) {
    return WRITE_OPEN_FAILED;
  }
  enum write_status image_status = to(file, image);
  if (image_status != WRITE_OK) {
    return image_status;
  }
  enum close_status close = close_file(file);
  if (close != CLOSE_OK) {
    return WRITE_CLOSE_FAILED;
  }
  return WRITE_OK;
}

void apply_filter(void(apply_filter_on_pixel)(struct pixel *),
                  const struct image *input, struct image *const output) {
  *output = initialize_image(input->width, input->height);
  struct pixel pixel;
  for (size_t i = 0; i < input->height; i++) {
    for (size_t j = 0; j < input->width; j++) {
      pixel = get_pixel(input, i, j);
      apply_filter_on_pixel(&pixel);
      set_pixel(output, i, j, pixel);
    }
  }
}

extern void sepia_asm(struct pixel[static 4], struct pixel *restrict);

void apply_filter_asm(void(apply_filter_on_pixel)(struct pixel *),
                      const struct image *input, struct image *output) {
  *output = initialize_image(input->width, input->height);
  size_t pixels_count = input->height * input->width;
  for (size_t i = 0; i < pixels_count / 4; i++) {
    sepia_asm(input->data + 4 * i, output->data + 4 * i);
  }
  struct pixel pixel;
  for (size_t i = pixels_count - pixels_count % 4; i < pixels_count; i++) {
    pixel = input->data[i];
    apply_filter_on_pixel(&pixel);
    output->data[i] = pixel;
  }
}

void rotate(const struct image image, struct image *const output) {
  size_t width = image.width;
  size_t height = image.height;
  *output = initialize_image(height, width);
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      struct pixel pixel = get_pixel(&image, i, j);
      set_pixel(output, j, height - i - 1, pixel);
    }
  }
}
