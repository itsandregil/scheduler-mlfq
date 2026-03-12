#include "scheduler/mlfq.h"
#include "queue/queue.h"
#include "utils/utils.h"
#include <stdlib.h>

// TODO: Implement boosting after a given time.
void mlfq_schedule(int num_queues, int boost_time, process_t processes[],
                   int num_processes) {
  queue_t queues[num_queues];

  // Initialize all queues.
  for (int i = 0; i < num_queues; i++) {
    queue_init(&queues[i], 1 << (i + 1));
  }

  // TODO: Move this inside the loop. Processes arrive at different times and
  // should be push to the top queue when they have arrive and not before.
  for (int i = 0; i < num_processes; i++) {
    node_t *node = node_create(&processes[i]);
    enqueue(&queues[0], node);
  }

  int current_time = 0;
  while (!all_queues_empty(queues, num_queues)) {
    for (int i = 0; i < num_queues; i++) {
      printf("=========Current Time: (%dms) =========\n", current_time);
      display_queues_state(queues, num_queues);

      if (queue_is_empty(&queues[i])) {
        continue;
      }

      int quantum = queues[i].time_quantum;
      node_t *node = dequeue(&queues[i]);
      process_t *process = node->process;

      if (process->arrival_time > current_time) {
        enqueue(&queues[i], node);
        continue;
      }

      process->start_time = current_time;
      process->remaining_time -= quantum;
      current_time += quantum;

      if (process->remaining_time > 0 && i < num_queues - 1) {
        enqueue(&queues[i + 1], node);
      } else {
        process->finish_time = current_time;
        node_destroy(node);
      }
    }
  }
}
