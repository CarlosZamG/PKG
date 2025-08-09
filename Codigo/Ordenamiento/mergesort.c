#include <stdio.h>

// Command to generate the executable:
//      gcc mergesort.c -o mergesort.out
// Command to run the program:
//      ./mergesort.out

void merge(int *arr, int start, int end, int middle)
{
    // Create auxiliar array
    int aux_array[end - start + 1];

    int i = start;
    int j = middle + 1;
    int k = 0;

    while (i <= middle && j <= end)
    {
        // Choose which element should be copied to auxiliar array
        if (arr[i] < arr[j])
        {
            aux_array[k] = arr[i];
            i++;
        }
        else
        {
            // arr[i] >= arr[j]
            aux_array[k] = arr[j];
            j++;
        }
        k++;
    }

    // Just one of the following  two loops will be executed
    while (i <= middle)
    {
        aux_array[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        aux_array[k] = arr[j];
        j++;
        k++;
    }

    // Copy data from auxiliar array to original array
    for (int m = start, k = 0; m <= end; m++, k++)
    {
        arr[m] = aux_array[k];
    }
}


void mergesorting(int *arr, int start, int end)
{
    // Base case: Array only have one element
    if (start == end)
    {
        // Do nothing
        return;
    }
    
    // Compute middle point between start and end
    int middle = start + (end - start)/2;
    // sort first half
    mergesorting(arr, start, middle);
    // sort second  half
    mergesorting(arr, middle + 1, end);
    // Merge two halves
    merge(arr, start, end, middle);
}


void mergesort(int *arr, int size)
{
    mergesorting(arr, 0, size - 1);
}

int main()
{
    int array[] = {2, 3, 1, 8, 6, 1, 2, 11, -7, 7, 4, 2};
    int size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    mergesort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("\n");
    int array2[] = {8, 6, 1, 2, 11, -7, 7, 4, 2 , 5, 1, -7, -4, 4, -12, 13, 6, 5, -9};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");
    mergesort(array2, size2);
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");
}