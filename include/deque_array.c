#include "deque_array.h"

void deque_init(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

bool deque_is_empty(const Deque *dq) {
    return dq->size == 0;
}

bool deque_is_full(const Deque *dq) {
    return dq->size == MAX_SIZE;
}

bool deque_push_front(Deque *dq, int value) {
    if (deque_is_full(dq)) return false;

    if (deque_is_empty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front--;
        if (dq->front < 0) {
            dq->front = MAX_SIZE - 1;
        }
    }
    dq->data[dq->front] = value;
    dq->size++;
    return true;
}

bool deque_push_back(Deque *dq, int value) {
    if (deque_is_full(dq)) return false;

    if (deque_is_empty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear++;
        if (dq->rear >= MAX_SIZE) {
            dq->rear = 0;
        }
    }
    dq->data[dq->rear] = value;
    dq->size++;
    return true;
}

bool deque_pop_front(Deque *dq, int *out) {
    if (deque_is_empty(dq)) return false;
    if (out) *out = dq->data[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front++;
        if (dq->front >= MAX_SIZE) {
            dq->front = 0;
        }
    }
    dq->size--;
    return true;
}

bool deque_pop_back(Deque *dq, int *out) {
    if (deque_is_empty(dq)) return false;
    if (out) *out = dq->data[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->rear--;
        if (dq->rear < 0) {
            dq->rear = MAX_SIZE - 1;
        }
    }
    dq->size--;
    return true;
}

bool deque_peek_front(const Deque *dq, int *out) {
    if (deque_is_empty(dq)) return false;
    *out = dq->data[dq->front];
    return true;
}

bool deque_peek_back(const Deque *dq, int *out) {
    if (deque_is_empty(dq)) return false;
    *out = dq->data[dq->rear];
    return true;
}