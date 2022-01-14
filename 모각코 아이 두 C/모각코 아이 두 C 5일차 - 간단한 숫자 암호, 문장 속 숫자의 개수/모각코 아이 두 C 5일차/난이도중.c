/*2021-05-04 아이 두 C 5일차 코딩뿌시기
난이도 중 문제 풀기 → 간단한 숫자 암호
두 수가 주어졌을 때, 곱셈, 덧셈, 뺄셈을 통해 만들어지는 숫자 암호가 있습니다.
조건을 참고하여 숫자 암호의 답을 출력하는 프로그램을 작성해보세요.
- 조건 1 : 정수 두 개를 입력받습니다.
- 조건 2 : 숫자 a, b가 있을 때 암호의 정답은 (a*b)(a+b)(a-b)를 차례로 출력한 값입니다.
- 조건 3 : 함수를 사용하여 프로그램을 작성해주세요.*/

/*
#include <stdio.h>

int step_2_first(int x, int y)
{
	return x * y;
}

int step_2_second(int x, int y)
{
	return x + y;
}

int step_2_third(int x, int y)
{
	return x - y;
}

int main() {
	int a, b;
	
	printf("정수 a를 입력하세요 : ");
	scanf_s("%d", &a);
	printf("정수 b를 입력하세요 : ");
	scanf_s("%d",&b);

	printf("%d%d%d", step_2_first(a,b), step_2_second(a,b), step_2_third(a,b));
}
*/