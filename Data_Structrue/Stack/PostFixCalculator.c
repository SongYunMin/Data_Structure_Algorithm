//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define MAX_STACK_SIZE 100
//#define TRUE 1
//#define FALSE 0
//
//typedef char element;
//typedef enum {
//	leftparen, rightparen, plus, minus, multiply, divide, eos, operand
//} words;
//
//typedef struct {
//	// Stack Definition
//	element stack[MAX_STACK_SIZE];
//	int top;
//} StackType;
//
//words classification(char* point) {
//	switch (*point) {
//	case'(': return leftparen;
//	case')': return rightparen;
//	case'+': return plus;
//	case'-': return minus;
//	case'*': return multiply;
//	case'/': return divide;
//	case'\'': return eos;
//	default: return operand;
//	}
//}
//
//int change_value(char* num, int* index) {
//	int value;
//	char temp[100];
//	int i, k;
//	for (i = 0; num[i] != ' '; i++)
//		temp[i] = num[i];
//	temp[i] = '\0';
//	value = atoi(temp);
//	k = *index;
//	*index = k + i;
//	return value;
//}
//
//// stack initalize
//void init(StackType* s)
//{
//	s->top = -1;		// empty stack
//}
//
//// stack empty?
//int is_empty(StackType* s)
//{
//	// 비어있다
//	if (s->top == -1)
//		return TRUE;
//	// 아니다
//	else
//		return FALSE;
//	// return (s->top == -1)
//}
//
//// stack full?
//int is_full(StackType* s)
//{
//	// index '0' start 기 때문에 -1 해주어야 함
//	if (s->top == MAX_STACK_SIZE - 1)	//array zero index
//		return TRUE;
//	else
//		return FALSE;
//}
//
//// stack data insert
//void push(StackType* s, element item)
//{
//	if (is_full(s))
//	{
//		printf("Stack Over Flow\n");
//		return;
//	}
//	else
//	{
//		// index를 먼저 증가 시킨 후 push해야 함
//		s->stack[++(s->top)] = item;
//	}
//}
//
//// stack data delete
//element pop(StackType* s)
//{
//	// pop 할땐 일딴 빈 Stack인지 확인 해야 함
//	if (is_empty(s))
//	{
//		printf("Stack Under Flow\n");
//		exit(0);
//	}
//	else
//	{
//		// 값을 pop하고 index를 감소 시켜줘야 함(후위감소)
//		return s->stack[(s->top)--];
//	}
//}
//
//// peek : 제일위에 무슨 값이 있는지
//element peek(StackType* s)
//{
//	if (is_empty(s))
//	{
//		printf("Stack empty\n");
//		exit(1);
//	}
//	else
//	{
//		return s->stack[s->top];
//	}
//}
//
//int eval(char exp[])
//{
//	words temp;
//	int op1, op2, value, i = 0;
//	int len = strlen(exp);
//	char ch;
//	StackType s;
//
//	init(&s);
//	//for (i = 0; i < len; i++) {
//	//	ch = exp[i];
//	//	if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
//	//		value = ch - '0';
//	//		push(&s, value);
//	//	}
//	//	else {
//	//		op2 = pop(&s);
//	//		op1 = pop(&s);
//	//		switch (ch) {
//	//		case'+':push(&s, op1 + op2); break;
//	//		case'-':push(&s, op1 - op2); break;
//	//		case'*':push(&s, op1 * op2); break;
//	//		case'/':push(&s, op1 / op2); break;
//	//		}
//	//	}
//	//}
//
//	for (i = 0; i < exp[i] != '\0'; i++) {
//		if (exp[i] == ' ')
//			i++;
//		temp = classification(&exp[i]);
//		if (temp == operand) {
//			value = change_value(&exp[i], &i);
//			push(&s, value);
//		}
//		else {
//			op2 = pop(&s);
//			op1 = pop(&s);
//			switch (ch) {
//			case'+':push(&s, op1 + op2); break;
//			case'-':push(&s, op1 - op2); break;
//			case'*':push(&s, op1 * op2); break;
//			case'/':push(&s, op1 / op2); break;
//			}
//		}
//
//		return pop(&s);
//	}
//}
//
//int main(void)
//{
//	int result;
//	printf("\n");
//	result = eval("3 5 189 * + ");
//	printf("결과값은 %d\n", result);
//
//	return 0;
//}