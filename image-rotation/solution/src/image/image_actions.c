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

struct image rotate(const struct image image) {
  size_t width = image.width;
  size_t height = image.height;
  struct image rotated_image = initialize_image(height, width);
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      struct pixel pixel = get_pixel(&image, i, j);
      set_pixel(&rotated_image, j, height - i - 1, pixel);
    }
  }
  return rotated_image;
}
