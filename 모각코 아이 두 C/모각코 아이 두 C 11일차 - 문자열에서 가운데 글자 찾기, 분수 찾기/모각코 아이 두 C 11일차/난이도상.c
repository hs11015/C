/*2021-05-13 ���� �� C 11���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� �м� ã��
�Ʒ� �׸��� ����, �迭�� ������ ���� �м��� �����ֽ��ϴ�.
�׸�ó�� ������� ���·� ������ ���� ���,
1/1�� ù ��°, 1/2�� �� ��° �м��� �˴ϴ�.
n��° �м��� ���ϴ� ���α׷��� �ۼ��غ�����.*/

#define _CRT_SECURE_NO_WARNINGS
#define RIGHT	0
#define DOWN	1
#include <stdio.h>
#include <stdlib.h>

void fraction(int n);

int main(void) {
	int n;

	printf("�� ��° �м��� ���� ���ұ��? : ");
	scanf("%d", &n);

	fraction(n);

	return 0;
}

void fraction(int n) {
	int fraction[2] = { 1, 1 };		// ���� ����, �и�
	int maxnum = 1;
	char direction = RIGHT;

	for (int i = 1; i < n; ++i) {
		if (direction == RIGHT) {
			if (fraction[1] == maxnum) {
				maxnum++;
				fraction[1]++;	// �и� 1 �ø�
				direction++;	// direction == DOWN
				continue;
			}
			fraction[0]--;	// ���������� ������ ���ڰ� �پ���
			fraction[1]++;	// �и� �þ
		}
		else {	// direction == DOWN
			if (fraction[0] == maxnum) {
				maxnum++;
				fraction[0]++;	// ���ڸ� 1 �ø�
				direction--;	// direction == RIGHT
				continue;
			}
			fraction[0]++;	// �Ʒ��� ���� ���ڰ� �þ��
			fraction[1]--;	// �и�� �پ��
		}
	}

	printf("\n%d��° �м��� %d/%d �Դϴ�.\n", n, fraction[0], fraction[1]);
}