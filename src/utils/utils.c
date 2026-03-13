#include "utils/utils.h"
#include "queue/queue.h"
#include <stdio.h>

void display_queues_state(queue_t queues[], int num_queues) {
  for (int i = 0; i < num_queues; i++) {
    printf("Queue %d: ", i);
    queue_display(&queues[i]);
  }
}

void write_output(char *filename, process_t processes[], int num_processes) {
  FILE *f = fopen(filename, "w");
  if (f == NULL) {
    return;
  }
  fprintf(f, "%s, %s, %s, %s, %s, %s, %s, %s\n", "PID", "Arrival Time",
          "Burst Time", "Start Time", "Finish Time", "Turnaround Time",
          "Response Time", "Waiting Time");
  for (int i = 0; i < num_processes; i++) {
    process_write(f, &processes[i]);
  }
  printf("Execution output wrote to %s\n", filename);
  fclose(f);
}
