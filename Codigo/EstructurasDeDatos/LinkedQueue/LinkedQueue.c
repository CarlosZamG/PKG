#include <stdio.h>
#include <stdlib.h>

#include "LinkedQueue.h"

void LinkedQueue_init_empty(LinkedQueue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;
}

void LinkedQueue_init_from_array(LinkedQueue *queue, int *array, int array_size)
{

    if (array_size == 0)
    {
        LinkedQueue_init_empty(queue);
        return;
    }

    QueueNode *new_node = NULL;

    queue->tail = malloc(sizeof(QueueNode));
    queue->tail->data = array[0];
    queue->tail->next = NULL;
    queue->head = queue->tail;

    for (int i = 1; i < array_size; i++)
    {
        new_node = malloc(sizeof(QueueNode));
        new_node->data = array[i];
        new_node->next = NULL;
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    queue->tail = new_node;
    queue->length = array_size;
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