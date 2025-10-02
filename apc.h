#ifndef APC_H
#define APC_H

#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
} Dlist;

/* Include the prototypes here */

int read_and_validate_args(int argc, char *argv[]);
/*store the operands into the list */
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

/*Addition */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/*Division */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

int insert_last(Dlist **head, Dlist **tail, int data);

int insert_first(Dlist **head, Dlist **tail, int data);

void print_res(Dlist *headR);

int compare_list(Dlist *head1, Dlist *head2);

int delete_list(Dlist **head, Dlist **tail);

void remove_zeros(Dlist **head, Dlist **tail);

Dlist *createNode(int digit);

void add_one_to_list(Dlist **head, Dlist **tail);

int check_operation(int argc, char *argv[]);
#endif
