/*
Documentation :
Name : T.Simhadri
Date : 07/09/2025
Project name : APC Project
*/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

char actual_op; // '+', '-', '*', or '/' depending on type of operation
int sign_flag;
int main(int argc, char *argv[])
{
	/* Declaring the pointers */
	if (argc < 4)
	{
		printf("Usage: ./a.out <num1> operator <num2>\n");
		return 0;
	}

	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;
	int res = check_operation(argc, argv);
	if (!res)
	{
		printf("Usage: ./a.out <num1> operator <num2>\n");
		return FAILURE;
	}
	if (read_and_validate_args(argc, argv) == FAILURE)
	{
		// printf("Pass arguements like\n");
		printf("Usage: ./a.out <num1> operator <num2>\n");
		return FAILURE;
	}

	digit_to_list(&head1, &tail1, &head2, &tail2, argv);
	char operator = argv[2][0];

	switch (actual_op)
	{
		case '+':
			addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("%s + %s = ", argv[1], argv[3]);
			if (sign_flag == -1)
				printf("-");
			print_res(headR);
			break;

		case '-':
			{
				int res = compare_list(head1, head2);
				if (res == 1)
					subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				else if (res == -1)
				{
					subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
				}
				else
				{
					insert_first(&headR, &tailR, 0);
				}
				if(res == -1)
					printf("%s - %s = -", argv[1], argv[3]);
				else
					printf("%s - %s = ", argv[1], argv[3]);

				print_res(headR);
			}
			break;

		case 'x':
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("%s x %s = ", argv[1], argv[3]);
			if (sign_flag == -1)
				printf("-");
			print_res(headR);
			break;

		case '/':
			division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			printf("%s / %s = ", argv[1], argv[3]);
			if (sign_flag == -1)
				printf("-");
			print_res(headR);
			break;

		default:
			printf("Usage: ./a.out num1 operator(+|-|x|/) num2\n");
	}
	return 0;
}
