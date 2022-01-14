/*2021-05-12 아이 두 C 10일차 코딩뿌시기
난이도 상 문제 풀기 → 파스칼의 삼각형
숫자 n을 입력받고, n줄 만큼의 파스칼의 삼각형을 출력하는 프로그램을 작성해주세요.
- 파스칼의 삼각형이란?
    - 첫 번째 줄은 1입니다.
    - 그 다음 줄을 만들기 위해서는 바로 위의 숫자와 왼쪽 숫자를 더합니다.
    - 가장자리의 수의 경우, 숫자가 없는 자리는 0이라고 생각합니다.
    - 예시
        1
        1 1
        1 2 1
        1 3 3 1*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Pascal(int x);

int main() {
    int num;

    printf("파스칼 삼각형을 몇 줄 출력할까요? : ");
    scanf("%d", &num);

    Pascal(num);
    return 0;
}

void Pascal(int x) {
    int p[34][34]; // 2차원 배열, 최대 34줄까지 입력 가능
    // 34줄 넘어가면 - 값이 나와서 최대 34줄까지 입력 가능함

    for (int n = 0; n < x; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0 || k == n) {
                p[n][k] = 1;
            }
            else {
                p[n][k] = p[n - 1][k - 1] + p[n - 1][k];
            }
            printf("%d ", p[n][k]);
        }
        printf("\n");
    }
}