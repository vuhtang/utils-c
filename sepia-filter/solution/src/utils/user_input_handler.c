#include "user_input_handler.h"

static void select_mode_if_specified(char **argv, bool *mode, bool *isCorrect) {
  if (strcmp(argv[3], DEFAULT) == 0) {
    *mode = false;
    *isCorrect = true;
    return ;
  } else if (strcmp(argv[3], ACCELERATION) == 0) {
    *mode = true;
    *isCorrect = true;
    return ;
  }
  *isCorrect = false;
}

enum user_input_status handle_input_and_select_mode(int argc, char **argv,
                                                    bool *mode) {
  if (argc == 3) {
    *mode = false;
    return MODE_NOT_SPECIFIED;
  }
  if (argc == 4) {
    bool isCorrect;
    select_mode_if_specified(argv, mode, &isCorrect);
    if (isCorrect)
      return MODE_SPECIFIED;
    else return INCORRECT_MODE;
  }
  return INCORRECT_NUMBER_OF_ARGUMENTS;
}
