#include "from_bmp.h"
#include "image.h"
#include "image_actions.h"
#include "sepia.h"
#include "status_codes.h"
#include "sys/time.h"
#include "time_counting.h"
#include "to_bmp.h"
#include "user_input_handler.h"

int main(int argc, char **argv) {
  bool mode;
  enum user_input_status userInputStatus =
      handle_input_and_select_mode(argc, argv, &mode);
  if (userInputStatus == INCORRECT_NUMBER_OF_ARGUMENTS ||
      userInputStatus == INCORRECT_MODE) {
    printf("%s", STATUS_MESSAGES_USER_INPUT[userInputStatus]);
    return 1;
  }
  printf("%s", STATUS_MESSAGES_USER_INPUT[userInputStatus]);

  long res = 0;
  struct timeval start;
  struct timeval end;

  const char *input_image_name = argv[1];
  struct image input_image = {0};
  enum read_status read_image_status =
      read_image(from_bmp, input_image_name, &input_image);
  printf("%s\n", STATUS_MESSAGES_READ[read_image_status]);
  if (read_image_status != READ_OK)
    return read_image_status;
  const char *output_image_name = argv[2];
  struct image output_image;

  if (mode) {
    for (uint8_t i = 0; i < 10; i++) {
      start = get_cur_time();
      apply_filter_asm(sepia, &input_image, &output_image);
      end = get_cur_time();
      res += ((end.tv_sec - start.tv_sec) * 1000000L) + end.tv_usec -
             start.tv_usec;
    }
  } else {
    for (uint8_t i = 0; i < 10; i++) {
      start = get_cur_time();
      apply_filter(sepia, &input_image, &output_image);
      end = get_cur_time();
      res += ((end.tv_sec - start.tv_sec) * 1000000L) + end.tv_usec -
             start.tv_usec;
    }
  }

  free_image(input_image);
  enum write_status write_image_status =
      write_image(to_bmp, output_image_name, &output_image);
  printf("%s", STATUS_MESSAGES_WRITE[write_image_status]);
  free_image(output_image);
  if (write_image_status != WRITE_OK)
    return write_image_status;

  res = res / 10;

  printf("\nAverage filter operation time: %ld", res);

  return 0;
}
