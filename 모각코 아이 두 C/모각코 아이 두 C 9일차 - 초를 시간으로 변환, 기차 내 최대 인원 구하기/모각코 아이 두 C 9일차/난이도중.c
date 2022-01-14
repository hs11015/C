/*2021-05-11 아이 두 C 9일차 코딩뿌시기
난이도 중 문제 풀기 → 초 시간 변환
초 단위의 시간을 입력받고, 분, 시간으로 변환하여 출력하는 프로그램을 작성해주세요.
- 조건 1 : 사용하지 않는 단위의 시간은 출력하지 않습니다.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void time(int sec);

int main() {
	int sec = 0;
	printf("초 단위의 시간을 입력하세요 : ");
	scanf("%d", &sec);
	time(sec);
	return 0;
}

void time(int sec) {
	int hour = sec / 3600;
	int minute = (sec - hour * 3600) / 60;
	int second = sec % 60;
	printf("%d시간 %d분 %d초", hour, minute, second);
}
*/