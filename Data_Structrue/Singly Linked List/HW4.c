#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;		// 계수와 지수를 담은 구조체

// 연결 리스트 헤더
typedef struct ListType {
	char name[30];
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;		// 리스트의 맨 앞과 끝

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(-1);
}

// 리스트를 만드는 함수
ListType* create(void)
{
	ListType* plist = (ListType*)malloc(sizeof(ListType));	// 리스트를 동적할당한다.
	plist->size = 0;
	plist->head = NULL;
	plist->tail = NULL;

	return plist;	// 동적할당 및 초기화를 마친 함수를 Return한다.
}

// 마지막에 삽입하는 insert_last
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	// 이부분은 파일을 받아오면서 전달해주는 것도 나쁘지 않을 것 같음
	if (plist->tail == NULL) {
		plist->head = temp;
		plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}

	// 정렬도 여기서 해버리면??
	plist->size++;
}

int main(void)
{
	ListType* list1, * list2, * list3;
	FILE* fp;
	int* buf_1;
	int* buf_2;
	int count = 0, coef_buf, expon_buf, i = 0, temp, index = 1;
	char name_1[10];
	char name_2[10];

	// list를 생성 및 초기화
	list1 = create();
	list2 = create();
	list3 = create();

	// 파일 Open 및 예외처리
	fp = fopen("data.txt", "r");
	while (fp == NULL)
	{
		printf("File Not Found\n");
		return -1;
	}


	// 다항식의 길이를 알기위한 Code Area
	fscanf(fp, "%s", name_1);		
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		// 파일을 읽어들이며 길이를 잰다.
		fscanf(fp, "%d %d", &coef_buf, &expon_buf);
		count++;
	}
	fscanf(fp, "%s", name_2);		
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		fscanf(fp, "%d %d", &coef_buf, &expon_buf);
		count++;
	}
	// END

	// 동적할당 및 계수, 지수 읽어들이기
	buf_1 = (int *)malloc(sizeof(int) * count);
	buf_2 = (int *)malloc(sizeof(int) * count);
	fseek(fp, 0, SEEK_SET);
	fscanf(fp, "%s", name_1);		// 첫번째 다항식 읽음
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		// List 1의 계수, 지수 읽음
		fscanf(fp, "%d", &buf_1[i]);
		i++;
	}
	i = 0;
	fscanf(fp, "%s", name_2);		// 두번째 다항식 읽음
	while (!feof(fp) && fgetc(fp) != '\n')
	{
		// List 2의 계수, 지수 읽음
		fscanf(fp, "%d",&buf_2[i]);
		i++;
	}
	// END

	// Sort Area : 차수가 큰 순으로 내림차순 
	for (i = 0; i < count / 2-1; i++) {
		for (int j = 0; j < count / 2 - 1; j++) {
			if (buf_1[index] < buf_1[index + 2]) {
				temp = buf_1[index];
				buf_1[index] = buf_1[index + 2];
				buf_1[index + 2] = temp;
				// 계수를 정렬 함
				temp = buf_1[index - 1];
				buf_1[index - 1] = buf_1[index + 1];
				buf_1[index + 1] = temp;
				index += 2;
			}
		}
	}

	//for (i = 0; i < count / 2 - 1; i++) {
	//	for (int j = 0; j < count / 2 - 1; j++) {
	//		if (buf_2[index] < buf_2[index + 2]) {
	//			temp = buf_2[index];
	//			buf_2[index] = buf_2[index + 2];
	//			buf_2[index + 2] = temp;
	//		}
	//		index += 2;
	//	}
	//	index = 1;
	//}

	for (int i = 0; i < 8; i++) {
		printf("%d ", buf_1[i]);
	}
	// END


	free(buf_1);
	free(buf_2);

	return 0;
}