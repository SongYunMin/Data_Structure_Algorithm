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
	unsigned num;	// ��ȯ�ϴ� ����
	int cd;			// ���
	int dno;		// ��ȯ �� �ڸ���
	char cno[512];	// ��ȯ�� ���� �� �ڸ��� ���ڸ� �����ϴ� ���� �迭
	int retry;		// �ѹ� �� ?

	puts("10������ ��� ��ȯ�մϴ�.");
	do {
		printf("��ȯ�ϴ� ���� �ƴ� ���� : "); scanf("%u", &num);
		do {
			printf("� ������ ��ȯ�ұ��?(2-36) : "); scanf("%d", &cd);
		} while (cd < 2 || cd >36);
		dno = card_convr(num, cd, cno);
		printf("%d �����δ� ", cd);
		for (i = dno - 1; i >= 0; i--)
			printf("%c", cno[i]);
		printf(" �Դϴ�.\n");
		printf("�� �� �� �ұ��?(1...�� /0...�ƴϿ�  : )");
		scanf("%d", &retry);



	} while (retry == 1);
	return 0;
}