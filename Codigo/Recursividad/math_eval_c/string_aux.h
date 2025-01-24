#ifndef STRING_AUX_H_INCLUDED
#define STRING_AUX_H_INCLUDED

// Checks if a substring of `str` represents a valid number.
//
// Parameters: 
//      - `str`: the source string from which the substring will be verified.
//      - `start`: the beginning of the substring.
//      - `end`: the end of the substring.
// Returns:
//      - 1 if the substring of `str` represents a valid number.
//      - 0 otherwise.
int str_is_number(char* str, int start, int end);

// Copies a substring of `str` to `output`.
//
// Parameters: 
//      - `str`: the source string from which the substring will be copied.
//      - `start`: the beginning of the substring.
//      - `end`: the end of the substring.
// Returns:
//      - `output`: the string with the corresponding copy.
void copysubstr(char* str, int start, int end, char* output);

// Compares whether a substring of `str` is equal to `str2comp`.
// Parameters:
//      - `str`: the source string from which the substring will be compared.
//      - `start`: the beginning of the substring.
//      - `end`: the end of the substring.
//      - `str2comp` : the string to be compared with.
// Returns:
//      - 1 if the substring of `str` is equal to `str2comp`.
//      - 0 otherwise.
int comparesubstr(char* str, int start, int end, char* str2comp);

#endif