#include <stdio.h>

#include "MySorting.h"

// Command to generate the executable:
//       gcc quicksort.c quicksort_random_pivot_test.c -o quicksort_random_pivot_test.out
// Command to run the program:
//      ./quicksort_random_pivot_test.out

int main()
{
    int array[] = {2, 3, 1, 8, 6, 1, 2, 11, -7, 7, 4, 2};
    int size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    quicksort_random_pivot(array, size);
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
    quicksort_random_pivot(array2, size2);
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
    quicksort_random_pivot(array3, size3);
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
    quicksort_random_pivot(array4, size4);
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
    quicksort_random_pivot(array5, size5);
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
    quicksort_random_pivot(array6, size6);
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
    quicksort_random_pivot(array7, size7);
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
    quicksort_random_pivot(array8, size8);
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
    quicksort_random_pivot(array9, size9);
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
    quicksort_random_pivot(array10, size10);
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
    quicksort_random_pivot(array11, size11);
    for (int i = 0; i < size11; i++)
    {
        printf("%d ", array11[i]);
    }
    printf("\n");
}