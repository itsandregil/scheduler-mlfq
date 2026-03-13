#ifndef QUEUE_H
#define QUEUE_H

#include "process/process.h"

typedef struct Node node_t;

typedef struct Node {
    process_t *process;
    node_t *next;
} node_t;

typedef struct Queue {
    node_t *head;
    node_t *tail;
    int time_quantum;
} queue_t;

node_t *node_create(process_t *process);
void node_destroy(node_t *node);

void enqueue(queue_t *q, node_t *node);
node_t *dequeue(queue_t *q);
int queue_is_empty(queue_t *q);
int all_queues_empty(queue_t *queues, int num_queues);

void queue_init_helper(queue_t *q, int time_quantum);
void queues_init(queue_t queues[], int num_queues);
void queue_display(queue_t *q);

#endif
