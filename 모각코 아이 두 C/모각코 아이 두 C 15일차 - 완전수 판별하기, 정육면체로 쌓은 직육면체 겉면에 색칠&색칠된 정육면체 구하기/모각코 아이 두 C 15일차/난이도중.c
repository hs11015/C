/*2021-05-20 아이 두 C 15일차 코딩뿌시기
난이도 중 문제 풀기 → 완전수 판별하기
완전수란 자신을 제외한 약수의 합이 자신이 되는 수를 뜻합니다.
예를 들어 숫자 6은 자신을 제외한 약수가 1, 2, 3이고 1+2+3은 6이므로 완전수입니다.
완전수를 출력하는 프로그램을 작성해보세요.
- 조건 1 : 자연수를 입력받고 해당 숫자가 완전수인지 판별하는 내용을 출력합니다.*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Perfect_number(int n);

int main() {
	int num;
	printf("완전수인지 확인할 정수를 입력해주세요 : ");
	scanf("%d", &num);

	Perfect_number(num);

	return 0;
}

void Perfect_number(int n) {
	int sum = 0;

	// n을 포함하지 않는 이유는 자신을 제외한 약수의 합을 구해야하기 때문임
	for (int i = 1; i < n; i++) {
		if (n % i == 0)	// n을 i로 나눴을 떄 나누어떨어지면 그 i는 n의 약수
			sum += i;	// n의 약수의 합을 구해야하기 때문에 sum += i 써준다.
	}

	if (sum == n)
		printf("%d은(는) 완전수입니다.", n);

	else {	// sum != n

		printf("자신을 제외한 약수의 합 : %d\n", sum);
		printf("%d은(는) 완전수가 아닙니다.", n);
	}
}
*/