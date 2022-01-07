/*제목 : 과제 2 Recursive Matrix Multiplication을 코딩하시오.
 * 생성자 : 김현서(학번-202012468)
 * 생성날짜 : 2021-03-30*/


#include <stdio.h>
#include <stdlib.h>  //동적할당에 이용되는 함수들을 포함하는 헤더파일


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


	int** temp_a1 = {0, };  // 할당할 배열을 포인터로 선언

	temp_a1 = (int**)calloc(n/2, sizeof(int*));  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n/2; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		temp_a1[i] = (int*)malloc(sizeof(int) * n/2);  // 여기서 i는 행을 의미

	}

	
	int** temp_a2 = {0, };  // 할당할 배열을 포인터로 선언

	temp_a2 = (int**)malloc(sizeof(int*) * n/2);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n/2; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		temp_a2[i] = (int*)malloc(sizeof(int) * n/2);  // 여기서 i는 행을 의미

	}


	int** temp_a3 = {0, };  // 할당할 배열을 포인터로 선언
				
    	temp_a3 = (int**)malloc(sizeof(int*) * n/2);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n/2; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		temp_a3[i] = (int*)malloc(sizeof(int) * n/2);  // 여기서 i는 행을 의미

	}


	int** temp_a4 = {0, };  // 할당할 배열을 포인터로 선언

	temp_a4 = (int**)malloc(sizeof(int*) * n/2);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n/2; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		temp_a4[i] = (int*)malloc(sizeof(int) * n/2);  // 여기서 i는 행을 의미

	}


	
	for (int i = 0; i < n / 2; i++)

	{

		for (int j = 0; j < n / 2; j++)

		{

			temp_a1[i][j] = arr1[i][j];

		}


		
		for (int j = n / 2; j < n; j++)

		{

			temp_a2[i][j - n/2] = arr1[i][j];

		}

	}


	
	for (int i = n / 2; i < n; i++)

	{

		for (int j = 0; j < n / 2; j++)

		{

			temp_a3[i - n / 2][j] = arr1[i][j];

		}


		
		for (int j = n / 2; j < n; j++)

		{

			temp_a4[i - n / 2][j - n / 2] = arr1[i][j];

		}

	}




	
	int** temp_b1 = {0, };  // 할당할 배열을 포인터로 선언

	temp_b1 = (int**)malloc(sizeof(int*) * n / 2);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n / 2; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		temp_b1[i] = (int*)malloc(sizeof(int) * n / 2);  // 여기서 i는 행을 의미

	}


	
	int** temp_b2 = {0, };  // 할당할 배열을 포인터로 선언

	temp_b2 = (int**)malloc(sizeof(int*) * n / 2);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n / 2; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		temp_b2[i] = (int*)malloc(sizeof(int) * n / 2);  // 여기서 i는 행을 의미

	}


	
	int** temp_b3 = {0, };  // 할당할 배열을 포인터로 선언

	temp_b3 = (int**)malloc(sizeof(int*) * n / 2);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n / 2; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		temp_b3[i] = (int*)malloc(sizeof(int) * n / 2);  // 여기서 i는 행을 의미

	}


	
	int** temp_b4 = {0, };  // 할당할 배열을 포인터로 선언

	temp_b4 = (int**)malloc(sizeof(int*) * n / 2);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n / 2; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		temp_b4[i] = (int*)malloc(sizeof(int) * n / 2);  // 여기서 i는 행을 의미

	}


	
	for (int i = 0; i < n / 2; i++)

	{

		for (int j = 0; j < n / 2; j++)

		{

			temp_b1[i][j] = arr2[i][j];

		}


		
		for (int j = n / 2; j < n; j++)

		{

			temp_b2[i][j - n / 2] = arr2[i][j];

		}

	}


	
	for (int i = n / 2; i < n; i++)

	{

		for (int j = 0; j < n / 2; j++)

		{

			temp_b3[i - n / 2][j] = arr2[i][j];

		}


		
		for (int j = n / 2; j < n; j++)

		{

			temp_b4[i - n / 2][j - n / 2] = arr2[i][j];

		}

	}


	
	if (n == 2)

	{

		for (int i = 0; i < n / 2; i++)  // for (int i = 0; i < 2; i++)

		{

			for (int j = 0; j < n / 2; j++)

			{

				for (int k = 0; k < n / 2; k++)

				{

					*(*(arr3 + i) + j) = (*(*(temp_a1 + i) + k)) * (*(*(temp_b1 + k) + j)) + (*(*(temp_a2 + i) + k)) * (*(*(temp_b3 + k) + j));

					// arr3[i][j] = arr1[i][k] * arr2[k][j]와 같은 의미

				}
	
			}
							
		}

					
		for (int i = 0; i < n / 2; i++)  // for (int i = 0; i < 2; i++)
			
		{
				
			for (int j = n / 2; j < n; j++)					
			{
					
				for (int k = 0; k < n / 2; k++)					
				{

					
					*(*(arr3 + i) + j) = (*(*(temp_a1 + i) + k)) * (*(*(temp_b2 + k) + j)) + (*(*(temp_a2 + i) + k)) * (*(*(temp_b4 + k) + j));					
					// arr3[i][j] = arr1[i][k] * arr2[k][j]와 같은 의미
					
				}
																																						
			}
																																						
		}
																													
		for (int i = n / 2; i < n; i++)  // for (int i = 0; i < 2; i++)
																																						
		{
																																						
			for (int j = 0; j < n / 2; j++)
																																						
			{
																																						
				for (int k = 0; k < n / 2; k++)
																																						
				{
																																						
					*(*(arr3 + i) + j) = (*(*(temp_a3 + i) + k)) * (*(*(temp_b1 + k) + j)) + (*(*(temp_a4 + i) + k)) * (*(*(temp_b3 + k) + j));
																																						
					// arr3[i][j] = arr1[i][k] * arr2[k][j]와 같은 의미
																																						
				}
																																						
			}
	
		}
																		
		for (int i = 0; i < n / 2; i++)  // for (int i = 0; i < 2; i++)
																																						
		{
																																						
			for (int j = 0; j < n / 2; j++)
																																						
			{
	
				for (int k = 0; k < n / 2; k++)

				{																																				
					*(*(arr3 + i) + j) = (*(*(temp_a3 + i) + k)) * (*(*(temp_b2 + k) + j)) + (*(*(temp_a4 + i) + k)) * (*(*(temp_b4 + k) + j));
																																						
					// arr3[i][j] = arr1[i][k] * arr2[k][j]와 같은 의미
																																					
				}
																																						
			}
																																						
		}
																													
	}
									
	
	else     // n이 4, 8, 16, ...일때																																	
	{

		Recursive_Matrix_Multiplication(n / 2, arr1, arr2, arr3);

	}

	for (int i = 0; i < n; i++)

	{

		free(temp_a1[i]);

		free(temp_a2[i]);

		free(temp_a3[i]);

		free(temp_a4[i]);

		free(temp_b1[i]);

		free(temp_b2[i]);

		free(temp_b3[i]);

		free(temp_b4[i]);

	}


	free(temp_a1);

	free(temp_a2);

	free(temp_a3);

	free(temp_a4);

	free(temp_b1);

	free(temp_b2);

	free(temp_b3);

	free(temp_b4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	return arr3;

}



int main() {

	int n;

	printf("입력할 정방행렬의 타일의 개수를 입력하세요(단, 타일의 개수는 2의 제곱꼴이어야함. e.g. 2,4,8,16,...) : ");

	scanf("%d", &n);

	int** matrix_a = {0, };  // 할당할 배열을 포인터로 선언

	matrix_a = (int**)malloc(sizeof(int*) * n);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		matrix_a[i] = (int*)malloc(sizeof(int) * n);  // 여기서 i는 행을 의미

	}


	int** matrix_b = {0, };  // 할당할 배열을 포인터로 선언

	matrix_b = (int**)malloc(sizeof(int*) * n);  // n개짜리 요소를 갖는 int형 배열 동적할당

	for (int i = 0; i < n; i++)  // 반복문을 사용해 n층(2차원 배열의 행부분) 동적할당

	{

		matrix_b[i] = (int*)malloc(sizeof(int) * n);  // 여기서 i는 행을 의미    

	}


	
	int** matrix_result = {0, };  // 할당할 배열을 포인터로 선언

	matrix_result = (int**)malloc(sizeof(int*) * n);  // n개짜리 요소를 갖는 int형 배열 동적할당

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



