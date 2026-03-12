#include "process/process.h"
#include "scheduler/mlfq.h"
#include <stdio.h>

int main() {
  process_t processes[DEFAULT_NUM_PROCESS] = {
      process_create(1, 8, 0),
      process_create(2, 4, 1),
      process_create(3, 9, 2),
      process_create(4, 5, 3),
  };
  mlfq_schedule(DEFAULT_NUM_QUEUES, DEFAULT_BOOST_TIME, processes, 4);
  return 0;
}
