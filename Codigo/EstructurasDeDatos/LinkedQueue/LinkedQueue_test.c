#include <stdio.h>

#include "LinkedQueue.h"

int main()
{
    int array[] = {1, 3, 5, 7};

    LinkedQueue queue;
    LinkedQueue_init_from_array(&queue, array, 4);
    LinkedQueue_print(queue);
    printf("\nhead data: %d", queue.head->data);
    printf("\ntail data: %d", queue.tail->data);
    printf("\nqueue length: %d", queue.length);
    printf("\n");
}