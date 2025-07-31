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
        // If queue is empty, show error message and return EXIT_FAILURE
        fprintf(stderr, "Cannot dequeue from empty queue\n");
        return EXIT_FAILURE;
    }

    QueueNode *deleted_node = queue->head;
    queue->head = queue->head->next;

    // Return deleted_node data
    *return_value = deleted_node->data;
    // Clean deleted_node values
    deleted_node->data = 0;
    deleted_node->next = NULL;
    // Free deleted_node memory
    free(deleted_node);
    queue->length--;

    if (queue->length == 0)
    {
        LinkedQueue_set_empty(queue);
    }
    
    return EXIT_SUCCESS;
}


int LinkedQueue_peek(LinkedQueue queue, int *return_value)
{
    if (queue.length == 0)
    {
        // If queue is empty, show error message and return EXIT_FAILURE
        fprintf(stderr, "Cannot peek from empty queue\n");
        return EXIT_FAILURE;
    }

    // Return head data
    *return_value = queue.head->data; 
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
    // Print an openning square bracket
    printf("[");
    if (queue.length == 0)
    {
        // If queue is empty, print a closing square bracket
        printf(" ]");
        return;
    }

    QueueNode *current_node = queue.head;
    // Print all nodes data except for the last one
    while (current_node->next != NULL)
    {
        int value = current_node->data;
        printf("%d, ", value);
        current_node = current_node->next;
    }
    // Print last node data and a closing square bracket
    printf("%d]", current_node->data);
}


void LinkedQueue_info(LinkedQueue queue)
{
    printf("{\n\t queue data: ");
    LinkedQueue_print(queue);
    printf("\n\t length: %d\n\t", queue.length);

    // Print head information
    if (queue.head == NULL)
    {
        printf(" head is NULL\n\t");
    }
    else
    {
        printf(" head data: %d\n\t", queue.head->data);
    }

    // Print tail information
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
    int ret;
    // Dequeue all queue elements
    while (queue->length > 0)
    {
        LinkedQueue_dequeue(queue, &ret);
    }
}