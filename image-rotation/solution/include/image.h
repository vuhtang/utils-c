#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include <stdio.h>

struct __attribute__((packed)) pixel {
  uint8_t b, g, r;
};

struct image {
  size_t width, height;
  struct pixel *data;
};

struct __attribute__((packed)) bmp_header {
  uint16_t bfType;
  uint32_t bfileSize;
  uint32_t bfReserved;
  uint32_t bOffBits;
  uint32_t biSize;
  uint32_t biWidth;
  uint32_t biHeight;
  uint16_t biPlanes;
  uint16_t biBitCount;
  uint32_t biCompression;
  uint32_t biSizeImage;
  uint32_t biXPelsPerMeter;
  uint32_t biYPelsPerMeter;
  uint32_t biClrUsed;
  uint32_t biClrImportant;
};

struct image initialize_image(size_t width, size_t height);

void free_image(struct image image);

uint8_t get_padding(const struct image *image);

void set_pixel(struct image *image, size_t row, size_t column,
               struct pixel pixel);

struct pixel get_pixel(const struct image *image, size_t row, size_t column);

#endif
