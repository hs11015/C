/* ���� ���� �� C 7���� �ڵ��ѽñ�
������ ���� N�� �Է� �ް� �� �� �Ҽ��� ���� ���� ���*/

#include <stdio.h>
#include <stdlib.h>

int getPrime(int* ptr, int size)
{
	int prime_count = 0;
	int* arr = (int*)calloc(1, sizeof(int));   // calloc���� �����Ҵ�
	int cnt = 0;

	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 1; j <= ptr[i]; j++)
		{
			if (ptr[i] % j == 0)
				count++;
		}

		if (count == 2)
		{
			arr[prime_count] = ptr[i];
			prime_count += 1;
			arr = (int*)realloc(arr, prime_count * sizeof(int));    // realloc���� �����
		}
	}

	printf("�Է¹��� ���� �� �Ҽ��� �Ʒ� %d���Դϴ�.", prime_count);

	for (int k = 0; k < prime_count; k++)
	{
		printf("%5d", arr[k]);
		cnt++;
		if ((cnt % 5) == 0)
			printf("\n");
	}

	free(arr);
}
/*
int getPrime(int* ptr, int size)
{
	int prime_count = 0;
	int* arr = (int*)calloc(1, sizeof(int));
	int cnt = 0;

	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 1; j <= ptr[i]; j++)
		{

			if (ptr[i] % j == 0)
				count++;
		}

		if (count == 2)
		{
			printf("%d��°�� �Է��Ͻ� �� %d�� �Ҽ��� �½��ϴ�.\n", i + 1, ptr[i]);
			prime_count += 1;
		}

		else
			printf("%d��°�� �Է��Ͻ� �� %d�� �Ҽ��� �ƴմϴ�.\n", i + 1, ptr[i]);
	}

	printf("\n���� �Է��Ͻ� ���� �� �Ҽ��� %d���Դϴ�.\n", prime_count);
}
*/


int main()
{
	int size;
	printf("�� ���� ������ �Է��Ͻ� �ǰ���? : ");
	scanf_s("%d", &size);
	int* arr = (int*)malloc(size * sizeof(size));

	for (int i = 0; i < size; i++)
	{
		printf("%d��° ���� : ", i + 1);
		scanf_s("%d", &arr[i]); // ������ ����!!
	}

	printf("\n�Է��Ͻ� ������ �Ҽ����� �Ǻ��ϰڽ��ϴ�.\n\n");
	getPrime(arr, size);

	free(arr);

	return 0;
}