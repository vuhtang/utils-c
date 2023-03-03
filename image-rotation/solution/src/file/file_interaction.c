#include "file_interaction.h"

enum open_status open_file(FILE **const file, const char *filename,
                           const char *mode) {
  *file = fopen(filename, mode);
  if (*file)
    return OPEN_OK;
  return OPEN_FAILED;
}

enum close_status close_file(FILE *const file) {
  int result = fclose(file);
  if (result)
    return CLOSE_FAILED;
  return CLOSE_OK;
}
