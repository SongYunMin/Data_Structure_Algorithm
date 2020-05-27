/*
DATA
정우람 100.0 45.9 78.5 23.6
양현종 64.8 78.9 100 75.4
박해진 82.4 93.5 88.4 63.5
양다혜 3.3 4.4 5.5 6.6
송윤민 1.1 2.2 3.3 4.4
박강민 3.3 4.4 5.5 6.6
*/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// 학생 성적 구조체
//typedef struct Student {
//	int num;
//	char name[30];
//	double lan;
//	double math;
//	double eng;
//	double com;
//} Student;
//
//// 노드를 가르킬 구조체
//typedef struct ListNode {
//	Student data;
//	struct ListNode* link;		// 다음 노드를 가리킴
//	struct ListNode* back;		// 이전 노드를 가리킴
//} ListNode;
//
//int count;
//
//// 학생 검색 함수
//void Search_Stduent(ListNode* head)
//{
//	int num;
//	ListNode* p = head;
//	printf("검색할 번호를 입력 하세요 : "); scanf("%d", &num);
//
//	while (p != NULL) {
//		if(p->data.num == num) {
//			printf("\n번호\t이름\t언어\t수학\t영어\t컴퓨터\n");
//			printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n\n", p->data.num, p->data.name, p->data.lan,
//				p->data.math,p->data.eng,p->data.com);
//			return;
//		}
//		p = p->link;
//	}
//
//	return NULL;
//}
//
//// 학생 출력 함수
//void Print_Student(ListNode* head)
//{
//	// Local 복사
//	ListNode* p = head;
//
//	// 모든 노드 출력함
//	while (p != NULL)
//	{
//		printf("번호\t이름\t언어\t수학\t영어\t컴퓨터\n");
//		printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",
//			p->data.num,p->data.name, p->data.lan, p->data.math, p->data.eng,
//			p->data.com);
//		p = p->link;	// 다음 노드로 이동
//	}
//	printf("\n");
//
//}
//
//// 노드 생성 함수
//ListNode* create_node(Student data)
//{
//	ListNode* new_node;		// 메모리를 할당받지 않은 포인터
//	new_node = (ListNode*)malloc(sizeof(ListNode));
//	// 예외 처리
//	if (new_node == NULL)
//	{
//		printf("Memory Allocation Fail\n");
//		exit(1);
//	}
//	new_node->data = data;		// 새로운 노드에 데이터를 대입하고
//	new_node->link = NULL;		// 대입된 노드는 다음 노드를 가리킨다
//
//	return new_node;
//}
//
//void insert_node(ListNode** phead, ListNode** tail, ListNode* new_node)
//{
//	// 데이터가 없다면
//	if (*phead == NULL) {
//		new_node->link = NULL;
//		*phead = new_node;
//		*tail = new_node;
//	}
//	// 데이터가 있다면
//	else {
//		//new_node->link = *phead;
//		//*phead = new_node;
//		(*tail)->link = new_node;
//		(*tail) = new_node;
//	}
//}
//
//int main(void)
//{
//	int choice = 1;
//	// File Open
//	FILE* fp = NULL;				// 파일 포인터 선언
//	Student temp;					// Data구조체 선언
//	ListNode* list = NULL;			// 연결리스트의 시작 노드 포인터
//	ListNode* tail = NULL;			// 맨 뒤 삽입을 위한 tail
//	temp.num = 0;
//	// File Open 및 예외 처리
//	fp = fopen("data.txt", "rt");
//	if (fp == NULL)
//	{
//		printf("File Not Found\n");
//		return -1;
//	}
//
//	// 우선 데이터를 전부 읽어들인다.
//	while (!feof(fp))
//	{
//		temp.num++;
//		fscanf(fp, "%s %lf %lf %lf %lf",
//			temp.name, &temp.lan, &temp.math, &temp.eng, &temp.com);
//		insert_node(&list, &tail,create_node(temp));
//	}
//	
//	// 메뉴 입력 반복문
//	while (choice != 0) {
//		printf("0:종료 1:학생 데이터입력 2:학생 검색 3:목록 보기\n");
//		scanf("%d", &choice); 
//		if (choice == 0)
//		{
//			printf("프로그램을 종료합니다\n");
//			exit(0);
//		}
//		// 학생 데이터 입력 메뉴
//		else if (choice == 1)
//		{
//			// 쓰기 모드로 변경
//			fp = fopen("data.txt", "at");
//			// 예외 처리
//			if (fp == NULL)
//			{
//				printf("File Not Found\n");
//				return -1;
//			}
//			printf("이름 입력 : "); scanf("%s", temp.name);
//			// 이름 제한은 4글자
//			if (strlen(temp.name) > 4) {
//				printf("이름은 4글자가 최대입니다. 다시입력해주십시오.\n");
//				printf("이름 입력 : "); scanf("%s", temp.name);
//			}
//			
//			printf("언어 점수 : "); scanf("%lf", &temp.lan);
//			printf("수학 점수 : "); scanf("%lf", &temp.math);
//			printf("영어 점수 : "); scanf("%lf", &temp.eng);
//			printf("컴퓨터 점수 : "); scanf("%lf", &temp.com);
//			// 파일 입력
//			fprintf(fp, "\n%s %.1lf %.1lf %.1lf %.1lf", temp.name, temp.lan,
//				temp.math, temp.eng, temp.com);
//			fclose(fp);
//			temp.num++;
//			insert_node(&list,&tail, create_node(temp));
//		}
//		// 학생 검색 메뉴
//		else if (choice == 2)
//		{
//			Search_Stduent(list);
//		}
//		// 학생 목록 출력 메뉴
//		else if (choice == 3)
//		{
//			Print_Student(list);
//		}
//	}
//	// 파일 close
//	fclose(fp);
//	// Memory 할당 해제
//	free(list);
//	free(tail);
//	return 0;
//}