#ifndef ARRAY_STACK_H_INCLUDED
#define ARRAY_STACK_H_INCLUDED

#define STACK_MIN_CAPACITY 16

typedef struct ArrayStack
{
    char **data;
    int length;
    int capacity;
} ArrayStack;

void ArrayStack_print(ArrayStack stack);


int ArrayStack_init_from_array(ArrayStack *stack, char **array, int array_size);


int ArrayStack_init_empty(ArrayStack *stack);


int max(int num_1, int num_2);


#endif