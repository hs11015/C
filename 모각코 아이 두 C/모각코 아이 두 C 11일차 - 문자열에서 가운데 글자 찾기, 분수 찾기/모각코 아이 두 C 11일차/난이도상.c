/*2021-05-13 아이 두 C 11일차 코딩뿌시기
난이도 상 문제 풀기 → 분수 찾기
아래 그림과 같이, 배열에 다음과 같은 분수가 적혀있습니다.
그림처럼 지그재그 형태로 순서를 정할 경우,
1/1은 첫 번째, 1/2는 두 번째 분수가 됩니다.
n번째 분수를 구하는 프로그램을 작성해보세요.*/

#define _CRT_SECURE_NO_WARNINGS
#define RIGHT	0
#define DOWN	1
#include <stdio.h>
#include <stdlib.h>

void fraction(int n);

int main(void) {
	int n;

	printf("몇 번째 분수의 값을 구할까요? : ");
	scanf("%d", &n);

	fraction(n);

	return 0;
}

void fraction(int n) {
	int fraction[2] = { 1, 1 };		// 각각 분자, 분모
	int maxnum = 1;
	char direction = RIGHT;

	for (int i = 1; i < n; ++i) {
		if (direction == RIGHT) {
			if (fraction[1] == maxnum) {
				maxnum++;
				fraction[1]++;	// 분모만 1 늘림
				direction++;	// direction == DOWN
				continue;
			}
			fraction[0]--;	// 오른쪽으로 갈수록 분자가 줄어들고
			fraction[1]++;	// 분모가 늘어남
		}
		else {	// direction == DOWN
			if (fraction[0] == maxnum) {
				maxnum++;
				fraction[0]++;	// 분자만 1 늘림
				direction--;	// direction == RIGHT
				continue;
			}
			fraction[0]++;	// 아래로 가면 분자가 늘어나고
			fraction[1]--;	// 분모는 줄어듦
		}
	}

	printf("\n%d번째 분수는 %d/%d 입니다.\n", n, fraction[0], fraction[1]);
}