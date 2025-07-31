#include <stdio.h>

#include "LinkedQueue.h"

// Command to generate the executable:
//      gcc LinkedQueue.c LinkedQueue_test.c -o queue_test.out
// Command to run the program:
//      ./queue_test.out

int main()
{
    int array[] = {1, 3, 5, 7};

    LinkedQueue queue;
    LinkedQueue_init_from_array(&queue, array, 4);
    LinkedQueue_print(queue);
    printf("\n");

    LinkedQueue_enqueue(&queue, 8);
    LinkedQueue_enqueue(&queue, 11);

    LinkedQueue_info(queue);

    int ret;
    while (queue.length > 0)
    {
        LinkedQueue_dequeue(&queue, &ret);
        printf("\nDeleted value: %d\n", ret);
        LinkedQueue_info(queue);
    }

    LinkedQueue q2;
    LinkedQueue_set_empty(&q2);
    LinkedQueue_info(q2);
    LinkedQueue_enqueue(&q2, 2);
    LinkedQueue_enqueue(&q2, 4);
    LinkedQueue_enqueue(&q2, 6);
    LinkedQueue_info(q2);
    LinkedQueue_peek(q2, &ret);
    printf("\nPeeked value: %d\n", ret);
    LinkedQueue_free(&q2);
    LinkedQueue_info(q2);
    
    printf("\n");
}