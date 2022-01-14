#include "calc.h"
#include <stdio.h>

int main() {
	int a, b;
	printf("a : ");
	scanf_s("%d", &a);
	printf("b : ");
	scanf_s("%d", &b);

	int (*ptr[4])(int, int) = { plus, minus, multiplication, division };
	// 함수 포인터 이용!
	printf("%d + %d = %d\n", a, b, ptr[0](a, b)); // plus값을 입력해줌
	printf("%d - %d = %d\n", a, b, ptr[1](a, b)); // minus값을 입력해줌
	printf("%d * %d = %d\n", a, b, ptr[2](a, b)); // multiplication값을 입력해줌
	printf("%d / %d = %d\n", a, b, ptr[3](a, b)); // division값을 입력해줌

	return 0;
}




/*
int main(){
	int a, b;
	printf("a : ");
	scanf_s("%d", &a);
	printf("b : ");
	scanf_s("%d", &b);

	printf("%d + %d = %d", a, b, plus(a,b)); // a, b, 함수 값 입력
	printf("%d - %d = %d", a, b, minus(a, b)); // 함수 자체가 print값이 아니라
	printf("%d * %d = %d", a, b, multiplication(a, b)); // int로 반환되는 retrun형
	printf("%d / %d = %d", a, b, division(a, b)); // 그래서 이렇게 %d로 사용하기 가능

	return 0;
}
*/



/*
int main() {
	char OPER;
	printf("연산 종류(+, -, *, /) : ");
	scanf_s("%c", &OPER, sizeof(OPER));

	int a, b;
	printf("a : ");
	scanf_s("%d", &a);
	printf("b : ");
	scanf_s("%d", &b);

	int (*ptr[4])(int, int) = { plus, minus, multiplication, division };
	// 함수 포인터 이용!
	printf("a %c b = ", OPER); // 입력받은 OPER 값을 %c로 넣어줌

	if (OPER == '+')
		printf("%d\n", ptr[0](a, b));
	else if (OPER == '-')
		printf("%d\n", ptr[1](a, b));
	else if (OPER == '*')
		printf("%d\n", ptr[2](a, b));
	else if (OPER == '/')
		printf("%d\n", ptr[3](a, b));

	return 0;
}
*/