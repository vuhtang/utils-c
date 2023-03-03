#include "time_counting.h"

struct timeval get_cur_time() {
  struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  return r.ru_utime;
}