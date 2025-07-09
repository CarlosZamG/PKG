#include <stdlib.h>
#include <stdio.h>


#include "ArrayList.h" 


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

