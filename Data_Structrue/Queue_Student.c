//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_QUEUE_SIZE 100
//#define TRUE 1
//#define FALSE 0
//
//typedef struct QueueObject {
//	int nNum;
//	char Name[100];
//} QueueObject;
//
//QueueObject queue[MAX_QUEUE_SIZE];
//int front, rear;
//// ť �ʱ�ȭ �Լ�
//void initialize(void)
//{
//	front = 0, rear = 0;
//}
//
//// ť�� ����������� üũ�ϴ� �Լ�
//int isEmpty(void)
//{
//	if (front == rear)
//		return TRUE;
//	else
//		return FALSE;
//	// return (front == rear);
//}
//
//// ť�� ��ȭ�������� üũ�ϴ� �Լ�
//int isFull(void)
//{
//	
//	if ((rear + 1) % MAX_QUEUE_SIZE == front)
//		return TRUE;
//	else
//		return FALSE;
//	// return ((rear + 1) % MAX_QUEUE_SIZE == front);
//}
//
//void addQ(QueueObject item)
//{
//	if (isFull())
//	{
//		printf("Ququq is Full\n");
//		return -1;
//	}
//
//	rear = (rear + 1) % MAX_QUEUE_SIZE;
//	queue[rear] = item;
//}
//
//QueueObject deleteQ(void)
//{
//	if (isEmpty())
//	{
//		printf("Queue is Empty\n");
//		exit(1);
//	}
//
//	front = (front + 1) % MAX_QUEUE_SIZE;
//	return queue[front];
//}
//
//
//int main(void)
//{
//	FILE* fp;
//	int nCount;
//	QueueObject temp;			// fscanf�� ������ �о�� �ϱ� ������ temp ����ü �ʿ�
//	fp = fopen("data.txt", "r");
//
//	if (fp == NULL)
//	{
//		printf("File Not Found\n");
//		return 0;
//	}
//	nCount = 0;
//	while (!feof(fp))
//	{
//		fscanf(fp, "%d %s", &temp.nNum, temp.Name);
//		addQ(temp);
//		nCount++;
//	}
//
//	printf("front=%d rear=%d\n", front, rear);
//
//	for (int i = 0; i < nCount; i++)
//	{
//		temp = deleteQ();
//		printf("%d | %s\n", temp.nNum, temp.Name);
//	}
//
//	printf("front=%d rear=%d\n", front, rear);
//
//	fclose(fp);
//	return 0;
//}