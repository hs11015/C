/*2021-05-18 ���� �� C 14���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� ������ ���ϱ�
�ڿ��� 10���� n���� ���� �������� ���ϰ�,
�� ������ �� ���� �ٸ� ���� �� �� �ִ��� ����ϴ� ���α׷��� �ۼ����ּ���
- ���� 1 : �ڿ��� n�� ���� �Է¹޽��ϴ�.
- ���� 2 : �ڿ��� 10���� �Է¹޽��ϴ�.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int cnt = 0, index = 0, n, arr[11] = { 0 };
	printf("���� ���� �Է����ּ��� : ");
	scanf("%d", &n);

	printf("\n�ڿ��� 10���� �Է����ּ���\n");
	for (int i = 0; i < 10; i++) {
		printf("%d��° ���� : ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\n�Էµ� �ڿ����� %d�� ���� ������\n", n);
	for (int i = 0; i < 10; i++) {
		arr[i] = arr[i] % n;
		printf("%d ", arr[i]);
	}

	while (index < 10) {
		for (int i = index + 1; i < 10; i++) {
			if (arr[index] == arr[i]) {
				cnt++;
				break;
			}
		}
		index++;
	}

	printf("\n\n�� %d���� ���� �ٸ� ���������� �ֽ��ϴ�.", cnt);

	return 0;
}*/