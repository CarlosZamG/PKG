#ifndef ARRAY_LIST_H_INCLUDED
#define ARRAY_LIST_H_INCLUDED

// Defines the minimum capacity an ArrayList can have.
#define MIN_CAPACITY 16

// Defines the implementation of the Abstract Data Type List using arrays for store integer values.
// It has the following members:
//      - int *data: pointer to integer to store the integers elements dynamically.
//      - int capacity: number of elements that can be stored in data.
//      - int length: number of elements that are stored in data.
typedef struct ArrayList
{
    int *data;
    int capacity;
    int length;
} ArrayList;

// Prints list with nice format.
void ArrayList_print(ArrayList list);

// Creates an ArrayList with the values of array.
void ArrayList_init_from_array(ArrayList *list, int *array, int array_size);

// Frees the memory of list. Set list->length and list->capacity to 0.
void ArrayList_free(ArrayList *list);

// Prints list information like data stored, capacity and length.
void ArrayList_info(ArrayList list);

// Resizes list copying data stored to new array.
// If more is true, then doubles the capacity.
// If more is false, the reduces the capacity by half.
void ArrayList_resize(ArrayList *list, int more);

// Inserts value to the end of list
void ArrayList_append(ArrayList *list, int value);

// Inserts value to the beginning of list
void ArrayList_prepend(ArrayList *list, int value);

// Inserts value in the specified position of list
void ArrayList_insert(ArrayList *list, int position, int value);

// Deletes the value at the end of the list
int ArrayList_pop_last(ArrayList *list);

// Deletes the value of list at the specified position
int ArrayList_pop(ArrayList *list, int position);

// Returns the maximun of num_1 and num_2
int max(int num_1, int num_2);


#endif
