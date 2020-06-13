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
	// 비어있다
	if (s->top == -1)
		return TRUE;
	// 아니다
	else
		return FALSE;
	// return (s->top == -1)
}

// stack full?
int is_full(StackType* s)
{
	// index '0' start 기 때문에 -1 해주어야 함
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
		// index를 먼저 증가 시킨 후 push해야 함
		s->stack[++(s->top)] = item;
	}
}

// stack data delete
element pop(StackType* s)
{
	// pop 할땐 일딴 빈 Stack인지 확인 해야 함
	if (is_empty(s))
	{
		printf("Stack Under Flow\n");
		exit(0);
	}
	else
	{
		// 값을 pop하고 index를 감소 시켜줘야 함(후위감소)
		return s->stack[(s->top)--];
	}
}

// peek : 제일위에 무슨 값이 있는지
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
	// Stack 초기화
	init(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];	// { A [ ( i + 1 ) ] = 0 } 하나씩 읽음
		// Open 괄호들이 나오면 Push 함
		// Close 괄호가 나오면 peek 해보고 pop함
		// 변수 혹은 operand(연산자) 는 무시함
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
			// 문장이 시작되자마자 close brace가 나온다면
			if (is_empty(&s)) // search open brace in empty stack
			{
				return FALSE;
			}
			else
			{
				//empty stack이 아니고 open brace가 있는지 chack
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

	// 짝이 안맞는 경우
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
		// 한줄을 읽고
		fscanf(fp, "%s", buf);
		if (check_matching(buf) == TRUE)
			printf("괄호검사성공 : ");
		else
			printf("괄호검사실패 : ");

		printf("%s\n", buf);
	}

	fclose(fp);

	return 0;
}