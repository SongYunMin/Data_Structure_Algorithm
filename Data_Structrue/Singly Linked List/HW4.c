#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;		// ����� ������ ���� ����ü

// ���� ����Ʈ ���
typedef struct ListType {
	char name[30];
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;		// ����Ʈ�� �� �հ� ��

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(-1);
}

// ����Ʈ�� ����� �Լ�
ListType* create(void)
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));	// ����Ʈ�� �����Ҵ��Ѵ�.
	plist->size = 0;
	plist->head = NULL;
	plist->tail = NULL;

	return plist;	// �����Ҵ� �� �ʱ�ȭ�� ��ģ �Լ��� Return�Ѵ�.
}

// �������� �����ϴ� insert_last
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("�޸� �Ҵ� ����");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	// �̺κ��� ������ �޾ƿ��鼭 �������ִ� �͵� ������ ���� �� ����
	if (plist->tail == NULL) {
		plist->head = temp;
		plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}

	// ���ĵ� ���⼭ �ع�����??
	plist->size++;
}

int main(void)
{
	ListType* list1, * list2, * list3;
	FILE* fp;
	int* buf;
	int count_1 = 0, count_2 = 0, coef_buf, expon_buf;
	char name_1[10];
	char name_2[10];

	// list�� ���� �� �ʱ�ȭ�Ѵ�.
	list1 = create();
	list2 = create();
	list3 = create();

	// ���� Open �� ����ó��
	fp = fopen("data.txt", "r");
	while (fp == NULL)
	{
		printf("File Not Found\n");
		return -1;
	}


	// File Reading Area
	fscanf(fp, "%s", name_1);
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		fscanf(fp, "%d %d", &coef_buf, &expon_buf);
		count_1++;
	}
	// END

	// Memory Allocation Area


	// END


	

	//fscanf(fp, "%s", name_2);
	//do {
	//	fscanf(fp, "%d %d", &BUF.coef, &BUF.expon);
	//	list1->head->coef = BUF.coef;

	//} while (!feof(fp) && fgetc(fp) != '\n');

	return 0;
}