#include "queue.h"
#include <stdio.h>

node *create_node(int load)
{
	node *n = (node *)malloc(sizeof(node));
	n->load = load;
	n->link = NULL;
	return n;
}

queue *create_queue()
{
	queue *q = (queue *)malloc(sizeof(queue));
	q->rear = q->front = NULL;
	return q;
}

int isEmpty(queue *q)
{
	return (q->rear == NULL);
}

//find length of the queue
int qlen(queue *q)
{
	if (q->rear == NULL) return 0;
	else
	{
		int i = 0;
		node *temp = q->front;
		while (temp != q->rear)
		{
			temp = temp->link;
			i++;
		}
		return ++i;
	}
}

//adding a load to queue, enQueue
void add_load(queue* q, int load)
{
	node *temp = create_node(load);
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	} 
	else if (qlen(q) == 10) 
	{
		printf("\nQueue is full!! Please unload to continue...");
		return;
	}
	q->rear->link = temp;
	q->rear = temp;
}

//removing load from queue, deQueue
void remove_load(queue* q)
{ 
	if (isEmpty(q))
	{
		printf("\nQueue is already empty!!");
		return;
	}
	else if (q->front == q->rear && q->front != NULL)
	{
		q->front = q->rear = NULL;
		return;
	}

	node* temp = q->front;
	q->front = q->front->link;
	printf("\nQueue Deloaded!! \nLoad Deleted has weight: %d", temp->load);
	delete(temp);
	if (q->front == NULL)
	{
		q->rear = NULL; 
		printf("Empty");
	}
}

//finding the total load in a queue
int queue_load(queue *q)
{
	int sum = 0;
	if (q->rear == NULL) return sum;

	node *temp = q->front;
	if (q->front == q->rear) return temp->load;

	while (temp != NULL)
	{
		sum += temp->load;
		temp = temp->link;
	}
	return sum;
}

//function to calculate which queue the load should be added to
void load_balance(int load, queue *q_list[5], queue *queue_A)
{
	if (load > 0 && load <= 5)
	{
		if (isEmpty(queue_A))
		{
			add_load(queue_A, load);
		}
		else 
		{
			//check the queue_load of each queue in q_list and compare with queue_A. add_load to according queue.
			queue *q = q_list[0]; int n = 0;
			for (int i = 1; i <= 4; i++)
			{
				if (queue_load(q) > queue_load(q_list[i])) 
				{
					q = q_list[i]; n = i;
				}
			}printf("least Load: %d in queue number: %d", queue_load(q),n);
	
			if (queue_load(q) < queue_load(queue_A))
			{
				add_load(q, load); printf("x");
				printf("\nLoad of %d added to queue-%d", load,n);
			}
			else if (queue_load(q) >= queue_load(queue_A))
			{
				add_load(queue_A, load);
				printf("\nLoad of %d added to queue_A", load);
			}
		}
	}
	else if(load > 5)
	{
		queue *q = q_list[0]; int n = 0;
		for (int i = 1; i <= 4; i++)
		{
			if (queue_load(q) >= queue_load(q_list[i]))
			{
				q = q_list[i]; n = i;
			}
		}
		add_load(q, load);
		printf("\nLoad of %d added to queue-%d", load, n);
	}
	else printf("\nLoad negligible. Hence not added.");
}

void display(queue *q)
{
	if (q->rear == NULL)
	{
		printf("EMPTY QUEUE!!");
		return;
	}

	node *temp = q->front;
	while (temp != NULL)
	{
		printf("| %d |-", temp->load);
		temp = temp->link;
	}

}
