//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct ListNode {
//	int coef;
//	int expon;
//	struct ListNode* link;
//} ListNode;
//
//// 연결 리스트 헤더
//typedef struct ListType {
//	int size;
//	ListNode* head;
//	ListNode* tail;
//} ListType;
//
//void error(char* message)
//{
//	fprintf(stderr, "%s\n", message);
//	exit(-1);
//}
//
//ListType* create(void)
//{
//	ListType* plist = (ListType*)malloc(sizeof(ListType));
//	plist->size = 0;
//	plist->head = NULL;
//	plist->tail = NULL;
//
//	return plist;
//}
//
//// 마지막에 삽입하는 insert_last
//void insert_last(ListType* plist, int coef, int expon)
//{
//	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
//	if (temp == NULL) error("메모리 할당 에러");
//	temp->coef = coef;
//	temp->expon = expon;
//	temp->link = NULL;
//
//	// 이부분은 파일을 받아오면서 전달해주는 것도 나쁘지 않을 것 같음
//	if (plist->tail == NULL) {
//		plist->head = temp;
//		plist->tail = temp;
//	}
//	else {
//		plist->tail->link = temp;
//		plist->tail = temp;
//	}
//
//	// 정렬도 여기서 해버리면??
//	plist->size++;
//}
//
//int main(void)
//{
//	ListType* list1, * list2, * list3;
//	ListNode BUF;
//	FILE* fp;
//	char arrayName[30];
//	fp = fopen("data.txt", "r");
//
//	while (fp == NULL)
//	{
//		printf("File Not Found\n");
//		return -1;
//	}
//	
//
//	while (!feof(fp)) {
//		fscanf(fp, "%s", arrayName);
//		do {
//			fscanf(fp, "%d %d", &BUF.coef, &BUF.expon);
//			list1->head->coef = BUF.coef;
//
//		} while (!feof(fp) && fgetc(fp) != '\n');
//	}
//	return 0;
//}