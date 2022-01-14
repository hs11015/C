/*20201-04-29 아이두C 2일차 코딩뿌시기
난이도 상 문제풀기 : 원래 숫자 구하기
조건 1: 0이상 99이하의 정수를 입력 받고, 각 자릿수의 합을 구합니다. (9 이하의 수는 그대로 사용)
조건 2: 입력 받은 수의 가장 오른쪽 자릿수와 앞에서 구한 합의 가장 오른쪽 자릿수를 이어 붙여 새로운 수를 생성 합니다.
조건 3: 새로운 수로 1, 2를 반복하여 본래의 숫자로 돌아갈 때 까지 몇 번의 과정을 거쳐야 하는지 계산하는 프로그램을 작성해보세요.*/

/*
#include <stdio.h>

int main(void)
{
	int num, count = 0;
	printf("숫자를 입력해주세요 : ");
	scanf_s("%d", &num);

	int new_num, num_ten, num_one, num_sum;

	count++;
	num_ten = num / 10;	// 10으로 나눈 몫 = 10의 자리 수
	num_one = num % 10;	// 10으로 나눈 나머지 = 1의 자리 수

	num_sum = num_ten + num_one;	// 각 자리 수의 합
	new_num = num_one * 10 + num_sum % 10; // 입력 받은 수의 1의 자리 수 = 10의자리, 합의 1의 자리 수 = 1의 자리
	printf("%d번째 바뀐 수 : %d\n", count, new_num);

	while (new_num != num)
	{
		count++;
		num_ten = new_num / 10;	// 10으로 나눈 몫 = 10의 자리 수
		num_one = new_num % 10;	// 10으로 나눈 나머지 = 1의 자리 수

		num_sum = num_ten + num_one;	// 각 자리 수의 합
		new_num = num_one * 10 + num_sum % 10; // 입력 받은 수의 1의 자리 수 = 10의자리, 합의 1의 자리 수 = 1의 자리
		printf("%d번째 바뀐 수 : %d\n", count, new_num);
	}

	printf("\n%d번 반복해야 %d는 원래 수인 %d로 돌아온다.", count, num, new_num);
}
*/


/*
#include <stdio.h>

int num, count = 0;
// 전역변수 사용. 전역변수 사용하지 않으면 num 값이 계속 바뀌어서 main함수와 New_Num 함수 두 곳에서 동시 사용 불가능

int New_Num(int num);

int main(void)
{
	printf("숫자를 입력해주세요 : ");
	scanf_s("%d", &num);
	
	New_Num(num);
}

int New_Num(int number)
{
	int new_num, num_ten, num_one, num_sum;

	count++;
	num_ten = number / 10;	// 10으로 나눈 몫 = 10의 자리 수
	num_one = number % 10;	// 10으로 나눈 나머지 = 1의 자리 수

	num_sum = num_ten + num_one;	// 각 자리 수의 합
	new_num = num_one * 10 + num_sum % 10; // 입력 받은 수의 1의 자리 수 = 10의자리, 합의 1의 자리 수 = 1의 자리

	printf("%d번째 바뀐 수 : %d\n", count, new_num);

	if (new_num == num)
	{
		printf("\n%d번 반복해야 %d는 원래 수인 %d로 돌아온다.", count, num, new_num);
		return 0;
	}

	else	// new_num != num
		New_Num(new_num);
}
*/