/*2021-05-18 아이 두 C 14일차 코딩뿌시기
난이도 중 문제 풀기 → 나머지 구하기
자연수 10개를 n으로 나눈 나머지를 구하고,
그 나머지 중 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성해주세요
- 조건 1 : 자연수 n을 먼저 입력받습니다.
- 조건 2 : 자연수 10개를 입력받습니다.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int cnt = 0, index = 0, n, arr[11] = { 0 };
	printf("나눌 수를 입력해주세요 : ");
	scanf("%d", &n);

	printf("\n자연수 10개를 입력해주세요\n");
	for (int i = 0; i < 10; i++) {
		printf("%d번째 숫자 : ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("\n입력된 자연수를 %d로 나눈 나머지\n", n);
	for (int i = 0; i < 10; i++) {
		arr[i] = arr[i] % n;
		printf("%d ", arr[i]);
	}

	while (index < 10) {
		for (int i = index + 1; i < 10; i++) {
			if (arr[index] == arr[i]) {
				cnt++;
				break;
			}
		}
		index++;
	}

	printf("\n\n총 %d개의 서로 다른 나머지들이 있습니다.", cnt);

	return 0;
}*/