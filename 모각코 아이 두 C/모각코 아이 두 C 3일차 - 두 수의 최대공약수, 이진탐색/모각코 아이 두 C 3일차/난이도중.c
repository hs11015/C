/*2021-04-30 ���� �� C ����Ǯ�� 5������ �ڵ��ѽñ�
���̵� �� : �� ���� �ִ�����
�ִ������� ���� �������� ���� ��, ���� ������ ��� �� ���� ū ���� ���մϴ�.
�� ���ڸ� �Է¹ް� �� �ִ� ������� ����ϴ� ���α׷��� �ۼ��غ�����.
- ���� 1 : �Է¹޴� ���ڴ� �ڿ����Դϴ�.
- ���� 2 : �Լ��� Ȱ���Ͽ� �ۼ����ּ���.*/

/*
#include <stdio.h>

void Input_Number(int x);
void GCD(int x, int y);	// �ִ����� = Greatest Common Denominator(GCD)

int main(void)
{
	int a = 0, b = 0;

	printf("ù ��° ���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &a);	// scanf�� Input_Number �Լ� �ȿ� ������ �ν��� �ȵ�
	Input_Number(a);	// ���ڰ� �ڿ������� Ȯ���ϴ� �뵵

	printf("�� ��° ���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &b);
	Input_Number(b);

	GCD(a, b);	// a�� b�� �ִ� ����� ���ϴ� �Լ�

	return 0;
}

void Input_Number(int x)
{
	printf("�Է��Ͻ� ���� ");

	if (x <= 0)
	{
		printf("���� 1(�Է� �޴� ���ڴ� �ڿ����Դϴ�.)�� ���ϴ�.");
		exit(-1);
	}

	printf("%d�Դϴ�.\n", x);
}

void GCD(int x, int y)
{
	int num;

	if (x < y)
	{
		if (y % x == 0)
			num = x;
		else	// ������ �������� ������ x�� y�� x�� ���� �������� ��� ȣ��
			GCD(x, y % x);
	}

	else if (x == y)	// x�� y�� ���� ��� �ִ� ������� �ڱ� �ڽ�
		num = x;

	else	// x > y
	{
		if (x % y == 0)
			num = y;
		else	// ������ �������� ������ y�� x�� y�� ���� �������� ��� ȣ��
			GCD(y, x % y);
	}

	printf("�� ���� �ִ� ������� %d�Դϴ�.", num);
}
*/