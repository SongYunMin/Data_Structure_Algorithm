#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

// ���� �ʱ�ȭ �Լ�
void init(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	// ���� ���¸� true(1) ��ȯ
	return (s->top == -1);
}

int is_full(StackType* s)
{
	// �迭 �ε��� 0���� �����ϱ� ������ -1
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) // ������ �� ���ִٸ�?
	{
		printf("Stack Over Flow\n");
		exit(1);
	}
	else 
	{
		s->data[++(s->top)] = item;
	}
}