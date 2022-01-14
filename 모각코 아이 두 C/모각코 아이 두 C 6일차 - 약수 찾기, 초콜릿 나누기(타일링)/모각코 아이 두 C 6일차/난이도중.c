/*2021-05-06 아이 두 C 6일차 코딩뿌시기
난이도 중 문제 풀기 → 약수 찾기
아래 조건을 참고하여, 숫자 n을 입력받고 해당 숫자가 2, 3, 5를 약수로 가지는 상황에 따라 A~D를 출력하는 프로그램을 작성해보세요.
- 조건 1 : 2, 3, 5 모두 약수로 가지는 경우 A를 출력합니다
- 조건 2 : 2, 3, 5 중 두 숫자만을 약수로 가지는 경우 B를 출력합니다.
- 조건 3 : 2 ,3, 5 중 한 숫자만을 약수로 가지는 경우 C를 출력합니다.
- 조건 4 : 2, 3, 5 중 아무 숫자도 약수로 가지지 않는 경우 D를 출력합니다.*/

/*
#include <stdio.h>

void printing_program(int num);

int main()
{
    int num;
    scanf_s("%d", &num);
    printing_program(num);
    return 0;
}

void printing_program(int num)
{
    if (num % 2 == 0 && num % 3 == 0 && num % 5 == 0)
        printf("A\n");

    else if (num % 2 == 0 && num % 3 == 0 || num % 3 == 0 && num % 5 == 0 || num % 5 == 0 && num % 2 == 0)
        printf("B\n");

    else if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0)
        printf("C\n");

    else
        printf("D\n");

    return;
}
*/