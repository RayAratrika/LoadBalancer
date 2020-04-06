#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("-- WELCOME TO LOAD BALANCING -- \n1.Add load to queue.\n2.Remove load from queue.\n");
	int l, opt, n;
	printf("Enter your option: "); scanf_s("%d", &opt);

	queue *queue_A = create_queue();
	queue *q_list[5]; 
	for (int i = 0; i < 5; i++)
	{
		q_list[i] = create_queue();
	}
	while (opt != -1)
	{
		switch (opt)
		{
		case 1: printf("\nEnter Load value: "); scanf_s("%d", &l);
			load_balance(l, q_list, queue_A);
			for (int i = 0; i < 5; i++)
			{
				printf("\nQueue number-%d ",i);  display(q_list[i]);
			}printf("\nqueue_A "); 
			display(queue_A);
			break;

		case 2: printf("\nEnter queue number to Remove load from(Enter 6 for queue_A): "); scanf_s("%d", &n);
			if (n == 6) remove_load(queue_A);
			else remove_load(q_list[n]);
			for (int i = 0; i < 5; i++)
			{
				printf("\nqueue number-%d ", i);  display(q_list[i]);
			}printf("\nqueue_A ");
			display(queue_A);
			break;

		default: printf("\nInvalid Option!");
			break;
		}
		printf("\nEnter your option(-1 to Exit): "); scanf_s("%d", &opt);
	}
}