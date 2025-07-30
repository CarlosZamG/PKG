#ifndef LINKED_QUEUE_H_INCLUDED
#define LINKED_QUEUE_H_INCLUDED

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;


typedef struct LinkedQueue
{
    QueueNode *head;
    QueueNode *tail;
    int length;
} LinkedQueue;


void LinkedQueue_init_empty(LinkedQueue *queue);

void LinkedQueue_init_from_array(LinkedQueue *queue, int *array, int array_size);

void LinkedQueue_print(LinkedQueue queue);

void LinkedQueue_free(LinkedQueue *queue);

#endif