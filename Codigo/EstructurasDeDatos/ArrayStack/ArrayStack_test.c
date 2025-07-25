#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");

    char *str = "Alan";
    ArrayStack_push(&stack_2, str);
    ArrayStack_print(stack_2);
    printf("\n");

    ArrayStack_push(&stack_2, "Jim");
    ArrayStack_push(&stack_2, "Ray");
    ArrayStack_push(&stack_2, "Robby");
    ArrayStack_push(&stack_2, "John");
    ArrayStack_print(stack_2);
    printf("\n");

    char *alphabet[26];
    char c = 'A';
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = malloc(sizeof(char) * 2);
        alphabet[i][0] = c + i;
        alphabet[i][1] = '\0';
        ArrayStack_push(&stack_2, alphabet[i]);
    }
    
    char c_str[3] = "abc";
    printf("%s\n", c_str);


    ArrayStack_print(stack_2);
    printf("\n");

    return 0;
}