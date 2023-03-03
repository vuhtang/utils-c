#include <stdio.h>

#include "from_bmp.h"
#include "image.h"
#include "image_actions.h"
#include "status_codes.h"
#include "to_bmp.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("%s", INCORRECT_ARGUMENTS);
    return 1;
  }
  const char *input_image_name = argv[1];
  struct image input_image = {0};
  enum read_status read_image_status =
      read_image(from_bmp, input_image_name, &input_image);
  printf("%s\n", STATUS_MESSAGES_READ[read_image_status]);
  if (read_image_status != READ_OK)
    return read_image_status;
  const char *output_image_name = argv[2];
  struct image output_image = rotate(input_image);
  free_image(input_image);
  enum write_status write_image_status =
      write_image(to_bmp, output_image_name, &output_image);
  printf("%s", STATUS_MESSAGES_WRITE[write_image_status]);
  free_image(output_image);
  if (write_image_status != WRITE_OK)
    return write_image_status;
  return 0;
}
