#ifndef STATUS_CODES_H
#define STATUS_CODES_H

extern const char *INCORRECT_ARGUMENTS;
extern const char *const STATUS_MESSAGES_OPEN[];
extern const char *const STATUS_MESSAGES_CLOSE[];
extern const char *const STATUS_MESSAGES_READ[];
extern const char *const STATUS_MESSAGES_WRITE[];

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
