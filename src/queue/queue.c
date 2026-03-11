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

void queue_init(queue_t *q) {
  q->head = NULL;
  q->tail = NULL;
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
    printf("Queue is empty\n");
    return;
  }
  node_t *current = q->head;
  while (current != NULL) {
    printf("[PID=%d] -> ", current->process->pid);
    current = current->next;
  }
  printf("NULL\n");
}
