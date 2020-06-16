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
	int* buf_1;
	int* buf_2;
	int count = 0, coef_buf, expon_buf, i = 0, temp, index = 1;
	char name_1[10];
	char name_2[10];

	// list�� ���� �� �ʱ�ȭ
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


	// ���׽��� ���̸� �˱����� Code Area
	fscanf(fp, "%s", name_1);		
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		// ������ �о���̸� ���̸� ���.
		fscanf(fp, "%d %d", &coef_buf, &expon_buf);
		count++;
	}
	fscanf(fp, "%s", name_2);		
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		fscanf(fp, "%d %d", &coef_buf, &expon_buf);
		count++;
	}
	// END

	// �����Ҵ� �� ���, ���� �о���̱�
	buf_1 = (int *)malloc(sizeof(int) * count);
	buf_2 = (int *)malloc(sizeof(int) * count);
	fseek(fp, 0, SEEK_SET);
	fscanf(fp, "%s", name_1);		// ù��° ���׽� ����
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		// List 1�� ���, ���� ����
		fscanf(fp, "%d", &buf_1[i]);
		i++;
	}
	i = 0;
	fscanf(fp, "%s", name_2);		// �ι�° ���׽� ����
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		// List 2�� ���, ���� ����
		fscanf(fp, "%d",&buf_2[i]);
		i++;
	}
	// END

	// Sort Area : ������ ū ������ �������� 
	for (i = 0; i < count / 2-1; i++) {
		for (int j = 0; j < count / 2 - 1; j++) {
			if (buf_1[index] < buf_1[index + 2]) {
				temp = buf_1[index];
				buf_1[index] = buf_1[index + 2];
				buf_1[index + 2] = temp;
				// ����� ���� ��
				temp = buf_1[index - 1];
				buf_1[index - 1] = buf_1[index + 1];
				buf_1[index + 1] = temp;
				index += 2;
			}
		}
	}

	//for (i = 0; i < count / 2 - 1; i++) {
	//	for (int j = 0; j < count / 2 - 1; j++) {
	//		if (buf_2[index] < buf_2[index + 2]) {
	//			temp = buf_2[index];
	//			buf_2[index] = buf_2[index + 2];
	//			buf_2[index + 2] = temp;
	//		}
	//		index += 2;
	//	}
	//	index = 1;
	//}

	for (int i = 0; i < 8; i++) {
		printf("%d ", buf_1[i]);
	}
	// END


	free(buf_1);
	free(buf_2);

	return 0;
}