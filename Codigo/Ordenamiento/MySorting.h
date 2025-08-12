#ifndef MY_SORTING_H_INCLUDED
#define MY_SORTING_H_INCLUDED

// Sort in place the given integer array using quicksort algorithm
// 
// If is sorting arr[start:end], choose pivot as median of
// three elements: arr[start], arr[end], arr[middle]
// where middle is the middle point between start and end
// Parmameters:
//      int *arr: integer pointer to the beginning of the array
//      int size: size of the given array 
void quicksort_static_median(int *arr, int size);


// Sort in place the given integer array between the range [start: end]
// 
// Auxiliar function for quicksort_static_median()
// Parmameters:
//      int *arr: integer pointer to the beginning of the array
//      int start: beginning of the range that is going to be sorted
//      int end: end of the range that is going to be sorted 
void quicksorting_static_median(int *arr, int start, int end);


// Compute pivot for quicksort algorithm as median of three elements:
// arr[start], arr[end], arr[middle] where middle is the middle
// point between start and end
// Parmameters:
//      int *arr: integer pointer to the beginning of the array
//      int start: beginning of the range that is going to be sorted
//      int end: end of the range that is going to be sorted 
// Returns:
//      int: the value of the pivot
int compute_pivot_static_median(int *arr, int start, int end);


// Sort in place the given integer array using quicksort algorithm
// 
// Choose pivot as median of three random elements
// Parmameters:
//      int *arr: integer pointer to the beginning of the array
//      int size: size of the given array 
void quicksort_random_median(int *arr, int size);


// Sort in place the given integer array between the range [start: end]
// 
// Auxiliar function for quicksort_random_median()
// Parmameters:
//      int *arr: integer pointer to the beginning of the array
//      int start: beginning of the range that is going to be sorted
//      int end: end of the range that is going to be sorted 
void quicksorting_random_median(int *arr, int start, int end);


// Compute pivot for quicksort algorithm as median of three random elements:
// Parmameters:
//      int *arr: integer pointer to the beginning of the array
//      int start: beginning of the range that is going to be sorted
//      int end: end of the range that is going to be sorted 
// Returns:
//      int: the value of the pivot
int compute_pivot_random_median(int *arr, int start, int end);


// Do the partition for quicksort algorithm given an integer
// array between the range [start: end] and a pivot 
// Parmameters:
//      int *arr: integer pointer to the beginning of the array
//      int start: beginning of the range that is going to be sorted
//      int end: end of the range that is going to be sorted 
//      int pivot: the pivot of quicksort algorithm
// Returns:
//      int: index of where is the pivot
int partition(int *arr, int start, int end, int pivot);


// Compute the median of num_1, num_2 and num_3
int median_of_3(int num_1, int num_2, int num_3);


// Swap values between two integers a and b
void swap(int *a, int *b);


#endif