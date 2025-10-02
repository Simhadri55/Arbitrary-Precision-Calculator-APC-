/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"
int delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL && *tail == NULL)
    {
        return FAILURE;
    }

    Dlist *temp = *head;

    while (*head)
    {
        temp = (*head)->next;
        free(*head);
        (*head) = temp;
    }

    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}

void remove_zeros(Dlist **head, Dlist **tail)
{
    if (head == NULL || tail == NULL)
        return;

    /* Nothing to do on empty list */
    if (*head == NULL)
    {
        *tail = NULL;
        return;
    }

    /* Remove zeros from the front (most significant digits) */
    while (*head && (*head)->data == 0 && (*head)->next != NULL)
    {
        Dlist *to_del = *head;
        *head = (*head)->next;
        /* detach and free old head */
        (*head)->prev = NULL;
        free(to_del);
    }

    if (*head == NULL)
    {
        *tail = NULL;
        return;
    }

    /* Ensure tail is correct (walk to end if tail is wrong) */
    if (*tail == NULL || (*tail)->next != NULL)
    {
        Dlist *t = *head;
        while (t->next)
            t = t->next;
        *tail = t;
    }
}