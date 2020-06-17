#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	int coef;				// 계수
	int expon;				// 지수
	struct ListNode* link;	// 링크
}ListNode;

typedef struct ListType {
	char name[10];			// 다항식의 이름
	int length;				// 다항식의 길이
	ListNode* head;			// List의 앞부분
	ListNode* tail;			// List의 뒷부분
}ListType;

// Node를 초기화 하는 함수
void nodeInitialization(ListType* plist)
{
	plist->length = 0;		// 길이 및 List의 앞, 뒷부분을 초기화
	plist->head = NULL;
	plist->tail = NULL;
}

// 에러 출력 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// List 삽입 함수
void lastNodeInsertion(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));	// Memory Allocation
	if (temp == NULL) error("메모리 할당 에러");			// 예외 처리
	temp->coef = coef;										// 지수 및
	temp->expon = expon; 
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}//tail은 리스트의 맨끝
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;
} //노드 삽입 함수

// 다항식을 지수가 큰 순서대로 정렬 함
void polynomiaSort(ListNode* list1)
{
	int i, j, least, temp;
	ListNode* p, * q, * tmp;

	int cnt = 1;
	p = list1;
	while (p->link != NULL)
	{
		tmp = p;
		q = p->link;
		// 지수가 큰지 판별 함
		while (q != NULL)
		{
			if (q->expon > tmp->expon)
				tmp = q;
			q = q->link;
		}
		// 지수 및 계수 자리 변경
		if (tmp != NULL)
		{
			temp = p->expon;
			p->expon = tmp->expon;
			tmp->expon = temp;
			temp = p->coef;
			p->coef = tmp->coef;
			tmp->coef = temp;
		} 
		p = p->link;
	}
}

// 다항식 곱셈 함수
void polynomialMultiplication(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* list1 = plist1->head;
	ListNode* list2 = plist2->head;
	ListNode* p = plist3->head;
	int loopState;
	while (list1 != NULL)
	{
		list2 = plist2->head;
		while (list2 != NULL)
		{
			p = plist3->head;
			loopState = 0;
			while (p != NULL)
			{
				if (list1->expon + list2->expon == p->expon) //지수가 같으면
				{
					p->coef = list1->coef * list2->coef + p->coef; //계수 덧셈
					loopState++;
					break;
				}
				p = p->link;
			}
			if (loopState == 1)
				list2 = list2->link;
			else
			{
				lastNodeInsertion(plist3, list1->coef * list2->coef, list1->expon + list2->expon);
				list2 = list2->link;
			}
		}
		list1 = list1->link;
	}
	polynomiaSort(plist3->head);
}

// 메모리 할당 해제 함수
void memoryUnallocation(ListType* header)
{
	ListNode* p;
	ListNode** head = &header->head;
	while (*head)
	{
		p = *head;
		*head = (*head)->link;
		free(p);
	}
}

// 다항식을 출력하는 함수
void polynomialPrint(ListType* plist)
{
	ListNode* p = plist->head;
	printf("%s : %dx^%d", plist->name, p->coef, p->expon);
	p = p->link;		
	for (; p; p = p->link) {
		if (p->coef < 0)
			printf(" | %dx^%d |", p->coef, p->expon);
		else if (p->coef == 1)
			printf(" | +x^%d |", p->expon);
		else
			printf(" | +%dx^%d |", p->coef, p->expon);
	}
	printf("\n");
} 

int main(void) {
	ListType list1, list2, list3;
	FILE* fp;
	int coef, expon;
	char buf;

	nodeInitialization(&list1); 
	nodeInitialization(&list2);
	nodeInitialization(&list3);//다항식 초기화

	strcpy(list3.name, "poly3");
	fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("오류로 인해 프로그램을 종료합니다.\n");
		return 0;
	}//파일 열고 오류발생시 프로그램 종료

	fscanf(fp, "%s", list1.name);
	while (1)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		fscanf(fp, "%c", &buf);
		lastNodeInsertion(&list1, coef, expon);
		if (buf == '\n')
			break;
	} //줄바꿈 문자 받으면 반복문 종료
	fscanf(fp, "%s", list2.name);
	while (1)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		fscanf(fp, "%c", &buf);
		lastNodeInsertion(&list2, coef, expon);
		if (feof(fp))
			break;
	}//파일의 끝에서 반복문 종료
	printf("------------------------\n");
	printf("파일에서 입력받은 다항식\n");
	printf("------------------------\n\n");
	polynomialPrint(&list1);
	polynomialPrint(&list2);
	printf("\n");

	polynomialMultiplication(&list1, &list2, &list3);

	printf("--------------------------\n");
	printf("다항식 곱셈 연산 후 다항식\n");
	printf("--------------------------\n\n");
	polynomialPrint(&list3);
	printf("\n");

	memoryUnallocation(&list1);
	memoryUnallocation(&list2);
	memoryUnallocation(&list3);
	fclose(fp);
	return 0; 
}