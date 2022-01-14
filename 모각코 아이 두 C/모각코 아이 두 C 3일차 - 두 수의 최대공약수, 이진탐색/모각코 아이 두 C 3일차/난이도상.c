/*2021-04-30 ���� �� C ����Ǯ�� 5������ �ڵ��ѽñ�
���̵� �� : ���� Ž��
���� Ž�� �˰����� ���� Ư�� ������ �� ��°�� �����ϴ��� ã�� ���α׷��� �ۼ�
- ���� 1 : �Է¹��� ������ ������ ���� �Է¹���.
- ���� 2 : �Է¹޴� ���ڵ��� �����̸� �迭�� �Է¹���. �̶� �� ���ڴ� ������������ �Է�.
- ���� 3 : �ߺ��� ���� �Է¹��� ����. ���� ã�� ���� �������� �ʴ´ٸ� -1 ���
- ���� 4 : �Լ��� Ȱ���� �ۼ�*/

#include <stdio.h>
#include <stdlib.h>

int binsearch(int a[], int key, int left, int right);

int main(void)
{
	int num;
	printf("�Է¹��� ������ ���� : ");
	scanf_s("%d", &num);

	int* a = (int*)malloc(num * sizeof(int));

	printf("\n�ߺ��Ǵ� ���ڴ� �Է� �Ұ����ϰ�, ������������ �Է����ּ���.\n");

	for (int i = 0; i < num; i++)
	{
		printf("%d��° ���� : ", i + 1);
		scanf_s("%d", &a[i]);
	}

	printf("\n�Է��Ͻ� �� : ");
	
	for (int i = 0; i < num; i++)
		printf("%d ", a[i]);

	int finding_num;
	printf("\nã����� ���� : ");
	scanf_s("%d", &finding_num);

	int idx = binsearch(a, finding_num, 0, num);
	
	if (idx == -1)
		printf("Ž�� ����! �ش��ϴ� ���ڰ� �����ϴ�.\n");
	else
		printf("Ž�� ����! �ش��ϴ� ���ڴ� %d��° �ε����� ����Ǿ� �ֽ��ϴ�.\n", idx);
}

// left�� right�� ���� �𸣰ھ left�� ù �ε��� ��, right�� ������ �ε��� ������ �����ϰ� ����
int binsearch(int a[], int key, int left, int right)
{
	int first = left;	// Ž�� ��� ���� �ε��� ��
	int last = right - 1;	// Ž�� ��� ������ �ε��� ��
	int mid;	// ���ؾ��ϴ� ��

	while (first <= last)
	{
		mid = (first + last) / 2;	// Ž�� ����� �߾��� ã�´�

		if (key == a[mid])	// �߾ӿ� ����� ���� Ÿ���̶��
			return mid;		// Ž�� �Ϸ�

		else	// Ÿ���� �ƴ϶�� Ž�� ����� ������ ���δ�
		{
			if (key < a[mid])		// ��Һ񱳸� ���� ���� ������ ����
				last = mid - 1;		// mid ���� ã�� ���� �ƴ϶�� ���� �˾����� �׺��� 1 ���� index���� Ȯ���ص� ��
			
			else	// key > a[mid]
				first = mid + 1;	// mid ���� ã�� ���� �ƴ϶�� ���� �˾����� �׺��� 1 ū index���� Ȯ���ص� ��
		}

		return -1;	// ã�� ������ �� ��ȯ�Ǵ� �� -1 (���� 3 ��)
	}
}