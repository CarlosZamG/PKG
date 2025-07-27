# include <stdio.h>

// Command to generate executable:
//       gcc strings_example_c_02.c -o example_02.out
// Command to run the program:
//      ./example_02.out

int main()
{
    char s1[] = "abcd";
    char *s2 = "abcd";

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    s1[0] = 'A';
    printf("s1: %s\n", s1);
    s2[0] = 'A';     //It's not going to work
    printf("s2: %s\n", s2);

    return 0;
}