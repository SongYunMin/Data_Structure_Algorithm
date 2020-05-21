#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화 함수
void init(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	// 공백 상태면 true(1) 반환
	return (s->top == -1);
}

int is_full(StackType* s)
{
	// 배열 인덱스 0부터 시작하기 때문에 -1
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) // 스택이 꽉 차있다면?
	{
		printf("Stack Over Flow\n");
		exit(1);
	}
	else 
	{
		s->data[++(s->top)] = item;
	}
}