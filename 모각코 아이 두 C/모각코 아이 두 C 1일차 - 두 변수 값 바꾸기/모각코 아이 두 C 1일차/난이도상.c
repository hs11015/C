/*2021-04-28 약수 개수가 짝수인 수. 코딩뿌시기
두 정수 a, b를 입력받고 그 사이 숫자 중 약수의 개수가 짝수인 수의 개수를 출력하는 프로그램
조건 1: 함수를 활용하세요
조건 2: 숫자 a, b 또한 범위에 포함됩니다.*/

#include <stdio.h>
#include <math.h>		// sqrt라는 제곱근 함수가 존재함

void sequence(int *px, int *py);
int divisor_even(int x);

int main(void)
{
	int a, b, sum = 0;
	printf("숫자 사이를 띄어쓰기로 구분해주고, 두 번째 숫자 입력 후 엔터 눌러주기\n\n");
	printf("정수 두 개를 입력해주세요: ");
	scanf_s("%d %d", &a, &b);

	sequence(&a, &b);		// 순서 맞춰주기

	for (int i = a; i <= b; i++)
	{
		sum += divisor_even(i);		// sum으로 divisor_even에서 나온 값 더하기
	}

	printf("%d", sum);

	return 0;
}

void sequence(int *px, int *py)
{
	if (*px > *py)		// x가 y보다 큰 경우
	{
		int ptr;
		ptr = *px;	// ptr에 px가 가리키는 변수 값 저장
		*px = *py;	// px가 가리키는 변수에 py가 가리키는 변수 값 저장
		*py = ptr;	// py가 가리키는 변수에 ptr(px) 값 저장
		// 매개변수를 사용해 x->y, y->x로 바꿔주기
	}
}

// 약수가 짝수인 경우는 약수가 홀수인 경우를 제외한 것.
// 약수가 홀수인 경우는 해당하는 수가 제곱수인 경우.
// 약수가 홀수인 경우는 only 제곱수인 경우
int divisor_even(int x)
{
	int a = sqrt(x);	// x의 양의 제곱근 (소수점 제거)

	if (x == a*a)		// 제곱근을 두 번 곱했을 때 같은 수가 나옴.
		return 0;		// 제곱근을 씌운 형태가 정수형이라는 뜻

	else				// 제곱근을 두 번 곱했을 때 다른 수가 나옴
		return 1;		// 제곱근을 씌운 형태가 실수라 소수점 아래를 지우면 값이 달라짐
}
