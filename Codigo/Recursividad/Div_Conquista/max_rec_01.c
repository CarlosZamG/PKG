#include <stdio.h>

#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET "\x1B[0m"

// Command to generate the executable:
//      gcc max_rec_01.c -o max_01.out
// Command to run the program:
//      ./max_01.out


int max_array(int *arr, int end)
{
    if (end == 0)
    {
        return arr[0];
    }

    int aux = max_array(arr, end - 1);

    //return max(arr[end], aux);
    return arr[end] > aux ? arr[end] : aux;

    /*
    if (arr[end] > aux)
    {
        return arr[end];
    }
    else
    {
        return aux;
    }
    */
}

int main()
{
    int arr[] = {1, 2, 5, 7, 9, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    if (max_array(arr, size - 1) == 11) 
        printf(GREEN "Test 1 passed\n" RESET);
    else
        printf(RED "Test 1 failed\n" RESET);

    arr[3] = 45;
    if (max_array(arr, size - 1) == 45) 
        printf(GREEN "Test 2 passed\n" RESET);
    else
        printf(RED "Test 2 failed\n" RESET);

    int arr2[] = {77};
    size = sizeof(arr2)/sizeof(arr2[0]);
    if (max_array(arr2, size - 1) == 77) 
        printf(GREEN "Test 3 passed\n" RESET);
    else
        printf(RED "Test 3 failed\n" RESET);


    arr[0] = 111;
    size = sizeof(arr)/sizeof(arr[0]);
    if (max_array(arr, size - 1) == 111) 
        printf(GREEN "Test 4 passed\n" RESET);
    else
        printf(RED "Test 4 failed\n" RESET);

    arr[1] = 112;
    size = sizeof(arr)/sizeof(arr[0]);
    if (max_array(arr, size - 1) == 112) 
        printf(GREEN "Test 5 passed\n" RESET);
    else
        printf(RED "Test 5 failed\n" RESET);

    
    int arr3[] = {-1, -5, -33, -22, -6};
    size = sizeof(arr3)/sizeof(arr3[0]);
    if (max_array(arr3, size - 1) == -1) 
        printf(GREEN "Test 6 passed\n" RESET);
    else
        printf(RED "Test 6 failed\n" RESET);


    int arr4[] = {2, 2, 2};
    size = sizeof(arr4)/sizeof(arr4[0]);
    if (max_array(arr4, size - 1) == 2) 
        printf(GREEN "Test 7 passed\n" RESET);
    else
        printf(RED "Test 7 failed\n" RESET);

    int arr5[] = {0, 1, 30, 2, 23, 5, 30};
    size = sizeof(arr5)/sizeof(arr5[0]);
    if (max_array(arr5, size - 1) == 30) 
        printf(GREEN "Test 8 passed\n" RESET);
    else
        printf(RED "Test 8 failed\n" RESET);
}