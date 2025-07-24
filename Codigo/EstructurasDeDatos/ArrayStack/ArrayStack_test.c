#include <stdio.h>

#include "ArrayStack.h"

int main() {

    char *arr[5] = {"Hello", "World", "of", "Data", "Structures"};

    ArrayStack stack;
    ArrayStack_init_from_array(&stack, arr, 5);
    ArrayStack_print(stack); 
    printf("\n");

    ArrayStack stack_2;
    ArrayStack_init_empty(&stack_2);
    ArrayStack_print(stack_2);


    return 0;
}