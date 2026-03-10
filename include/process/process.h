#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>

typedef struct Process {
  int pid;
  int burst_time; // Total CPU time needed to finish (ms).
  int arrival_time;
  int start_time; // Time of first execution.
  int finish_time;
  int waiting_time; // Total time a process waited before finishing.
} process_t;

int turnaround_time(process_t *p);
int response_time(process_t *p);

/* Writes the state of a process to a CSV file. */
void process_write(FILE *f, process_t *p);

#endif
