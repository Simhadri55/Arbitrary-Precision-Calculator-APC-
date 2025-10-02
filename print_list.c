/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"

void print_res(Dlist *headR)
{
    if (headR == NULL)
    {
        return;
    }

    while (headR != NULL)
    {
        printf("%d", headR->data);
        headR = headR->next;
    }
    printf("\n");
}