#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;		// 계수와 지수를 담은 구조체

// 연결 리스트 헤더
typedef struct ListType {
	char name[30];
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;		// 리스트의 맨 앞과 끝

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(-1);
}

// 리스트를 만드는 함수
ListType* create(void)
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));	// 리스트를 동적할당한다.
	plist->size = 0;
	plist->head = NULL;
	plist->tail = NULL;

	return plist;	// 동적할당 및 초기화를 마친 함수를 Return한다.
}

// 마지막에 삽입하는 insert_last
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	// 이부분은 파일을 받아오면서 전달해주는 것도 나쁘지 않을 것 같음
	if (plist->tail == NULL) {
		plist->head = temp;
		plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}

	// 정렬도 여기서 해버리면??
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

	// list를 생성 및 초기화한다.
	list1 = create();
	list2 = create();
	list3 = create();

	// 파일 Open 및 예외처리
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