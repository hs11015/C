/*2021-05-07 아이두 C 7일차 코딩뿌시기
난이도 상 문제 풀기 → 올바른 괄호
올바른 괄호란 '('로 시작하고 ')'로 닫히는 괄호를 뜻합니다.
올바른 괄호를 사용하였는지 판별하는 프로그램을 작성해주세요.*/

/*
#include <stdio.h>
#include <string.h>

int i = 0, temp = 0;

void brk(char* str);

int main() {
	char arr[100] = { 0, };
	fgets(arr, 101, stdin);
	brk(arr);
	return 0;
}

void brk(char* str) {
	if (str[i] == '(')
		temp++;

	if (str[i] == ')')
		temp--;

	if (i < strlen(str)) {
		if (temp < 0)	// 여는 괄호가 없는데 닫는 괄호가 있는 경우
			printf("잘못된 괄호입니다.");
		else	// 여는 괄호가 먼저 나오고 닫는 괄호가 나오는 경우
		{
			i++;
			brk(str);
		}
	}

	else	// i >= strlen(str)
	{
		if (temp == 0)
			printf("올바른 괄호입니다.");

		else	// temp != 0
			printf("잘못된 괄호입니다.");
	}
}
*/