#ifndef PROCESS_H
#define PROCESS_H

typedef struct Process {
  int pid;
  int burst_time; // Total CPU time needed to finish (ms).
  int arrival_time;
  int start_time; // Time of first execution.
  int finish_time;
  int waiting_time; // Total time a process waited before finishing.
} process_t;

#endif
