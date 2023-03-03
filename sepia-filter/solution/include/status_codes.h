#ifndef STATUS_CODES_H
#define STATUS_CODES_H

extern const char *DEFAULT;
extern const char *ACCELERATION;
extern const char *STATUS_MESSAGES_USER_INPUT[];
extern const char *STATUS_MESSAGES_OPEN[];
extern const char *STATUS_MESSAGES_CLOSE[];
extern const char *STATUS_MESSAGES_READ[];
extern const char *STATUS_MESSAGES_WRITE[];

enum user_input_status {
  INCORRECT_NUMBER_OF_ARGUMENTS = 0,
  MODE_NOT_SPECIFIED,
  MODE_SPECIFIED,
  INCORRECT_MODE
};

enum open_status { OPEN_OK = 0, OPEN_FAILED };

enum close_status { CLOSE_OK = 0, CLOSE_FAILED };

enum read_status {
  READ_OK = 0,
  READ_INVALID_SIGNATURE,
  READ_INVALID_BITS,
  READ_INVALID_HEADER,
  READ_OPEN_FAILED,
  READ_CLOSE_FAILED
};

enum write_status {
  WRITE_OK = 0,
  WRITE_ERROR_HEADER,
  WRITE_ERROR_PIXELS,
  WRITE_OPEN_FAILED,
  WRITE_CLOSE_FAILED
};

#endif
