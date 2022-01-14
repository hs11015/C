/*2021-05-04 아이 두 C 5일차 코딩뿌시기
난이도 상 문제 풀기 → 문장 속 0부터 9까지의 개수
문자열을 입력받고, 그 문자열에 포함된 각 숫자의 개수를 출력하는 프로그램을 작성해보세요.
- 조건 1 : 문자열의 길이는 100을 초과하지 않습니다.
- 조건 2 :  0부터 9까지의 각 숫자가 몇 개인지 출력해야 합니다.*/

#include <stdio.h>

int main() {
	char sentence[101] = { 0, };	// 문자열의 길이는 100을 초과하지 않는다

	printf("문장을 입력하세요 : ");
	fgets(sentence, 101, stdin);	// 마지막 문자열 \0, 마지막에서 2번쨰 문자열 \n 저장

	int number[10] = { 0, };	// 마지막 문자열 \0
	for (int i = 0; i < 100; i++)
	{
		if (sentence[i] == '0')
			number[0]++;

		if (sentence[i] == '1')
			number[1]++;

		if (sentence[i] == '2')
			number[2]++;

		if (sentence[i] == '3')
			number[3]++;

		if (sentence[i] == '4')
			number[4]++;

		if (sentence[i] == '5')
			number[5]++;

		if (sentence[i] == '6')
			number[6]++;

		if (sentence[i] == '7')
			number[7]++;

		if (sentence[i] == '8')
			number[8]++;

		if (sentence[i] == '9')
			number[9]++;

		if (sentence[i] == '\n')
			break;
	}

	for (int j = 0; j < 10; j++)
	{
		printf("%d : %d개\n", j, number[j]);
	}
}