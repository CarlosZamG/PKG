#include <stdio.h>

#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET "\x1B[0m"

// Command to generate the executable:
//      gcc max_rec_02.c -o max_02.out
// Command to run the program:
//      ./max_02.out

int max_array(int *arr, int start, int end)
{
    if (start == end)
    {
        return arr[start];
    }

    int middle = (start + end) / 2;

    int max_left = max_array(arr, start, middle);
    int max_right = max_array(arr, middle + 1, end);
    
    //return max(max_left, max_right);
    return max_left > max_right ? max_left : max_right;

    /*
    if (max_left > max_right)
    {
        return max_left;
    }
    else
    {
        return max_right;
    }
    */
}

int main()
{
    int arr[] = {1, 2, 5, 7, 9, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    if (max_array(arr, 0, size - 1) == 11) 
        printf(GREEN "Test 1 passed\n" RESET);
    else
        printf(RED "Test 1 failed\n" RESET);

    arr[3] = 45;
    if (max_array(arr, 0, size - 1) == 45) 
        printf(GREEN "Test 2 passed\n" RESET);
    else
        printf(RED "Test 2 failed\n" RESET);

    int arr2[] = {77};
    size = sizeof(arr2)/sizeof(arr2[0]);
    if (max_array(arr2, 0, size - 1) == 77) 
        printf(GREEN "Test 3 passed\n" RESET);
    else
        printf(RED "Test 3 failed\n" RESET);


    arr[0] = 111;
    size = sizeof(arr)/sizeof(arr[0]);
    if (max_array(arr, 0, size - 1) == 111) 
        printf(GREEN "Test 4 passed\n" RESET);
    else
        printf(RED "Test 4 failed\n" RESET);

    arr[1] = 112;
    size = sizeof(arr)/sizeof(arr[0]);
    if (max_array(arr, 0, size - 1) == 112) 
        printf(GREEN "Test 5 passed\n" RESET);
    else
        printf(RED "Test 5 failed\n" RESET);

    
    int arr3[] = {-1, -5, -33, -22, -6};
    size = sizeof(arr3)/sizeof(arr3[0]);
    if (max_array(arr3, 0, size - 1) == -1) 
        printf(GREEN "Test 6 passed\n" RESET);
    else
        printf(RED "Test 6 failed\n" RESET);


    int arr4[] = {2, 2, 2};
    size = sizeof(arr4)/sizeof(arr4[0]);
    if (max_array(arr4, 0, size - 1) == 2) 
        printf(GREEN "Test 7 passed\n" RESET);
    else
        printf(RED "Test 7 failed\n" RESET);

    int arr5[] = {0, 1, 30, 2, 23, 5, 30};
    size = sizeof(arr5)/sizeof(arr5[0]);
    if (max_array(arr5, 0, size - 1) == 30) 
        printf(GREEN "Test 8 passed\n" RESET);
    else
        printf(RED "Test 8 failed\n" RESET);
}