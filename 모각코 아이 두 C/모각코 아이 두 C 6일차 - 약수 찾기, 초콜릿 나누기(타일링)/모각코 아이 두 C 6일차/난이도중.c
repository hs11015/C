/*2021-05-06 ���� �� C 6���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� ��� ã��
�Ʒ� ������ �����Ͽ�, ���� n�� �Է¹ް� �ش� ���ڰ� 2, 3, 5�� ����� ������ ��Ȳ�� ���� A~D�� ����ϴ� ���α׷��� �ۼ��غ�����.
- ���� 1 : 2, 3, 5 ��� ����� ������ ��� A�� ����մϴ�
- ���� 2 : 2, 3, 5 �� �� ���ڸ��� ����� ������ ��� B�� ����մϴ�.
- ���� 3 : 2 ,3, 5 �� �� ���ڸ��� ����� ������ ��� C�� ����մϴ�.
- ���� 4 : 2, 3, 5 �� �ƹ� ���ڵ� ����� ������ �ʴ� ��� D�� ����մϴ�.*/

/*
#include <stdio.h>

void printing_program(int num);

int main()
{
    int num;
    scanf_s("%d", &num);
    printing_program(num);
    return 0;
}

void printing_program(int num)
{
    if (num % 2 == 0 && num % 3 == 0 && num % 5 == 0)
        printf("A\n");

    else if (num % 2 == 0 && num % 3 == 0 || num % 3 == 0 && num % 5 == 0 || num % 5 == 0 && num % 2 == 0)
        printf("B\n");

    else if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0)
        printf("C\n");

    else
        printf("D\n");

    return;
}
*/