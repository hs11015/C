/*모각코 아이두C 3월과정 8일차 코딩뿌시기
두 개의 문자열을 입력 받은 후 두 문자열 중 긴 문자열의 길이를 출력
단, 두 문자열의 길이가 같으면, 두 문자열을 하나의 문자열로 합쳐서 출력
공백도 문자열의 길이에 포함하기*/

#define _CRT_SECURE_NO_WARNINGS   // strcpy와 strcat 쓸 때 필요함
#include <stdio.h>
#include <string.h>    // 문자열 함수 헤더파일
#include <stdlib.h>    // 동적 함수 헤더파일
#pragma warning(disable : 6387)

void ComparingSentenceLength(char* ptr1, char* ptr2); // 두 문자열 비교

int main()
{
	char buffer1[100] = { 0 };
	char buffer2[100] = { 0 };
	char* sentence1 = buffer1;
	char* sentence2 = buffer2;

	printf("1번째 문자열을 입력하세요 : ");
	scanf("%[^\n]s", sentence1);
	getchar();
	printf("%s\n", sentence1);

	printf("2번째 문자열을 입력하세요 : ");
	scanf("%[^\n]s", sentence2);
	getchar();
	printf("%s\n", sentence1);

	ComparingSentenceLength(sentence1, sentence2);

	return 0;
}

void ComparingSentenceLength(char* ptr1, char* ptr2) //결과 자료값 char
{
	char ptr3[200] = { 0, };

	printf("문자열 1 길이 : %d\n문자열 2 길이 : %d\n", strlen(ptr1), strlen(ptr2));

	if (strlen(ptr1) > strlen(ptr2))
		printf("둘 중 더 긴 문자열은 다음입니다.\n%s", ptr1);

	else if (strlen(ptr1) < strlen(ptr2))
		printf("둘 중 더 긴 문자열은 다음입니다.\n%s", ptr2);

	else  //strlen(ptr1) = strlen(ptr2) ptr1, ptr2의 길이가 같음
	{
		if (strcmp(ptr1, ptr2) == 0)  //ptr1과 ptr2 문자열이 같음
			printf("중복된 문자열이므로 한 번만 출력합니다.\n%s", ptr1);
		//ptr1 대신 ptr2여도 상관 없음

		else  //ptr1과 ptr2에 입력된 문자열이 같지 않을 경우
		{
			strcpy(ptr3, ptr1);  //ptr1을 ptr3에 복사(채워넣기)
			strcat(ptr3, ptr2);  //ptr2를 ptr3뒤에 붙임
			printf("%s", ptr3);
		}
	}
}