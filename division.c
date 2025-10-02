/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	// Check division by zero
	if (*head2 == NULL || ((*head2)->data == 0 && (*head2)->next == NULL))
	{
		printf("Error: Division by zero\n");
		return FAILURE;
	}

	// If divisor is 1, result is the dividend
	if (((*head2)->data == 1) && ((*head2)->next == NULL))
	{
		Dlist *temp = *head1;
		while (temp)
		{
			insert_last(headR, tailR, temp->data);
			temp = temp->next;
		}
		return SUCCESS;
	}

	// If dividend < divisor, quotient = 0
	if (compare_list(*head1, *head2) < 0)
	{
		insert_last(headR, tailR, 0);
		return SUCCESS;
	}

	// Initialize quotient as 0
	insert_last(headR, tailR, 0);

	Dlist *tempHead = NULL, *tempTail = NULL; // Temporary list for subtraction

	// Keep subtracting divisor from dividend
	while (*head1 && compare_list(*head1, *head2) >= 0)
	{
		subtraction(head1, tail1, head2, tail2, &tempHead, &tempTail);

		delete_list(head1, tail1);

		if (tempHead == NULL) // nothing left after subtraction
		{
			*head1 = NULL;
			*tail1 = NULL;
			break;
		}

		*head1 = tempHead;
		*tail1 = tempTail;
		tempHead = tempTail = NULL;

		add_one_to_list(headR, tailR); // Increment quotient
	}

	return SUCCESS;
}

void add_one_to_list(Dlist **head, Dlist **tail)
{
	Dlist *temp = *tail; // start from last digit
	int carry = 1;		 // we are adding 1

	// Add carry to digits from LSB to MSB
	while (temp && carry)
	{
		int sum = temp->data + carry;
		temp->data = sum % 10; // update digit
		carry = sum / 10;	   // update carry
		temp = temp->prev;	   // move to previous digit
	}

	// If carry remains, add new node at front
	if (carry)
	{
		Dlist *newNode = createNode(carry);
		newNode->next = *head;
		(*head)->prev = newNode;
		*head = newNode;
	}
}

Dlist *createNode(int digit)
{
	Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));
	if (!newNode)
	{
		printf("Memory allocation failed\n");
		exit(FAILURE);
	}
	newNode->data = digit;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}
