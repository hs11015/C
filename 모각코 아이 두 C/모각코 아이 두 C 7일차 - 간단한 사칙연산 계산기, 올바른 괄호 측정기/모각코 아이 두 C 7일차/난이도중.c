/*2021-05-07 ���̵� C 7���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� ������ ��Ģ���� ����
���ڿ��� �� ������ ��Ģ������ �Է¹ް�, �� ����� ����ϴ� ���α׷��� �ۼ����ּ���.
- ���� 1 : ������ ������ ���ϱ�, ����, ���ϱ�, �����Ⱑ �ֽ��ϴ�.
- ���� 2 : ������ ���� �ÿ��� ���� ���մϴ�.
- ���� 3 : �Լ��� Ȱ���Ͽ� ���α׷��� �ۼ����ּ���.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int calculation(char *arr);

int main() {
    char arr[100] = { 0 };

    printf("�Է��ϼ��� : ");
    for (int i = 0; i < 100; i++)
        scanf("%c", &arr[i]);

	return 0;
}

int calculation(char *arr)
{
    if (arr < 48 || arr > 57)   // ASCII code 47~57�� 0~9

    switch (op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        return -1;
    }
}