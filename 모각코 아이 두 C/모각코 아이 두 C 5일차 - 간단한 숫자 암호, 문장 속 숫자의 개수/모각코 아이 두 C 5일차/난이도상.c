/*2021-05-04 ���� �� C 5���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� ���� �� 0���� 9������ ����
���ڿ��� �Է¹ް�, �� ���ڿ��� ���Ե� �� ������ ������ ����ϴ� ���α׷��� �ۼ��غ�����.
- ���� 1 : ���ڿ��� ���̴� 100�� �ʰ����� �ʽ��ϴ�.
- ���� 2 :  0���� 9������ �� ���ڰ� �� ������ ����ؾ� �մϴ�.*/

#include <stdio.h>

int main() {
	char sentence[101] = { 0, };	// ���ڿ��� ���̴� 100�� �ʰ����� �ʴ´�

	printf("������ �Է��ϼ��� : ");
	fgets(sentence, 101, stdin);	// ������ ���ڿ� \0, ���������� 2���� ���ڿ� \n ����

	int number[10] = { 0, };	// ������ ���ڿ� \0
	for (int i = 0; i < 100; i++)
	{
		if (sentence[i] == '0')
			number[0]++;

		if (sentence[i] == '1')
			number[1]++;

		if (sentence[i] == '2')
			number[2]++;

		if (sentence[i] == '3')
			number[3]++;

		if (sentence[i] == '4')
			number[4]++;

		if (sentence[i] == '5')
			number[5]++;

		if (sentence[i] == '6')
			number[6]++;

		if (sentence[i] == '7')
			number[7]++;

		if (sentence[i] == '8')
			number[8]++;

		if (sentence[i] == '9')
			number[9]++;

		if (sentence[i] == '\n')
			break;
	}

	for (int j = 0; j < 10; j++)
	{
		printf("%d : %d��\n", j, number[j]);
	}
}