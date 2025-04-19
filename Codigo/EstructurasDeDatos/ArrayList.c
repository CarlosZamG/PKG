#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 8

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
    int capacity = max(INIT_CAPACITY, array_size);
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

int main(int argc, char* argv[])
{
    
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = 10 - i;
    }
    
    ArrayList list;
    ArrayList_init_from_array(&list, arr, 10);
    ArrayList_info(list);

    list.data[3] = 3;
    ArrayList_info(list);

    ArrayList_append(&list, 55);
    ArrayList_info(list);
    ArrayList_append(&list, 255);
    ArrayList_info(list);
    ArrayList_append(&list, 256);
    ArrayList_info(list);

    for (int i = 1; i <= 10; i++)
    {
        ArrayList_prepend(&list, -i);
    }
    
    ArrayList_info(list);

    int k = list.length+15;
    for (int i = 0; i <= k; i+=2)
    {
        ArrayList_insert(&list, i, i);
    }

    ArrayList_info(list);

    ArrayList_free(&list);
    ArrayList_info(list);
    return 0;
}