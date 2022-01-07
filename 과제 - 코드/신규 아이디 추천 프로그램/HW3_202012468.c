/*제목: 신규 아이디 추천 프로그램 작성
 * 생성자 : 202012468 김현서
 * 생성날짜 : 2021-04-13*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>  // tolower 함수(대문자를 소문자로 만들어주는 함수)가 있는 헤더파일
#include "DBDLinkedList.h"

// 단계별 함수

void Stage1(List plist, Data pdata);
void Stage2(List plist, Data pdata);
void Stage3(List plist, Data pdata);
void Stage4(List plist, Data pdata);
void Stage5(List plist, Data pdata);
void Stage6(List plist, Data pdata);
void Stage7(List plist, Data pdata);


int main(void)
{
	// 문자열 형태로 new_id를 입력받음
	
        char new_id[1000] = { 0 };  // id를 1000자까지 입력받을 수 있다는 조건


    	printf("id를 입력해주세요 : ");
   
       	int i = 0;
   
       	while (1)

	{

		scanf("%c", &new_id[i]);    // id 한 자씩 배열로 입력받기

		if (new_id[i] == '\n')      // 엔터 치면 종료

			break;

		i++;

	}
   
       	List list;  // list 선언

    	Data data;  // data 선언
   
       	ListInit(&list);    // 초기화

	// 문자열 형태로 저장받은 데이터를 링크드리스트로 저장


	for (int j = 0; j < i; j++) // j<i인 이유는 new_id[i] 마지막 값은 \n이라 포함시키면 안되기 때문
	
	{

		LInsert(&list, new_id[j]);  // 배열에 저장된 id 한 글자 한 글자를 노드 하나 하나에 저장

	}


	// 저장된 데이터 조회


       	printf("\n입력하신 아이디 : ");   

   	if (LFirst(&list, &data))   // LFirst 읽어들이기

	{

		printf("%c", data);     // 읽어들인 LFirst의 data 출력하기


		
		while (LNext(&list, &data))     // LNext가 TRUE를 반환하는 동안 진행됨(다음 노드가 tail 더미노드가 아니면 진행됨)

			printf("%c", data);     // LNext가 진행될 때마다 각각의 노드에 저장되어있는 data 출력


		
		printf("\n");

	}


	// 총 7단계의 수정과정

	 Stage1(list, data);


	 Stage2(list, data);


 	 Stage3(list, data);


	 Stage4(list, data);


	 Stage5(list, data);

	
	 Stage6(list, data);


	 Stage7(list, data);


	 // 수정과정 이후의 아이디 출력

	printf("\n수정 이후의 아이디 : ");

	if (LFirst(&list, &data))

	{

		printf("%c", data);

		while (LNext(&list, &data))

			printf("%c", data);

		
		printf("\n");

	}

}


// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.

void Stage1(List plist, Data pdata)
{

	char temp;

	if (LFirst(&plist, &pdata))

	{

		if ((pdata >= 'A') && (pdata <= 'Z'))   // 'A'~'Z' = 65~90, 'a'~'z' = 97~122

		{

			temp = tolower(pdata);  // tolower 이용해서 대문자인 pdata를 소문자로 바꿔서 반환

			LRemove(&plist);        // cur 지우기

			LChange(&plist, temp);  // 지웠던 노드 그 자리에 소문자로 바꾼 데이터 집어넣기

		}




		
		while (LNext(&plist, &pdata))   // LNext가 TRUE를 반환하는 동안 진행됨(다음 노드가 tail 더미노드가 아니면 진행됨)

		{

			if ((pdata >= 'A') && (pdata <= 'Z'))   // pdata의 아스키코드값이 65~90인 경우

			{

				temp = tolower(pdata);

				LRemove(&plist);

				LChange(&plist, temp);

			}

		}

	}

}



// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.

void Stage2(List plist, Data pdata)
{

	if (LFirst(&plist, &pdata))

	{

		if (!(pdata >= 'a' && pdata <= 'z') && !(pdata >= '0' && pdata <= '9') && !(pdata == '-') && !(pdata == '_') && !(pdata == '.')) // 만족 해야하는 조건들에 !(not)을 붙여줌


			LRemove(&plist);     // 만약 조건에 만족하지 않는다면 삭제함

			
		while (LNext(&plist, &pdata))

			if (!(pdata >= 'a' && pdata <= 'z') && !(pdata >= '0' && pdata <= '9') && !(pdata == '-') && !(pdata == '_') && !(pdata == '.')) // 만족 해야하는 조건들에 !(not)을 붙여줌

				LRemove(&plist);     // 만약 조건에 만족하지 않는다면 삭제함

	}

}


// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.

void Stage3(List plist, Data pdata)
{

	
		
	if ((LFirst(&plist, &pdata) != 0)&&(LNext(&plist, &pdata) != 0))    // LCount가 2개 이상인 경우

	{

		LFirst(&plist, &pdata); // LFirst 확인

		if (pdata == '.')       // 처음 노드의 data가 .인 경우


		{


			while (pdata == '.')    // pdata가 .인 동안


			{


				LNext(&plist, &pdata);  // LNext 확인


				if (pdata == '.')       // pdata가 .인 경우


				{


					LRemove(&plist);    // LRemove 해줌 cur은 이전 노드로 돌아가지만 while문이 돌아가면서 LNext를 이용해 다음 노드로 넘어감


					//LPrev(&plist, &pdata);


				}
				       	        // LNext의 값이 .이 아닌 경우 while문 빠져나옴


		       	
			}



			
			while (LNext(&plist, &pdata))   // 다시 while문으로 LNext문 걸어줌
			
    			{

				if (pdata == '.')   // LNext(2번)가 .인 경우

				{

					LNext(&plist, &pdata);  // LNext(3번) 값 확인

					if (pdata == '.')   // 그 다음 노드(3번)도 .경우

					{

						LRemove(&plist);    // 해당 노드(3번) LRemove, cur은 이전 노드(2번)로

						LPrev(&plist, &pdata);  // cur을 while문에서 LNext가 실행되기 이전 노드로 (2번 노드 전인 1번 노드). while문 다시 돌면 2번 노드 확인, .일 경우 4번 노드 확인

					}

				}

			}
		}
		

	

		 else   // LFirst의 pdata != '.'
			         
		 {
		
			 while (LNext(&plist, &pdata))   // LNext while문 걸어줌

			 {

				 if (pdata == '.')   // LNext(2번)가 .인 경우

				 {

					 LNext(&plist, &pdata);  // LNext(3번) 값 확인

					 if (pdata == '.')       // r그 다음 노드(3번)도 .인 경우

					 {

						 LRemove(&plist);    // 해당 노드 (3번) LRemove, cur은 이전 노드 (2번)로

						 LPrev(&plist, &pdata);  // cur을  while문에서 LNext가 실행되기 이전 노드로 (2번 노드 전인 1번 노드). while문 다시 돌면 2번 노드 확인, .일 경우 4번 노드 확인

					 }

				 }

			 }

		 }

	}

	else    // LCount(&plist) < 2

		return;

}



// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.

void Stage4(List plist, Data pdata)
{

	if (LFirst(&plist, &pdata)) // LFirst 조회

		if (pdata == '.')   // LFirst가 .인 경우

			LRemove(&plist);    // LRemove로 노드 지움



	if (LLast(&plist, &pdata))  // LLast 조회

		if (pdata == '.')   // LLast가 .인 경우

			LRemove(&plist);    // LRemove로 노드 지움

}



// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.


void Stage5(List plist, Data pdata)
{
		
     	if (LFirst(&plist, &pdata) == 0)    // 연결리스트가 비었으면

		LInsert(&plist, 'a');   // 'a' 집어넣기

}


/* 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
 *         만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.*/


