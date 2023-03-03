
#ifndef IMAGE_TRANSFORMER_TO_BMP_H
#define IMAGE_TRANSFORMER_TO_BMP_H

#include "image.h"
#include "status_codes.h"

enum write_status to_bmp(FILE *file, struct image *image);

#endif
