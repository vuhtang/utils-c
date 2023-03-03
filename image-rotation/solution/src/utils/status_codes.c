#include "status_codes.h"

const char *INCORRECT_ARGUMENTS = "Incorrect number of arguments";

const char *const STATUS_MESSAGES_OPEN[] = {
    [OPEN_OK] = "File opened successfully",
    [OPEN_FAILED] = "Error opening file"};

const char *const STATUS_MESSAGES_CLOSE[] = {
    [CLOSE_OK] = "File closed successfully",
    [CLOSE_FAILED] = "Error closing file"};

const char *const STATUS_MESSAGES_READ[] = {
    [READ_OK] = "File was read successfully",
    [READ_CLOSE_FAILED] = "Error closing file",
    [READ_OPEN_FAILED] = "Error opening file",
    [READ_INVALID_SIGNATURE] = "Wrong file signature",
    [READ_INVALID_BITS] = "Wrong bits arrangement",
    [READ_INVALID_HEADER] = "Wrong file header"};

const char *const STATUS_MESSAGES_WRITE[] = {
    [WRITE_OK] = "File was written successfully",
    [WRITE_OPEN_FAILED] = "Error opening file",
    [WRITE_CLOSE_FAILED] = "Error closing file",
    [WRITE_ERROR_HEADER] = "Error writing file header",
    [WRITE_ERROR_PIXELS] = "Error writing image pixels"};
