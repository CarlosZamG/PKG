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
    // Print openning square bracket
    printf("[");
    
    // Store the stack length in a variable
    int length = stack.length;

    // If the stack is empty, print closing square bracket
    if (length == 0)
    {
        printf(" ]");
        return;
    }

    // Print all elements separated by commas except for the last one
    for (int i = 0; i < length - 1; i++)
    {
        printf("\"%s\", ", stack.data[i]);
    }

    // Print the last one element with a closing square bracket  
    printf("\"%s\"]", stack.data[length - 1]);

}


void ArrayStack_info(ArrayStack stack)
{
    printf("{\n\t data: ");
    ArrayStack_print(stack);
    printf("\n\t length: %d\n\t capacity: %d\n}\n", stack.length, stack.capacity);
}


int ArrayStack_init_from_array(ArrayStack *stack, char **array, int array_size)
{
    // Compute initial capacity, can be STACK_MIN_CAPCITY or twice as needed for the array
    int capacity = max(STACK_MIN_CAPACITY, 2*array_size);
    // Request memory according to required capacity
    stack->data = malloc(sizeof(char*) * capacity);
    // If memory allocation failed, show error message and return EXIT_FAILURE
    if (stack->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    // Copy array data to stack data
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
    // Request memory according to minimum capacity
    stack->data = malloc(sizeof(char*) * STACK_MIN_CAPACITY);
    if (stack->data == NULL)
    {
        // If memory allocation failed, show error message and return EXIT_FAILURE
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    stack->length = 0;
    stack->capacity = STACK_MIN_CAPACITY;

    return EXIT_SUCCESS;
}


void ArrayStack_free(ArrayStack *stack)
{
    free(stack->data);
    stack->data = NULL;
    // Set list->capacity and list->length to 0 
    stack->capacity = 0;
    stack->length = 0;
}


int ArrayStack_resize(ArrayStack *stack, int more)
{
    if (more)
    {
        // If more space is needed, doubles de capacity
        stack->capacity *= 2;
    }
    else
    {
        // If less space is needed, doubles de capacity
        stack->capacity /= 2;
    }

    char **tmp = malloc(sizeof(char *) * stack->capacity);
    if(tmp == NULL)
    {
        // If memory allocation failed, show error message and return EXIT_FAILURE
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    // Copy stack data to the new memory space
    for (int i = 0; i < stack->length; i++)
    {
        tmp[i] = stack->data[i];
    }
    free(stack->data);
    stack->data = tmp;
}


int ArrayStack_push(ArrayStack *stack, char *element)
{
    if (stack->length + 1 > stack->capacity)
    {
        stack->capacity *= 2;
        char **tmp = malloc(sizeof(char *) * stack->capacity);
        if(tmp == NULL)
        {
            // If memory allocation failed, show error message and return EXIT_FAILURE
            fprintf(stderr, "Memory allocation failed\n");
            return EXIT_FAILURE;
        }
        // Copy stack data to the new memory space
        for (int i = 0; i < stack->length; i++)
        {
            tmp[i] = stack->data[i];
        }
        free(stack->data);
        stack->data = tmp;
    }

    stack->data[stack->length] = element;
    stack->length++;

    return EXIT_SUCCESS;
}


int ArrayStack_peek(ArrayStack stack, char **element)
{
    if (stack.length == 0)
    {
        // If stack is empty, show error message and return EXIT_FAILURE
        fprintf(stderr, "Cannot peek from empty stack\n");
        return EXIT_FAILURE;
    }

    // Return the next element in the LIFO ordering
    *element = stack.data[stack.length - 1];
    return EXIT_SUCCESS;
}


int ArrayStack_pop(ArrayStack *stack, char **element)
{
    if (stack->length == 0)
    {
        // If stack is empty, show error message and return EXIT_FAILURE
        fprintf(stderr, "Cannot pop from empty stack\n");
        return EXIT_FAILURE;
    }

    // Return the next element in the LIFO ordering
    *element = stack->data[stack->length - 1];
    stack->length--;

    if (stack->length <= (stack->capacity/4))
    {
        ArrayStack_resize(stack, 0);
    }
    
    return EXIT_SUCCESS;
}