/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"

int compare_list(Dlist *head1, Dlist *head2)
{
    int list1_len = 0, list2_len = 0;
    Dlist *temp1 = head1, *temp2 = head2;

    // count lengths
    while (temp1)
    {
        list1_len++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        list2_len++;
        temp2 = temp2->next;
    }

    // compare lengths first
    if (list1_len > list2_len)
        return 1;
    else if (list1_len < list2_len)
        return -1;

    // lengths equal -> compare digit by digit
    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return 1;
        else if (head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0; // numbers are equal
}