#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
#define TRUE 1
#define FALSE 0
typedef int element;
typedef struct {
	int id;
	int arrival_time;
	int service_time;
}QueueObject;
QueueObject queue[MAX_QUEUE_SIZE];

int front, rear;
void initialize(void)
{
	front = 0, rear = 0;
}

// 큐가 공백상태인지 체크하는 함수
int isEmpty(void)
{
	if (front == rear)
		return TRUE;
	else
		return FALSE;
	// return (front == rear);
}

// 큐가 포화상태인지 체크하는 함수
int isFull(void)
{
	
	if ((rear + 1) % MAX_QUEUE_SIZE == front)
		return TRUE;
	else
		return FALSE;
	// return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

void addQ(QueueObject item)
{
	if (isFull())
	{
		printf("Ququq is Full\n");
		return -1;
	}

	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

QueueObject deleteQ(void)
{
	if (isEmpty())
	{
		printf("Queue is Empty\n");
		exit(1);
	}

	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

int main(void)
{
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int sevice_time = 0;
	int service_customer;
	QueueObject queue;
	initialize(&queue);

	srand(time(NULL));
	return 0;
}