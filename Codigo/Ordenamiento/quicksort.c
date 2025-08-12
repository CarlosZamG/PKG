#include <stdlib.h>

#include "MySorting.h"


void quicksort_static_median(int *arr, int size)
{
    quicksorting_static_median(arr, 0, size - 1);
}


void quicksorting_static_median(int *arr, int start, int end)
{
    // Base case: Array only have one element or zero elements
    if (start >= end)
    {
        // Do nothing
        return;
    }

    int pivot = compute_pivot_static_median(arr, start, end);
    int index = partition(arr, start, end, pivot);
    // index of where is the pivot after partition

    // Call recursively quicksorting_static_median() 
    if (index - 1 >= start)
    {
        quicksorting_static_median(arr, start, index - 1);
    }
    if (index + 1 <= end)
    {
        quicksorting_static_median(arr, index + 1, end);
    }
}


int compute_pivot_static_median(int *arr, int start, int end)
{
    // Compute middle point of start and end
    int middle = start + (end-start)/2;
    // Choose pivot as the median of arr[start], arr[end] and arr[middle]
    return median_of_3(arr[start], arr[middle], arr[end]);
}


void quicksort_random_median(int *arr, int size)
{
    quicksorting_random_median(arr, 0, size - 1);
}


void quicksorting_random_median(int *arr, int start, int end)
{
    // Base case: Array only have one element or zero elements
    if (start >= end)
    {
        // Do nothing
        return;
    }

    int pivot = compute_pivot_random_median(arr, start, end);
    int index = partition(arr, start, end, pivot);
    // index of where is the pivot after partition

    // Call recursively quicksorting_static_median() 
    if (index - 1 >= start)
    {
        quicksorting_static_median(arr, start, index - 1);
    }
    if (index + 1 <= end)
    {
        quicksorting_static_median(arr, index + 1, end);
    }
}


int compute_pivot_random_median(int *arr, int start, int end)
{
    int length = end - start + 1;
    int r1 = start + (rand() % length);
    int r2 = start + (rand() % length);
    int r3 = start + (rand() % length);
    return median_of_3(arr[r1], arr[r2], arr[r3]);
}


int partition(int *arr, int start, int end, int pivot)
{
    int i = start;
    int j = end;
    while (i < j)
    {
        if (arr[i] < pivot)
        {
            // arr[i] is in the right side
            i++;
        }
        else if(arr[j] > pivot)
        {
            // arr[j] is in the right side
            j--;
        }
        else
        {
            // arr[j] <= pivot <= arr[i]
            swap(&arr[i], &arr[j]);
            if (arr[i] == pivot && arr[j] == pivot)
            {
                i++;
            }
        }
    }

    return i;
}


int median_of_3(int num_1, int num_2, int num_3)
{
    int min, max, median;
    if (num_1 > num_2)
    {
        min = num_2;
        max = num_1;
    }
    else
    {
        // num_1 <= num_2
        min = num_1;
        max = num_2;
    }

    if (num_3 > max)
    {
        // num_3 > max >= min
        median = max;
        max = num_3;
    }
    else if(num_3 < min)
    {
        // num_3 < min <= max
        median = min;
        min = num_3;
    }
    else
    {
        //min <= num_3 <= max
        median = num_3;
    }

    return median;
}


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
