#include "process/process.h"
#include "scheduler/mlfq.h"
#include <stdio.h>

int main() {
  int boost_time = 20;
  int num_queues = 3;
  process_t processes[4] = {
      process_create(1, 8, 0),
      process_create(2, 4, 1),
      process_create(3, 9, 2),
      process_create(4, 5, 3),
  };
  int num_processes = sizeof(processes) / sizeof(processes[0]);
  mlfq_schedule(num_queues, boost_time, processes, num_processes);
  return 0;
}
