#include <stdlib.h>
#include <stdbool.h>

#ifndef INTQUEUE_H
#define INTQUEUE_H

typedef struct {
    int *arr;
    size_t size;
    size_t head;
    size_t tail;
    size_t capacity;
} Queue;

void initQueue(Queue *q, int capacity);
bool qIsEmpty(Queue *q);
bool qIsFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void printQueue(Queue *q);
void freeQueue(Queue *q);

#endif
