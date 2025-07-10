#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"

int main(int argc, char* argv[])
{

    const int size = 5;

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

    printf("\nLet's delete some elements:\n");
    ArrayList_pop(&list, 10);
    ArrayList_print(list);

}