#include "MySorting.h"
#include <stdio.h>

void insertionsort(int *arr, int size)
{
    if(size == 1)
    {
        // Do nothing
        return;
    }

    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int tmp = arr[i];
        while (j >= 0 && tmp < arr[j])
        {
            // Shift elelements to insert tmp
            arr[j + 1] = arr[j];
            j--;
        }
        // Insert tmp
        arr[j + 1] = tmp;
    }

}