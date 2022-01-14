/*2021-05-17 아이 두 C 13일차 코딩뿌시기
난이도 중 문제 풀기 → 문제 점수 계산
- 조건 1 : O일 경우의 점수는 그 때까지의 연속된 O의 개수를 점수로 가집니다
(ex. O → 1점, OOO → 1 + 2 + 3 = 6점)
- 조건 2 : X일 경우의 점수는 0점 입니다.
- 조건 3 : 문제의 개수는 10개입니다.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Counting(char* arr);

int main() {
	char arr[11] = { 0, };	// index 10 = \n, index 11 = \0

	printf("문제의 정답을 OX 형태로 입력하세요 : ");
	scanf("%s", arr);

	Counting(arr);

	return 0;
}

void Counting(char* arr) {
	int count = 0, sum = 0;
	
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 'O') {
			count++;
			sum += count;
		}

		else if (arr[i] == 'X')
			count = 0;

		else {	// OX로 나타나지않은 경우
			printf("OX 형태로 나타나지 않았습니다.\n");
			exit(-1);
		}
	}

	printf("총 합 : %d", sum);
}
*/