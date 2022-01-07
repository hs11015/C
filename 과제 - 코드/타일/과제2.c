/*자료구조및알고리즘 과제2
 * Recursive Matrix Multiplication 코드 작성하기
 * 202012468 김현서*/


#include <stdio.h>

int Matrix_Multiplication(int i, int j, int k)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int sum = 0;
			for (int k = 0; k < 2; k++)
			{
				sum += *(*(ptr_a + i) + k) * (*(*(ptr_b + k) + j));
				// matrix_mul[i][j] = matrix_a[i][k] * matrix_b[k][j]와 같은 의미
			}
			*(*(ptr_mul + i) + j) = sum;
		}
	}
}

int Recursive_Matrix_Multiplication(int n)
{
	int matrix_a[n][n], matrix_b[n][n], matrix_mul[n][n] = { 0 }; // matrix_mul은 행렬 안 값을 0으로 초기화 해줘야 밑에서 이중포인터 입력 가능
	int(*ptr_a)[n] = matrix_a, (*ptr_b)[n] = matrix_b, (*ptr_mul)[n] = matrix_mul; // 3짜리 열 가진 각각의 행렬 포인터

	if (n == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int sum = 0;
				for (int k = 0; k < 2; k++)
				{
					sum += *(*(ptr_a + i) + k) * (*(*(ptr_b + k) + j));
					// matrix_mul[i][j] = matrix_a[i][k] * matrix_b[k][j]와 같은 의미
				}
				*(*(ptr_mul + i) + j) = sum;
			}
		}
	}

	else if (n==4)
	{
		for (int i = 0; i < 2 ; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int sum = 0;
				for (int k = 0; k < 2; k++)
				{
					sum += *(*(ptr_a+ i) + k) * (*(*(ptr_b + k) + j));
  					// matrix_mul[i][j] = matrix_a[i][k] * matrix_b[k][j]와 같은 의미
	                        }
	                        *(*(ptr_mul + i) + j) = sum;
	                }
		}

		for (int i = 0; i < 2 ; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				int sum = 0;
				for (int k = 0; k < 2; k++)
				{
					sum += *(*(ptr_a+ i) + k) * (*(*(ptr_b + k) + j));
					// matrix_mul[i][j] = matrix_a[i][k] * matrix_b[k][j]와 같은 의미
				}
				*(*(ptr_mul + i) + j) = sum;
                        }
		}

		for (int i = 2; i < 4 ; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int sum = 0;
				for (int k = 0; k < 2; k++)
				{
					sum += *(*(ptr_a+ i) + k) * (*(*(ptr_b + k) + j));
					// matrix_mul[i][j] = matrix_a[i][k] * matrix_b[k][j]와 같은 의미
				}
				*(*(ptr_mul + i) + j) = sum;
			}
		}
			
		for (int i = 2; i < 4 ; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				int sum = 0;
				for (int k = 0; k < 2; k++)
				{
					sum += *(*(ptr_a+ i) + k) * (*(*(ptr_b + k) + j));
					// matrix_mul[i][j] = matrix_a[i][k] * matrix_b[k][j]와 같은 의미
				}
				*(*(ptr_mul + i) + j) = sum;
			}																	
		}
	}


	else
	{
		
	}

}


int main()
{
	int n;
	printf("타일의 개수를 입력하세요(단, 타일의 개수는 무조건 2의 제곱꼴이어야함. e.g. 2,4,8,16,...)");
	scnaf("%d", &n);

	int matrix_a[Rows][Cols], matrix_b[Rows][Cols], matrix_mul[Rows][Cols] = { 0 }; // matrix_mul은 행렬 안 값을 0으로 초기화 해줘야 밑에서 이중포인터 입력 가능
	int(*ptr_a)[Cols] = matrix_a, (*ptr_b)[Cols] = matrix_b, (*ptr_mul)[Cols] = matrix_mul; // 3짜리 열 가진 각각의 행렬 포인터
	int matrix_result[n][n];
	printf("행렬 A의 숫자를 입력해주세요.\n"); // 행렬 A 입력

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d번째 행, %d번째 열의 숫자를 입력해주세요 : ", i, j);
			scanf("%d", *(ptr_a + i) + j); //  &maxtrix_a[i][j])와 동일, 포인터 사용 위함
		}
	}

	printf("\n행렬 B의 숫자를 입력해주세요.\n"); // 행렬 B 입력

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d번째 행, %d번째 열의 숫자를 입력해주세요 : ", i, j);
			scanf("%d", *(ptr_b + i) + j); // &maxtrix_b[i][j]와 동일, 포인터 사용 위함
		}
	}

	printf("\n\n입력하신 행렬들의 값이 옳게 출력됐는지 확인해주세요 :\n\n");

	printf("[행렬 A]\n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%5d", *(*(ptr_a + i) + j));  // 이중포인터를 사용해 행렬 출력
		}
		printf("\n");
	}

	printf("[행렬 B]\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%5d", *(*(ptr_b + i) + j));  // 이중포인터를 이용해 행렬 출력
		}
		printf("\n");
	}

	printf("\n입력받은 값들을 이용해 행렬의 곱을 출력하겠습니다.\n\n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int sum = 0;
			for (int n = 0; n < 3; n++)
			{
				sum += *(*(ptr_a + i) + n) * (*(*(ptr_b + n) + j));
				// matrix_mul[i][j] = matrix_a[i][n] * matrix_b[n][j]를과 같은 의미
			}
			*(*(ptr_mul + i) + j) = sum;
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%5d", *(*(ptr_mul + i) + j));
		}
		printf("\n");
	}
	
	return 0;
}
