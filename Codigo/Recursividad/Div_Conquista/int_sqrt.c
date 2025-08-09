#include <stdio.h>

#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET "\x1B[0m"

// Command to generate the executable:
//      gcc int_sqrt.c -o int_sqrt.out
// Command to run the program:
//      ./int_sqrt.out


int sqrt_search(int start, int end, int num)
{
    if (start == end)
    {
        return start;
    }
    
    int middle = (start + end) / 2;
    
    
    if (middle == start)
    {
        if (end*end <= num)
        {
            return end;
        }
        return middle;
    }


    if (middle*middle > num)
    {
        return sqrt_search(start, middle - 1, num);
    }
    else
    {
        return sqrt_search(middle, end, num);
    }
}


int int_sqrt(int num)
{
    return sqrt_search(0, num, num);
}

int main()
{    
    
    if(int_sqrt(10) == 3)
        printf(GREEN "Test 1 passed\n" RESET);
    else
        printf(RED "Test 1 failed\n" RESET);
    
    if(int_sqrt(4) == 2)
        printf(GREEN "Test 2 passed\n" RESET);
    else
        printf(RED "Test 2 failed\n" RESET);

    if(int_sqrt(9) == 3)
        printf(GREEN "Test 3 passed\n" RESET);
    else
        printf(RED "Test 3 failed. Get %d\n" RESET, int_sqrt(9));

    if(int_sqrt(17) == 4)
        printf(GREEN "Test 4 passed\n" RESET);
    else
        printf(RED "Test 4 failed. Get %d\n" RESET, int_sqrt(17));

    if(int_sqrt(50) == 7)
        printf(GREEN "Test 5 passed\n" RESET);
    else
        printf(RED "Test 5 failed. Get %d\n" RESET, int_sqrt(50));

    if(int_sqrt(100) == 10)
        printf(GREEN "Test 6 passed\n" RESET);
    else
        printf(RED "Test 6 failed. Get %d\n" RESET, int_sqrt(100));

    if(int_sqrt(70) == 8)
        printf(GREEN "Test 7 passed\n" RESET);
    else
        printf(RED "Test 7 failed. Get %d\n" RESET, int_sqrt(100));

    if(int_sqrt(256) == 16)
        printf(GREEN "Test 8 passed\n" RESET);
    else
        printf(RED "Test 8 failed. Get %d\n" RESET, int_sqrt(100));
}