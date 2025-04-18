#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 256

int max(int num_1, int num_2);


typedef struct ArrayList
{
    int *data;
    int capacity;
    int length;
} ArrayList;


void ArrayList_print(ArrayList list);

void ArrayList_init_from_array(ArrayList* list, int* array, int array_size);

void ArrayList_free(ArrayList* list);

void ArrayList_info(ArrayList list);


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


void ArrayList_init_from_array(ArrayList* list, int* array, int array_size)
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


void ArrayList_free(ArrayList* list)
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

    for (int i = 0; i < list.length; i++)
    {
        printf("%d\n", list.data[i]);
    }
    

    ArrayList_free(&list);
    ArrayList_info(list);
    return 0;
}