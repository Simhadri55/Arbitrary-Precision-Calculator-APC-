/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int borrow = 0, d1, d2, sub;
	Dlist *temp1 = *tail1, *temp2 = *tail2;
	while (temp1 != NULL || temp2 != NULL)
	{

		d1 = 0, d2 = 0;
		if (temp1 != NULL)
			d1 = temp1->data;
		if (temp2 != NULL)
			d2 = temp2->data;
		// if borrow was taken
		if (borrow)
		{
			d1 = d1 - 1;
			borrow = 0;
		}
		// brrowing
		if (d1 < d2)
		{
			d1 = d1 + 10;
			borrow = 1;
		}

		sub = d1 - d2;
		// inserting into list
		insert_first(headR, tailR, sub);
		if (temp1 != NULL)
			temp1 = temp1->prev;
		if (temp2 != NULL)
			temp2 = temp2->prev;
	}

	remove_zeros(headR, tailR);
	return SUCCESS;
}
