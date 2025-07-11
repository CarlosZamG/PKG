#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"

// Command to generate the executable:
//      gcc ArrayList.c malloc_error_test.c -o malloc_error.out
// Command to run the program:
//      ./malloc_error.out

int main(int argc, char* argv[])
{

    const int size = 2999999;

    printf("\nLet's create a list with the first %d positive numbers:\n", size);

    int arr[size];
    for (int i = 1; i <= size; i++)
    {
        arr[i - 1] = i;
    }
    
    ArrayList list;
    ArrayList_init_from_array(&list, arr, size);
    ArrayList_print(list);
    printf("\n");

    printf("\nLet's insert a new number:\n");
    ArrayList_insert(&list, size, size+1);
    ArrayList_print(list);
    printf("\n");

    printf("%d", list.capacity);

}