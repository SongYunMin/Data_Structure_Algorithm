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
//// 오류 함수
//void error(char* message)
//{
//	fprintf(stderr, "%s\n", message);
//	exit(1);
//}
//
//// 리스트 헤더 생성 함수
//ListType* create()
//{
//	// plist 초기화
//	ListType* plist = (ListType*)malloc(sizeof(ListType));
//	plist->size = 0;
//	plist->head = NULL;
//	plist->tail = NULL;
//	return plist;
//}
//
//// plist는 연결 리스트의 헤더를 가리키는 포인터
//// coef는 계수, expon지수
//void insert_last(ListType* plist, int coef, int expon)
//{
//	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
//	if (temp == NULL) error("메모리 할당 에러");
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
//	// a와 b가 둘다 NULL이 아닐때
//	while (a && b)
//	{
//		// a와 b의 차수가 같다면?
//		if (a->expon == b->expon) {	// a의 차수 b의 차수
//			sum = a->coef + b->coef;
//			if (sum != 0) insert_last(plist3, sum, a->expon);
//			a = a->link;
//			b = b->link;
//		}
//		// a가 b의 차수보다 크다면?
//		else if (a->expon > b->expon) {
//			insert_last(plist3, a->coef, a->expon);
//			a = a->link;
//		}
//		// a가 b의 차수보다 작다면?
//		else {
//			insert_last(plist3, b->coef, b->expon);
//			b = b->link;
//		}
//	}
//
//	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두
//	// 결과 다항식으로 복사
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
//
//	// 연결리스트 헤더 생성
//
//	list1 = create();
//	list2 = create();
//	list3 = create();
//
//	// 다항식 1을 생성
//	insert_last(list1, 3, 12);
//	insert_last(list1, 2, 8);
//	insert_last(list1, 1, 0);
//
//	// 다항식 2를 생성
//	insert_last(list2, 8, 12);
//	insert_last(list2, -3, 10);
//	insert_last(list2, 10, 6);
//
//	poly_print(list1);
//	poly_print(list2);
//
//	// 다항식 3 = 다항식 1 + 다항식 2
//	poly_add(list1, list2, list3);
//	poly_print(list3);
//
//	// 이거 이렇게 해제해도 됨..?
//	free(list1);
//	free(list2);
//	free(list3);
//	return 0;
//}