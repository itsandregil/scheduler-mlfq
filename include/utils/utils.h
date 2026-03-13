#ifndef UTILS_H
#define UTILS_H

#include "process/process.h"
#include "queue/queue.h"

void display_queues_state(queue_t queues[], int num_queues);
void write_output(char *filename, process_t processes[], int num_processes);

#endif
