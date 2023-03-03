

#ifndef IMAGE_TRANSFORMER_FROM_BMP_H
#define IMAGE_TRANSFORMER_FROM_BMP_H

#include "image.h"
#include "status_codes.h"

enum read_status from_bmp(FILE *file, struct image *image);

#endif
