/*2021-05-13 아이 두 C 11일차 코딩뿌시기
난이도 중 문제 풀기 → 가운데 글자 찾기
문자열을 입력받고, 그 문자열의 가운데 글자를 출력하는 프로그램을 작성해보세요.
- 조건 1 : 문자열의 길이는 20을 넘지 않습니다.
- 조건 2 : 문자열의 길이가 짝수인 경우 가운데 글자 2개를 출력합니다.
- 조건 3 : 문자열의 길이가 홀수인 경우 가운데 글자 1개를 출력합니다.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void middle(char str[], int len);

int main(void) {
	char str[21];	// 조건 1, 문자열의 길이는  20을 넘지 않는다.

	printf("문자열을 입력하세요 : ");
	scanf("%s", str);

	middle(str, strlen(str));

	return 0;
}

void middle(char str[], int len) {
	printf("문자열 %s의 가운데 글자 : ", str);

	if (len % 2 == 1)	// 조건 3, 문자열의 길이가 홀수인 경우 가운데 글자 1개 출력
		printf("%c", str[len / 2]);
	else	// 조건 2, 문자열의 길이가 짝수인 경우 가운데 글자 2개 출력
		printf("%c%c", str[len / 2 - 1], str[len / 2]);
}
*/