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
    // Print opening square bracket 
    printf("[");

    if (list.length <= 0)
    {
        // If the list is empty, print closing square bracket
        printf(" ]");
        return;
    }
    
    int last_index = list.length - 1;
    
    // Print all elements separated by commas except for the last one
    for (int i = 0; i < last_index; i++)
    {
        printf("%d, ", list.data[i]);
    }
    // Print the last element and a closing square bracket
    printf("%d]", list.data[last_index]);
}


void ArrayList_init_from_array(ArrayList *list, int *array, int array_size)
{
    int capacity = max(MIN_CAPACITY, array_size);
    // Request memory according to the required capacity
    list->data = malloc(sizeof(int) * capacity);

    // Show error message if memory allocation failed
    if (list->data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    //Copy the array values to the list data
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
    // Set list->capacity and list->length to 0 
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
        // If more memory is required, the capacity is doubled
        list->capacity *= 2;
    }
    else
    {
        // If less memory is needed, the capacity is reduced by half
        list->capacity /= 2;
    }
    // Always respect the minimum capacity
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
    // If more memory is required, resize the list
    if (list->length + 1 > list->capacity)
    {
        ArrayList_resize(list, 1);
    }
    // Insert value at the end of the list
    list->data[list->length] = value;
    list->length++;

}


void ArrayList_prepend(ArrayList *list, int value)
{
    // If more memory is required, resize the list
    if (list->length + 1 > list->capacity)
    {
        ArrayList_resize(list, 1);
    }
    // Shift all data one place
    for (int i = list->length; i > 0; i--)
    {
        list->data[i] = list->data[i-1];
    }
    // Insert value at the beginning of the list
    list->data[0] = value;
    list->length++;
}


void ArrayList_insert(ArrayList *list, int position, int value)
{
    if (position == list->length)
    {
        // If position is equal to list->length, 
        // then append value to the list
        ArrayList_append(list, value);
    }
    else if (position == 0)
    {
        // If position is equal to 0, then prepend value to the list
        ArrayList_prepend(list, value);
    }
    else if( 0 < position && position < list->length)
    {
        // If more memory is required, resize the list
        if (list->length + 1 > list->capacity)
        {
            ArrayList_resize(list, 1);
        }
        // Shift the required data one place
        for (int i = list->length; i > position; i--)
        {
            list->data[i] = list->data[i-1];
        }
        // Inserts value in the specified position
        list->data[position] = value;
        list->length++;
    }
    else
    {
        // If the specified position is invalid, show an error message
        fprintf(stderr, "Invalid position. Integer position must be between 0 and %d\n",list->length);
        exit(EXIT_FAILURE);
    }
}


int ArrayList_pop_last(ArrayList *list)
{
    if (list->length <= 0)
    {
        // If the list is empty, show an error message
        fprintf(stderr, "Cannot pop from empty list\n");
        exit(EXIT_FAILURE);
    }

    list->length--;
    if (list->length <= (list->capacity/4) )
    {
        // If is not using a lot of capacity, then resize the list
        ArrayList_resize(list, 0);
    }
    
    return list->data[list->length];
}


int ArrayList_pop(ArrayList *list, int position)
{
    if (list->length <= 0)
    {
        // If the list is empty, show an error message
        fprintf(stderr, "Cannot pop from empty list\n");
        exit(EXIT_FAILURE);
    }

    if (position < 0 || position >= list->length)
    {
        // If position is invalid, show an error message
        fprintf(stderr, "Index out of bounds in ArrayList_pop\n");
        exit(EXIT_FAILURE);
    }
    
    int deleted = list->data[position];

    // Shift the required data one place
    for (int i = position + 1; i < list->length; i++)
    {
        list->data[i - 1] = list->data[i];
    }

    list->length--;
    if (list->length <= (list->capacity/4) )
    {
        // If is not using a lot of capacity, then resize the list
        ArrayList_resize(list, 0);
    }

    return deleted;
}