/*2021-05-12 ���� �� C 10���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� �ټ� �ڸ� ������ �ڸ����� ��
�ټ� �ڸ� ���� �Է¹ް�, �Է¹��� ������ �� �ڸ����� ���� ���ϴ� ���α׷��� �ۼ����ּ���.
- ���� 1 : 12345�� �ڸ����� ���� 1+2+3+4+5�̹Ƿ� 15�Դϴ�.
- ���� 2 : �ټ� �ڸ� ���� �����Դϴ�.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calculation(int x);

int main() {
	int num;

	printf("�ټ� �ڸ� ���� �Է��ϼ��� : ");
	scanf("%d", &num);

	printf("�ټ� �ڸ� ���� �� : %d",calculation(num));
}

int calculation(int x) {
	int first, second, third, fourth, fifth;
	first = x / 10000;
	second = x / 1000 - first * 10;
	third = x / 100 - first * 100 - second * 10;
	fourth = x / 10 - first * 1000 - second * 100 - third * 10;
	fifth = x % 10;

	return first + second + third + fourth + fifth;
}
*/