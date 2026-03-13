#ifndef MLFQ_H
#define MLFQ_H

#include "process/process.h"
#include "queue/queue.h"

#define DEFAULT_NUM_PROCESS 4
#define DEFAULT_NUM_QUEUES 3
#define DEFAULT_BOOST_TIME 20

void mlfq_schedule(int num_queues, int boost_time, process_t processes[], int num_processes);
void demote(node_t *node, int current_queue, queue_t queues[], int num_queues);
int runtime(process_t *process, int time_quantum);

#endif
