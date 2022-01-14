/*2021-05-11 아이 두 C 9일차 코딩뿌시기
난이도 상 문제 풀기 → 기차 내 최대 인원
역이 4개 존재하는 기차가 있습니다. 타고 내리는 사람의 명 수가 주어졌을 때,
기차 내에 가장 많은 사람이 존재하는 경우의 사람 수를 출력하는 프로그램을 작성해주세요.
- 조건 1 : 처음 기차에 타고 있는 사람은 0명입니다.
- 조건 2 : 입력 값은 "(내리는 인원) (타는 인원)"으로 주어집니다.
           처음 기차에 타고 있는 사람이 0명이므로 처음 내리는 인원은 0명입니다.
- 조건 3 : 인원이 음수가 될 경우 오류 메시지를 출력합니다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int person_num = 0, person_in, person_out, person_max = 0;
    
    for (int i = 0; i < 4; i++) {
        printf("%d번째 역 : ", i + 1);
        scanf("%d %d", &person_out, &person_in);

        person_num -= person_out;   // 나간 사람
        if (person_num < 0) {
            printf("잘못된 입력입니다.");
            exit(-1);
        }

        person_num += person_in;    // 들어온 사람
        if (person_max < person_num)
            person_max = person_num;    // 최대 인원 저장
    }
    
    printf("종점까지 타고 있는 사람의 수 : %d\n", person_num);
    printf("기차에 탔던 최대 인원 : %d\n", person_max);
}