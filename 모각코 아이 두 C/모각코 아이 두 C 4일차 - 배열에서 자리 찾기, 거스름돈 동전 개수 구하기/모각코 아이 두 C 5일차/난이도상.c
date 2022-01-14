/*2021-05-03 코딩뿌시기 아이두C 문제풀이 5월과정
난이도 상 문제 풀기 → 거스름돈 동전의 개수
지불 금액과 물건의 가격을 차례대로 입력받고, 거스름돈을 동전으로만 받을 경우,
동전을 최소 몇 개 받을지를 출력하는 프로그램을 작성해주세요.
- 조건 1 : 물건의 가격이 지불 금액보다 큰 경우는 고려하지 않습니다.
- 조건 2 : 동전의 종류는 500, 100, 50, 10이 존재합니다.
- 조건 3 : 모든 금액에서 일의 자리 숫자는 0입니다.*/

#include <stdio.h>

void change_sum(int money_give, int money_need_to_pay);	// 지불 금액과 물건 가격을 입력하면 거스름돈 출력

int main(void)
{
	int a, b;

	printf("지불 금액을 입력하세요 : ");
	scanf_s("%d", &a);

	printf("물건의 가격을 입력하세요 : ");
	scanf_s("%d", &b);

	change_sum(a, b);	// change_sum(지불금액, 물건가격)

	return 0;
}

void change_sum(int money_give, int money_need_to_pay)
{
	int change = money_give - money_need_to_pay;	// 거스름돈 = 지불금액 - 물건가격
	
	// 전체 거스름돈에서 500으로 나눈 몫 = 500원 개수
	int change_numOf_500 = change / 500;
	// 전체 거스름돈에서 500으로 나눈 나머지를 100으로 나눈 몫 = 100원 개수
	int change_numOf_100 = (change % 500) / 100;
	// 전체 거스름돈에서 500으로 나눈 나머지를 100으로 나눈 나머지를 50으로 나눈 몫 = 50원 개수
	int change_numOf_50 = ((change % 500) % 100) / 50;
	// 전체 거스름돈에서 500으로 나눈 나머지를 100으로 나눈 나머지를 50으로 나눈 나머지를 10으로 나눈 몫 = 10원 개수
	int change_numOf_10 = (((change % 500) % 100) % 50) / 10;

	// 전체 거스름돈의 동전 개수 = 500원 개수 + 100원 개수 + 50원 개수 + 10원 개수
	int change_numof_coin = change_numOf_500 + change_numOf_100 + change_numOf_50 + change_numOf_10;

	printf("500원 개수 : %d\n100원 개수 : %d\n50원 개수 : %d\n10원 개수 : %d\n", change_numOf_500, change_numOf_100, change_numOf_50, change_numOf_10);

	printf("거스름돈으로 받는 동전의 개수 : %d", change_numof_coin);
}