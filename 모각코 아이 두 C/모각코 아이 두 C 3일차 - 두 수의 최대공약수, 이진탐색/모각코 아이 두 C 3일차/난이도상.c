/*2021-04-30 아이 두 C 문제풀이 5월과정 코딩뿌시기
난이도 상 : 이진 탐색
이진 탐색 알고리즘을 통해 특정 정수가 몇 번째에 존재하는지 찾는 프로그램을 작성
- 조건 1 : 입력받을 정수의 개수를 먼저 입력받음.
- 조건 2 : 입력받는 숫자들은 정수이며 배열로 입력받음. 이때 각 숫자는 오름차순으로 입력.
- 조건 3 : 중복된 값을 입력받지 않음. 만약 찾는 값이 존재하지 않는다면 -1 출력
- 조건 4 : 함수를 활용해 작성*/

#include <stdio.h>
#include <stdlib.h>

int binsearch(int a[], int key, int left, int right);

int main(void)
{
	int num;
	printf("입력받을 정수의 개수 : ");
	scanf_s("%d", &num);

	int* a = (int*)malloc(num * sizeof(int));

	printf("\n중복되는 숫자는 입력 불가능하고, 오름차순으로 입력해주세요.\n");

	for (int i = 0; i < num; i++)
	{
		printf("%d번째 숫자 : ", i + 1);
		scanf_s("%d", &a[i]);
	}

	printf("\n입력하신 수 : ");
	
	for (int i = 0; i < num; i++)
		printf("%d ", a[i]);

	int finding_num;
	printf("\n찾고싶은 숫자 : ");
	scanf_s("%d", &finding_num);

	int idx = binsearch(a, finding_num, 0, num);
	
	if (idx == -1)
		printf("탐색 실패! 해당하는 숫자가 없습니다.\n");
	else
		printf("탐색 성공! 해당하는 숫자는 %d번째 인덱스에 저장되어 있습니다.\n", idx);
}

// left와 right가 뭔지 모르겠어서 left는 첫 인덱스 값, right는 마지막 인덱스 값으로 가정하고 시작
int binsearch(int a[], int key, int left, int right)
{
	int first = left;	// 탐색 대상 시작 인덱스 값
	int last = right - 1;	// 탐색 대상 마지막 인덱스 값
	int mid;	// 구해야하는 값

	while (first <= last)
	{
		mid = (first + last) / 2;	// 탐색 대상의 중앙을 찾는다

		if (key == a[mid])	// 중앙에 저장된 것이 타겟이라면
			return mid;		// 탐색 완료

		else	// 타겟이 아니라면 탐색 대상을 반으로 줄인다
		{
			if (key < a[mid])		// 대소비교를 통해 다음 범위를 구함
				last = mid - 1;		// mid 값은 찾는 값이 아니라는 것을 알았으니 그보다 1 작은 index부터 확인해도 됨
			
			else	// key > a[mid]
				first = mid + 1;	// mid 값은 찾는 값이 아니라는 것을 알았으니 그보다 1 큰 index부터 확인해도 됨
		}

		return -1;	// 찾지 못했을 때 반환되는 값 -1 (조건 3 中)
	}
}