/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"

extern char actual_op;
extern int sign_flag;

int check_operation(int argc, char *argv[])
{
    if (argc != 4)
        return 0; // must have 3 args

    char first1 = argv[1][0]; // first character of num 1
    char first2 = argv[3][0]; // first character of num 2
    char op = argv[2][0];     // operator

    sign_flag = 1;

    switch (op)
    {
    case '+':
        if ((first1 == '+' || isdigit(first1)) && (first2 == '+' || isdigit(first2)))
        {
            actual_op = '+';
            sign_flag = 1;
        }
        else if (first1 == '-' && first2 == '-')
        {
            actual_op = '+';
            sign_flag = -1;
        }
        else if ((first1 == '+' || isdigit(first1)) && first2 == '-')
        {
            actual_op = '-';
            sign_flag = 1; // will subtract second from first
        }
        else if (first1 == '-' && (first2 == '+' || isdigit(first2)))
        {
            actual_op = '-';
            sign_flag = -1; // subtract second from first
        }
        else
            return 0;
        break;

    case '-':
        if ((first1 == '+' || isdigit(first1)) && (first2 == '+' || isdigit(first2)))
        {
            actual_op = '-';
            sign_flag = 1;
        }
        else if (first1 == '-' && first2 == '-')
        {
            actual_op = '-';
            sign_flag = 1; // -a - (-b) = -a + b → subtraction
        }
        else if ((first1 == '+' || isdigit(first1)) && first2 == '-')
        {
            actual_op = '+';
            sign_flag = 1; // a - (-b) = a + b
        }
        else if (first1 == '-' && (first2 == '+' || isdigit(first2)))
        {
            actual_op = '+';
            sign_flag = -1; // -a - b = -(a + b)
        }
        else
            return 0;
        break;

    case 'x':
    case '/':
        actual_op = op;
        // Determine result sign
        if ((first1 == '-' && (first2 == '+' || isdigit(first2))) ||
            ((first1 == '+' || isdigit(first1)) && first2 == '-'))
        {
            sign_flag = -1;
        }
        else
        {
            sign_flag = 1;
        }
        break;

    default:
        return 0; // unsupported operator
    }

    return 1; // valid operation
}
