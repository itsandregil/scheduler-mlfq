#include "queue/queue.h"
#include <stdlib.h>

node_t *node_create(process_t *process) {
  node_t *node = malloc(sizeof(node_t));
  if (node == NULL) {
    return NULL;
  }
  node->process = process;
  node->next = NULL;
  return node;
}

void node_destroy(node_t *node) {
  if (node == NULL) {
    return;
  }
  free(node);
}

void queue_init_helper(queue_t *q, int time_quantum) {
  q->head = NULL;
  q->tail = NULL;
  q->time_quantum = time_quantum;
}

/* Add a new node to the back of the queue. */
void enqueue(queue_t *q, node_t *node) {
  node->next = NULL;
  if (q->head == NULL) {
    q->head = node;
    q->tail = node;
    return;
  }
  q->tail->next = node;
  q->tail = node;
}

/* Removes the node at the front of the queue */
node_t *dequeue(queue_t *q) {
  if (q->head == NULL) {
    return NULL;
  }
  node_t *node = q->head;
  q->head = q->head->next;
  if (q->head == NULL) {
    q->tail = NULL;
  }
  node->next = NULL;
  return node;
}

void queue_display(queue_t *q) {
  if (q == NULL || q->head == NULL) {
    printf("-\n");
    return;
  }
  node_t *current = q->head;
  while (current != NULL) {
    if (current->next == NULL) {
      printf("[PID=%d]\n", current->process->pid);
      break;
    }
    printf("[PID=%d] -> ", current->process->pid);
    current = current->next;
  }
}

int queue_is_empty(queue_t *q) {
  if (q == NULL || q->head == NULL) {
    return 1;
  }
  return 0;
}

int all_queues_empty(queue_t queues[], int num_queues) {
  for (int i = 0; i < num_queues; i++) {
    if (!queue_is_empty(&queues[i])) {
      return 0;
    }
  }
  return 1;
}

void queues_init(queue_t queues[], int num_queues) {
  for (int i = 0; i < num_queues; i++) {
    queue_init_helper(&queues[i], 1 << (i + 1));
  }
}
