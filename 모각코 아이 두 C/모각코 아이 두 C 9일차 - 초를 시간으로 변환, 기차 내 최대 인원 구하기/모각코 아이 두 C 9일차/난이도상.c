/*2021-05-11 ���� �� C 9���� �ڵ��ѽñ�
���̵� �� ���� Ǯ�� �� ���� �� �ִ� �ο�
���� 4�� �����ϴ� ������ �ֽ��ϴ�. Ÿ�� ������ ����� �� ���� �־����� ��,
���� ���� ���� ���� ����� �����ϴ� ����� ��� ���� ����ϴ� ���α׷��� �ۼ����ּ���.
- ���� 1 : ó�� ������ Ÿ�� �ִ� ����� 0���Դϴ�.
- ���� 2 : �Է� ���� "(������ �ο�) (Ÿ�� �ο�)"���� �־����ϴ�.
           ó�� ������ Ÿ�� �ִ� ����� 0���̹Ƿ� ó�� ������ �ο��� 0���Դϴ�.
- ���� 3 : �ο��� ������ �� ��� ���� �޽����� ����մϴ�.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int person_num = 0, person_in, person_out, person_max = 0;
    
    for (int i = 0; i < 4; i++) {
        printf("%d��° �� : ", i + 1);
        scanf("%d %d", &person_out, &person_in);

        person_num -= person_out;   // ���� ���
        if (person_num < 0) {
            printf("�߸��� �Է��Դϴ�.");
            exit(-1);
        }

        person_num += person_in;    // ���� ���
        if (person_max < person_num)
            person_max = person_num;    // �ִ� �ο� ����
    }
    
    printf("�������� Ÿ�� �ִ� ����� �� : %d\n", person_num);
    printf("������ ���� �ִ� �ο� : %d\n", person_max);
}