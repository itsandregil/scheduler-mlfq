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
} queue_t;

node_t *node_create(process_t *process);
void queue_init(queue_t *q);
void enqueue(queue_t *q, node_t *node);
node_t *dequeue(queue_t *q);
void queue_display(queue_t *q);

#endif
