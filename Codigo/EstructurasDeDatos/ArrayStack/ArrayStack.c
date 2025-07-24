#include <stdio.h>
#include <stdlib.h>

#include "ArrayStack.h"

int max(int num_1, int num_2)
{
    if (num_1 > num_2)
    {
        return num_1;
    }
    return num_2;
}


void ArrayStack_print(ArrayStack stack)
{
    printf("[");
    
    int length = stack.length;

    if (length == 0)
    {
        printf(" ]");
        return;
    }

    for (int i = 0; i < length - 1; i++)
    {
        printf("\"%s\", ", stack.data[i]);
    }

    printf("\"%s\"]", stack.data[length - 1]);

}


int ArrayStack_init_from_array(ArrayStack *stack, char **array, int array_size)
{
    int capacity = max(STACK_MIN_CAPACITY, 2*array_size);
    stack->data = malloc(sizeof(char*) * capacity);
    if (stack->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < array_size; i++)
    {
        stack->data[i] = array[i];
    }
    
    stack->length = array_size;
    stack->capacity = capacity;

    return EXIT_SUCCESS;
}

int ArrayStack_init_empty(ArrayStack *stack)
{
    stack->data = malloc(sizeof(char*) * STACK_MIN_CAPACITY);
    if (stack->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    stack->length = 0;
    stack->capacity = STACK_MIN_CAPACITY;

    return EXIT_SUCCESS;
}