void Stage6(List plist, Data pdata)
{
	
    	if (LCount(&plist) >= 16)   // LCount가 16 이상인 경우

	{

		LFirst(&plist, &pdata);

		for (int i = 2; i < 16; i++)   // 1번째 LNext는 2번째 노드, 15번째 노드까지 출력하므로 i<=15를 하고

		{

			LNext(&plist, &pdata);


		}   // 반복문 나왔을 때 15번째 노드 대기, 이 이후부터는 지워주면 됨

		
		while (LNext(&plist, &pdata))
	        
		    	LRemove(&plist);    // 지워줌


		LLast(&plist, &pdata);  // 마지막 노드 확인

		if (pdata == '.')       // .인 경우 지우기
			
			LRemove(&plist);
		    
	}

}


// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

void Stage7(List plist, Data pdata)
{
	
    	LFirst(&plist, &pdata); // cur을 맨 처음으로 옮겨줌

	if (LNext(&plist, &pdata) == 0)  // LCount가 1(LFirst만 존재)인 경우

	{

		LLast(&plist, &pdata);  // LLast값 확인

		LMultiply(&plist);      // LLast 를 복사해서 붙여넣기(2번노드)

		LMultiply(&plist);      // LLast를 복사해서 붙여넣기(3번노드)

	}


	
	LFirst(&plist, &pdata); // cur을 맨 처음으로 옮겨줌

	if (LNext(&plist, &pdata))  // LCount가 2(2번째 노드까지 존재)인 경우

	{

		if (LNext(&plist, &pdata) == 0)  // 3번째 노드는 비어있음

		{

			LLast(&plist, &pdata);  // LLast값 확인

			LMultiply(&plist);      // LLast 를 복사해서 붙여넣기(2번노드)

		}

	}

}
