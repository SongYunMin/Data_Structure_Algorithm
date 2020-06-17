#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	int coef;				// ���
	int expon;				// ����
	struct ListNode* link;	// ��ũ
}ListNode;

typedef struct ListType {
	char name[10];			// ���׽��� �̸�
	int length;				// ���׽��� ����
	ListNode* head;			// List�� �պκ�
	ListNode* tail;			// List�� �޺κ�
}ListType;

// Node�� �ʱ�ȭ �ϴ� �Լ�
void nodeInitialization(ListType* plist)
{
	plist->length = 0;		// ���� �� List�� ��, �޺κ��� �ʱ�ȭ
	plist->head = NULL;
	plist->tail = NULL;
}

// ���� ��� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// List ���� �Լ�
void lastNodeInsertion(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));	// Memory Allocation
	if (temp == NULL) error("�޸� �Ҵ� ����");			// ���� ó��
	// �Ҵ���� �޸𸮰����� ���ڷ� ���� ��� �� ���� ����
	temp->coef = coef;
	temp->expon = expon;
	// ������ ���� NULL�� �ʱ�ȭ
	temp->link = NULL;
	// tail�� NULL�̶�� ù Node�̱� ������ Head, Tail��� temp�� ����Ű�� ��
	if (plist->tail == NULL) {
		plist->head = temp;
		plist->tail = temp;
	}
	// Node�� �����ÿ� list�� tail�� link�� temp�� ����Ű�� �ϰ�, 
	// tail ��ü�� temp�� ����Ű�� ��
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;				// ���̸� ���� ��Ŵ
}

// ���׽��� ������ ū ������� ���� ��
void polynomiaSort(ListNode* list1)
{
	int i, j, temp;
	ListNode* p, * q, * tmp;

	int cnt = 1;
	p = list1;
	while (p->link != NULL)
	{
		tmp = p;
		q = p->link;
		// ������ ū�� �Ǻ� ��
		while (q != NULL)
		{
			if (q->expon > tmp->expon)
				tmp = q;
			q = q->link;
		}
		// ���� �� ��� �ڸ� ����
		if (tmp != NULL)
		{
			temp = p->expon;
			p->expon = tmp->expon;
			tmp->expon = temp;
			temp = p->coef;
			p->coef = tmp->coef;
			tmp->coef = temp;
		}
		p = p->link;
	}
}

// ���׽� ���� �Լ�
void polynomialMultiplication(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* list1 = plist1->head;
	ListNode* list2 = plist2->head;
	ListNode* p = plist3->head;
	int loopState;												// �ݺ����� ���¸� ��Ÿ��
	while (list1 != NULL) {
		list2 = plist2->head;
		while (list2 != NULL) {
			p = plist3->head;
			loopState = 0;
			while (p != NULL) {

				if (list1->expon + list2->expon == p->expon) {
					p->coef = list1->coef * list2->coef + p->coef;
					loopState++;
					break;
				}
				p = p->link;
			}
			if (loopState == 1) {
				list2 = list2->link;
			}
			else {
				// ����� ���ϰ�, ������ ������ ���� Insert ����
				lastNodeInsertion(plist3, list1->coef * list2->coef, 
					list1->expon + list2->expon);
				list2 = list2->link;		// List2�� ���� �� �̵�
			}
		}
		list1 = list1->link;				// List1�� ���� �� �̵�
	}
	polynomiaSort(plist3->head);
}

// �޸� �Ҵ� ���� �Լ�
void memoryUnallocation(ListType* header)
{
	ListNode* p;
	// ���� �����͸� �����ؾ� �ϱ� ������ ���� ������ ���
	ListNode** head = &header->head;
	while (*head)
	{
		p = *head;
		*head = (*head)->link;
		free(p);
	}
}

// ���׽��� ����ϴ� �Լ�
void polynomialPrint(ListType* plist)
{
	ListNode* p = plist->head;
	printf("%s : %dx^%d", plist->name, p->coef, p->expon);
	p = p->link;
	for (; p; p = p->link) {
		if (p->coef < 0)					// ������ ��� ���
			printf(" | %dx^%d |", p->coef, p->expon);
		else if (p->coef == 1)				// 1�̶�� x�� ���
			printf(" | +x^%d |", p->expon);
		else								// ����� ��� ���
			printf(" | +%dx^%d |", p->coef, p->expon);
	}
	printf("\n");
}

int main(void) {
	int coef, expon;
	char buf;
	ListType list1, list2, list3;
	FILE* fp;

	//���׽� �ʱ�ȭ
	nodeInitialization(&list1);
	nodeInitialization(&list2);
	nodeInitialization(&list3);

	// list3�� �̸��� ����
	strcpy(list3.name, "poly3");
	// File Open
	fp = fopen("data.txt", "r");
	if (fp == NULL)					// ����ó��
	{
		printf("������ ���� ���α׷��� �����մϴ�.\n");
		return 0;
	}

	fscanf(fp, "%s", list1.name);
	while (1)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		fscanf(fp, "%c", &buf);
		lastNodeInsertion(&list1, coef, expon);
		if (buf == '\n')		// ���๮�ڷ� �ݺ����� ������
			break;
	}
	fscanf(fp, "%s", list2.name);
	while (1)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		fscanf(fp, "%c", &buf);
		lastNodeInsertion(&list2, coef, expon);
		if (feof(fp))			// ������ ���� �Ǵ��ؼ� �ݺ����� ������
			break;
	}//������ ������ �ݺ��� ����
	printf("------------------------\n");
	printf("���Ͽ��� �Է¹��� ���׽�\n");
	printf("------------------------\n\n");
	polynomialPrint(&list1);					// ���� ���׽� ���
	polynomialPrint(&list2);
	printf("\n");

	// ���׽� ���� �Լ� ����
	polynomialMultiplication(&list1, &list2, &list3);

	printf("--------------------------\n");
	printf("���׽� ���� ���� �� ���׽�\n");
	printf("--------------------------\n\n");
	polynomialPrint(&list3);					// ��� ���׽� ���
	printf("\n");

	memoryUnallocation(&list1);
	memoryUnallocation(&list2);
	memoryUnallocation(&list3);
	fclose(fp);
	return 0;
}