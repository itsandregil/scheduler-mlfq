#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>

typedef struct Process {
  int pid;
  int burst_time; // Total CPU time needed to finish (ms).
  int arrival_time;
  int start_time; // Time of first execution.
  int finish_time;
  int waiting_time; // Total time a process waited for CPU.
  int remaining_time;
} process_t;

process_t *process_create(int pid, int burst_time, int arrival_time);
int turnaround_time(process_t *p);
int response_time(process_t *p);
void process_write(FILE *f, process_t *p);

#endif
