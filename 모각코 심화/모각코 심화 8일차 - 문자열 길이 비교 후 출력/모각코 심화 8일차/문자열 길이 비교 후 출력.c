/*���� ���̵�C 3������ 8���� �ڵ��ѽñ�
�� ���� ���ڿ��� �Է� ���� �� �� ���ڿ� �� �� ���ڿ��� ���̸� ���
��, �� ���ڿ��� ���̰� ������, �� ���ڿ��� �ϳ��� ���ڿ��� ���ļ� ���
���鵵 ���ڿ��� ���̿� �����ϱ�*/

#define _CRT_SECURE_NO_WARNINGS   // strcpy�� strcat �� �� �ʿ���
#include <stdio.h>
#include <string.h>    // ���ڿ� �Լ� �������
#include <stdlib.h>    // ���� �Լ� �������
#pragma warning(disable : 6387)

void ComparingSentenceLength(char* ptr1, char* ptr2); // �� ���ڿ� ��

int main()
{
	char buffer1[100] = { 0 };
	char buffer2[100] = { 0 };
	char* sentence1 = buffer1;
	char* sentence2 = buffer2;

	printf("1��° ���ڿ��� �Է��ϼ��� : ");
	scanf("%[^\n]s", sentence1);
	getchar();
	printf("%s\n", sentence1);

	printf("2��° ���ڿ��� �Է��ϼ��� : ");
	scanf("%[^\n]s", sentence2);
	getchar();
	printf("%s\n", sentence1);

	ComparingSentenceLength(sentence1, sentence2);

	return 0;
}

void ComparingSentenceLength(char* ptr1, char* ptr2) //��� �ڷᰪ char
{
	char ptr3[200] = { 0, };

	printf("���ڿ� 1 ���� : %d\n���ڿ� 2 ���� : %d\n", strlen(ptr1), strlen(ptr2));

	if (strlen(ptr1) > strlen(ptr2))
		printf("�� �� �� �� ���ڿ��� �����Դϴ�.\n%s", ptr1);

	else if (strlen(ptr1) < strlen(ptr2))
		printf("�� �� �� �� ���ڿ��� �����Դϴ�.\n%s", ptr2);

	else  //strlen(ptr1) = strlen(ptr2) ptr1, ptr2�� ���̰� ����
	{
		if (strcmp(ptr1, ptr2) == 0)  //ptr1�� ptr2 ���ڿ��� ����
			printf("�ߺ��� ���ڿ��̹Ƿ� �� ���� ����մϴ�.\n%s", ptr1);
		//ptr1 ��� ptr2���� ��� ����

		else  //ptr1�� ptr2�� �Էµ� ���ڿ��� ���� ���� ���
		{
			strcpy(ptr3, ptr1);  //ptr1�� ptr3�� ����(ä���ֱ�)
			strcat(ptr3, ptr2);  //ptr2�� ptr3�ڿ� ����
			printf("%s", ptr3);
		}
	}
}