#pragma once
#include "linked_list.h"

// ----------------------------
// Definición de la Cola Circular
// ----------------------------
#define DECLARE_CIRCULAR_QUEUE(TYPE) \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } CircularQueue_##TYPE; \
    \
    CircularQueue_##TYPE* cq_##TYPE##_create(void); \
    void cq_##TYPE##_destroy(CircularQueue_##TYPE* cq); \
    bool cq_##TYPE##_enqueue(CircularQueue_##TYPE* cq, TYPE value); \
    bool cq_##TYPE##_dequeue(CircularQueue_##TYPE* cq, TYPE* out); \
    bool cq_##TYPE##_peek(const CircularQueue_##TYPE* cq, TYPE* out); \
    bool cq_##TYPE##_is_empty(const CircularQueue_##TYPE* cq); \
    size_t cq_##TYPE##_size(const CircularQueue_##TYPE* cq); \
    void cq_##TYPE##_print(const CircularQueue_##TYPE* cq, void (*print_fn)(TYPE));

#define IMPLEMENT_CIRCULAR_QUEUE(TYPE) \
    CircularQueue_##TYPE* cq_##TYPE##_create(void) { \
        CircularQueue_##TYPE* cq = malloc(sizeof(CircularQueue_##TYPE)); \
        if (!cq) return NULL; \
        cq->head = NULL; \
        cq->tail = NULL; \
        cq->length = 0; \
        return cq; \
    } \
    \
    void cq_##TYPE##_destroy(CircularQueue_##TYPE* cq) { \
        if (!cq) return; \
        while (!cq_##TYPE##_is_empty(cq)) { \
            TYPE temp; \
            cq_##TYPE##_dequeue(cq, &temp); \
        } \
        free(cq); \
    } \
    \
    bool cq_##TYPE##_enqueue(CircularQueue_##TYPE* cq, TYPE value) { /*inserta al final de la cola*/ \
        Node_##TYPE* new_node = node_##TYPE##_create(value); \
        if (!new_node) return false; \
        if (cq_##TYPE##_is_empty(cq)) { \
            cq->head = new_node; \
            cq->tail = new_node; \
            new_node->next = new_node;\
        } else { \
            cq->tail->next = new_node; \
            cq->tail = new_node; \
            new_node->next = cq->head; \
        } \
        cq->length++; \
        return true; \
    } \
    \
    bool cq_##TYPE##_dequeue(CircularQueue_##TYPE* cq, TYPE* out) { /*inserta al inicio de la cola*/ \
        if (cq_##TYPE##_is_empty(cq)) return false; \
        Node_##TYPE* temp = cq->head; \
        if (out) { \
            *out = temp->value; \
        } \
        if (cq->head == cq->tail) { \
            cq->head = NULL; \
            cq->tail = NULL; \
        } else { \
            cq->head = cq->head->next; \
            cq->tail->next = cq->head; \
        } \
        node_##TYPE##_destroy(temp); \
        cq->length--; \
        return true; \
    } \
    \
    bool cq_##TYPE##_peek(const CircularQueue_##TYPE* cq, TYPE* out) { \
        if (cq_##TYPE##_is_empty(cq)) return false; \
        *out = cq->head->value; \
        return true; \
    } \
    \
    bool cq_##TYPE##_is_empty(const CircularQueue_##TYPE* cq) { \
        return cq->length == 0; \
    } \
    \
    size_t cq_##TYPE##_size(const CircularQueue_##TYPE* cq) { \
        return cq->length; \
    } \
    \
    void cq_##TYPE##_print(const CircularQueue_##TYPE* cq, void (*print_fn)(TYPE)) { \
        if (cq_##TYPE##_is_empty(cq)) return; \
        Node_##TYPE* current = cq->head; \
        do { \
            print_fn(current->value); \
            current = current->next; \
        } while (current != cq->head); \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_CIRCULAR_QUEUE(int)
DECLARE_CIRCULAR_QUEUE(char)
DECLARE_CIRCULAR_QUEUE(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef CIRCULAR_QUEUE_IMPLEMENTATION
IMPLEMENT_CIRCULAR_QUEUE(int)
IMPLEMENT_CIRCULAR_QUEUE(char)
IMPLEMENT_CIRCULAR_QUEUE(float)
#endif
