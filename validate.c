/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"

int read_and_validate_args(int argc, char *argv[])
{
    // validate num1 (argv[1])
    int start = 0;
    if (argv[1][0] == '+' || argv[1][0] == '-')
        start = 1;

    for (int i = start; argv[1][i]; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("num1 must contain only digits (0-9)\n");
            return FAILURE;
        }
    }

    // validate operator (argv[2][0])
    char op = argv[2][0];
    if (!(op == '+' || op == '-' || op == 'x' || op == '/') || argv[2][1] != '\0')
    {
        printf("Operator must be a single character: +, -, x, or /\n");
        return FAILURE;
    }

    // validate num2 (argv[3])
    start = 0;
    if (argv[3][0] == '+' || argv[3][0] == '-')
        start = 1;

    for (int i = start; argv[3][i]; i++)
    {
        if (!isdigit(argv[3][i]))
        {
            printf("num2 must contain only digits (0-9)\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}
