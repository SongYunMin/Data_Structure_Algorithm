//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef char element[100];
//
//typedef struct DListNode {
//	element data;
//	struct DListNode* llink;
//	struct DListNode* rlink;
//} DListNode;
//DListNode* current;
//
//void init(DListNode *phead)
//{
//	// 다른 List와의 틀린점은 초기화시 NULL을 가리키지 않고
//	// 자기 자신을 가리킴	``
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
//		if (p == current) {
//			printf("<-| #%s# |->", p->data);
//		}
//		else {
//			printf("<-| %s |->", p->data);
//		}
//	}
//	printf("\n");
//}
//
//// 데이터 추가 (시험에 나옴)
//void dinsert(DListNode *before, element data)
//{
//	// new node는 중간에 끼어드는 node
//	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
//	strcpy(newnode->data, data);
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
//	char ch;		// 화면에서 입력받을 커맨드 < > q
//	char song1[] = "미인";
//	char song2[] = "사랑은 지날수록 더욱 선명하게 남아";
//	char song3[] = "화려하지 않은 고백";
//	char song4[] = "My Love";
//	char song5[] = "가시";
//	char song6[] = "너에게 난, 나에게 넌";
//	char song7[] = "사랑하게 될 줄 알았어";
//	char song8[] = "깡";
//	char song9[] = "Glory Days";
//	char song10[] = "축배";
//
//	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
//	init(head);
//
//	dinsert(head, song1);
//	dinsert(head, song2);
//	dinsert(head, song3);
//	dinsert(head, song4);
//	dinsert(head, song5);
//	dinsert(head, song6);
//	dinsert(head, song7);
//	dinsert(head, song8);
//	dinsert(head, song9);
//	dinsert(head, song10);
//
//	current = head->rlink;
//	print_list(head);
//
//	do {
//		printf("\n 명령어를 입력하세요. < > q : ");
//		ch = getchar();
//
//		if (ch == '<') {
//			current = current->llink;
//			// head 까지 가면 다시 옮겨서 처음으로 돌아가게 한다.
//			if (current == head) {
//				current = current->llink;
//			}
//		}
//		else if (ch == '>') {
//			current = current->rlink;
//			if (current == head) {
//				current = current->rlink;
//			}
//		}
//		print_list(head);
//		getchar();
//	} while (ch != 'q');
//
//
//	free(head);
//	return 0;
//}