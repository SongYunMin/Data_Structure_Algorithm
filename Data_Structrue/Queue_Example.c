/*
DATA
56
45
3
46
57
12
74
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int QueueObject;
QueueObject queue[MAX_QUEUE_SIZE];
int front, rear;


// 큐 초기화 함수
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
		return -1;
	}

	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}


int main(void)
{
	FILE* fp;
	int temp;
	int nCount, i;

	fp = fopen("data.txt", "rt");
	if (fp == NULL)
	{
		printf("File Not Found\n");
		return 0;
	}

	// read the file and insert into the Queue
	nCount = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d",&temp);
		addQ(temp);
		nCount++;
	}

	printf("front = %d, rear = %d\n", front, rear);
	for (i = 0; i < nCount; i++)
	{
		printf("deleteQ() = %d\n", deleteQ());
	}
	printf("front %d rear %d\n",front,rear);

	fclose(fp);
	return 0;
}