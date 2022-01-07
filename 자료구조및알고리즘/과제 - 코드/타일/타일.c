/*¿¿ : ¿¿ 2 Recursive Matrix Multiplication¿ ¿¿¿¿¿.
* ¿¿¿ : ¿¿¿(¿¿-202012468)
* ¿¿¿¿ : 2021-03-30*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  //¿¿¿¿¿ ¿¿¿¿ ¿¿¿¿ ¿¿¿¿ ¿¿¿¿


void Print_matrix(int n, int** arr)  // ¿¿ ¿¿ ¿¿
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", arr[i][j]);   // ¿¿ ¿¿
        }
        printf("\n");
    }
}


void Scanf_matrix(int n, int** arr)   // ¿¿ ¿¿ ¿¿ ¿¿
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
		printf("%d¿¿ ¿, %d¿¿ ¿¿ ¿¿¿ ¿¿¿¿¿¿ : ", i + 1, j + 1);
		scanf("%d", &arr[i][j]); // ¿¿¿ ¿¿ ¿¿
        }
    }
}


int** Recursive_Matrix_Multiplication(int n, int(**arr1), int(**arr2), int(**arr3)) {  // ¿¿¿¿
    int i = 0, j = 0, k = 0;

    if (n == 2)      // 2x2 ¿¿¿ ¿
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                for (int k = 0; k < n; k++)
                {
                    sum += arr1[i][k] * arr2[k][j];
                }
                arr3[i][j] = sum;
            }
        }
        return arr3;
    }


    else if (n == 4)   // 4x4 ¿¿¿ ¿
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)      // 4¿¿ ¿¿¿ ¿ ¿¿ ¿
	    {
                int sum = 0;
                for (int k = 0; k < n / 2; k++)
                {
                    sum += arr1[i][k] * arr2[k][j];
                }
                arr3[i][j] = sum;
            }
        }

        for (int i = 0; i < n / 2; i++)
        {
            for (int j = n / 2; j < n; j++)   // 4¿¿ ¿¿¿ ¿ ¿¿¿ ¿
            {
                int sum = 0;
                for (int k = 0; k < n / 2; k++)
                {
                    sum += arr1[i][k] * arr2[k][j];
                }
                arr3[i][j] = sum;
            }
        }

        for (int i = n / 2; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)    // 4¿¿ ¿¿¿ ¿ ¿¿ ¿¿
            {
                int sum = 0;
                for (int k = 0; k < n / 2; k++)
                {
                    sum += arr1[i][k] * arr2[k][j];
                }
                arr3[i][j] = sum;
            }
        }

        for (int i = n / 2; i < n; i++)
        {
            for (int j = n / 2; j < n; j++)    // 4¿¿ ¿¿¿ ¿ ¿¿¿ ¿¿
            {
                int sum = 0;
                for (int k = 0; k < n / 2; k++)
                {
                    sum += arr1[i][k] * arr2[k][j];
                }
                arr3[i][j] = sum;
            }
        }
        return arr3;
    }

    else if ((n%2 ==0)&&(n %4 == 0))       //n¿ 8, 16, 32,... ¿ ¿
    {
        return Recursive_Matrix_Multiplication(n / 2, arr1, arr2, arr3);  //¿¿¿¿
    }

    else    //n¿ 2¿ ¿¿ ¿¿ ¿¿ ¿
    {
        printf("n¿ 2¿ ¿¿ ¿¿ ¿¿¿¿. ¿¿ ¿¿¿¿¿¿.");
        return 0;
    }
}


int main() {
    int n;
    printf("¿¿¿ ¿¿¿¿¿ ¿¿¿ ¿¿¿ ¿¿¿¿¿(¿, ¿¿¿ ¿¿¿ 2¿ ¿¿¿¿¿¿¿. e.g. 2,4,8,16,...) : ");
    scanf("%d", &n);

    int** matrix_a;  // n¿¿¿ ¿¿¿ ¿¿ int¿ ¿¿ ¿¿¿¿

    matrix_a = calloc(n, sizeof(int*));  // n¿¿¿ ¿¿¿ ¿¿ int¿ ¿¿ ¿¿¿¿

    
    for (int i = 0; i < n; i++)  // ¿¿¿¿ ¿¿¿ n¿(2¿¿ ¿¿¿ ¿¿¿) ¿¿¿¿

    {

	    matrix_a[i] = malloc(sizeof(int) * n);  // ¿¿¿ i¿ ¿¿ ¿¿

    }





    int** matrix_b;  // n¿¿¿ ¿¿¿ ¿¿ int¿ ¿¿ ¿¿¿¿

    matrix_b = calloc(n, sizeof(int*));  // n¿¿¿ ¿¿¿ ¿¿ int¿ ¿¿ ¿¿¿¿

    for (int i = 0; i < n; i++)  // ¿¿¿¿ ¿¿¿ n¿(2¿¿ ¿¿¿ ¿¿¿) ¿¿¿¿

    {

	    matrix_b[i] = (int*)malloc(sizeof(int) * n);  // ¿¿¿ i¿ ¿¿ ¿¿

    }





    int** matrix_result;  // n¿¿¿ ¿¿¿ ¿¿ int¿ ¿¿ ¿¿¿¿

    matrix_result = calloc(n, sizeof(int*));  // n¿¿¿ ¿¿¿ ¿¿ int¿ ¿¿ ¿¿¿¿

    for (int i = 0; i < n; i++)  // ¿¿¿¿ ¿¿¿ n¿(2¿¿ ¿¿¿ ¿¿¿) ¿¿¿¿

    {

	    matrix_result[i] = (int*)malloc(sizeof(int) * n);  // ¿¿¿ i¿ ¿¿ ¿¿

    }





    printf("[¿¿ A]¿ ¿¿¿¿ ¿¿¿¿¿¿\n");

    Scanf_matrix(n, matrix_a);  // matrix_a ¿¿¿ ¿¿ ¿¿



    printf("[¿¿ B]¿ ¿¿¿¿ ¿¿¿¿¿¿\n");

    Scanf_matrix(n, matrix_b);  // matrix_b ¿¿¿ ¿¿ ¿¿



    printf("\n\n[¿¿ A]\n");

    Print_matrix(n, matrix_a);



    printf("[¿¿ B]\n");

    Print_matrix(n, matrix_b);



    printf("[¿¿ A¿ ¿¿ B¿ ¿ ¿¿]\n");

    Recursive_Matrix_Multiplication(n, matrix_a, matrix_b, matrix_result);

    Print_matrix(n, matrix_result);



    for (int i = 0; i < n; i++)   //free ¿¿¿ ¿¿¿¿ ¿¿¿¿ ¿¿¿ ¿¿¿¿

    {

	    free(matrix_a[i]);        //2¿¿ ¿¿¿¿ ¿ ¿ ¿¿¿¿ (¿)

	    free(matrix_b[i]);

	    free(matrix_result[i]);

    }


    free(matrix_a);          //2¿¿ ¿¿¿¿ ¿ ¿ ¿¿¿¿ (¿)
    free(matrix_b);
    free(matrix_result);

    return 0;

}



