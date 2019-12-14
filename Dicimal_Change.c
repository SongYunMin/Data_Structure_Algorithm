#include <stdio.h>

int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;

	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x) {
			d[digits++] = dchar[x % n];
			x /= n;
		}
	return digits;
}

int main(void)
{
	int i;
	unsigned num;	// 변환하는 정수
	int cd;			// 기수
	int dno;		// 변환 후 자릿수
	char cno[512];	// 변환한 값의 각 자리의 숫자를 저장하는 문자 배열
	int retry;		// 한번 더 ?

	puts("10진수를 기수 변환합니다.");
	do {
		printf("변환하는 음이 아닌 정수 : "); scanf("%u", &num);
		do {
			printf("어떤 정수로 변환할까요?(2-36) : "); scanf("%d", &cd);
		} while (cd < 2 || cd >36);
		dno = card_convr(num, cd, cno);
		printf("%d 진수로는 ", cd);
		for (i = dno - 1; i >= 0; i--)
			printf("%c", cno[i]);
		printf(" 입니다.\n");
		printf("한 번 더 할까요?(1...예 /0...아니요  : )");
		scanf("%d", &retry);



	} while (retry == 1);
	return 0;
}