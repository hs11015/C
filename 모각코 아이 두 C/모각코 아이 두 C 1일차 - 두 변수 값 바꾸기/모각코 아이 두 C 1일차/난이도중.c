/*2021-04-28 �� ������ �� �ٲٱ�. �ڵ��ѽñ�
�� ���� a, b�� �Է¹ް� a,b�� ���� ���� �ٲ� ���
���� 1: �����Ϳ� �Լ��� Ȱ��
���� 2: ��½� printf("%d %d", a, b) ����ϱ�*/

#include <stdio.h>

void change(int x, int y);

int main(void)
{
	int a, b;
	printf("���� ���̸� ����� �������ְ�, �� ��° ���� �Է� �� ���� �����ֱ�\n\n");
	printf("���� �� ���� �Է����ּ���: ");
	scanf_s("%d %d", &a, &b);
	change(&a, &b);
	printf("%d %d", a, b);

	return 0;
}

void change(int *px, int *py)
{
	int ptr;
	ptr = *px;	// ptr�� px�� ����Ű�� ���� �� ����
	*px = *py;	// px�� ����Ű�� ������ py�� ����Ű�� ���� �� ����
	*py = ptr;	// py�� ����Ű�� ������ ptr(px) �� ����
	// �Ű������� ����� x->y, y->x�� �ٲ��ֱ�
}