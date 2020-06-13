//#include <stdlib.h>
//#include <stdio.h>
//
//// sample data : 0, 1, 2, 3, 4, ....
//typedef int element;
//typedef struct DListNode {
//	struct DListNode* llink;		// left Link
//	element data;
//	struct DListNode* rlink;		// Right Link
//} DListNode;
//
//void init(DListNode *phead)
//{
//	// 다른 List와의 틀린점은 초기화시 NULL을 가리키지 않고
//	// 자기 자신을 가리킴
//	phead->llink = phead;
//	phead->rlink = phead;
//}
//
//void print_list(DListNode * phead)
//{
//	DListNode* p;
//	// 헤드가 가리키는 rlink는 첫번째 node임
//	// 헤드엔 데이터가 없음
//	for (p = phead->rlink; p != phead; p = p->rlink)
//	{
//		printf("<-| |%d| |->", p->data);
//	}
//	printf("\n");
//}
//
//// 데이터 추가 (시험에 나옴)
//void dinsert(DListNode *before, element data)
//{
//	// new node는 중간에 끼어드는 node
//	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
//	newnode->data = data;
//	// newnode가 껴들때 4번의 포인터 변경이 필요함
//	// 중간에 끼어드는 노드는 before(왼쪽)를 가리키고
//	newnode->llink = before;
//	// rlink는 before가 가리키고 있는 rlink를 가리킨다
//	newnode->rlink = before->rlink;
//	// 직접 그려봐야 함..
//	before->rlink->llink = newnode;
//	before->rlink = newnode;
//}
//
//// 데이터 삭제
//void ddelete(DListNode* head, DListNode* removed)
//{
//	// 헤드는 '지시자' 역할, 데이터를 가지고 있지 않음
//	if (removed == head)
//		return;
//	// 그림 참조하면 편함
//	// delete할땐 2번이면 됨.
//	removed->llink->rlink = removed->rlink;
//	removed->rlink->llink = removed->llink;
//
//	free(removed);
//}
//
//int main(void)
//{
//	// 헤드 포인터 메모리 할당
//	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
//	init(head); // 헤드 포인터 초기화
//	
//	// 삽입 -> 출력
//	printf("insert node\n");
//	for (int i = 0; i < 5; i++)
//	{
//		dinsert(head, i);		// 4 - 3 - 2 - 1 - 0
//		print_list(head);
//	}
//
//	// 출력 -> 삭제
//	printf("delete node\n");
//	for (int i = 0; i < 5; i++)
//	{
//		print_list(head);
//		ddelete(head, head->rlink);
//	}
//
//	free(head);
//	return 0;
//}