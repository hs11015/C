#include "calc.h"
#include <stdio.h>

int main() {
	int a, b;
	printf("a : ");
	scanf_s("%d", &a);
	printf("b : ");
	scanf_s("%d", &b);

	int (*ptr[4])(int, int) = { plus, minus, multiplication, division };
	// �Լ� ������ �̿�!
	printf("%d + %d = %d\n", a, b, ptr[0](a, b)); // plus���� �Է�����
	printf("%d - %d = %d\n", a, b, ptr[1](a, b)); // minus���� �Է�����
	printf("%d * %d = %d\n", a, b, ptr[2](a, b)); // multiplication���� �Է�����
	printf("%d / %d = %d\n", a, b, ptr[3](a, b)); // division���� �Է�����

	return 0;
}




/*
int main(){
	int a, b;
	printf("a : ");
	scanf_s("%d", &a);
	printf("b : ");
	scanf_s("%d", &b);

	printf("%d + %d = %d", a, b, plus(a,b)); // a, b, �Լ� �� �Է�
	printf("%d - %d = %d", a, b, minus(a, b)); // �Լ� ��ü�� print���� �ƴ϶�
	printf("%d * %d = %d", a, b, multiplication(a, b)); // int�� ��ȯ�Ǵ� retrun��
	printf("%d / %d = %d", a, b, division(a, b)); // �׷��� �̷��� %d�� ����ϱ� ����

	return 0;
}
*/



/*
int main() {
	char OPER;
	printf("���� ����(+, -, *, /) : ");
	scanf_s("%c", &OPER, sizeof(OPER));

	int a, b;
	printf("a : ");
	scanf_s("%d", &a);
	printf("b : ");
	scanf_s("%d", &b);

	int (*ptr[4])(int, int) = { plus, minus, multiplication, division };
	// �Լ� ������ �̿�!
	printf("a %c b = ", OPER); // �Է¹��� OPER ���� %c�� �־���

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