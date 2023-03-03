#include <stdlib.h>

#include "image.h"

struct image initialize_image(size_t width, size_t height) {
  struct pixel *pixels = malloc(sizeof(struct pixel) * width * height);
  return (struct image){.height = height, .width = width, .data = pixels};
}

void set_pixel(struct image *image, size_t row, size_t column,
               struct pixel pixel) {
  image->data[image->width * row + column] = pixel;
}

struct pixel get_pixel(const struct image *image, size_t row, size_t column) {
  return image->data[image->width * row + column];
}

void free_image(struct image image) { free(image.data); }

uint8_t get_padding(const struct image *image) {
  uint8_t padding = image->width * sizeof(struct pixel) % 4;
  if (padding != 0)
    padding = 4 - padding;
  return padding;
}
