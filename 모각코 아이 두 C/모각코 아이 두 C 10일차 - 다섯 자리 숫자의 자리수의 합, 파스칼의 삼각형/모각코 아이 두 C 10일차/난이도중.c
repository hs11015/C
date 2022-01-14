/*2021-05-12 아이 두 C 10일차 코딩뿌시기
난이도 중 문제 풀기 → 다섯 자리 숫자의 자리수의 합
다섯 자리 수를 입력받고, 입력받은 숫자의 각 자리수의 합을 구하는 프로그램을 작성해주세요.
- 조건 1 : 12345의 자리수의 합은 1+2+3+4+5이므로 15입니다.
- 조건 2 : 다섯 자리 수는 정수입니다.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calculation(int x);

int main() {
	int num;

	printf("다섯 자리 수를 입력하세요 : ");
	scanf("%d", &num);

	printf("다섯 자리 수의 합 : %d",calculation(num));
}

int calculation(int x) {
	int first, second, third, fourth, fifth;
	first = x / 10000;
	second = x / 1000 - first * 10;
	third = x / 100 - first * 100 - second * 10;
	fourth = x / 10 - first * 1000 - second * 100 - third * 10;
	fifth = x % 10;

	return first + second + third + fourth + fifth;
}
*/