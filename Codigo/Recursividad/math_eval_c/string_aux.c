#include "string_aux.h"

int str_is_number(char* str, int start, int end)
{
    int already_dot = 0;

    for (int i = start; i <= end; i++)
    {
        if (str[i] == '-' )
        {
            // If the substring contains a `-` sign outside of the beginning,
            //it is not a valid number
            if (i != start)
            {
                return 0;
            }
        }
        else if (str[i] == '.')
        {
            // If the substring contains more than one dot, it is not a valid number.
            if (already_dot)
            {
                return 0;
            }
            already_dot = 1;
        }
        else if(str[i] < '0' || str[i] > '9') 
        {
            // The only valid characters are `-`, `.` and numeric digits
            return 0;
        }
    }
    return 1;
}

void copysubstr(char* str, int start, int end, char* output)
{
    // Variable that will be an adjusted index
    int j = 0;

    for (int i = start; i <= end; i++)
    {
        // The index is adjusted to copy correctly to `output`
        j = i - start;
        output[j] = str[i];
    }
}

int comparesubstr(char* str, int start, int end, char* str2comp)
{
    // Variable that will be an adjusted index
    int j = 0;

    for (int i = start; i <= end; i++)
    {
        // The index is adjusted to compare correctly with `str2comp`
        j = i - start;
        if(str[i] != str2comp[j])
            return 0;
    }

    return 1;
}