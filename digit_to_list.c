/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"

void digit_to_list(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   char *argv[])
{
    int i = 0, j = 0;

    // Convert argv[1] string to digits list
    if (argv[1][0] == '+' || argv[1][0] == '-')
        i = 1;

    while (argv[1][i])
    {
        char ch = argv[1][i];

        int digit = ch - '0';
        insert_last(head1, tail1, digit);

        i++;
    }
    remove_zeros(head1, tail1);
    // Convert argv[3] string to digits list
    if (argv[3][0] == '+' || argv[3][0] == '-')
        j = 1;
    while (argv[3][j])
    {

        char ch = argv[3][j];

        int digit = ch - '0';
        insert_last(head2, tail2, digit);

        j++;
    }
    remove_zeros(head2, tail2);
}
