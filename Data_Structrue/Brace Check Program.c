#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

//define
typedef char element;

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0
typedef struct {
	// Stack Definition
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

// stack initalize
void init(StackType* s)
{
	s->top = -1;		// empty stack
}

// stack empty?
int is_empty(StackType* s)
{
	// ����ִ�
	if (s->top == -1)
		return TRUE;
	// �ƴϴ�
	else
		return FALSE;
	// return (s->top == -1)
}

// stack full?
int is_full(StackType* s)
{
	// index '0' start �� ������ -1 ���־�� ��
	if (s->top == MAX_STACK_SIZE - 1)	//array zero index
		return TRUE;
	else
		return FALSE;
}

// stack data insert
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		printf("Stack Over Flow\n");
		return;
	}
	else
	{
		// index�� ���� ���� ��Ų �� push�ؾ� ��
		s->stack[++(s->top)] = item;
	}
}

// stack data delete
element pop(StackType* s)
{
	// pop �Ҷ� �ϵ� �� Stack���� Ȯ�� �ؾ� ��
	if (is_empty(s))
	{
		printf("Stack Under Flow\n");
		exit(0);
	}
	else
	{
		// ���� pop�ϰ� index�� ���� ������� ��(��������)
		return s->stack[(s->top)--];
	}
}

// peek : �������� ���� ���� �ִ���
element peek(StackType* s)
{
	if (is_empty(s))
	{
		printf("Stack empty\n");
		exit(1);
	}
	else
	{
		return s->stack[s->top];
	}
}

int check_matching(char* in) // *in = {A[(i+1)]=0}
{
	StackType s;
	int n = strlen(in);
	int i;
	char ch, open_ch;
	// Stack �ʱ�ȭ
	init(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];	// { A [ ( i + 1 ) ] = 0 } �ϳ��� ����
		// Open ��ȣ���� ������ Push ��
		// Close ��ȣ�� ������ peek �غ��� pop��
		// ���� Ȥ�� operand(������) �� ������
		switch (ch)
		{
			// open { [ (
		case '{':
		case '[':
		case '(':
			push(&s, ch);
			break;
			// close } ] )
		case '}':
		case ']':
		case ')':
			// ������ ���۵��ڸ��� close brace�� ���´ٸ�
			if (is_empty(&s)) // search open brace in empty stack
			{
				return FALSE;
			}
			else
			{
				//empty stack�� �ƴϰ� open brace�� �ִ��� chack
				open_ch = pop(&s);
				if (
					(open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '(' && ch != ')')
					)
					return FALSE;
			}
			break;
		}
	}

	// ¦�� �ȸ´� ���
	if (!is_empty(&s))
		return FALSE;

	return TRUE;
}

int main(void)
{
	FILE* fp;
	char buf[1024] = { 0, };

	StackType s;
	init(&s);

	// Stack Test Code
	/*
	push(&s, 'a');
	push(&s, 'b');
	push(&s, 'c');
	push(&s, 'd');

	printf("%c\n", pop(&s));
	printf("%c\n", pop(&s));
	printf("%c\n", pop(&s));
	printf("%c\n", pop(&s));
	*/

	// File Open
	fp = fopen("data.txt", "r");

	if (fp == NULL)
	{
		printf("File Not Found\n");
		return -1;
	}

	// data.txt File
	/*
	{A[(i+1)]=0}
	{B[100-(i+5)]*5}
	{C/(5/5*(5-4)}
	(10+5)-(30-20)
	*/

	while (!feof(fp))
	{
		// ������ �а�
		fscanf(fp, "%s", buf);
		if (check_matching(buf) == TRUE)
			printf("��ȣ�˻缺�� : ");
		else
			printf("��ȣ�˻���� : ");

		printf("%s\n", buf);
	}

	fclose(fp);

	return 0;
}