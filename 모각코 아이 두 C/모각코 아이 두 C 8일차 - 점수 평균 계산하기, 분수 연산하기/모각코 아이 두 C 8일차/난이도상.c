/*2021-05-10 ���̵�C 8���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� �м� �����ϱ�
�� �м��� ������ �Է¹ް�, �� ���� ����Ͽ� ����ϴ� ���α׷��� �ۼ����ּ���.
- ���� 1 : �и� 0�� ���� ������� �ʽ��ϴ�.
- ���� 2 : ����� ���� �м��� ���� ���м��� ���·� ������ּ���.*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int calculation(char* str);

int main(void)
{
    char str[100];
    scanf("%s", str);
    calculation(str);
    return 0;
}

int calculation(char* str)
{
    int j = 0, oper = 4, num[4] = { 0 };
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') {
            num[j] = num[j] * 10 + (str[i] - '0');
        }
        else if (str[i] == '+') {
            oper = 1;
            j++;
        }
        else if (str[i] == '-') {
            oper = 2;
            j++;
        }
        else if (str[i] == '*') {
            oper = 3;
            j++;
        }
        else if (str[i] == '/') {
            j++;
        }
        else {
            oper = 5;
        }
    }

    if (num[2] != 0 && num[3] != 0) // �и� 0�̸� �ȵ�
    {
        int deno, nume; // �и�, ����

        switch (oper) {
        case 1:
            nume = ((num[0] * num[3]) + (num[2] * num[1]));
            deno = num[1] * num[3];
            break;
        case 2:
            nume = ((num[0] * num[3]) - (num[2] * num[1]));
            deno = num[1] * num[3];
            break;
        case 3:
            nume = num[0] * num[2];
            deno = num[1] * num[3];
            break;
        case 4:
            nume = num[0] * num[3];
            deno = num[1] * num[2];
            break;
        default:
            break;
        }

        if (deno < nume) {
            for (int i = 2; i <= deno; i++) {
                if (deno % i == 0 && nume % i == 0) {
                    deno /= i;
                    nume /= i;
                }
            }
        }
        else {
            for (int i = 2; i <= nume; i++) {
                if (deno % i == 0 && nume % i == 0) {
                    deno /= i;
                    nume /= i;
                }
            }
        }

        printf("%d/%d", nume, deno);
    }
    return;
}