#include <stdio.h>
#include <stdlib.h>

#include "LinkedQueue.h"

void LinkedQueue_set_empty(LinkedQueue *queue)
{
    // Set queue head and tail to points to NULL
    queue->head = NULL;
    queue->tail = NULL;
    // Set queue length to 0
    queue->length = 0;
}


int LinkedQueue_enqueue(LinkedQueue *queue, int element)
{
    // Allocate memory for a new node
    QueueNode *new_node = malloc(sizeof(QueueNode));
    if (new_node == NULL)
    {
        // If memory allocation failed, show error message
        fprintf(stderr, "Memory allocation for a node failed\n");
        return EXIT_FAILURE;
    }

    // Set new node values
    new_node->data = element;
    new_node->next = NULL;

    if (queue->head == NULL)
    {
        // If queue head is NULL, points to new node
        queue->head = new_node;
    }

    if (queue->tail != NULL)
    {
        // If queue tail is not NULL, tail->next points to new node 
        queue->tail->next = new_node;
    }

    // Update queue tail
    queue->tail = new_node;
    // Update queue length
    queue->length++;

    return EXIT_SUCCESS;
}


int LinkedQueue_dequeue(LinkedQueue *queue, int *return_value)
{
    if (queue->length == 0)
    {
        fprintf(stderr, "Cannot dequeue from empty queue\n");
        return EXIT_FAILURE;
    }

    QueueNode *deleted_node = queue->head;
    queue->head = queue->head->next;

    *return_value = deleted_node->data;
    deleted_node->data = 0;
    deleted_node->next = NULL;
    free(deleted_node);
    queue->length--;

    if (queue->length == 1)
    {
        LinkedQueue_set_empty(queue);
    }
    
    return EXIT_SUCCESS;
    
}


int LinkedQueue_init_from_array(LinkedQueue *queue, int *array, int array_size)
{
    // Initializate an empty queue 
    LinkedQueue_set_empty(queue);

    // Enqueue array elements to the queue
    for (int i = 0; i < array_size; i++)
    {
        int status = LinkedQueue_enqueue(queue, array[i]);
        if (status == EXIT_FAILURE)
        {
            // If enqueuing an element fails, returns EXIT_FAILURE
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

void LinkedQueue_print(LinkedQueue queue)
{
    printf("[");
    if (queue.length == 0)
    {
        printf(" ]");
        return;
    }

    QueueNode *current_node = queue.head;
    while (current_node->next != NULL)
    {
        int value = current_node->data;
        printf("%d, ", value);
        current_node = current_node->next;
    }
    printf("%d]", current_node->data);
}


void LinkedQueue_info(LinkedQueue queue)
{
    printf("{\n\t queue data: ");
    LinkedQueue_print(queue);
    printf("\n\t length: %d\n\t", queue.length);

    if (queue.head == NULL)
    {
        printf(" head is NULL\n\t");
    }
    else
    {
        printf(" head data: %d\n\t", queue.head->data);
    }

    if (queue.tail == NULL)
    {
        printf(" tail is NULL\n}\n");
    }
    else
    {
        printf(" tail data: %d\n}\n", queue.tail->data);
    }
}


void LinkedQueue_free(LinkedQueue *queue)
{
    QueueNode *current_node = queue->head;
    QueueNode *prev_node = current_node;

    while (current_node != NULL)
    {
        prev_node = current_node;
        current_node = current_node->next;
        // Clean node values
        prev_node->data = 0;
        prev_node->next = NULL;
        // Free memory for each node
        free(prev_node);
    }

    // Set queue head and tail to points to NULL
    queue->head = NULL;
    queue->tail = NULL;
    // Set queue length to 0
    queue->length = 0;
}