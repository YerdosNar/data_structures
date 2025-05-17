#include <stdio.h>
#include <stdlib.h>
#include "intQueue.h"

void initQueue(Queue *q, int capacity) {
    q->arr = malloc(capacity * sizeof(int));
    q->capacity = capacity;
    q->head = 0;
    q->tail = 0;
    q->size = 0;
}

bool qIsEmpty(Queue *q) {
    return q->size == 0;
}

bool qIsFull(Queue *q) {
    return q->size == q->capacity;
}

void enqueue(Queue *q, int value) {
    if(qIsFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->arr[q->tail] = value;
    q->tail = (q->tail+1) % q->capacity;
    q->size++;
}

int dequeue(Queue *q) {
    if(qIsEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int returnVal = q->arr[q->head];
    q->head = (q->head+1) % q->capacity;
    q->size--;
    return returnVal;
}

void printQueue(Queue *q) {
    printf("Queue: [");
    if(qIsEmpty(q)) {
        printf("//is Empty.]\n");
        return;
    }
    for(int i = 0; i < q->size; i++) {
        int idx = (q->head+i) % q->capacity;
        if(i == q->size - 1) {
            printf("%d", q->arr[idx]);
        } else {
            printf("%d, ", q->arr[idx]);
        }
    }
    printf("]\n");
}

void freeQueue(Queue *q) {
    free(q->arr);
}
