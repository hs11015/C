/*2021-05-14 아이 두 C 12일차 코딩뿌시기
난이도 상 문제 풀기 → 피보나치 수열
숫자를 입력받고, 숫자 3자리마다 콤마를 찍어 출력하는 프로그램을 작성해주세요.
피보나치 수열은 수학에서 아래의 점화식으로 정의되는 수열입니다.
피보나치 수는 0 번째 숫자인 0과 첫 번째 숫자인 1로 시작하며,
두 번째 숫자는 0 번째 수와 첫 번째 수의 합인 0 + 1 = 1,
세 번째 숫자는 첫 번째 수와 두 번째 수의 합인 1 + 1 = 2 의 값을 가집니다.
숫자 n을 입력받아 피보나치 수열의 n번째 숫자를 출력하는 프로그램을 작성해보세요.
- 조건 1 : 입력받는 숫자 n은 2 이상의 자연수입니다.
- 조건 2 : n > 2인 피보나치 수에서, **n번째 수 = (n - 2)번째 수 + (n - 1)번째 수** 입니다.
- 조건 3 : 피보나치 수열을 나열하면 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... 입니다. */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int Fibo(int n);

int main(void)
{
	int num;
	printf("몇 번째 피보나치 수를 구할까요? : ");
	scanf("%d", &num);

	for (int i = 1; i < num + 1; i++)
		printf("%d ", Fibo(i));

	printf("\n%d번째 피보나치 수 : %d", num, Fibo(num));

	return 0;
}

int Fibo(int n)
{
	if (n == 0)
		return 0;
	else if ((n == 1) || (n == 2))
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}