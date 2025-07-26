# include <stdio.h>

// Command to generate executable:
//       gcc strings_example_c_01.c -o example_01.out
// Command to run the program:
//      ./example_01.out

int main()
{
    char string[5] = "Abcd";
    char not_string[4] = "Abcd";

    printf("string: %s\n", string);
    printf("not_string: %s\n", not_string);

    return 0;
}