#include <stdio.h>
#include <stdlib.h>

#include "ArrayStack.h"

// Command to generate the executable:
//      gcc ArrayStack.c ArrayStack_test.c -o stack_test.out
// Command to run the program:
//      ./stack_test.out
int main() {

    char *arr[5] = {"Hello", "World", "of", "Data", "Structures"};

    ArrayStack stack;
    ArrayStack_init_from_array(&stack, arr, 5);
    ArrayStack_print(stack); 
    printf("\n");

    ArrayStack stack_2;
    ArrayStack_init_empty(&stack_2);

    //ArrayStack_print(stack_2);

    char *peeked;

    if(ArrayStack_peek(stack_2, &peeked) == EXIT_SUCCESS)
    {
        printf("\npeeked string: %s", peeked);
    }
    else
    {
        printf("stack_2 is empty");
    }
    printf("\n");

    char *str = "Alan";
    ArrayStack_push(&stack_2, str);
    ArrayStack_print(stack_2);
    //printf("\n");

    if(ArrayStack_peek(stack_2, &peeked) == EXIT_SUCCESS)
    {
        printf("\npeeked string: %s", peeked);
    }
    else
    {
        printf("\nstack_2 is empty");
    }
    printf("\n");

    ArrayStack_push(&stack_2, "Jim");
    ArrayStack_push(&stack_2, "Ray");
    ArrayStack_push(&stack_2, "Robby");
    ArrayStack_push(&stack_2, "John");
    ArrayStack_print(stack_2);
    if(ArrayStack_peek(stack_2, &peeked) == EXIT_SUCCESS)
    {
        printf("\npeeked string: %s", peeked);
    }
    else
    {
        printf("\nstack_2 is empty");
    }
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
    
    //ArrayStack_info(stack_2);
    ArrayStack_print(stack_2);
    //printf("\n");
    //
    if(ArrayStack_peek(stack_2, &peeked) == EXIT_SUCCESS)
    {
        printf("\npeeked string: %s", peeked);
    }
    else
    {
        printf("\nstack_2 is empty");
    }
    printf("\n");
    ArrayStack_free(&stack);
    ArrayStack_free(&stack_2);
    //ArrayStack_info(stack);
    printf("\n");
    //ArrayStack_info(stack_2);

    return 0;
}