/*
DATA
����� 100.0 45.9 78.5 23.6
������ 64.8 78.9 100 75.4
������ 82.4 93.5 88.4 63.5
����� 3.3 4.4 5.5 6.6
������ 1.1 2.2 3.3 4.4
�ڰ��� 3.3 4.4 5.5 6.6
*/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// �л� ���� ����ü
//typedef struct Student {
//	int num;
//	char name[30];
//	double lan;
//	double math;
//	double eng;
//	double com;
//} Student;
//
//// ��带 ����ų ����ü
//typedef struct ListNode {
//	Student data;
//	struct ListNode* link;		// ���� ��带 ����Ŵ
//	struct ListNode* back;		// ���� ��带 ����Ŵ
//} ListNode;
//
//int count;
//
//// �л� �˻� �Լ�
//void Search_Stduent(ListNode* head)
//{
//	int num;
//	ListNode* p = head;
//	printf("�˻��� ��ȣ�� �Է� �ϼ��� : "); scanf("%d", &num);
//
//	while (p != NULL) {
//		if(p->data.num == num) {
//			printf("\n��ȣ\t�̸�\t���\t����\t����\t��ǻ��\n");
//			printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n\n", p->data.num, p->data.name, p->data.lan,
//				p->data.math,p->data.eng,p->data.com);
//			return;
//		}
//		p = p->link;
//	}
//
//	return NULL;
//}
//
//// �л� ��� �Լ�
//void Print_Student(ListNode* head)
//{
//	// Local ����
//	ListNode* p = head;
//
//	// ��� ��� �����
//	while (p != NULL)
//	{
//		printf("��ȣ\t�̸�\t���\t����\t����\t��ǻ��\n");
//		printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",
//			p->data.num,p->data.name, p->data.lan, p->data.math, p->data.eng,
//			p->data.com);
//		p = p->link;	// ���� ���� �̵�
//	}
//	printf("\n");
//
//}
//
//// ��� ���� �Լ�
//ListNode* create_node(Student data)
//{
//	ListNode* new_node;		// �޸𸮸� �Ҵ���� ���� ������
//	new_node = (ListNode*)malloc(sizeof(ListNode));
//	// ���� ó��
//	if (new_node == NULL)
//	{
//		printf("Memory Allocation Fail\n");
//		exit(1);
//	}
//	new_node->data = data;		// ���ο� ��忡 �����͸� �����ϰ�
//	new_node->link = NULL;		// ���Ե� ���� ���� ��带 ����Ų��
//
//	return new_node;
//}
//
//void insert_node(ListNode** phead, ListNode** tail, ListNode* new_node)
//{
//	// �����Ͱ� ���ٸ�
//	if (*phead == NULL) {
//		new_node->link = NULL;
//		*phead = new_node;
//		*tail = new_node;
//	}
//	// �����Ͱ� �ִٸ�
//	else {
//		//new_node->link = *phead;
//		//*phead = new_node;
//		(*tail)->link = new_node;
//		(*tail) = new_node;
//	}
//}
//
//int main(void)
//{
//	int choice = 1;
//	// File Open
//	FILE* fp = NULL;				// ���� ������ ����
//	Student temp;					// Data����ü ����
//	ListNode* list = NULL;			// ���Ḯ��Ʈ�� ���� ��� ������
//	ListNode* tail = NULL;			// �� �� ������ ���� tail
//	temp.num = 0;
//	// File Open �� ���� ó��
//	fp = fopen("data.txt", "rt");
//	if (fp == NULL)
//	{
//		printf("File Not Found\n");
//		return -1;
//	}
//
//	// �켱 �����͸� ���� �о���δ�.
//	while (!feof(fp))
//	{
//		temp.num++;
//		fscanf(fp, "%s %lf %lf %lf %lf",
//			temp.name, &temp.lan, &temp.math, &temp.eng, &temp.com);
//		insert_node(&list, &tail,create_node(temp));
//	}
//	
//	// �޴� �Է� �ݺ���
//	while (choice != 0) {
//		printf("0:���� 1:�л� �������Է� 2:�л� �˻� 3:��� ����\n");
//		scanf("%d", &choice); 
//		if (choice == 0)
//		{
//			printf("���α׷��� �����մϴ�\n");
//			exit(0);
//		}
//		// �л� ������ �Է� �޴�
//		else if (choice == 1)
//		{
//			// ���� ���� ����
//			fp = fopen("data.txt", "at");
//			// ���� ó��
//			if (fp == NULL)
//			{
//				printf("File Not Found\n");
//				return -1;
//			}
//			printf("�̸� �Է� : "); scanf("%s", temp.name);
//			// �̸� ������ 4����
//			if (strlen(temp.name) > 4) {
//				printf("�̸��� 4���ڰ� �ִ��Դϴ�. �ٽ��Է����ֽʽÿ�.\n");
//				printf("�̸� �Է� : "); scanf("%s", temp.name);
//			}
//			
//			printf("��� ���� : "); scanf("%lf", &temp.lan);
//			printf("���� ���� : "); scanf("%lf", &temp.math);
//			printf("���� ���� : "); scanf("%lf", &temp.eng);
//			printf("��ǻ�� ���� : "); scanf("%lf", &temp.com);
//			// ���� �Է�
//			fprintf(fp, "\n%s %.1lf %.1lf %.1lf %.1lf", temp.name, temp.lan,
//				temp.math, temp.eng, temp.com);
//			fclose(fp);
//			temp.num++;
//			insert_node(&list,&tail, create_node(temp));
//		}
//		// �л� �˻� �޴�
//		else if (choice == 2)
//		{
//			Search_Stduent(list);
//		}
//		// �л� ��� ��� �޴�
//		else if (choice == 3)
//		{
//			Print_Student(list);
//		}
//	}
//	// ���� close
//	fclose(fp);
//	// Memory �Ҵ� ����
//	free(list);
//	free(tail);
//	return 0;
//}