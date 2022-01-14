/*2021-05-20 아이 두 C 15일차 코딩뿌시기
난이도 상 문제 풀기 → 색칠한 블록
정육면체 모양의 블록을 쌓아 만든 직육면체가 있습니다. 직육면체의 겉면에만 색칠을 할 때,
2개의 면에만 색칠이 된 정육면체는 몇 개인지 구하는 프로그램을 작성해보세요.
- 조건 1 : 직육면체의 가로, 세로, 높이의 블록 개수를 입력받아야 합니다.
- 조건 2 : 그 직육면체에서 2개의 면만 색칠이 된 블록을 구해야합니다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Colored_Two(int n, int x, int y);
int Colored_Two_exception(int x, int y);

int main() {
	int width, length, height, sum_two;	// 가로, 세로, 높이를 구하기

	printf("가로 세로 높이를 입력하세요 : ");
	scanf("%d %d %d", &width, &length, &height);

	// width 기준, length 기준, heith 기준을 모두 더한 값
	sum_two = Colored_Two(width, length, height) + Colored_Two(length, height, width) + Colored_Two(height, width, length);

	printf("총 2개의 면에 색칠된 정육면체의 개수 : %d", sum_two);

	return 0;
}

// 가로 세로 높이 모두 2 이상일 때
// 직육면체의 꼭짓점 블록 : 3개의 색칠된 면.
// 꼭짓점이 아니지만 모서리인 블록 : 2개의 색칠된 면
// 면에 있는 블록 : 1개의 색칠된 면, 속에 있는 블록 : 0개의 색칠된 면
int Colored_Two(int n, int x, int y) {
	int edge_except_vertex = 0;

	if (n > 2 && x != 1 && y != 1)
		edge_except_vertex = (n - 2) * 4;

	else if (n == 2 && x != 1 && y != 1)
		edge_except_vertex = 0;

	else	// n < 2. n이 1일때
		edge_except_vertex = Colored_Two_exception(x, y);

	return edge_except_vertex;
}

// 가로가 1일 때 : (세로 - 2) * (높이 - 2). 모서리가 아닌 블록이 2개의 색칠된 면
// 세로, 높이가 각각 1일 때도 마찬가지. 나머지 두 길이를 각각 - 2 해서 곱해준 값
// 만약 가로 세로 높이 중 2개 이상이 1일 경우 2개의 색칠된 면이 존재하지 않음
int Colored_Two_exception(int x, int y) {
	if (x != 1 && y != 1)
		return (x - 2) * (y - 2);

	else	// 둘 중 하나라도 1이라면
		return 0;
}