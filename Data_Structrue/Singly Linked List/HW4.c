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
ListType* nodeInitialization(void)
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->length = 0;		// ���� �ʱ�ȭ
	plist->head = NULL;		// List�� Head �ʱ�ȭ
	plist->tail = NULL;		// List�� Tail �ʱ�ȭ

	return plist;			// List Return
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
void polynomiaSort(ListNode* list)
{
	int i, j, temp;					// ���� ���� �� Node ����
	ListNode* p, * tmp, * tmp_2;
	p = list;						// ���ڷ� ���� list ����
	while (p->link != NULL)	{		// list�� ������
		tmp = p;					// ����� p Node�� tmp Node�� ����
		tmp_2 = p->link;				// p�� �������� tmp_2 Node�� ����
		while (tmp_2 != NULL) {			// tmp_2 Node�� data�� ���� �� ���� �ݺ�
			// list�� 1��° ��(tmp)���� 2��° ��(tmp_2)�� ũ�ٸ�
			if (tmp_2->expon > tmp->expon)		
				tmp = tmp_2;				// 1��° ������ 2��°�� ����
			tmp_2 = tmp_2->link;				// tmp_2 �� �������� ����Ŵ
		}
		// ���� �� ��� �ڸ� ����
		if (tmp != NULL){
			temp = p->expon;			// ���� ����
			p->expon = tmp->expon;
			tmp->expon = temp;
			temp = p->coef;				// ��� ����
			p->coef = tmp->coef;
			tmp->coef = temp;
		}
		p = p->link;
		// �� ������ p�� �������� ��� ����Ű�� �ϸ鼭 ���� ��
	}
}

// ���׽� ���� �Լ�
void polynomialMultiplication(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* list1 = plist1->head;
	ListNode* list2 = plist2->head;
	ListNode* resultList = plist3->head;
	int loopState;	// �ݺ����� ���¸� ��Ÿ��
	// �й� �� ���� ����
	while (list1 != NULL) {
		list2 = plist2->head;				// list2 �ʱ�ȭ
		while (list2 != NULL) {				
			resultList = plist3->head;				// Result List �ʱ�ȭ
			loopState = 0;
			while (resultList != NULL) {				// Result List�� ������ �ݺ�
				if (list1->expon + list2->expon == resultList->expon) {	// ������ ���ٸ�
					resultList->coef += list1->coef * list2->coef;		// ������ ����
					loopState++;
					break;
				}
				resultList = resultList->link;				// Result List�� ����������
			}
			if (loopState == 1) {			// ���� �������̶�� ����������
				list2 = list2->link;
			}
			else {							// ���� �������� �ƴ϶��
				// ����� ���ϰ�, ������ ������ ���� Insert ����
				lastNodeInsertion(plist3, list1->coef * list2->coef, 
					list1->expon + list2->expon);
				list2 = list2->link;		
			}
		}
		list1 = list1->link;				// List1�� ���� �� �̵�
	}
	polynomiaSort(plist3->head);
}

// �޸� �Ҵ� ���� �Լ�
void memoryUnallocation(ListType* list)
{
	ListNode* p;							// p ����
	//ListNode* head = list->head;			// ListType�� head Node ����
	while (list->head) {					// list�� ������
		p = list->head;						// p�� head Node ����
		list->head = list->head->link;		// ���� link ����Ŵ
		free(p);							// �Ҵ� ����
		p = NULL;							// p �� NULL�� ����
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
	// �ʿ��� ���� ����
	int coef, expon;
	char buf;
	ListType* list1, *list2, *list3;
	FILE* fp;

	//���׽� �ʱ�ȭ
	list1 = nodeInitialization();
	list2 = nodeInitialization();
	list3 = nodeInitialization();

	// list3�� �̸��� ����
	strcpy(list3->name, "poly3");
	// File Open
	fp = fopen("data.txt", "r");
	if (fp == NULL)					// ����ó��
	{
		printf("������ ���� ���α׷��� �����մϴ�.\n");
		return 0;
	}

	fscanf(fp, "%s", list1->name);
	while (1)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		fscanf(fp, "%c", &buf);
		lastNodeInsertion(list1, coef, expon);
		if (buf == '\n')		// ���๮�ڷ� �ݺ����� ������
			break;
	}
	fscanf(fp, "%s", list2->name);
	while (1)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		fscanf(fp, "%c", &buf);
		lastNodeInsertion(list2, coef, expon);
		if (feof(fp))			// ������ ���� �Ǵ��ؼ� �ݺ����� ������
			break;
	}

	fclose(fp);					 // ���̻� ������ ������� �����Ƿ� ���� close

	printf("------------------------\n");
	printf("���Ͽ��� �Է¹��� ���׽�\n");
	printf("------------------------\n\n");
	polynomialPrint(list1);					// List1 ���׽� ���
	polynomialPrint(list2);					// List2 ���׽� ���
	printf("\n");

	// ���׽� ���� �Լ� ����
	polynomialMultiplication(list1, list2, list3);

	printf("--------------------------\n");
	printf("���׽� ���� ���� �� ���׽�\n");
	printf("--------------------------\n\n");
	polynomialPrint(list3);					// ��� ���׽� ���
	printf("\n");

	memoryUnallocation(list1);					// List1 Unallocation
	memoryUnallocation(list2);					// List2 Unallocation
	memoryUnallocation(list3);					// List3 Unallocation

	return 0;
}