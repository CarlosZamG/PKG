#include <stdio.h>

// Command to generate the executable:
//      gcc quicksort.c -o quicksort.out
// Command to run the program:
//      ./quicksort.out

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
        median = max;
        max = num_3;
    }
    else if(num_3 < min)
    {
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


int partition(int *arr, int start, int end, int pivot)
{
    int i = start;
    int j = end;
    while (i < j)
    {
        if (arr[i] < pivot)
        {
            i++;
        }
        else if(arr[j] > pivot)
        {
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


int compute_pivot_static_median(int *arr, int start, int end)
{
    int middle = start + (end-start)/2;
    int pivot = median_of_3(arr[start], arr[middle], arr[end]);
    return pivot;
}

void quicksorting_static_median(int *arr, int start, int end)
{
    // Base case: Array only have one element
    if (start >= end)
    {
        // Do nothing
        return;
    }

    int pivot = compute_pivot_static_median(arr, start, end);
    int index = partition(arr, start, end, pivot);

    if (index - 1 >= start)
    {
        quicksorting_static_median(arr, start, index - 1);
    }
    if (index + 1 <= end)
    {
        quicksorting_static_median(arr, index + 1, end);
    }

}


void quicksort_static_median(int *arr, int size)
{
    quicksorting_static_median(arr, 0, size - 1);
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
    quicksort_static_median(array, size);
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
    quicksort_static_median(array2, size2);
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");

    printf("\n");
    int array3[] = {7, 6, 5, 4, 3, 2, 1};
    int size3 = sizeof(array3) / sizeof(array3[0]);
    for (int i = 0; i < size3; i++)
    {
        printf("%d ", array3[i]);
    }
    printf("\n");
    quicksort_static_median(array3, size3);
    for (int i = 0; i < size3; i++)
    {
        printf("%d ", array3[i]);
    }
    printf("\n");

    
    printf("\n");
    int array4[] = {1, 3, 4, 2, 7, 5, 4, 10, 11, 9, 12, 8};
    int size4 = sizeof(array4) / sizeof(array4[0]);
    for (int i = 0; i < size4; i++)
    {
        printf("%d ", array4[i]);
    }
    printf("\n");
    quicksort_static_median(array4, size4);
    for (int i = 0; i < size4; i++)
    {
        printf("%d ", array4[i]);
    }
    printf("\n");


    printf("\n");
    int array5[] = {8, 8, 8, 8, 8};
    int size5 = sizeof(array5) / sizeof(array5[0]);
    for (int i = 0; i < size5; i++)
    {
        printf("%d ", array5[i]);
    }
    printf("\n");
    quicksort_static_median(array5, size5);
    for (int i = 0; i < size5; i++)
    {
        printf("%d ", array5[i]);
    }
    printf("\n");


    printf("\n");
    int array6[] = {1, 13, -4, 2, -7, 5, -1, 10, -11, 19, -12, 8, 0};
    int size6 = sizeof(array6) / sizeof(array6[0]);
    for (int i = 0; i < size6; i++)
    {
        printf("%d ", array6[i]);
    }
    printf("\n");
    quicksort_static_median(array6, size6);
    for (int i = 0; i < size6; i++)
    {
        printf("%d ", array6[i]);
    }
    printf("\n");


    printf("\n");
    int array7[] = {1, 3, 5, 7, 9, 11, 13, 12, 10, 8, 6, 4, 2};
    int size7 = sizeof(array7) / sizeof(array7[0]);
    for (int i = 0; i < size7; i++)
    {
        printf("%d ", array7[i]);
    }
    printf("\n");
    quicksort_static_median(array7, size7);
    for (int i = 0; i < size7; i++)
    {
        printf("%d ", array7[i]);
    }
    printf("\n");

    printf("\n");
    int array8[] = {1, -3, 5, -7, 9, -11, 13, -12, 10, -8, 6, -4, 2};
    int size8 = sizeof(array8) / sizeof(array8[0]);
    for (int i = 0; i < size8; i++)
    {
        printf("%d ", array8[i]);
    }
    printf("\n");
    quicksort_static_median(array8, size8);
    for (int i = 0; i < size8; i++)
    {
        printf("%d ", array8[i]);
    }
    printf("\n");

    printf("\n");
    int array9[] = {1, 7, 1, 7, -12, 7, 7, -12, 1, 7, 1, -12, 1, 7, -12};
    int size9 = sizeof(array9) / sizeof(array9[0]);
    for (int i = 0; i < size9; i++)
    {
        printf("%d ", array9[i]);
    }
    printf("\n");
    quicksort_static_median(array9, size9);
    for (int i = 0; i < size9; i++)
    {
        printf("%d ", array9[i]);
    }
    printf("\n");

    printf("\n");
    int array10[] = {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0};
    int size10 = sizeof(array10) / sizeof(array10[0]);
    for (int i = 0; i < size10; i++)
    {
        printf("%d ", array10[i]);
    }
    printf("\n");
    quicksort_static_median(array10, size10);
    for (int i = 0; i < size10; i++)
    {
        printf("%d ", array10[i]);
    }
    printf("\n");

    printf("\n");
    int array11[] = {0, 0, 1, 0, -3, 0, -1, 0, 2, 0, 0, 0, -2, 0, 0, 3};
    int size11 = sizeof(array11) / sizeof(array11[0]);
    for (int i = 0; i < size11; i++)
    {
        printf("%d ", array11[i]);
    }
    printf("\n");
    quicksort_static_median(array11, size11);
    for (int i = 0; i < size11; i++)
    {
        printf("%d ", array11[i]);
    }
    printf("\n");
}