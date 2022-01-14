/*2021-05-20 ���� �� C 15���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� ��ĥ�� ���
������ü ����� ����� �׾� ���� ������ü�� �ֽ��ϴ�. ������ü�� �Ѹ鿡�� ��ĥ�� �� ��,
2���� �鿡�� ��ĥ�� �� ������ü�� �� ������ ���ϴ� ���α׷��� �ۼ��غ�����.
- ���� 1 : ������ü�� ����, ����, ������ ��� ������ �Է¹޾ƾ� �մϴ�.
- ���� 2 : �� ������ü���� 2���� �鸸 ��ĥ�� �� ����� ���ؾ��մϴ�.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Colored_Two(int n, int x, int y);
int Colored_Two_exception(int x, int y);

int main() {
	int width, length, height, sum_two;	// ����, ����, ���̸� ���ϱ�

	printf("���� ���� ���̸� �Է��ϼ��� : ");
	scanf("%d %d %d", &width, &length, &height);

	// width ����, length ����, heith ������ ��� ���� ��
	sum_two = Colored_Two(width, length, height) + Colored_Two(length, height, width) + Colored_Two(height, width, length);

	printf("�� 2���� �鿡 ��ĥ�� ������ü�� ���� : %d", sum_two);

	return 0;
}

// ���� ���� ���� ��� 2 �̻��� ��
// ������ü�� ������ ��� : 3���� ��ĥ�� ��.
// �������� �ƴ����� �𼭸��� ��� : 2���� ��ĥ�� ��
// �鿡 �ִ� ��� : 1���� ��ĥ�� ��, �ӿ� �ִ� ��� : 0���� ��ĥ�� ��
int Colored_Two(int n, int x, int y) {
	int edge_except_vertex = 0;

	if (n > 2 && x != 1 && y != 1)
		edge_except_vertex = (n - 2) * 4;

	else if (n == 2 && x != 1 && y != 1)
		edge_except_vertex = 0;

	else	// n < 2. n�� 1�϶�
		edge_except_vertex = Colored_Two_exception(x, y);

	return edge_except_vertex;
}

// ���ΰ� 1�� �� : (���� - 2) * (���� - 2). �𼭸��� �ƴ� ����� 2���� ��ĥ�� ��
// ����, ���̰� ���� 1�� ���� ��������. ������ �� ���̸� ���� - 2 �ؼ� ������ ��
// ���� ���� ���� ���� �� 2�� �̻��� 1�� ��� 2���� ��ĥ�� ���� �������� ����
int Colored_Two_exception(int x, int y) {
	if (x != 1 && y != 1)
		return (x - 2) * (y - 2);

	else	// �� �� �ϳ��� 1�̶��
		return 0;
}