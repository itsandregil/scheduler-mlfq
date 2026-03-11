#include "process/process.h"
#include "scheduler/mlfq.h"
#include <stdio.h>

int main() {
  process_t processes[4] = {
      {.pid = 1, .burst_time = 8, .arrival_time = 0},
      {.pid = 2, .burst_time = 4, .arrival_time = 1},
      {.pid = 3, .burst_time = 9, .arrival_time = 2},
      {.pid = 4, .burst_time = 5, .arrival_time = 3},
  };
  mlfq_schedule(DEFAULT_NUM_QUEUES, DEFAULT_BOOST_TIME, processes, 4);
  return 0;
}
