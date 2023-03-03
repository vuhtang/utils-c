#ifndef ASSIGNMENT_5_SEPIA_FILTER_USER_INPUT_HANDLER_H
#define ASSIGNMENT_5_SEPIA_FILTER_USER_INPUT_HANDLER_H
#include "status_codes.h"
#include "stdbool.h"
#include "string.h"

enum user_input_status handle_input_and_select_mode(int argc, char **argv, bool* mode);

#endif
