/*2021-05-17 ���� �� C 13���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� �� �̵���Ű��
- ���� 1 : ���� n�� ���� ���·θ� �Էµ˴ϴ�.
- ���� 2 : �絿�̷� ��� �Ű����� ���� ��� -1�� ����մϴ�.
- ���� 3 : 8���͸� �Űܾ� �ϴ� ��� 5���� + 3���Ϳ� ���� ��������
			�̵��� �����ϹǷ� Ƚ���� �� 2ȸ�Դϴ�.
- ���� 4 : �絿�̴� ���� ä���� ����ؾ� �մϴ�.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit �Լ�

void Moving(int a);

int main() {
	int n;
	printf("�ٸ� ��⿡ �Űܾ� �ϴ� ���� ��(L) : ");
	scanf("%d", &n);

	Moving(n);

	return 0;
}

void Moving(int a) {
	int count_five = 0, count_three = 0, count_sum = 0, num_temp = 0, num = a;

	while (num != 0) {
		if (num % 5 == 0) {	// 5�� ���� ����������ν� �ּ� Ƚ�� ���ϱ� ����
			num -= 5;
			count_five++;
		}

		else {	// num % 5 != 0
			num_temp = num % 5;

			if ((num_temp % 3 == 0) || (num % 3 == 0)) {
				num -= 3;
				count_three++;
			}

			else {	// num % 3 != 0, 5�� 3 ��� ������ �������� ����.
				printf("�絿�̷� ��� �Ű����� �ʴ´�.\n-1");
				exit(-1);
			}
		}
	}

	count_sum = count_five + count_three;
	printf("5L �絿�̷� �ű� Ƚ�� : %d\n", count_five);
	printf("3L �絿�̷� �ű� Ƚ�� : %d\n", count_three);
	printf("�� �絿�̷� �ű� �ּ� Ƚ�� : %d\n", count_sum);
}