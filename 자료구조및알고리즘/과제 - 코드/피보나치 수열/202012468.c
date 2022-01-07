/*202012468 의생명공학과 김현서
 * 자료구조및알고리즘 과제1
 * 피보나치 수열을 재귀함수를 사용해 시간복잡도 O(n)으로 나타내기*/

#include <stdio.h>

long long int Fibo(int n)   //int 자료형을 사용할 경우 긴 숫자를 뽑아내지 못함
{
	//printf("func call param %d\n", n); // 코드가 몇 번 반복됐는지 알아보기 위해 써본 코드. 수열만 구하려면 필요x
	
	static long long arr[100];   // 배열의 정적 할당을 이용, 모든 값 0으로 채우기(단, 이렇게 하면 100까지만 할당 가능)

	if (n==1)  // 1을 입력하면 0 출력
		return 0;

	else if ((n==2) || (n==3))  // 2 또는 3을 입력하면 1 출력
		return 1;
	else
		if (arr[n-1] > 0)          // 위에서 정적할당을 이용해 arr[100]을 함으로써 100개의 공간이 모두 0으로 할당됨
			return arr[n-1];   // 때문에 0이 아닌 n번째 값이 배열 arr[n-1]에 저장되어 있다면 그걸 return

	        else
		        return arr[n-1] = Fibo(n-1) + Fibo(n-2); // n번째 값이 배열 arr[n-1]에 저장되어 있지 않다면 계산해서 저장 후 return
}

int main(void)
{
	int num, cnt = 0;
	printf("1과 93 사이의 정수를 입력하시면,\n입력하신 정수번째까지의 피보나치 수열을 출력해드립니다.\n(단, 피보나치 수열은 0부터 시작) : ");
	scanf("%d",&num);   // num은 int형이기 때문에 %d 사용해야함. 사용자에게 임의의 값을 입력받기
	printf("\n가독성을 높이기 위해 한 줄에 숫자 5개씩 출력하겠습니다.\n\n");

	for (int i=1; i<=num; i++)
	{
		printf("%lld\t", Fibo(i));   // Fibo 함수는 long long int형 함수이기 때문에 %lld 사용 사용자에게 입력받은 값을 Fibo로 출력
		cnt++;
		if ((cnt % 5) == 0)
			printf("\n");
	}
	
	return 0;
}


/* 0 1 1 2 3
 * 5 8 13 21 34
 * 55 89 ...... 이련 형식 */
