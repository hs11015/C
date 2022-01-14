/*2021-05-07 아이두 C 7일차 코딩뿌시기
난이도 중 문제 풀기 → 간단한 사칙연산 계산기
문자열로 두 정수의 사칙연산을 입력받고, 그 결과를 출력하는 프로그램을 작성해주세요.
- 조건 1 : 연산의 종류는 더하기, 빼기, 곱하기, 나누기가 있습니다.
- 조건 2 : 나누기 연산 시에는 몫을 구합니다.
- 조건 3 : 함수를 활용하여 프로그램을 작성해주세요.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int calculation(char *arr);

int main() {
    char arr[100] = { 0 };

    printf("입력하세요 : ");
    for (int i = 0; i < 100; i++)
        scanf("%c", &arr[i]);

	return 0;
}

int calculation(char *arr)
{
    if (arr < 48 || arr > 57)   // ASCII code 47~57이 0~9

    switch (op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        return -1;
    }
}