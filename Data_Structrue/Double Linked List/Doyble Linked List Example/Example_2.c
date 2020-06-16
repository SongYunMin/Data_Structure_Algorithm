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
//	// �ٸ� List���� Ʋ������ �ʱ�ȭ�� NULL�� ����Ű�� �ʰ�
//	// �ڱ� �ڽ��� ����Ŵ	``
//	phead->llink = phead;
//	phead->rlink = phead;
//}
//
//void print_list(DListNode * phead)
//{
//	DListNode* p;
//	// ��尡 ����Ű�� rlink�� ù��° node��
//	// ��忣 �����Ͱ� ����
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
//// ������ �߰� (���迡 ����)
//void dinsert(DListNode *before, element data)
//{
//	// new node�� �߰��� ������ node
//	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
//	strcpy(newnode->data, data);
//	// newnode�� ���鶧 4���� ������ ������ �ʿ���
//	// �߰��� ������ ���� before(����)�� ����Ű��
//	newnode->llink = before;
//	// rlink�� before�� ����Ű�� �ִ� rlink�� ����Ų��
//	newnode->rlink = before->rlink;
//	// ���� �׷����� ��..
//	before->rlink->llink = newnode;
//	before->rlink = newnode;
//}
//
//// ������ ����
//void ddelete(DListNode* head, DListNode* removed)
//{
//	// ���� '������' ����, �����͸� ������ ���� ����
//	if (removed == head)
//		return;
//	// �׸� �����ϸ� ����
//	// delete�Ҷ� 2���̸� ��.
//	removed->llink->rlink = removed->rlink;
//	removed->rlink->llink = removed->llink;
//
//	free(removed);
//}
//
//int main(void)
//{
//	char ch;		// ȭ�鿡�� �Է¹��� Ŀ�ǵ� < > q
//	char song1[] = "����";
//	char song2[] = "����� �������� ���� �����ϰ� ����";
//	char song3[] = "ȭ������ ���� ���";
//	char song4[] = "My Love";
//	char song5[] = "����";
//	char song6[] = "�ʿ��� ��, ������ ��";
//	char song7[] = "����ϰ� �� �� �˾Ҿ�";
//	char song8[] = "��";
//	char song9[] = "Glory Days";
//	char song10[] = "���";
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
//		printf("\n ��ɾ �Է��ϼ���. < > q : ");
//		ch = getchar();
//
//		if (ch == '<') {
//			current = current->llink;
//			// head ���� ���� �ٽ� �Űܼ� ó������ ���ư��� �Ѵ�.
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