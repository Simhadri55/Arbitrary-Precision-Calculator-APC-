/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"
int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    // If list is empty
    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    //  insert at fast
    new->next = *head;
    (*head)->prev = new;
    *head = new;

    return SUCCESS;
}

