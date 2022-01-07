/*제목 : 과제 2 Recursive Matrix Multiplication을 코딩하시오.
 * 생성자 : 김현서(학번-202012468)
 * 생성날짜 : 2021-03-30*/

#include <stdio.h>
#include <stdlib.h>  //동적할당에 이용되는 함수들을 포함하는 헤더파일
#pragma warning(disable : 4047)

void Print_matrix(int n, int** arr)
{

    	for (int i = 0; i < n; i++)
    
	{
        
	    	for (int j = 0; j < n; j++)
            
    		{
    
			printf("%5d", arr[i][j]);  // 출력 확인

		}

		printf("\n");

	}

}





void Scanf_matrix(int n, int** arr)

{

	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < n; j++)

		{


			printf("%d번째 행, %d번째 열의 숫자를 입력해주세요 : ", i + 1, j + 1);

			scanf("%d", &arr[i][j]); // 행렬에 값을 입력

		}

	}

}









int** Recursive_Matrix_Multiplication(int n, int(** arr1), int(** arr2), int(** arr3)) {

	if (n == 2)

	{

		for (int i = 0; i < n / 2; i++)  // for (int i = 0; i < 2; i++)

		{

			for (int j = 0; j < n / 2; j++)

			{

				for (int k = 0; k < n / 2; k++)

				{

					arr3[i][j] += arr1[i][j + k] * arr2[i + k][j];

					// arr3[i][j] = arr1[i][j+k] * arr2[i+k][j] + arr1[i][j+k] * arr2[i+k][j];와 같은 의미

				}

			}


                        
			for (int j = n / 2; j < n; j++)

			{

				for (int k = 0; k < n / 2; k++)

				{

					arr3[i][j] = arr1[i][j + k] * arr2[i + k][j];

					// arr3[i][j] = arr1[i][j + k] * arr2[i + k][j] + arr1[i][j + k] * arr2[i + k][j]와 같은 의미

				}

			}

		}


                
		for (int i = n / 2; i < n; i++)  // for (int i = 0; i < 2; i++)

		{

			for (int j = 0; j < n / 2; j++)

			{

				for (int k = 0; k < n / 2; k++)

				{

					arr3[i][j] = arr1[i][j + k] * arr2[i + k][j];

					// arr3[i][j] = arr1[i][j + k] * arr2[i + k][j] + arr1[i][j + k] * arr2[i + k][j]와 같은 의미

				}

			}

			for (int j = 0; j < n / 2; j++)

			{

				for (int k = 0; k < n / 2; k++)

				{

					arr3[i][j] = arr1[i][j + k] * arr2[i + k][j];

					// arr3[i][j] = arr1[i][j + k] * arr2[i + k][j] + arr1[i][j + k] * arr2[i + k][j]와 같은 의미

				}

			}

		}


                
		return arr3;

	}


        
	else if (n % 2 == 0)     // n이 4, 8, 16, ...일때

	{

		return Recursive_Matrix_Multiplication(n / 2, arr1, arr2, arr3);

	}


        
	else {

		printf("2의 n승꼴의 정방행렬이어야 합니다");

		return 0;

	}

}



int main() {

	int n;

	printf("입력할 정방행렬의 타일의 개수를 입력하세요(단, 타일의 개수는 2의 제곱꼴이어야함. e.g. 2,4,8,16,...) : ");

	scanf("%d", &n);


        
	int** matrix_a;  // n개짜리 요소를 갖는 int형 배열 동적할당

	matrix_a = malloc(sizeof(int*) * n);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		matrix_a[i] = malloc(sizeof(int) * n);  // 여기서 i는 행을 의미

	}




        
	int** matrix_b;  // n개짜리 요소를 갖는 int형 배열 동적할당

	matrix_b = (int**)malloc(sizeof(sizeof(int)) * n);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		matrix_b[i] = (int*)malloc(sizeof(int) * n);  // 여기서 i는 행을 의미

	}




        
	int** matrix_result;  // n개짜리 요소를 갖는 int형 배열 동적할당

	matrix_result = (int**)malloc(sizeof(sizeof(int)) * n);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		matrix_result[i] = (int*)malloc(sizeof(int) * n);  // 여기서 i는 행을 의미

	}




        
	printf("[행렬 A]의 요소들을 입력해주세요\n");

	Scanf_matrix(n, matrix_a);  // matrix_a 행렬에 값을 입력


        
	printf("[행렬 B]의 요소들을 입력해주세요\n");

	Scanf_matrix(n, matrix_b);  // matrix_b 행렬에 값을 입력


        
	printf("\n\n[행렬 A]\n");

	Print_matrix(n, matrix_a);


        
	printf("[행렬 B]\n");

	Print_matrix(n, matrix_b);


        
	printf("[행렬 A와 행렬 B의 곱 행렬]\n");

	Recursive_Matrix_Multiplication(n, matrix_a, matrix_b, matrix_result);

	Print_matrix(n, matrix_result);


        
	for (int i = 0; i < n; i++)

	{

		free(matrix_a[i]);

		free(matrix_b[i]);

		free(matrix_result[i]);

	}


        
	free(matrix_a);

	free(matrix_b);

	free(matrix_result);


        
	return 0;

}
