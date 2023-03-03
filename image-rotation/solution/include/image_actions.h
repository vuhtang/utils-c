
#ifndef IMAGE_TRANSFORMER_IMAGE_ACTIONS_H
#define IMAGE_TRANSFORMER_IMAGE_ACTIONS_H

#include "file_interaction.h"
#include "image.h"
#include "status_codes.h"

enum read_status read_image(enum read_status(from)(FILE *, struct image *image),
                            const char *filename, struct image *image);

enum write_status write_image(enum write_status(to)(FILE *,
                                                    struct image *image),
                              const char *filename, struct image *image);

struct image rotate(struct image image);

#endif
