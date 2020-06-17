//#include <stdio.h>
//#include <stdlib.h>
//
///*
//DATA
//����� 100.0 45.9 78.5
//������ 64.8 78.9 100
//������ 82.4 93.5 88.4
//�߽ż� 99.5 43.9 88.3
//����ȣ 100.0 99.9 78.5
//�̴�ȣ 88.9 99.9 78.9
//����ȣ 85.4 78.6 31.5
//������ 82.4 93.5 78.4
//*/
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