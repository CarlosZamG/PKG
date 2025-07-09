#include <stdio.h>
#include <stdlib.h>

#define MIN_CAPACITY 16

int max(int num_1, int num_2);


typedef struct ArrayList
{
    int *data;
    int capacity;
    int length;
} ArrayList;


void ArrayList_print(ArrayList list);

void ArrayList_init_from_array(ArrayList *list, int *array, int array_size);

void ArrayList_free(ArrayList *list);

void ArrayList_info(ArrayList list);

void ArrayList_append(ArrayList *list, int value);

void ArrayList_prepend(ArrayList *list, int value);

void ArrayList_insert(ArrayList *list, int position, int value);

int ArrayList_pop_last(ArrayList *list);

int ArrayList_pop(ArrayList *list, int position);

int max(int num_1, int num_2)
{
    if (num_1 > num_2)
    {
        return num_1;
    }
    return num_2;
}



void ArrayList_print(ArrayList list)
{
    printf("[");

    if (list.length <= 0)
    {
        printf(" ]");
        return;
    }
    
    int last_index = list.length - 1;
    
    for (int i = 0; i < last_index; i++)
    {
        printf("%d, ", list.data[i]);
    }
    printf("%d]", list.data[last_index]);
}


void ArrayList_init_from_array(ArrayList *list, int *array, int array_size)
{
    int capacity = max(MIN_CAPACITY, array_size);
    list->data = malloc(sizeof(int) * capacity);
    
    for (int i = 0; i < array_size; i++)
    {
        list->data[i] = array[i];
    }

    list->length = array_size;
    list->capacity = capacity;  
}


void ArrayList_free(ArrayList *list)
{
    free(list->data);
    list->data = NULL;
    list->capacity = 0;
    list->length = 0;
}

void ArrayList_info(ArrayList list)
{
    printf("{\n\t data: ");
    ArrayList_print(list);
    printf("\n\t length: %d\n\t capacity: %d\n}\n", list.length, list.capacity);
}


void ArrayList_append(ArrayList *list, int value)
{
    if (list->length + 1 > list->capacity)
    {
        list->capacity *= 2;
        int *tmp = (int *) malloc(sizeof(int) * list->capacity);

        for (int i = 0; i < list->length; i++)
        {
            tmp[i] = list->data[i];
        }

        free(list->data);
        list->data = tmp;
    }

    list->data[list->length] = value;
    list->length++;

}

void ArrayList_prepend(ArrayList *list, int value)
{
    if (list->length + 1 > list->capacity)
    {
        list->capacity *= 2;
        int *tmp = (int *) malloc(sizeof(int) * list->capacity);

        for (int i = 0; i < list->length; i++)
        {
            tmp[i + 1] = list->data[i];
        }
        free(list->data);
        list->data = tmp;
    }
    else
    {
        for (int i = list->length; i > 0; i--)
        {
            list->data[i] = list->data[i-1];
        }
    }

    list->data[0] = value;
    list->length++;
}

void ArrayList_insert(ArrayList *list, int position, int value)
{
    if (position >= list->length)
    {
        ArrayList_append(list, value);
    }
    else if (position == 0)
    {
        ArrayList_prepend(list, value);
    }
    else
    {
        if (list->length + 1 > list->capacity)
        {
            list->capacity *= 2;
            int *tmp = (int *) malloc(sizeof(int) * list->capacity);

            for (int i = 0; i < list->length; i++)
            {
                tmp[i] = list->data[i];
            }
            free(list->data);
            list->data = tmp;
        }

        for (int i = list->length; i > position; i--)
        {
            list->data[i] = list->data[i-1];
        }

        list->data[position] = value;
        list->length++;

    }

}


int ArrayList_pop_last(ArrayList *list)
{
    list->length--;
    return list->data[list->length];
}


int ArrayList_pop(ArrayList *list, int position)
{
    int deleted = list->data[position];

    for (int i = position + 1; i < list->length; i++)
    {
        list->data[i - 1] = list->data[i];
    }

    list->length--;

    return deleted;
}

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