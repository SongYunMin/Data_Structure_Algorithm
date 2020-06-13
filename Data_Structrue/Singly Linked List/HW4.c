//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct ListNode {
//	int coef;
//	int expon;
//	struct ListNode* link;
//} ListNode;
//
//// ���� ����Ʈ ���
//typedef struct ListType {
//	int size;
//	ListNode* head;
//	ListNode* tail;
//} ListType;
//
//// ���� �Լ�
//void error(char* message)
//{
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//
//// ����Ʈ ��� ���� �Լ�
//ListType* create()
//{
//	// plist �ʱ�ȭ
//	ListType* plist = (ListType*)malloc(sizeof(ListType));
//	plist->size = 0;
//	plist->head = NULL;
//	plist->tail = NULL;
//	return plist;
//}
//
//// plist�� ���� ����Ʈ�� ����� ����Ű�� ������
//// coef�� ���, expon����
//void insert_last(ListType* plist, int coef, int expon)
//{
//	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
//	if (temp == NULL) error("�޸� �Ҵ� ����");
//	temp->coef = coef;
//	temp->expon = expon;
//	temp->link = NULL;
//	if (plist->tail == NULL) {
//		plist->head = temp;
//		plist->tail = temp;
//	}
//	else {
//		plist->tail->link = temp;
//		plist->tail = temp;
//	}
//	plist->size++;
//}
//
//// list3 = list1 + list 2
//void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
//{
//	ListNode* a = plist1->head;
//	ListNode* b = plist2->head;
//	int sum;
//
//	// a�� b�� �Ѵ� NULL�� �ƴҶ�
//	while (a && b)
//	{
//		// a�� b�� ������ ���ٸ�?
//		if (a->expon == b->expon) {	// a�� ���� b�� ����
//			sum = a->coef + b->coef;
//			if (sum != 0) insert_last(plist3, sum, a->expon);
//			a = a->link;
//			b = b->link;
//		}
//		// a�� b�� �������� ũ�ٸ�?
//		else if (a->expon > b->expon) {
//			insert_last(plist3, a->coef, a->expon);
//			a = a->link;
//		}
//		// a�� b�� �������� �۴ٸ�?
//		else {
//			insert_last(plist3, b->coef, b->expon);
//			b = b->link;
//		}
//	}
//
//	// a�� b���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ���
//	// ��� ���׽����� ����
//
//	for (; a != NULL; a = a->link)
//		insert_last(plist3, a->coef, a->expon);
//	for (; b != NULL; b = b->link)
//		insert_last(plist3, b->coef, b->expon);
//}
//
//void poly_print(ListType* plist)
//{
//	ListNode* p = plist->head;
//
//	printf("polynomial = ");
//	for (; p; p = p->link) {
//		printf("%d^%d + ", p->coef, p->expon);
//	}
//	printf("\n");
//}
//
//int main(void)
//{
//	ListType* list1, * list2, * list3;
//	FILE* fp;
//	fp = fopen("data.txt", "r");
//
//	while (fp == NULL)
//	{
//		printf("File Not Found\n");
//		return -1;
//	}
//
//	return 0;
//}