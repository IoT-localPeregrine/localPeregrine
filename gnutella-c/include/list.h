#pragma once

#include "utils.h"

#define LIST_NODE_DECLARE(TYPE)                           \
    typedef struct ListNode_##TYPE                        \
    {                                                     \
        TYPE *data;                                       \
        struct ListNode_##TYPE *next;                     \
    } ListNode_##TYPE;                                    \
    ListNode_##TYPE *list_node_##TYPE##_ctor(TYPE *data); \
    void list_node_##TYPE##_dtor(ListNode_##TYPE *node);

#define LIST_NODE_DEFINE(TYPE, DTOR_FUNC)                       \
    ListNode_##TYPE *list_node_##TYPE##_ctor(TYPE *data)        \
    {                                                           \
        ListNode_##TYPE *new_node = my_calloc(ListNode_##TYPE); \
        new_node->data = data;                                  \
        return new_node;                                        \
    }                                                           \
    void list_node_##TYPE##_dtor(ListNode_##TYPE *node)         \
    {                                                           \
        DTOR_FUNC(node->data);                                  \
        free(node);                                             \
    }

#define LIST_DECLARE(TYPE)                            \
    LIST_NODE_DECLARE(TYPE)                           \
    typedef struct                                    \
    {                                                 \
        ListNode_##TYPE *head;                        \
        ListNode_##TYPE *tail;                        \
        size_t count;                                 \
    } List_##TYPE;                                    \
    List_##TYPE *list_##TYPE##_new();                 \
    void list_##TYPE##_dtor(List_##TYPE *collection); \
    void list_##TYPE##_push_back(List_##TYPE *const col, TYPE *const ent);

#define LIST_DEFINE(TYPE, DTOR_FUNC)                                      \
    LIST_NODE_DEFINE(TYPE, DTOR_FUNC)                                     \
    List_##TYPE *list_##TYPE##_new()                                      \
    {                                                                     \
        return my_calloc(List_##TYPE);                                    \
    }                                                                     \
    void list_##TYPE##_dtor(List_##TYPE *collection)                      \
    {                                                                     \
        while (collection->head != NULL)                                  \
        {                                                                 \
            ListNode_##TYPE *nxt = collection->head->next;                \
            list_node_##TYPE##_dtor(collection->head);                    \
            collection->head = nxt;                                       \
        }                                                                 \
        free(collection);                                                 \
    }                                                                     \
    void list_##TYPE##_push_back(List_##TYPE *const col, TYPE *const ent) \
    {                                                                     \
        if (col->head == NULL)                                            \
        {                                                                 \
            col->head = list_node_##TYPE##_ctor(ent);                     \
            col->tail = col->head;                                        \
        }                                                                 \
        else                                                              \
        {                                                                 \
            col->tail->next = list_node_##TYPE##_ctor(ent);               \
            col->tail->next = col->tail;                                  \
        }                                                                 \
        col->count += 1;                                                  \
    }
