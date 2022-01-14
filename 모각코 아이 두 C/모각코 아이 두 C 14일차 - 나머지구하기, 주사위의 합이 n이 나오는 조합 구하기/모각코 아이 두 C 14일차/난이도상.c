/*2021-05-18 아이 두 C 14일차 코딩뿌시기
난이도 상 문제 풀기 → 주사위 합이 n인 경우
각 면에 1부터 6까지의 숫자가 적힌 주사위 2개가 있습니다.
두 주사위의 값을 합했을 때 n이 나오는 경우를 모두 출력하는 프로그램을 작성해주세요.
- 조건 1 : 숫자 n의 범위는 2 ~ 12 사이입니다.
- 조건 2 : 입력은 숫자 n입니다.
- 조건 3 : 주사위는 무조건 2개 굴립니다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	printf("숫자를 입력해주세요 (2~12사이) : ");
	scanf("%d", &n);

	while (n < 2 || n > 12) {
		printf("숫자를 입력해주세요 (2~12사이) : ");
		scanf("%d", &n);
	}

	int temp = n % 6;
	for (int i = temp; i < 6 + 1; i++) {
		printf("%d %d\n", i, n - i);
	}
}