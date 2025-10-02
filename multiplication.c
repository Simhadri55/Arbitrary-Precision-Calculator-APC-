/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"
#include <stdio.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;

	Dlist *headR1 = NULL, *tailR1 = NULL,					  // to hold final result
							  *headR2 = NULL, *tailR2 = NULL; // to hold partial product

	int carry = 0, d1, d2, mul, count = 0, i;

	// go through each digit of number2
	while (temp2)
	{
		d2 = temp2->data;
		carry = 0;

		headR2 = tailR2 = NULL;

		// add zeros at the end based on position
		for (i = 0; i < count; i++)
		{
			insert_first(&headR2, &tailR2, 0);
		}

		// multiply current digit of number2 with all digits of number1
		temp1 = *tail1;
		while (temp1)
		{
			d1 = temp1->data;
			mul = d1 * d2 + carry;
			carry = mul / 10;

			insert_first(&headR2, &tailR2, mul % 10); // store digit
			temp1 = temp1->prev;
		}

		// add leftover carry if any
		if (carry > 0)
		{
			insert_first(&headR2, &tailR2, carry);
		}

		if (count == 0)
		{
			// first partial product becomes initial result
			headR1 = headR2;
			tailR1 = tailR2;
		}
		else
		{
			// add partial product to result
			addition(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);

			// free old lists
			delete_list(&headR1, &tailR1);
			delete_list(&headR2, &tailR2);

			// update result with new sum
			headR1 = *headR;
			tailR1 = *tailR;

			*headR = NULL;
			*tailR = NULL;
		}

		count++;
		temp2 = temp2->prev; // move to next digit of number2
	}

	// store final result
	*headR = headR1;
	*tailR = tailR1;

	return SUCCESS;
}
