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
//// ���� �ʱ�ȭ �Լ�
//void init(StackType* s)
//{
//	// �迭�� � ���� �����ϴ��� top�� ���� -1���ϸ� ������ ����ִ� �ɷ� ����
//	s->top = -1;
//}
//
//// ���� ���� ���� �Լ�
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
//// ��ȭ ���� ���� �Լ�
//int is_full(StackType* s)
//{
//	// index '0' start �� ������ -1 ���־�� ��
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
//		// index�� ���� ���� ��Ų �� push �ؾ� ��
//		s->data[++(s->top)] = item;
//	}
//}
//
//// Stack Data Delete
//element pop(StackType* s)
//{
//	//pop �Ҷ� �ϴ� �� Stack���� Ȯ�� �ؾ� ��
//	if (is_empty(s))
//	{
//		printf("Stack Under Flow\n");
//		exit(0);
//	}
//	else
//	{
//		// ���� pop�ϰ� index�� ���� ������� �� (��������)
//		return s->data[(s->top)--];
//	}
//}
//
//// peek : �������� ���� ���� �ִ���?
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
//	// ���� �ʱ�ȭ
//	init(&s);
//
//	for (i = 0; i < len; i++)
//	{
//		ch = exp[i];
//		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
//		{
//			value = ch - '0';		// �Է��� �ǿ������̸�
//			push(&s, value);		// ���ÿ� ����
//		}
//		else
//		{	// �������̸� �ǿ����ڸ� ���ÿ��� ����
//			op2 = pop(&s);
//			op1 = pop(&s);
//			switch (ch) {	// ���� ���� �� ���ÿ� ����
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
//		// ���� ������ ���� ǥ�� ��
//		printf("���� ǥ����� %s\n", buf);
//		result = eval(buf);
//		printf("��� ���� %d\n\n", result);
//	}
//	fclose(fp);
//
//	return 0;
//}