#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0
#pragma warning(disable : 4996)

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;


// ���� �ʱ�ȭ �Լ�
void init(StackType* s)
{
	// �迭�� � ���� �����ϴ��� top�� ���� -1���ϸ� ������ ����ִ� �ɷ� ����
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	if (s->top == -1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	// index '0' start �� ������ -1 ���־�� ��
	if (s->top == MAX_STACK_SIZE - 1)	//array zero index
		return TRUE;
	else
		return FALSE;
}

// Stack Data Insert
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		printf("Stack Over Flow\n");
		return;
	}
	else
	{
		// index�� ���� ���� ��Ų �� push �ؾ� ��
		s->data[++(s->top)] = item;
	}
}

// Stack Data Delete
element pop(StackType* s)
{
	//pop �Ҷ� �ϴ� �� Stack���� Ȯ�� �ؾ� ��
	if (is_empty(s))
	{
		printf("Stack Under Flow\n");
		exit(0);
	}
	else
	{
		// ���� pop�ϰ� index�� ���� ������� �� (��������)
		return s->data[(s->top)--];
	}
}

// peek : �������� ���� ���� �ִ���?
element peek(StackType* s)
{
	if (is_empty(s))
	{
		printf("Stack empty\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
}


// ������ �켱������ �˱����� �Լ�
int prec(char op)
{
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[])
{
	/*
		basic fule
		�ǿ����� -> ���
		������ -> ���ÿ� push
		1) * (/)
		2) + -
		3) ( )
	*/

	StackType s;
	int len = strlen(exp);
	char ch, top_op;
	int i = 0;

	init(&s);

	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		switch (ch)
		{
			// �������� ��쿡
		case '+':
		case '-':
		case '*':
		case '/':
			// ���ÿ� �̹� push�� �������� �켱������ �� ���ų� ������ pop
				// ������ ������� �ʾ��� �� ���� �о���� �������� �켱���� ����
				// ���ÿ� ����ִ� �������� �켱������ ��ũ�ٸ�
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) // ch + vs peek(&s) *
			{
				printf("%c", pop(&s));	// a*b+c -> ab*
			}
			push(&s, ch); // +
			break;
		case '(':
			push(&s, ch);		// ��ȣ�� �켱���� ���� ���� �ٷ� stack�� ������ ��
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:	// �� ������
			printf("%c", ch);
			break;
		} // end of witch
	}	// end of loop

	while (!is_empty(&s))
		printf("%c", pop(&s));
	printf("\n");
}

int main(void)
{
	char buf[100];
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("File Not Found\n");
		return 0;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s", buf);
		infix_to_postfix(buf);
	}

	return 0;
}