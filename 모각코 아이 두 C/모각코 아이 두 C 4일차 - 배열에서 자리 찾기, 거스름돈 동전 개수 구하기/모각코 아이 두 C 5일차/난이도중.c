/*2021-05-03 코딩뿌시기 아이두C 문제풀이 5월과정
난이도 중 문제 풀기 → 배열에서 자리 찾기
오름차순으로 정렬된 숫자 5개를 저장하는 배열을 선언한 후에 숫자 하나를 더 입력받아,
추가로 입력된 숫자가 배열 내에 오름차순으로 제 자리를 찾아 출력되는 프로그램을 작성해주세요.
- 조건 1 : 각 숫자는 정수입니다.
- 조건 2 : 배열은 오름차순으로 입력받습니다.*/


#include <stdio.h>

void Sequence(int arr[]);	// 오름차순으로 정렬

int main(void)
{
	int arr[6] = { 0 };		// 숫자 5개 입력하고 추후 1개 추가로 입력받기 때문에 6+1개(맨 마지막 \0 위해 비워둠)

	for (int i = 0; i < 5; i++)	// 숫자 5개 입력
	{
		printf("%d번째 숫자를 입력하세요 : ", i+1);
		scanf_s("%d", &arr[i]);
	}

	printf("새로 입력하실 숫자 : ");
	scanf_s("%d", &arr[5]);	// 새로 입력받는 6번째 숫자

	printf("입력하신 숫자의 순서 : ");
	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i]);

	Sequence(arr);			// 오름차순으로 정렬

	printf("\n오름차순으로 정렬 후 : ");
	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i]);
}

void Sequence(int arr[])
{
	int i, j, temp;

	for (i = 0; i < 6; i++)
		for (j = 0; j < 5;j++)
			if (arr[j] > arr[j + 1])	// 만약 현재 인덱스의 크기 > 이후 인덱스의 크기
			{
				// 오른차순으로 정렬하기 위해 순서 바꾸기
				temp = arr[j];			// temp에 현재 인덱스 값 저장
				arr[j] = arr[j + 1];	// 현재 인덱스 값에 이후 인덱스 값 대입
				arr[j + 1] = temp;		// 이후 인덱스 값에 temp에 저장해놓은 현재 인덱스 값 저장
			}
}
