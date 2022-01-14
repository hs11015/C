/*20201-04-29 아이두C 2일차 코딩뿌시기
난이도 중 문제풀기 : 문자열 덧셈식 계산
조건 1: 연산의 종류는 덧셈만 존재합니다
조건 2: 입력받는 문자열의 길이는 50을 넘지 않습니다
조건 3: 숫자의 개수는 최대 10개이며 모두 정수입니다*/


#include <stdio.h>

int main(void)
{
    char str[50];   // 문자열 길이는 50을 넘지 않는다

    gets(str);  // scanf 대신 gets를 사용해봄
    printf("str : %s\n", str);

    int  j = 0, temp = 0, count = 0, total = 0;
    while (1)
    {
        if (str[j] == '\0')
        {
            total += temp;      // 마지막. +가 없는 맨 마지막에 더한 수를 합해줌
            break;
        }

        printf("[%c]", str[j]);     // 한 글자씩 입력되었음을 보여주려고, 어디서 오류났는지 알 수 있음

        if (str[j] >= 48 && str[j] <= 57)     // int형으로 0~9 = ascii code 형으로 48~57
            temp = temp * 10 + str[j] - 48;    // 만약 1, 0이 연달아 나오면 10으로 만들어줌

        else if (str[j] == '+')
        {
            total += temp;
            temp = 0;   // temp 초기화
            count++;    // +가 나온 횟수 세어줌
        }

        j++;

        if (j > 50)
        {
            printf("\n\n조건 2(입력받는 문자열의 길이는 50을 넘지 않습니다)를 어깁니다!\n");
            return 0;
        }

        if (count > 9)
        {
            printf("\n\n조건 3(숫자의 개수는 최대 10개)를 어깁니다!\n");
            return 0;
        }

        if (str[j] == '.')      // .이 찍히면 실수
        {
            printf("\n\n조건 3(숫자는 모두 정수)를 어깁니다!\n");
            return 0;
        }
    }

    printf("\n\n총 합 : %d\n", total);

    return 0;
}
