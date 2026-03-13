#include "scheduler/mlfq.h"
#include "process/process.h"
#include "queue/queue.h"
#include "utils/utils.h"
#include <stdlib.h>
#include <unistd.h>

void mlfq_schedule(int num_queues, int boost_time, process_t processes[],
                   int num_processes) {
  queue_t queues[num_queues];
  queues_init(queues, num_queues);
  process_sort(processes, num_processes);

  int current_time = 0;
  int next_pid = 0;
  int next_boost_time = boost_time;

  while (!all_queues_empty(queues, num_queues) || next_pid < num_processes) {

    while (next_pid < num_processes &&
           processes[next_pid].arrival_time <= current_time) {
      node_t *node = node_create(&processes[next_pid]);
      enqueue(&queues[0], node);
      next_pid++;
    }

    if (all_queues_empty(queues, num_queues) && next_pid < num_processes) {
      current_time = processes[next_pid].arrival_time;
      continue;
    }

    if (current_time >= next_boost_time) {
      for (int i = 1; i < num_queues; i++) {
        while (!queue_is_empty(&queues[i])) {
          node_t *node = dequeue(&queues[i]);
          enqueue(&queues[0], node);
        }
      }
      next_boost_time += boost_time;
    }

    printf("=========Current Time: (%dms) =========\n", current_time);
    display_queues_state(queues, num_queues);

    for (int i = 0; i < num_queues; i++) {
      if (queue_is_empty(&queues[i])) {
        continue;
      }

      int quantum = queues[i].time_quantum;
      node_t *node = dequeue(&queues[i]);
      process_t *process = node->process;

      if (process->start_time == -1) {
        process->start_time = current_time;
      }

      int t = runtime(process, quantum);
      process->remaining_time -= t;
      current_time += t;

      if (process->remaining_time > 0) {
        demote(node, i, queues, num_queues);
      } else {
        process->finish_time = current_time;
        node_destroy(node);
      }

      break;
    }
    sleep(1);
  }
  printf("Total CPU time taken: %dms\n", current_time);
  write_output("output.csv", processes, num_processes);
}

int runtime(process_t *process, int time_quantum) {
  if (process->remaining_time <= time_quantum) {
    return process->remaining_time;
  }
  return time_quantum;
}

void demote(node_t *node, int current_queue, queue_t queues[], int num_queues) {
  if (current_queue < num_queues - 1) {
    enqueue(&queues[current_queue + 1], node);
  } else {
    enqueue(&queues[current_queue], node);
  }
}
