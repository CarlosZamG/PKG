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

    if (list->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    
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

void ArrayList_resize(ArrayList *list, int more)
{
    if (more)
    {
        list->capacity *= 2;
    }
    else
    {
        list->capacity /= 2;
    }
    list->capacity = max(list->capacity, MIN_CAPACITY);
    
    int *tmp = (int *) malloc(sizeof(int) * list->capacity);

    // Show error message if memory allocation failed
    if (tmp == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy the data to the new memory space
    for (int i = 0; i < list->length; i++)
    {
        tmp[i] = list->data[i];
    }

    // Free the old memory space
    free(list->data);
    // Update list->data
    list->data = tmp;
}



void ArrayList_append(ArrayList *list, int value)
{
    if (list->length + 1 > list->capacity)
    {
        ArrayList_resize(list, 1);
    }

    list->data[list->length] = value;
    list->length++;

}

void ArrayList_prepend(ArrayList *list, int value)
{
    if (list->length + 1 > list->capacity)
    {
        ArrayList_resize(list, 1);
    }

    for (int i = list->length; i > 0; i--)
    {
        list->data[i] = list->data[i-1];
    }

    list->data[0] = value;
    list->length++;
}

void ArrayList_insert(ArrayList *list, int position, int value)
{
    if (position == list->length)
    {
        ArrayList_append(list, value);
    }
    else if (position == 0)
    {
        ArrayList_prepend(list, value);
    }
    else if( 0 < position && position < list->length)
    {
        if (list->length + 1 > list->capacity)
        {
            ArrayList_resize(list, 1);
        }

        for (int i = list->length; i > position; i--)
        {
            list->data[i] = list->data[i-1];
        }

        list->data[position] = value;
        list->length++;
    }
    else
    {
        fprintf(stderr, "Invalid position. Integer position must be between 0 and %d\n",list->length);
        exit(EXIT_FAILURE);
    }


}


int ArrayList_pop_last(ArrayList *list)
{
    if (list->length <= 0)
    {
        fprintf(stderr, "Cannot pop from empty list\n");
        exit(EXIT_FAILURE);
    }

    list->length--;
    if (list->length <= (list->capacity/4) )
    {
        ArrayList_resize(list, 0);
    }
    
    return list->data[list->length];
}


int ArrayList_pop(ArrayList *list, int position)
{

    if (list->length <= 0)
    {
        fprintf(stderr, "Cannot pop from empty list\n");
        exit(EXIT_FAILURE);
    }

    if (position < 0 || position >= list->length)
    {
        fprintf(stderr, "Index out of bounds in ArrayList_pop\n");
        exit(EXIT_FAILURE);
    }
    

    int deleted = list->data[position];

    for (int i = position + 1; i < list->length; i++)
    {
        list->data[i - 1] = list->data[i];
    }

    list->length--;
    if (list->length <= (list->capacity/4) )
    {
        ArrayList_resize(list, 0);
    }

    return deleted;
}

