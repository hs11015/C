/*20201-04-29 ���̵�C 2���� �ڵ��ѽñ�
���̵� �� ����Ǯ�� : ���� ���� ���ϱ�
���� 1: 0�̻� 99������ ������ �Է� �ް�, �� �ڸ����� ���� ���մϴ�. (9 ������ ���� �״�� ���)
���� 2: �Է� ���� ���� ���� ������ �ڸ����� �տ��� ���� ���� ���� ������ �ڸ����� �̾� �ٿ� ���ο� ���� ���� �մϴ�.
���� 3: ���ο� ���� 1, 2�� �ݺ��Ͽ� ������ ���ڷ� ���ư� �� ���� �� ���� ������ ���ľ� �ϴ��� ����ϴ� ���α׷��� �ۼ��غ�����.*/

/*
#include <stdio.h>

int main(void)
{
	int num, count = 0;
	printf("���ڸ� �Է����ּ��� : ");
	scanf_s("%d", &num);

	int new_num, num_ten, num_one, num_sum;

	count++;
	num_ten = num / 10;	// 10���� ���� �� = 10�� �ڸ� ��
	num_one = num % 10;	// 10���� ���� ������ = 1�� �ڸ� ��

	num_sum = num_ten + num_one;	// �� �ڸ� ���� ��
	new_num = num_one * 10 + num_sum % 10; // �Է� ���� ���� 1�� �ڸ� �� = 10���ڸ�, ���� 1�� �ڸ� �� = 1�� �ڸ�
	printf("%d��° �ٲ� �� : %d\n", count, new_num);

	while (new_num != num)
	{
		count++;
		num_ten = new_num / 10;	// 10���� ���� �� = 10�� �ڸ� ��
		num_one = new_num % 10;	// 10���� ���� ������ = 1�� �ڸ� ��

		num_sum = num_ten + num_one;	// �� �ڸ� ���� ��
		new_num = num_one * 10 + num_sum % 10; // �Է� ���� ���� 1�� �ڸ� �� = 10���ڸ�, ���� 1�� �ڸ� �� = 1�� �ڸ�
		printf("%d��° �ٲ� �� : %d\n", count, new_num);
	}

	printf("\n%d�� �ݺ��ؾ� %d�� ���� ���� %d�� ���ƿ´�.", count, num, new_num);
}
*/


/*
#include <stdio.h>

int num, count = 0;
// �������� ���. �������� ������� ������ num ���� ��� �ٲ� main�Լ��� New_Num �Լ� �� ������ ���� ��� �Ұ���

int New_Num(int num);

int main(void)
{
	printf("���ڸ� �Է����ּ��� : ");
	scanf_s("%d", &num);
	
	New_Num(num);
}

int New_Num(int number)
{
	int new_num, num_ten, num_one, num_sum;

	count++;
	num_ten = number / 10;	// 10���� ���� �� = 10�� �ڸ� ��
	num_one = number % 10;	// 10���� ���� ������ = 1�� �ڸ� ��

	num_sum = num_ten + num_one;	// �� �ڸ� ���� ��
	new_num = num_one * 10 + num_sum % 10; // �Է� ���� ���� 1�� �ڸ� �� = 10���ڸ�, ���� 1�� �ڸ� �� = 1�� �ڸ�

	printf("%d��° �ٲ� �� : %d\n", count, new_num);

	if (new_num == num)
	{
		printf("\n%d�� �ݺ��ؾ� %d�� ���� ���� %d�� ���ƿ´�.", count, num, new_num);
		return 0;
	}

	else	// new_num != num
		New_Num(new_num);
}
*/