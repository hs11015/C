/*2021-05-14 ���� �� C 12���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� ���� 3�ڸ� ���� �޸� ���
���ڸ� �Է¹ް�, ���� 3�ڸ����� �޸��� ��� ����ϴ� ���α׷��� �ۼ����ּ���.
- ���� 1 : 4�ڸ� �̸��� ���ڶ�� �޸��� ���� �ʽ��ϴ�.
- ���� 2 : ������ ���̴� 20�� ���� �ʽ��ϴ�.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void Program_Comma(char* a);

int main() {
	char num[21] = { 0 };	// 20�ڸ��� ���� �����Ƿ� index 19���� �Է�, 20 = \n, 21 = \0
	printf("���ڸ� �Է����ּ��� : ");
	fgets(num, 21, stdin);

	Program_Comma(num);

	return 0;
}

void Program_Comma(char* a) {
	int length = strlen(a) - 1, first_comma = length % 3 - 1, i;
	
	if (length < 4) {
		for (i = 0; i < length + 1; i++)
			printf("%c", a[i]);
	}

	else {	// (length >= 4)
		for (i = 0; i < first_comma; i++) {
			printf("%c", a[i]);

			if ((i - first_comma) % 3 == 0)
				printf(",");
		}

		for (i = first_comma; i < length + 1; i++) {
			printf("%c", a[i]);

			if ((i - first_comma) % 3 == 0 && length-1 != i)
				printf(",");
		}
	}
}
*/