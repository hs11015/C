/*2021-05-17 아이 두 C 13일차 코딩뿌시기
난이도 상 문제 풀기 → 물 이동시키기
- 조건 1 : 숫자 n은 정수 형태로만 입력됩니다.
- 조건 2 : 양동이로 모두 옮겨지지 않을 경우 -1을 출력합니다.
- 조건 3 : 8리터를 옮겨야 하는 경우 5리터 + 3리터와 같은 형식으로
			이동이 가능하므로 횟수는 총 2회입니다.
- 조건 4 : 양동이는 가득 채워서 사용해야 합니다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit 함수

void Moving(int a);

int main() {
	int n;
	printf("다른 용기에 옮겨야 하는 물의 양(L) : ");
	scanf("%d", &n);

	Moving(n);

	return 0;
}

void Moving(int a) {
	int count_five = 0, count_three = 0, count_sum = 0, num_temp = 0, num = a;

	while (num != 0) {
		if (num % 5 == 0) {	// 5를 먼저 고려해줌으로써 최소 횟수 구하기 가능
			num -= 5;
			count_five++;
		}

		else {	// num % 5 != 0
			num_temp = num % 5;

			if ((num_temp % 3 == 0) || (num % 3 == 0)) {
				num -= 3;
				count_three++;
			}

			else {	// num % 3 != 0, 5와 3 모두 나누어 떨어지지 않음.
				printf("양동이로 모두 옮겨지지 않는다.\n-1");
				exit(-1);
			}
		}
	}

	count_sum = count_five + count_three;
	printf("5L 양동이로 옮긴 횟수 : %d\n", count_five);
	printf("3L 양동이로 옮긴 횟수 : %d\n", count_three);
	printf("총 양동이로 옮긴 최소 횟수 : %d\n", count_sum);
}