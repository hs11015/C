/*2021-05-17 ���� �� C 13���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� ���� ���� ���
- ���� 1 : O�� ����� ������ �� �������� ���ӵ� O�� ������ ������ �����ϴ�
(ex. O �� 1��, OOO �� 1 + 2 + 3 = 6��)
- ���� 2 : X�� ����� ������ 0�� �Դϴ�.
- ���� 3 : ������ ������ 10���Դϴ�.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Counting(char* arr);

int main() {
	char arr[11] = { 0, };	// index 10 = \n, index 11 = \0

	printf("������ ������ OX ���·� �Է��ϼ��� : ");
	scanf("%s", arr);

	Counting(arr);

	return 0;
}

void Counting(char* arr) {
	int count = 0, sum = 0;
	
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 'O') {
			count++;
			sum += count;
		}

		else if (arr[i] == 'X')
			count = 0;

		else {	// OX�� ��Ÿ�������� ���
			printf("OX ���·� ��Ÿ���� �ʾҽ��ϴ�.\n");
			exit(-1);
		}
	}

	printf("�� �� : %d", sum);
}
*/