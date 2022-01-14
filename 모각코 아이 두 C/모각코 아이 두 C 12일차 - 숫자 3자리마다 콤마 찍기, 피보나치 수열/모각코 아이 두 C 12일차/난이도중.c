/*2021-05-14 아이 두 C 12일차 코딩뿌시기
난이도 중 문제 풀기 → 숫자 3자리 마다 콤마 찍기
숫자를 입력받고, 숫자 3자리마다 콤마를 찍어 출력하는 프로그램을 작성해주세요.
- 조건 1 : 4자리 미만의 숫자라면 콤마를 찍지 않습니다.
- 조건 2 : 숫자의 길이는 20을 넘지 않습니다.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void Program_Comma(char* a);

int main() {
	char num[21] = { 0 };	// 20자리를 넘지 않으므로 index 19까지 입력, 20 = \n, 21 = \0
	printf("숫자를 입력해주세요 : ");
	fgets(num, 21, stdin);

	Program_Comma(num);

	return 0;
}

void Program_Comma(char* a) {
	int length = strlen(a) - 1, first_comma = length % 3 - 1, i;
	
	if (length < 4) {
		for (i = 0; i < length + 1; i++)
			printf("%c", a[i]);
	}

	else {	// (length >= 4)
		for (i = 0; i < first_comma; i++) {
			printf("%c", a[i]);

			if ((i - first_comma) % 3 == 0)
				printf(",");
		}

		for (i = first_comma; i < length + 1; i++) {
			printf("%c", a[i]);

			if ((i - first_comma) % 3 == 0 && length-1 != i)
				printf(",");
		}
	}
}
*/