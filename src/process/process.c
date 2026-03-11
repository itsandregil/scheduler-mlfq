#include "process/process.h"
#include <stdio.h>
#include <stdlib.h>

process_t process_create(int pid, int burst_time, int arrival_time) {
  process_t p;
  p.pid = pid;
  p.burst_time = burst_time;
  p.arrival_time = arrival_time;
  p.waiting_time = 0;
  p.remaining_time = burst_time;
  p.start_time = -1;
  p.finish_time = -1;
  return p;
}

int turnaround_time(process_t *p) {
  if (p->finish_time == 0) {
    return 0;
  }
  return p->finish_time - p->arrival_time;
}

int response_time(process_t *p) { return p->start_time - p->arrival_time; }

/* Writes the state of a process to a CSV file. */
void process_write(FILE *f, process_t *p) {
  if (p == NULL) {
    return;
  }
  fprintf(f, "%d, %d, %d, %d, %d, %d, %d, %d\n", p->pid, p->arrival_time,
          p->burst_time, p->start_time, p->finish_time, turnaround_time(p),
          response_time(p), p->waiting_time);
}
