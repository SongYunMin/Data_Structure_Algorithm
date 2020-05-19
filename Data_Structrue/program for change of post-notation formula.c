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


// 스택 초기화 함수
void init(StackType* s)
{
	// 배열에 어떤 값이 존재하더라도 top의 값만 -1로하면 스택은 비어있는 걸로 간주
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	if (s->top == -1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// 포화 상태 검출 함수
int is_full(StackType* s)
{
	// index '0' start 기 때문에 -1 해주어야 함
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
		// index를 먼저 증가 시킨 후 push 해야 함
		s->data[++(s->top)] = item;
	}
}

// Stack Data Delete
element pop(StackType* s)
{
	//pop 할땐 일단 빈 Stack인지 확인 해야 함
	if (is_empty(s))
	{
		printf("Stack Under Flow\n");
		exit(0);
	}
	else
	{
		// 값을 pop하고 index를 감소 시켜줘야 함 (후위감소)
		return s->data[(s->top)--];
	}
}

// peek : 제일위에 무슨 값이 있는지?
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


// 연산자 우선순위를 알기위한 함수
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
		피연선자 -> 출력
		연산자 -> 스택에 push
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
			// 연산자인 경우에
		case '+':
		case '-':
		case '*':
		case '/':
			// 스택에 이미 push된 연산자의 우선수위가 더 높거나 같으면 pop
				// 스택이 비어있지 않았을 때 현재 읽어들인 연산자의 우선순위 보다
				// 스택에 들어있는 연산자의 우선순위가 더크다면
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) // ch + vs peek(&s) *
			{
				printf("%c", pop(&s));	// a*b+c -> ab*
			}
			push(&s, ch); // +
			break;
		case '(':
			push(&s, ch);		// 괄호는 우선순위 가장 낮음 바로 stack에 넣으면 됨
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:	// 피 연산자
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