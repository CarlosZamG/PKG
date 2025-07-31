#ifndef LINKED_QUEUE_H_INCLUDED
#define LINKED_QUEUE_H_INCLUDED

// Defines the node used for LinkedQueue
typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

// Defines the implementation of ADT Queue using Linked Lists for store integers
typedef struct LinkedQueue
{
    QueueNode *head;
    QueueNode *tail;
    int length;
} LinkedQueue;

// Set queue to an empty queue
void LinkedQueue_set_empty(LinkedQueue *queue);

// Creates a queue with the values of the array 
int LinkedQueue_init_from_array(LinkedQueue *queue, int *array, int array_size);

// Prints the queue with a nice format
void LinkedQueue_print(LinkedQueue queue);

// Prints the queue information with a nice format
void LinkedQueue_info(LinkedQueue queue);

// Free memory used fot the queue
void LinkedQueue_free(LinkedQueue *queue);

// Add a new element to the queue in the FIFO ordering
int LinkedQueue_enqueue(LinkedQueue *queue, int element);

//  Remove and return the next item in FIFO ordering
int LinkedQueue_dequeue(LinkedQueue *queue, int *return_value);

//  Return (without removing) the next item in the queue in FIFO ordering
int LinkedQueue_peek(LinkedQueue queue, int *return_value);

#endif