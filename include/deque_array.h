#ifndef DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;  
    int size;    
} Deque;

void deque_init(Deque *dq);
bool deque_is_empty(const Deque *dq);
bool deque_is_full(const Deque *dq);
bool deque_push_front(Deque *dq, int value);
bool deque_push_back(Deque *dq, int value);
bool deque_pop_front(Deque *dq, int *out);
bool deque_pop_back(Deque *dq, int *out);
bool deque_peek_front(const Deque *dq, int *out);
bool deque_peek_back(const Deque *dq, int *out);

#endif