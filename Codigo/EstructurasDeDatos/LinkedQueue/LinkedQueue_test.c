#include <stdio.h>

#include "LinkedQueue.h"

int main()
{
    int array[] = {1, 3, 5, 7};

    LinkedQueue queue;
    LinkedQueue_init_from_array(&queue, array, 4);
    LinkedQueue_print(queue);
    printf("\n");

    LinkedQueue_enqueue(&queue, 8);
    LinkedQueue_print(queue);
    printf("\nqueue length: %d", queue.length);
    printf("\n");

    LinkedQueue_info(queue);

    int ret;
    LinkedQueue_dequeue(&queue, &ret);
    printf("\nDeleted value: %d\n", ret);
    LinkedQueue_info(queue);

    LinkedQueue_dequeue(&queue, &ret);
    LinkedQueue_dequeue(&queue, &ret);
    LinkedQueue_dequeue(&queue, &ret);

    LinkedQueue_info(queue);


    /*
    LinkedQueue q2;
    LinkedQueue_init_empty(&q2);
    LinkedQueue_print(q2);
    printf("\nq2 length: %d", q2.length);
    printf("\n");
    LinkedQueue_enqueue(&q2, 2);
    LinkedQueue_enqueue(&q2, 4);
    LinkedQueue_enqueue(&q2, 6);
    LinkedQueue_print(q2);
    printf("\nq2 length: %d", q2.length);
    
    LinkedQueue_enqueue(&queue, 11);
    LinkedQueue_enqueue(&queue, 12);
    printf("\nqueue: ");
    LinkedQueue_print(queue);
    LinkedQueue_free(&queue);
    printf("\nqueue: ");
    LinkedQueue_print(queue);
    printf("\n");
    */

    printf("\n");
}