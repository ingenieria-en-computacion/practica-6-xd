#ifndef __CIRCULAR_QUEUE_ARRAY_H__
#define __CIRCULAR_QUEUE_ARRAY_H__

#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int arr[MAX_SIZE];
    int front;  // primer elemento
    int rear;   // último elemento
    int size;
} CircularQueue;

void cq_init(CircularQueue *cq);
bool cq_is_empty(CircularQueue *cq);
bool cq_is_full(CircularQueue *cq);
bool cq_enqueue(CircularQueue *cq, int value);
bool cq_dequeue(CircularQueue *cq, int *out);
bool cq_peek(CircularQueue *cq, int *out);

#endif