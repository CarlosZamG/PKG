#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "math_eval.h"
#include "string_aux.h"

// Command to generate the executable:
//      gcc string_aux.c math_eval.c -o math_eval.out -lm

// Command to run the program:
//      ./math_eval.out
int main(int argc, char *argv[])
{
    char* input = "sin(5*(6.14159-3)/2)";
    int s = 0;
    int e = strlen(input) - 1;
    
    double r = eval(input, s, e);

    printf("%s = %lf \n", input, r);
    return EXIT_SUCCESS;
}


double eval(char* str, int start, int end)
{   
    for (int i = start; i <= end; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    
    int new_start, new_end;

    // We scan the expression and act depending on its type.
    enum EXPRESSION case_expression = scan_expr(str, start, end, &new_start, &new_end);

    //In the case of a function, we evaluate the substring corresponding to its argument.
    if (case_expression < NUM_FUNC)
    {
        double arg = eval(str, new_start, new_end);
        return func[case_expression](arg);
    }
    else
    {
        switch (case_expression)
        {
        //In the case of parentheses, we evaluate the substring inside them.
        case PARENTHESIS:
            return eval(str, new_start, new_end);
            break;
        //In the case of a number, we convert the substring to `double`.
        case NUMBER:
        {
            char* arg =  malloc(sizeof(char) * (new_end - new_start));  
            copysubstr(str, new_start, new_end, arg);
            double ret = atof(arg);
            free(arg);
            return ret;
        }
        // In the case of a composite expression, we use the `decompose()` function.
        case COMPOUND:
            return decompose(str, new_start, new_end);
        default:
            return -1;
            break;
        }
    }
    
}

enum EXPRESSION scan_expr(char* str, int start, int end, int *ret_start, int *ret_end){
    
    if(str_is_number(str, start, end))
    {
        *ret_start = start;
        *ret_end = end;
        return NUMBER;
    }
    // If the substring is not a number and does not end with a parenthesis, 
    // we can say it is a composite expression
    else if (str[end] != ')')
    {
        *ret_start = start;
        *ret_end = end;
        return COMPOUND;
    }
    else
    {
        int count_parenthesis = 0;
        int closer_ind;
        int starter_ind;
        
        // We look for the first parenthesis and the parenthesis that closes it.
        for ( closer_ind = start; closer_ind <= end; closer_ind++)
        {
            if (str[closer_ind] == '(')
            {
                if (count_parenthesis == 0)
                {
                    starter_ind = closer_ind;
                }
                count_parenthesis++;        
            }
            else if (str[closer_ind] == ')')
            {
                count_parenthesis--;
                if (count_parenthesis == 0)
                {
                    break;
                }
            }
        }
        // If the parenthesis that closes the first parenthesis is not the last character,
        // we can say it is a composite expression.
        if (closer_ind != end)
        {
            *ret_start = start;
            *ret_end = end;
            return COMPOUND;
        }
        // We compare the beginning of the string to see if the expression corresponds to a function.
        for (int i = 0; i < NUM_FUNC; i++)
        {
            if (comparesubstr(str, start, start + strlen(strfunc[i]) - 1, strfunc[i]))
            {
                *ret_start = starter_ind + 1;
                *ret_end = closer_ind - 1;
                return i;
            }
        }

        if (starter_ind == start)
        {
            *ret_start = start + 1;
            *ret_end = end - 1;
            return PARENTHESIS;
        }
        
        *ret_start = start;
        *ret_end = end;
        return COMPOUND;
        
    }
    *ret_start = -1;
    *ret_end = -1;
    return COMPOUND;
}


double decompose(char* str, int start, int end)
{
    int last_op_level = 3;
    int last_op_ind = end;
    int op_level;
    int count_parenthesis = 0;

    // We look for the index of the lowest-priority operator.
    for (int i = end; i >= start; i--)
    {
        if(str[i] == ')')
        {
            count_parenthesis++;
        }
        else if (str[i] == '(')
        {
            count_parenthesis--;
        }
        
        if(count_parenthesis > 0)
        {
            continue;
        }
        else if(count_parenthesis < 0)
        {    
            printf("Algo salió mal");
        }
        else
        {
            switch (str[i])
            {
                case '^':
                    op_level = 2;
                    break;
                case '*':
                case '/':
                case '%':
                    op_level = 1;
                    break;
                case '+':
                case '-':
                    op_level = 0;
                    break;
                default:
                    op_level = last_op_level;
                    break;
            }

            if (op_level < last_op_level)
            {
                last_op_ind = i;
                last_op_level = op_level;
            }
        }
    }

    double result1, result2;
    result2 = eval(str, last_op_ind + 1, end);
    result1 = eval(str, start, last_op_ind-1);
    // We perform the corresponding operation based on the operator.
    switch (str[last_op_ind])
    {
        case '^':
            return pow(result1, result2);
            break;
        case '*':
            return result1*result2;
            break;
        case '/':
            return result1 / result2;
            break;
        case '%':
            return (int) result1 % (int) result2;
            break;
        case '+':
            return result1 + result2;
            break;
        case '-':
            return result1 - result2;
            break;
        default:
            printf("Algo salió mal");
            break;
    }
}