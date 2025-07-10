#ifndef ARRAY_LIST_H_INCLUDED
#define ARRAY_LIST_H_INCLUDED

// Defines the minimum capacity an ArrayList can have.
#define MIN_CAPACITY 16


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

void ArrayList_resize(ArrayList *list, int more);

void ArrayList_append(ArrayList *list, int value);

void ArrayList_prepend(ArrayList *list, int value);

void ArrayList_insert(ArrayList *list, int position, int value);

int ArrayList_pop_last(ArrayList *list);

int ArrayList_pop(ArrayList *list, int position);

int max(int num_1, int num_2);


#endif
