///*
//DATA
//23+4*9+
//15+32-*
//52*3+42-+
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_STACK_SIZE 100
//#define TRUE 1
//#define FALSE 0
//#pragma warning(disable : 4996)
//
//typedef char element;
//
//typedef struct {
//	element data[MAX_STACK_SIZE];
//	int top;
//} StackType;
//
//
//// 스택 초기화 함수
//void init(StackType* s)
//{
//	// 배열에 어떤 값이 존재하더라도 top의 값만 -1로하면 스택은 비어있는 걸로 간주
//	s->top = -1;
//}
//
//// 공백 상태 검출 함수
//int is_empty(StackType* s)
//{
//	if (s->top == -1) {
//		return TRUE;
//	}
//	else {
//		return FALSE;
//	}
//}
//
//// 포화 상태 검출 함수
//int is_full(StackType* s)
//{
//	// index '0' start 기 때문에 -1 해주어야 함
//	if (s->top == MAX_STACK_SIZE - 1)	//array zero index
//		return TRUE;
//	else
//		return FALSE;
//}
//
//// Stack Data Insert
//void push(StackType* s, element item)
//{
//	if (is_full(s))
//	{
//		printf("Stack Over Flow\n");
//		return;
//	}
//	else
//	{
//		// index를 먼저 증가 시킨 후 push 해야 함
//		s->data[++(s->top)] = item;
//	}
//}
//
//// Stack Data Delete
//element pop(StackType* s)
//{
//	//pop 할땐 일단 빈 Stack인지 확인 해야 함
//	if (is_empty(s))
//	{
//		printf("Stack Under Flow\n");
//		exit(0);
//	}
//	else
//	{
//		// 값을 pop하고 index를 감소 시켜줘야 함 (후위감소)
//		return s->data[(s->top)--];
//	}
//}
//
//// peek : 제일위에 무슨 값이 있는지?
//element peek(StackType* s)
//{
//	if (is_empty(s))
//	{
//		printf("Stack empty\n");
//		exit(1);
//	}
//	else
//	{
//		return s->data[s->top];
//	}
//}
//
//int eval(char exp[])
//{
//	StackType s;
//	int len = strlen(exp);
//	char ch;
//	int i = 0, op1, op2, value;
//
//	// 스택 초기화
//	init(&s);
//
//	for (i = 0; i < len; i++)
//	{
//		ch = exp[i];
//		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
//		{
//			value = ch - '0';		// 입력이 피연산자이면
//			push(&s, value);		// 스택에 넣음
//		}
//		else
//		{	// 연산자이면 피연산자를 스택에서 제거
//			op2 = pop(&s);
//			op1 = pop(&s);
//			switch (ch) {	// 연산 수행 후 스택에 저장
//			case '+': push(&s, op1 + op2); break;
//			case '-': push(&s, op1 - op2); break;
//			case '*': push(&s, op1 * op2); break;
//			case '/': push(&s, op1 / op2); break;
//			}
//		}
//	}	// end of loop
//
//	return pop(&s);
//}
//
//int main(void)
//{
//	char buf[1024] = { 0, };
//	int result = 0;
//	FILE* fp = fopen("data.txt", "r");
//	if (fp == NULL)
//	{
//		printf("File Not Found\n");
//		return 0;
//	}
//
//	while (!feof(fp))
//	{
//		fscanf(fp, "%s", buf);
//		// 읽은 파일의 후위 표기 식
//		printf("후위 표기식은 %s\n", buf);
//		result = eval(buf);
//		printf("결과 값은 %d\n\n", result);
//	}
//	fclose(fp);
//
//	return 0;
//}