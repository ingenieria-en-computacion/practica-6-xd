#pragma once
#include "linked_list.h"

// ----------------------------
// Definición de la Bicola
// ----------------------------
#define DECLARE_DEQUE(TYPE) \
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
        size_t length; \
    } Deque_##TYPE; \
    \
    Deque_##TYPE* deque_##TYPE##_create(void); \
    void deque_##TYPE##_destroy(Deque_##TYPE* deque); \
    bool deque_##TYPE##_insert_front(Deque_##TYPE* deque, TYPE value); \
    bool deque_##TYPE##_insert_back(Deque_##TYPE* deque, TYPE value); \
    bool deque_##TYPE##_remove_front(Deque_##TYPE* deque, TYPE* out); \
    bool deque_##TYPE##_remove_back(Deque_##TYPE* deque, TYPE* out); \
    bool deque_##TYPE##_peek_front(const Deque_##TYPE* deque, TYPE* out); \
    bool deque_##TYPE##_peek_back(const Deque_##TYPE* deque, TYPE* out); \
    bool deque_##TYPE##_is_empty(const Deque_##TYPE* deque); \
    size_t deque_##TYPE##_size(const Deque_##TYPE* deque); \
    void deque_##TYPE##_print(const Deque_##TYPE* deque, void (*print_fn)(TYPE));

#define IMPLEMENT_DEQUE(TYPE) \
    Deque_##TYPE* deque_##TYPE##_create(void) { \
        Deque_##TYPE* deque = malloc(sizeof(Deque_##TYPE)); \
        if (!deque) return NULL; \
        deque->head = NULL; \
        deque->tail = NULL; \
        deque->length = 0; \
        return deque; \
    } \
    \
    void deque_##TYPE##_destroy(Deque_##TYPE* deque) { \
        if (!deque) return; \
        while (!deque_##TYPE##_is_empty(deque)) { \
            TYPE temp; \
            deque_##TYPE##_remove_front(deque, &temp); \
        } \
        free(deque); \
    } \
    \
    bool deque_##TYPE##_insert_front(Deque_##TYPE* deque, TYPE value) { \
        Node_##TYPE* new_node = node_##TYPE##_create(value); \
        if (!new_node) return false; \
        if (deque_##TYPE##_is_empty(deque)) { \
            deque->head = new_node; \
            deque->tail = new_node; \
        } else { \
            new_node->next = deque->head; \
            deque->head->prev = new_node; \
            deque->head = new_node; \
        } \
        deque->length++; \
        return true; \
    } \
    \
    bool deque_##TYPE##_insert_back(Deque_##TYPE* deque, TYPE value) { \
        Node_##TYPE* new_node = node_##TYPE##_create(value); \
        if (!new_node) return false; \
        if (deque_##TYPE##_is_empty(deque)) { \
            deque->head = new_node; \
            deque->tail = new_node; \
        } else { \
            new_node->prev = deque->tail; \
            deque->tail->next = new_node; \
            deque->tail = new_node; \
        } \
        deque->length++; \
        return true; \
    } \
    \
    bool deque_##TYPE##_remove_front(Deque_##TYPE* deque, TYPE* out) { \
        if (deque_##TYPE##_is_empty(deque)) return false; \
        Node_##TYPE* temp = deque->head; \
        if (out) { \
            *out = temp->value; \
        } \
        if (deque->head == deque->tail) { \
            deque->head = NULL; \
            deque->tail = NULL; \
        } else { \
            deque->head = deque->head->next; \
            deque->head->prev = NULL; \
        } \
        node_##TYPE##_destroy(temp); \
        deque->length--; \
        return true; \
    } \
    \
    bool deque_##TYPE##_remove_back(Deque_##TYPE* deque, TYPE* out) { \
        if (deque_##TYPE##_is_empty(deque)) return false; \
        Node_##TYPE* temp = deque->tail; \
        if (out) { \
            *out = temp->value; \
        } \
        if (deque->head == deque->tail) { \
            deque->head = NULL; \
            deque->tail = NULL; \
        } else { \
            deque->tail = deque->tail->prev; \
            deque->tail->next = NULL; \
        } \
        node_##TYPE##_destroy(temp); \
        deque->length--; \
        return true; \
    } \
    \
    bool deque_##TYPE##_peek_front(const Deque_##TYPE* deque, TYPE* out) { \
        if (deque_##TYPE##_is_empty(deque)) return false; \
        *out = deque->head->value; \
        return true; \
    } \
    \
    bool deque_##TYPE##_peek_back(const Deque_##TYPE* deque, TYPE* out) { \
        if (deque_##TYPE##_is_empty(deque)) return false; \
        *out = deque->tail->value; \
        return true; \
    } \
    \
    bool deque_##TYPE##_is_empty(const Deque_##TYPE* deque) { \
        return deque->length == 0; \
    } \
    \
    size_t deque_##TYPE##_size(const Deque_##TYPE* deque) { \
        return deque->length; \
    } \
    \
    void deque_##TYPE##_print(const Deque_##TYPE* deque, void (*print_fn)(TYPE)) { \
        if (deque_##TYPE##_is_empty(deque)) return; \
        Node_##TYPE* current = deque->head; \
        while (current) { \
            print_fn(current->value); \
            current = current->next; \
        } \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_DEQUE(int)
DECLARE_DEQUE(char)
DECLARE_DEQUE(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef DEQUE_IMPLEMENTATION
IMPLEMENT_DEQUE(int)
IMPLEMENT_DEQUE(char)
IMPLEMENT_DEQUE(float)
#endif
