/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"
#include <stdio.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int carry = 0;
	Dlist *temp1 = *tail1, *temp2 = *tail2; // start from last digits

	while (temp1 != NULL || temp2 != NULL)
	{
		int d1 = 0, d2 = 0;

		if (temp1 != NULL)
			d1 = temp1->data; // get digit from number1

		if (temp2 != NULL)
			d2 = temp2->data; // get digit from number2

		int sum = d1 + d2 + carry; // add digits + carry
		int digit = sum % 10;	   // result digit
		carry = sum / 10;		   // update carry

		insert_first(headR, tailR, digit); // store result at front

		if (temp1 != NULL)
			temp1 = temp1->prev; // move left in number1
		if (temp2 != NULL)
			temp2 = temp2->prev; // move left in number2
	}

	// if carry remains, add it to result
	if (carry > 0)
	{
		insert_first(headR, tailR, carry);
	}
}
