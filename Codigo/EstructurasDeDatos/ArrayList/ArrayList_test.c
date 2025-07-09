#include <stdio.h>
#include <stdlib.h>


#include "ArrayList.h"

int main(int argc, char* argv[])
{

    printf("\nTest 1.");
    printf("\nLet's create a list with the first 10 positive numbers stored in descending order:\n");

    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 10 - i;
    }
    
    ArrayList list;
    ArrayList_init_from_array(&list, arr, 10);
    ArrayList_print(list);
    printf("\n");
    //ArrayList_info(list);
    //printf("\n");



    printf("\nTest 2.");
    printf("\nLet's append the first 10 positive multiplies of 11 to the list:\n");

    for (int i = 1; i <= 10; i++)
    {
        ArrayList_append(&list, i*11);
    }
    
    ArrayList_print(list);
    printf("\n");
    //ArrayList_info(list);
    //printf("\n");


    
    printf("\nTest 3.");
    printf("\nLet's prepend -1, -2, ..., -10 to the list:\n");
    for (int i = 1; i <= 10; i++)
    {
        ArrayList_prepend(&list, -i);
    }
    
    ArrayList_print(list);
    printf("\n");
    //ArrayList_info(list);
    //printf("\n");


    printf("\nTest 4.");
    printf("\nLet's insert even numbers in the even positions in the list:\n");
    int k = (list.length * 2) - 1;
    for (int i = 0; i <= k; i+=2)
    {
        ArrayList_insert(&list, i, i);
    }

    ArrayList_print(list);
    printf("\n");
    //ArrayList_info(list);
    //printf("\n");


    printf("\nTest 5.");
    printf("\nLet's delete the last 15 numbers in the list:\n");
    
    for (int i = 0; i < 15; i++)
    {
        ArrayList_pop_last(&list);
    }

    ArrayList_print(list);
    printf("\n");
    
    
    printf("\nTest 6.");
    printf("\nLet's print the deleted element:\n");
    int deleted = ArrayList_pop_last(&list);
    printf("\nThe deleted is %d\n", deleted);
    ArrayList_print(list);
    printf("\n");
    

    printf("\nTest 7.");
    printf("\nLet's delete some elements:\n");
    
    for (int i = 1; i < list.length; i++)
    {
        ArrayList_pop(&list, i);
    }
    ArrayList_print(list);
    printf("\n");

    ArrayList_info(list);
    ArrayList_free(&list);
    ArrayList_info(list);
    
    return 0;
}