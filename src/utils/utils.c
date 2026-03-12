#include "utils/utils.h"
#include "queue/queue.h"

void display_queues_state(queue_t queues[], int num_queues) {
  for (int i = 0; i < num_queues; i++) {
    printf("Queue %d: ", i);
    queue_display(&queues[i]);
  }
}
