#include "sepia.h"

static unsigned char sat(uint64_t x) {
  if (x < 256)
    return x;
  return 255;
}

void sepia(struct pixel *pixel) {
  static const float c[3][3] = {
      {.393f, .769f, .189f}, {.349f, .686f, .168f}, {.272f, .543f, .131f}};
  struct pixel old = *pixel;
  pixel->r = sat(old.r * c[0][0] + old.g * c[0][1] + old.b * c[0][2]);
  pixel->g = sat(old.r * c[1][0] + old.g * c[1][1] + old.b * c[1][2]);
  pixel->b = sat(old.r * c[2][0] + old.g * c[2][1] + old.b * c[2][2]);
}
