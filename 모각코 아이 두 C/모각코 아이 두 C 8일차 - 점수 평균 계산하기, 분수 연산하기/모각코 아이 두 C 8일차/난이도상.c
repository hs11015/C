/*2021-05-10 아이두C 8일차 코딩뿌시기
난이도 상 문제 풀기 → 분수 연산하기
두 분수의 연산을 입력받고, 그 값을 계산하여 출력하는 프로그램을 작성해주세요.
- 조건 1 : 분모가 0인 경우는 고려하지 않습니다.
- 조건 2 : 계산이 끝난 분수의 값은 기약분수의 형태로 출력해주세요.*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int calculation(char* str);

int main(void)
{
    char str[100];
    scanf("%s", str);
    calculation(str);
    return 0;
}

int calculation(char* str)
{
    int j = 0, oper = 4, num[4] = { 0 };
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') {
            num[j] = num[j] * 10 + (str[i] - '0');
        }
        else if (str[i] == '+') {
            oper = 1;
            j++;
        }
        else if (str[i] == '-') {
            oper = 2;
            j++;
        }
        else if (str[i] == '*') {
            oper = 3;
            j++;
        }
        else if (str[i] == '/') {
            j++;
        }
        else {
            oper = 5;
        }
    }

    if (num[2] != 0 && num[3] != 0) // 분모가 0이면 안됨
    {
        int deno, nume; // 분모, 분자

        switch (oper) {
        case 1:
            nume = ((num[0] * num[3]) + (num[2] * num[1]));
            deno = num[1] * num[3];
            break;
        case 2:
            nume = ((num[0] * num[3]) - (num[2] * num[1]));
            deno = num[1] * num[3];
            break;
        case 3:
            nume = num[0] * num[2];
            deno = num[1] * num[3];
            break;
        case 4:
            nume = num[0] * num[3];
            deno = num[1] * num[2];
            break;
        default:
            break;
        }

        if (deno < nume) {
            for (int i = 2; i <= deno; i++) {
                if (deno % i == 0 && nume % i == 0) {
                    deno /= i;
                    nume /= i;
                }
            }
        }
        else {
            for (int i = 2; i <= nume; i++) {
                if (deno % i == 0 && nume % i == 0) {
                    deno /= i;
                    nume /= i;
                }
            }
        }

        printf("%d/%d", nume, deno);
    }
    return;
}