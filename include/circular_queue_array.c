#include "circular_queue_array.h"

void cq_init(CircularQueue *cq) {
    cq->front = 0;
    cq->rear = -1;
    cq->size = 0;
}

bool cq_is_empty(CircularQueue *cq) {
    return cq->size == 0;
}

bool cq_is_full(CircularQueue *cq) {
    return cq->size == MAX_SIZE;
}
/*añade*/
bool cq_enqueue(CircularQueue *cq, int value) {
    if (cq_is_full(cq)) return false;
    cq->rear++;
    if (cq->rear == MAX_SIZE) {
        cq->rear = 0;
    }
    cq->arr[cq->rear] = value;
    cq->size++;
    return true;
}

/*saca*/
bool cq_dequeue(CircularQueue *cq, int *out) {
    if (cq_is_empty(cq)) return false;

    if (out) *out = cq->arr[cq->front];
    cq->front++;
    if (cq->front == MAX_SIZE) {
        cq->front = 0; 
    }
    cq->size--;
    return true;
}

bool cq_peek(CircularQueue *cq, int *out) {
    if (cq_is_empty(cq)) return false;
    *out = cq->arr[cq->front];
    return true;
}