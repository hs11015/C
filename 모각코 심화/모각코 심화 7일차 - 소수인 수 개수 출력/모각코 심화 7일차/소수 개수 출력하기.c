/* 모각코 아이 두 C 7일차 코딩뿌시기
임의의 숫자 N개 입력 받고 그 중 소수인 수의 개수 출력*/

#include <stdio.h>
#include <stdlib.h>

int getPrime(int* ptr, int size)
{
	int prime_count = 0;
	int* arr = (int*)calloc(1, sizeof(int));   // calloc으로 동적할당
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
			arr = (int*)realloc(arr, prime_count * sizeof(int));    // realloc으로 재배정
		}
	}

	printf("입력받은 수들 중 소수는 아래 %d개입니다.", prime_count);

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
			printf("%d번째로 입력하신 수 %d는 소수가 맞습니다.\n", i + 1, ptr[i]);
			prime_count += 1;
		}

		else
			printf("%d번째로 입력하신 수 %d는 소수가 아닙니다.\n", i + 1, ptr[i]);
	}

	printf("\n따라서 입력하신 정수 중 소수는 %d개입니다.\n", prime_count);
}
*/


int main()
{
	int size;
	printf("몇 개의 정수를 입력하실 건가요? : ");
	scanf_s("%d", &size);
	int* arr = (int*)malloc(size * sizeof(size));

	for (int i = 0; i < size; i++)
	{
		printf("%d번째 숫자 : ", i + 1);
		scanf_s("%d", &arr[i]); // 정수만 가능!!
	}

	printf("\n입력하신 수들이 소수인지 판별하겠습니다.\n\n");
	getPrime(arr, size);

	free(arr);

	return 0;
}