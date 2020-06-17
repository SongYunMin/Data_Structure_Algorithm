//#include <stdio.h>
//#include <stdlib.h>
//
///*
//DATA
//정우람 100.0 45.9 78.5
//양현종 64.8 78.9 100
//박해진 82.4 93.5 88.4
//추신수 99.5 43.9 88.3
//박찬호 100.0 99.9 78.5
//이대호 88.9 99.9 78.9
//강백호 85.4 78.6 31.5
//이재학 82.4 93.5 78.4
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
//	ListNode* new_node;	// 메모리를 할당받지 않은 포인터
//	// void *malloc(int size);
//	// 해당 타입으로 꼭 캐스팅 해야 됨
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
//	// 1. 홍길동
//	// 2. 심청이
//	if (*phead == NULL)	// 데이터가 없다면
//	{
//		// 홍길동
//		new_node->link = NULL;
//		*phead = new_node;
//	}
//	else // 데이터가 있다면
//	{
//		// 심청이 -> 링크 = 홍길동
//		// 마스터 = 심청이
//		new_node->link = *phead;
//		*phead = new_node;
//	}
//}
//
//void display(ListNode* head)
//{
//	// local 복사
//	ListNode* p = head;
//
//	while (p != NULL)
//	{
//		printf("%s %lf %lf %lf %lf\n",
//			p->data.name, p->data.kor, p->data.math,
//			p->data.com, p->data.total);
//		p = p->link; // 다음 노드로 이동
//	}
//	printf("\n");
//}
//
//int main(void)
//{
//	FILE* fp = NULL;		// 파일포인터 선언
//	element temp;			// Data 구조체 선언
//	ListNode* new_node;		// 새로운 node를 참조할 구조체
//	ListNode* list = NULL;		// 연결리스트의 시작노드 포인터
//
//	// 파일 오픈
//	fp = fopen("data.txt", "r");
//	if (fp == NULL)		// 예외 처리
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
//	// 출력함수
//	display(list);
//
//	// 파일포인터 close
//	fclose(fp);
//
//	return 0;
//}