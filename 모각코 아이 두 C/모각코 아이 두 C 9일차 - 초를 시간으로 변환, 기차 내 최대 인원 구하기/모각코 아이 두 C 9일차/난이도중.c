/*2021-05-11 ���� �� C 9���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� �� �ð� ��ȯ
�� ������ �ð��� �Է¹ް�, ��, �ð����� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ����ּ���.
- ���� 1 : ������� �ʴ� ������ �ð��� ������� �ʽ��ϴ�.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void time(int sec);

int main() {
	int sec = 0;
	printf("�� ������ �ð��� �Է��ϼ��� : ");
	scanf("%d", &sec);
	time(sec);
	return 0;
}

void time(int sec) {
	int hour = sec / 3600;
	int minute = (sec - hour * 3600) / 60;
	int second = sec % 60;
	printf("%d�ð� %d�� %d��", hour, minute, second);
}
*/