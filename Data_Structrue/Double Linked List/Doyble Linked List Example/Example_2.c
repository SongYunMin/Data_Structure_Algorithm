#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
DListNode* current;

void init(DListNode *phead)
{
	// �ٸ� List���� Ʋ������ �ʱ�ȭ�� NULL�� ����Ű�� �ʰ�
	// �ڱ� �ڽ��� ����Ŵ
	phead->llink = phead;
	phead->rlink = phead;
}

void print_list(DListNode * phead)
{
	DListNode* p;
	// ��尡 ����Ű�� rlink�� ù��° node��
	// ��忣 �����Ͱ� ����
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		if (p == current) {
			printf("<-| #%s# |->", p->data);
		}
		else {
			printf("<-| %s |->", p->data);
		}
	}
	printf("\n");
}

// ������ �߰� (���迡 ����)
void dinsert(DListNode *before, element data)
{
	// new node�� �߰��� ������ node
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	// newnode�� ���鶧 4���� ������ ������ �ʿ���
	// �߰��� ������ ���� before(����)�� ����Ű��
	newnode->llink = before;
	// rlink�� before�� ����Ű�� �ִ� rlink�� ����Ų��
	newnode->rlink = before->rlink;
	// ���� �׷����� ��..
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// ������ ����
void ddelete(DListNode* head, DListNode* removed)
{
	// ���� '������' ����, �����͸� ������ ���� ����
	if (removed == head)
		return;
	// �׸� �����ϸ� ����
	// delete�Ҷ� 2���̸� ��.
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;

	free(removed);
}


int main(void)
{
	char ch;		// ȭ�鿡�� �Է¹��� Ŀ�ǵ� < > q
	char song1[] = "Mamamia";
	char song2[] = "Dancing Queen";
	char song3[] = "Fernando";

	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, song1);
	dinsert(head, song2);
	dinsert(head, song3);

	current = head->rlink;
	print_list(head);

	do {
		printf("\n ��ɾ �Է��ϼ���. < > q : ");
		ch = getchar();

		if (ch == '<') {
			current = current->llink;
			// head ���� ���� �ٽ� �Űܼ� ó������ ���ư��� �Ѵ�.
			if (current == head) {
				current = current->llink;
			}
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head) {
				current = current->rlink;
			}
		}
		print_list(head);
		getchar();
	} while (ch != 'q');


	free(head);
	return 0;
}