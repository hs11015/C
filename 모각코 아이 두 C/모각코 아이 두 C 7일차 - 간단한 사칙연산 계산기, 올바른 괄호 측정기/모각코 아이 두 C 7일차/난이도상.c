/*2021-05-07 ���̵� C 7���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� �ùٸ� ��ȣ
�ùٸ� ��ȣ�� '('�� �����ϰ� ')'�� ������ ��ȣ�� ���մϴ�.
�ùٸ� ��ȣ�� ����Ͽ����� �Ǻ��ϴ� ���α׷��� �ۼ����ּ���.*/

/*
#include <stdio.h>
#include <string.h>

int i = 0, temp = 0;

void brk(char* str);

int main() {
	char arr[100] = { 0, };
	fgets(arr, 101, stdin);
	brk(arr);
	return 0;
}

void brk(char* str) {
	if (str[i] == '(')
		temp++;

	if (str[i] == ')')
		temp--;

	if (i < strlen(str)) {
		if (temp < 0)	// ���� ��ȣ�� ���µ� �ݴ� ��ȣ�� �ִ� ���
			printf("�߸��� ��ȣ�Դϴ�.");
		else	// ���� ��ȣ�� ���� ������ �ݴ� ��ȣ�� ������ ���
		{
			i++;
			brk(str);
		}
	}

	else	// i >= strlen(str)
	{
		if (temp == 0)
			printf("�ùٸ� ��ȣ�Դϴ�.");

		else	// temp != 0
			printf("�߸��� ��ȣ�Դϴ�.");
	}
}
*/