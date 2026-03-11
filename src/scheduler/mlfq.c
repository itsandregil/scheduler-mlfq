#include "scheduler/mlfq.h"
#include "queue/queue.h"

void mlfq_schedule(int queues_num, int boost_time, process_t processes[],
                   int num_processes) {
  queue_t queues[queues_num];
  int time_quantum = 2;

  for (int i = 0; i < queues_num; i++) {
    queue_init(&queues[i]);
  }

  // TODO: How to do this with a array of structs using pointer arithmetic
  for (int i = 0; i < num_processes; i++) {
    node_t *node = node_create(&processes[i]);
    enqueue(&queues[0], node);
  }

  // Display all queues
  for (int i = 0; i < queues_num; i++) {
    printf("Queue %d: ", i);
    queue_display(&queues[i]);
  }
}
