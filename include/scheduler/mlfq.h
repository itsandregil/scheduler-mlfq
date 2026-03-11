#ifndef MLFQ_H
#define MLFQ_H

#include "process/process.h"

#define DEFAULT_NUM_QUEUES 3
#define DEFAULT_BOOST_TIME 20

void mlfq_schedule(int queues_num, int boost_time, process_t *processes, int num_processes);

#endif
