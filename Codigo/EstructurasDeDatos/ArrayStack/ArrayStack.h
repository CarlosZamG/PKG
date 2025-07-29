#ifndef ARRAY_STACK_H_INCLUDED
#define ARRAY_STACK_H_INCLUDED

#define STACK_MIN_CAPACITY 16

typedef struct ArrayStack
{
    char **data;
    int length;
    int capacity;
} ArrayStack;

// Print stack data with pretty format 
void ArrayStack_print(ArrayStack stack);

// Print stack information with pretty format 
void ArrayStack_info(ArrayStack stack);


int ArrayStack_init_from_array(ArrayStack *stack, char **array, int array_size);


int ArrayStack_init_empty(ArrayStack *stack);

// Free stack memory 
void ArrayStack_free(ArrayStack *stack);

// Add a new element to the stack
int ArrayStack_push(ArrayStack *stack, char *element);

// Remove and return the next element in the LIFO ordering
int ArrayStack_pop(ArrayStack *stack, char **element);

// Return the next element in the LIFO ordering
int ArrayStack_peek(ArrayStack stack, char **element);

// Change capacity of stack
int ArrayStack_resize(ArrayStack *stack, int more);

int max(int num_1, int num_2);


#endif