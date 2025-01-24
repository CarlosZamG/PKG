#ifndef MATH_EVAL_H_INCLUDED
#define MATH_EVAL_H_INCLUDED

#include <math.h>

// Defines the total number of mathematical functions that can be evaluated
// by the `eval()`. This value should be updated if compatible mathematical
// functions are added or removed
#define NUM_FUNC 7

// Enumeration defining valid types of mathematical expressions:
enum EXPRESSION 
{
    SIN,        // 0    Represents the sin(expr) expression.
    COS,        // 1    Represents the cos(expr) expression.
    TAN,        // 2    Represents the tan(expr) expression.
    LOG_TEN,    // 3    Represents the log10(expr) expression.
    LOG_TWO,    // 4    Represents the log2(expr) expression.
    LOG,        // 5    Represents the log(expr) expression.
    SQRT,       // 6    Represents the sqrt(expr) expression.
    PARENTHESIS,// 7    Represents the (expr) expression.
    NUMBER,     // 8    Represents a numeric constant, such as 12, -12 or 1.2 .
    COMPOUND    // 9    Represents a expression that combine multiple subexpressions
                //      or elements using operators.
};

// Array of strings containing the names of supported mathematical functions that can be
// evaluated by eval().
// This array must match the with func[]. It is crucial that both arrays are kept
// in sync, as the names are used to identify and associate the functions to be evaluated.
char *strfunc[NUM_FUNC] = {"sin", "cos", "tan", "log10", "log2", "log", "sqrt"};

// Array of function pointers containing the implementatios of supported mathematical 
// functions that can be evaluated by eval().
// This array must match the with strfunc[]. It is crucial that both arrays are kept
// in sync, as the names are used to identify and associate the functions to be evaluated.
double (*func[NUM_FUNC]) (double) = {sin, cos, tan, log10, log2, log, sqrt};

// Evaluates the mathematical expression contained in a substring.
// Parameters: 
//      - `str`: the string from which the substring to be evaluated will be extracted.
//      - `start`: the beginning of the substring.
//      - `end`: the end of the substring.
// Returns:
//      - The result of evaluating the mathematical expression contained in the substring.
double eval(char* str, int start, int end);

// Examines a substring representing a mathematical expression and classifies its type.
// Parameters: 
//      - `str`: the string containing the substring to classify.
//      - `start`: the beginning of the substring.
//      - `end`: the end of the substring.
// Returns:
//      - `ret_start`: the index that marks the starting point from which the expression will continue to be evaluated.
//      - `ret_end`: the index that marks the end of the substring that will continue to be evaluated.
//      - The type of the mathematical expression.
enum EXPRESSION scan_expr(char* str, int start, int end, int *ret_start, int *ret_end);

// Evaluates the compound mathematical expression contained in a substring.
// Parameters: 
//      - `str`: the string from which the substring to be evaluated will be extracted.
//      - `start`: the beginning of the substring.
//      - `end`: the end of the substring.
double decompose(char* str, int start, int end);

#endif
