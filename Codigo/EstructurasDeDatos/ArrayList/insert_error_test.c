#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"

// Command to generate the executable:
//      gcc ArrayList.c insert_error_test.c -o insert_error.out
// Command to run the program:
//      ./insert_error.out

int main(int argc, char* argv[])
{
    printf("\nLet's create a list with the first 10 positive numbers:\n");

    int arr[10];
    for (int i = 1; i <= 10; i++)
    {
        arr[i - 1] = i;
    }
    
    ArrayList list;
    ArrayList_init_from_array(&list, arr, 10);
    ArrayList_print(list);
    printf("\n");

    printf("\nLet's insert a new number:\n");
    ArrayList_insert(&list, 10, 11);
    ArrayList_print(list);
    printf("\n");

    printf("\nLet's insert a new number:\n");
    ArrayList_insert(&list, 12, 12);
    ArrayList_print(list);
    printf("\n");
}