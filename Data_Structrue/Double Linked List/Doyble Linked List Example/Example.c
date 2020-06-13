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
//	// �ٸ� List���� Ʋ������ �ʱ�ȭ�� NULL�� ����Ű�� �ʰ�
//	// �ڱ� �ڽ��� ����Ŵ
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
//		printf("<-| |%d| |->", p->data);
//	}
//	printf("\n");
//}
//
//// ������ �߰� (���迡 ����)
//void dinsert(DListNode *before, element data)
//{
//	// new node�� �߰��� ������ node
//	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
//	newnode->data = data;
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
//	// ��� ������ �޸� �Ҵ�
//	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
//	init(head); // ��� ������ �ʱ�ȭ
//	
//	// ���� -> ���
//	printf("insert node\n");
//	for (int i = 0; i < 5; i++)
//	{
//		dinsert(head, i);		// 4 - 3 - 2 - 1 - 0
//		print_list(head);
//	}
//
//	// ��� -> ����
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