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
	// 할당받은 메모리공간에 인자로 받은 계수 및 지수 대입
	temp->coef = coef;
	temp->expon = expon;
	// 다음을 위해 NULL로 초기화
	temp->link = NULL;
	// tail이 NULL이라면 첫 Node이기 때문에 Head, Tail모두 temp를 가리키게 함
	if (plist->tail == NULL) {
		plist->head = temp;
		plist->tail = temp;
	}
	// Node가 있을시엔 list의 tail의 link가 temp를 가리키게 하고, 
	// tail 자체도 temp를 가리키게 함
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;				// 길이를 증가 시킴
}

// 다항식을 지수가 큰 순서대로 정렬 함
void polynomiaSort(ListNode* list1)
{
	int i, j, temp;					// 제어 변수 및 Node 선언
	ListNode* p, * q, * tmp;
	p = list1;						// 인자로 받은 list1 대입
	while (p->link != NULL)			// list의 끝까지
	{
		tmp = p;					// 복사된 p Node를 tmp Node에 대입
		q = p->link;				// p의 다음항에 q Node 대입
		while (q != NULL)			// q Node에 data가 있다면
		{
			// list의 1번째 항(tmp)보다 2번째 항(q)이 크다면
			if (q->expon > tmp->expon)		
				tmp = q;				// 1번째 항으로 2번째항 대입
			q = q->link;				// q는 다음항을 가리킴
		}
		// 지수 및 계수 자리 변경
		if (tmp != NULL)
		{
			temp = p->expon;			// 지수 정렬
			p->expon = tmp->expon;
			tmp->expon = temp;
			temp = p->coef;				// 계수 정렬
			p->coef = tmp->coef;
			tmp->coef = temp;
		}
		p = p->link;
		// 위 과정을 p의 다음항을 계속 가리키게 하면서 정렬 함
	}
}

// 다항식 곱셈 함수
void polynomialMultiplication(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* list1 = plist1->head;
	ListNode* list2 = plist2->head;
	ListNode* p = plist3->head;
	int loopState;	// 반복문의 상태를 나타냄
	// 분배 및 곱셈 진행
	while (list1 != NULL) {
		list2 = plist2->head;				// list2 초기화
		while (list2 != NULL) {				// list2 의 끝까지 반복
			p = plist3->head;				// Result List 초기화
			loopState = 0;
			while (p != NULL) {				// Result List의 끝까지 반복
				if (list1->expon + list2->expon == p->expon) {	// 지수가 같다면
					p->coef += list1->coef * list2->coef;		// 동류항 생성
					loopState++;
					break;
				}
				p = p->link;				// Result List의 다음항으로
			}
			if (loopState == 1) {			// 만약 동류항이라면 다음항으로
				list2 = list2->link;
			}
			else {							// 만약 동류항이 아니라면
				// 계수는 곱하고, 지수는 더해준 값을 Insert 진행
				lastNodeInsertion(plist3, list1->coef * list2->coef, 
					list1->expon + list2->expon);
				list2 = list2->link;		
			}
		}
		list1 = list1->link;				// List1의 다음 항 이동
	}
	polynomiaSort(plist3->head);
}

// 메모리 할당 해제 함수
void memoryUnallocation(ListType* header)
{
	ListNode* p;
	// 기존 포인터를 참조해야 하기 때문에 더블 포인터 사용
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
		if (p->coef < 0)					// 음수의 경우 출력
			printf(" | %dx^%d |", p->coef, p->expon);
		else if (p->coef == 1)				// 1이라면 x만 출력
			printf(" | +x^%d |", p->expon);
		else								// 양수의 경우 출력
			printf(" | +%dx^%d |", p->coef, p->expon);
	}
	printf("\n");
}

int main(void) {
	// 필요한 변수 선언
	int coef, expon;
	char buf;
	ListType list1, list2, list3;
	FILE* fp;

	//다항식 초기화
	nodeInitialization(&list1);
	nodeInitialization(&list2);
	nodeInitialization(&list3);

	// list3의 이름을 지정
	strcpy(list3.name, "poly3");
	// File Open
	fp = fopen("data.txt", "r");
	if (fp == NULL)					// 예외처리
	{
		printf("오류로 인해 프로그램을 종료합니다.\n");
		return 0;
	}

	fscanf(fp, "%s", list1.name);
	while (1)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		fscanf(fp, "%c", &buf);
		lastNodeInsertion(&list1, coef, expon);
		if (buf == '\n')		// 개행문자로 반복문을 종료함
			break;
	}
	fscanf(fp, "%s", list2.name);
	while (1)
	{
		fscanf(fp, "%d %d", &coef, &expon);
		fscanf(fp, "%c", &buf);
		lastNodeInsertion(&list2, coef, expon);
		if (feof(fp))			// 파일의 끝을 판단해서 반복문을 종료함
			break;
	}//파일의 끝에서 반복문 종료
	printf("------------------------\n");
	printf("파일에서 입력받은 다항식\n");
	printf("------------------------\n\n");
	polynomialPrint(&list1);					// List1 다항식 출력
	polynomialPrint(&list2);					// List2 다항식 출력
	printf("\n");

	// 다항식 곱셈 함수 실행
	polynomialMultiplication(&list1, &list2, &list3);

	printf("--------------------------\n");
	printf("다항식 곱셈 연산 후 다항식\n");
	printf("--------------------------\n\n");
	polynomialPrint(&list3);					// 결과 다항식 출력
	printf("\n");

	memoryUnallocation(&list1);					// List1 Unallocation
	memoryUnallocation(&list2);					// List2 Unallocation
	memoryUnallocation(&list3);					// List3 Unallocation
	fclose(fp);
	return 0;
}