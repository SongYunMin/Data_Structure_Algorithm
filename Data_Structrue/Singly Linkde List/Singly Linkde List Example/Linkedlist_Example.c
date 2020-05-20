//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct element {
//	char name[20];
//	double kor;
//	double math;
//	double com;
//	double total;
//} element;
//
//typedef struct ListNode {
//	element data;
//	struct ListNote* link;
//} ListNode;
//
//ListNode *create_node(element data)
//{
//	// malloc(sizeof(element))
//	// malloc(sizeof(ListNode))
//	ListNode* new_node;	// �޸𸮸� �Ҵ���� ���� ������
//	// void *malloc(int size);
//	// �ش� Ÿ������ �� ĳ���� �ؾ� ��
//	new_node = (ListNode *)malloc(sizeof(ListNode));
//	if (new_node == NULL)
//	{
//		printf("Memory Allocation Fail\n");
//		exit(1);
//	}
//	new_node->data = data;
//	new_node->link = NULL;
//
//	return new_node;
//}
//
//void insert_node(ListNode** phead, ListNode* new_node)
//{
//	// 1. ȫ�浿
//	// 2. ��û��
//	if (*phead == NULL)	// �����Ͱ� ���ٸ�
//	{
//		// ȫ�浿
//		new_node->link = NULL;
//		*phead = new_node;
//	}
//	else // �����Ͱ� �ִٸ�
//	{
//		// ��û�� -> ��ũ = ȫ�浿
//		// ������ = ��û��
//		new_node->link = *phead;
//		*phead = new_node;
//	}
//}
//
//void display(ListNode* head)
//{
//	// local ����
//	ListNode* p = head;
//
//	while (p != NULL)
//	{
//		printf("%s %lf %lf %lf %lf\n",
//			p->data.name, p->data.kor, p->data.math,
//			p->data.com, p->data.total);
//		p = p->link; // ���� ���� �̵�
//	}
//	printf("\n");
//}
//
//int main(void)
//{
//	FILE* fp = NULL;		// ���������� ����
//	element temp;			// Data ����ü ����
//	ListNode* new_node;		// ���ο� node�� ������ ����ü
//	ListNode* list = NULL;		// ���Ḯ��Ʈ�� ���۳�� ������
//
//	// ���� ����
//	fp = fopen("data.txt", "r");
//	if (fp == NULL)		// ���� ó��
//	{
//		printf("File Not Found\n");
//		return 0;
//	}
//
//	// 
//	while (!feof(fp))
//	{
//		fscanf(fp, "%s %lf %lf %lf",
//			temp.name, &temp.kor, &temp.math, &temp.com);
//		temp.total = temp.kor + temp.math + temp.com;
//
//		insert_node(&list, create_node(temp));
//	}
//
//	// ����Լ�
//	display(list);
//
//	// ���������� close
//	fclose(fp);
//
//	return 0;
//}