/*2021-04-30 아이 두 C 문제풀이 5월과정 코딩뿌시기
난이도 중 : 두 수의 최대공약수
최대공약수는 여러 정수들이 있을 때, 그중 공통인 약수 중 가장 큰 값을 뜻합니다.
두 숫자를 입력받고 그 최대 공약수를 출력하는 프로그램을 작성해보세요.
- 조건 1 : 입력받는 숫자는 자연수입니다.
- 조건 2 : 함수를 활용하여 작성해주세요.*/

/*
#include <stdio.h>

void Input_Number(int x);
void GCD(int x, int y);	// 최대공약수 = Greatest Common Denominator(GCD)

int main(void)
{
	int a = 0, b = 0;

	printf("첫 번째 숫자를 입력하세요 : ");
	scanf_s("%d", &a);	// scanf를 Input_Number 함수 안에 넣으면 인식이 안됨
	Input_Number(a);	// 숫자가 자연수인지 확인하는 용도

	printf("두 번째 숫자를 입력하세요 : ");
	scanf_s("%d", &b);
	Input_Number(b);

	GCD(a, b);	// a와 b의 최대 공약수 구하는 함수

	return 0;
}

void Input_Number(int x)
{
	printf("입력하신 수는 ");

	if (x <= 0)
	{
		printf("조건 1(입력 받는 숫자는 자연수입니다.)를 어깁니다.");
		exit(-1);
	}

	printf("%d입니다.\n", x);
}

void GCD(int x, int y)
{
	int num;

	if (x < y)
	{
		if (y % x == 0)
			num = x;
		else	// 나누어 떨어지지 않으면 x와 y를 x로 나눈 나머지로 재귀 호출
			GCD(x, y % x);
	}

	else if (x == y)	// x와 y가 같은 경우 최대 공약수는 자기 자신
		num = x;

	else	// x > y
	{
		if (x % y == 0)
			num = y;
		else	// 나누어 떨어지지 않으면 y와 x를 y로 나눈 나머지로 재귀 호출
			GCD(y, x % y);
	}

	printf("두 수의 최대 공약수는 %d입니다.", num);
}
*/