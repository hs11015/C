/*2021-04-28 두 변수의 값 바꾸기. 코딩뿌시기
두 정수 a, b를 입력받고 a,b의 값을 서로 바꿔 출력
조건 1: 포인터와 함수를 활용
조건 2: 출력시 printf("%d %d", a, b) 사용하기*/

#include <stdio.h>

void change(int x, int y);

int main(void)
{
	int a, b;
	printf("숫자 사이를 띄어쓰기로 구분해주고, 두 번째 숫자 입력 후 엔터 눌러주기\n\n");
	printf("정수 두 개를 입력해주세요: ");
	scanf_s("%d %d", &a, &b);
	change(&a, &b);
	printf("%d %d", a, b);

	return 0;
}

void change(int *px, int *py)
{
	int ptr;
	ptr = *px;	// ptr에 px가 가리키는 변수 값 저장
	*px = *py;	// px가 가리키는 변수에 py가 가리키는 변수 값 저장
	*py = ptr;	// py가 가리키는 변수에 ptr(px) 값 저장
	// 매개변수를 사용해 x->y, y->x로 바꿔주기
}