
#ifndef FILE_INTERACTION_H
#define FILE_INTERACTION_H

#include <stdio.h>

#include "status_codes.h"

enum open_status open_file(FILE **file, const char *filename, const char *mode);

enum close_status close_file(FILE* file);

#endif
