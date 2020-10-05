#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct
{
	int nPriority;
} QueueObject;

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

void addQ(int item, int nltems)
{
	int j;
	if (isFull())
	{
		printf("queue is full\n");
	}
	if (nltems == 0)
		queue[nltems++].nPriority = item;
	else 
	{
		for (j = nltems - 1; j >= 0; j--)
		{
			if (item < queue[j].nPriority)
				queue[j + 1].nPriority = queue[j].nPriority;
			else
				break;
		}
		queue[j + 1].nPriority = item;
	}

	rear = (rear + 1) % MAX_QUEUE_SIZE;
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
	FILE* fp;
	int temp;
	QueueObject sttemp;
	int i, nCount;

	// TODO : 데이터 체크
	fp = fopen("data.txt", "r");
	nCount = 1;

	while (!feof(fp))
	{
		fscanf(fp, "%d", &temp);
		addQ(temp, nCount);
		nCount++;
	}

	for (i = 0; i < nCount - 1; i++) 
	{
		sttemp = deleteQ();
		printf("%d -> ", sttemp.nPriority);
	}
	printf("\n");

	return 0;
}