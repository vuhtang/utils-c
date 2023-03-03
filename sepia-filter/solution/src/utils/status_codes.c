#include "status_codes.h"

const char *DEFAULT = "DEFAULT";
const char *ACCELERATION = "ACCELERATION";

const char *STATUS_MESSAGES_USER_INPUT[] = {
    [INCORRECT_NUMBER_OF_ARGUMENTS] = "Incorrect number of arguments\n",
    [MODE_NOT_SPECIFIED] = "You have not specified the program's operating "
                           "mode, the DEFAULT method "
                           "is selected\n(\"DEFAULT\" - default mode, "
                           "\"ACCELERATION\" - speed up)\n",
    [MODE_SPECIFIED] = "Mode selected\n",
    [INCORRECT_MODE] = "Incorrect mode!\n(\"DEFAULT\" - default mode, "
                       "\"ACCELERATION\" - speed up)\n"};

const char *STATUS_MESSAGES_OPEN[] = {[OPEN_OK] = "File opened successfully",
                                      [OPEN_FAILED] = "Error opening file"};

const char *STATUS_MESSAGES_CLOSE[] = {[CLOSE_OK] = "File closed successfully",
                                       [CLOSE_FAILED] = "Error closing file"};

const char *STATUS_MESSAGES_READ[] = {
    [READ_OK] = "File was read successfully",
    [READ_CLOSE_FAILED] = "Error closing file",
    [READ_OPEN_FAILED] = "Error opening file",
    [READ_INVALID_SIGNATURE] = "Wrong file signature",
    [READ_INVALID_BITS] = "Wrong bits arrangement",
    [READ_INVALID_HEADER] = "Wrong file header"};

const char *STATUS_MESSAGES_WRITE[] = {
    [WRITE_OK] = "File was written successfully",
    [WRITE_OPEN_FAILED] = "Error opening file",
    [WRITE_CLOSE_FAILED] = "Error closing file",
    [WRITE_ERROR_HEADER] = "Error writing file header",
    [WRITE_ERROR_PIXELS] = "Error writing image pixels"};
