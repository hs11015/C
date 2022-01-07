/*중간고사 대체 과제 : 검열 프로그램 작성
 * 생성날짜 : 2021-05-04
 * 생성자 : 김현서*/


#include <stdio.h>
#include <string.h>		// 문자열 관련 헤더파일
#include <stdlib.h>		// 동적할당 헤더파일
#include "ListBaseStack.h"

void Input_Data(char string[], Stack* stack);	// 배열로 입력받은 문자 스택에 집어넣기
void Sequencing_Data(Stack* stack_original, Stack* stack_new);	// 스택에서 스택으로 옮기기(정순→역순)
void Remove_Data(Stack* stack_sentence_original, Stack* stack_senctence_new, Stack* stack_word_original, Stack* stack_word_new);	// 검열 후 단어 지우기

int main(void)
{
	Stack stack_reverse_T;	// stack_reverse_T 생성(T를 입력받은 역순으로 갖고있는 스택)
	Stack stack_T;	// stack_T 생성(T를 입력받은 순서대로 갖고있는 스택)
	Stack stack_reverse_A;	// stack_reverse_A 생성(A를 입력받은 역순으로 갖고있는 스택)
	Stack stack_A;	// stack_A 생성(A를 입력받은 순서대로 갖고있는 스택)
	
    	StackInit(&stack_reverse_T);	// stack_reverse_T 초기화
	StackInit(&stack_T);	// stack_T 초기화
       	StackInit(&stack_reverse_A);	// stack_reverse_A 초기화
	StackInit(&stack_A);	// stack_A 초기화

    	char str_T[300001] = { 0, };	// 0~300001, 즉 300002자까지 입력이 가능하나, 마지막은 \0, 마지막에서 두 번째는 \n을 입력할 공간 필요(실제로는 300000자까지 입력 가능)
	char str_A[26] = { 0, };		// 0~26, 즉 27자까지 입력이 가능하나, 마지막은 \0, 마지막에서 두 번째는 \n을 입력할 공간 필요(실제로는 25자리까지 입력 가능)

    	printf("삭제할 단어를 입력하세요 : ");
    	fgets(str_A, 26, stdin);		// gets는 10 이상의 단어를 입력 하기에 부적합. 그래서 fgets 이용. 표준 입력 stdin 버퍼에서 문자열을 가져옴   
       	printf("입력한 단어 : %s\n", str_A);	// str_A에 입력된 단어들을 출력
   
       	printf("텍스트 전체를 입력하세요 : ");
    	fgets(str_T, 300001, stdin);		// gets는 10 이상의 단어를 입력 하기에 부적합. 그래서 fgets 이용. 표준 입력 stdin 버퍼에서 문자열을 가져옴	
       	printf("입력한 문장 : %s\n", str_T);	// str_T에 입력된 단어들을 출력

    	Input_Data(str_T, &stack_reverse_T);	// str_T에 입력받은 데이터를 stack_reverse_T에 저장
       	Input_Data(str_A, &stack_reverse_A);	// str_A에 입력받은 데이터를 stack_reverse_A에 저장

    	Sequencing_Data(&stack_reverse_T, &stack_T);	// 역순으로 저장된 T(stack_reverse_T)를 입력받은 순서대로 stack-T에 저장하는 과정
	Sequencing_Data(&stack_reverse_A, &stack_A);	// 역순으로 저장된 A(stack_reverse_A)를 입력받은 순서대로 stack_A에 저장하는 과정

	Remove_Data(&stack_T, &stack_reverse_T, &stack_A, &stack_reverse_A);	// 입력된 단어가 문장 안에 있다면 조건에 제시된 순서대로 지워주는 과정

    	if (SIsEmpty(&stack_T))		// stack_T가 비어있다면(stack_T가 stack_sentence original 이었다면)
		Sequencing_Data(&stack_reverse_T, &stack_T);		// stack_reverse_T(stack_sentence_new)를 역순으로 stack_T에 저장

    	printf("삭제 후의 단어 : ");
      	while (!SIsEmpty(&stack_T))	// stack_T에 남아있는 스택이 없을 때까지
		printf("%c", SPop(&stack_T));	// stack_T에 들어있는 스택들 하나씩 SPop으로 printf 하기

    	printf("\n");	// 가독성을 높이기 위함 없어도 되는 문장

       	return 0;

}



void Input_Data(char string[], Stack* stack)	// 데이터 넣기
{
	int i = 0;
	
	while (1)
	{
		if (string[i] == '\n')	// string에 입력된 데이터가 없다면(fgets 함수는 \n도 문자열로 받아들임)	
			break;		// 반복문을 빠져나옴

		SPush(stack, string[i]);	// string에 입력된 데이터가 있다면 stack에 집어넣기
		i++;	// index 하나씩 늘려주기
	}
}



void Sequencing_Data(Stack *stack_original, Stack *stack_new)	// stack_original와 역순인 stack_new를 갖게된다.
{
	while (!SIsEmpty(stack_original))	// 원래 스택(stack_original)이 비어있지 않다면
		SPush(stack_new, SPop(stack_original));	// 새로운 스택(stack_new)에 원래 스택의 pop한 값을 집어넣는다.
}


void Remove_Data(Stack *stack_sentence_original, Stack* stack_sentence_new, Stack* stack_word_original, Stack *stack_word_new)		// 원래 문장, 새로운 문장, 원래 단어, 새로운 단어 입력.
{
	Stack temp_sentence;	// word와 중복되는 sentence 단어 역순으로 임시 저장
	Stack temp_word;		// sentence 단어와 중복되는 word 역순으로 임시 저장

	StackInit(&temp_sentence);	// temp_sentence 초기화
	StackInit(&temp_word);		// temp_word 초기화

	int original_sentence_length = SCount(stack_sentence_original);		// 원래 문장의 길이를 original_sentence_length에 저장해두기

	while (1)
	{
		if (!SIsEmpty(stack_sentence_original) && !SIsEmpty(stack_word_original))	// 원래 문장과 원래 단어 모두 비어있지 않다면
		{
			while (SPeek(stack_sentence_original) == SPeek(stack_word_original))	// 원래 문장과 원래 단어의 맨 위 스택이 같을 때
			{
				SPush(&temp_sentence, SPop(stack_sentence_original));		// 원래 문장의 맨 위 스택을 temp_sentence에 저장
				SPush(&temp_word, SPop(stack_word_original));				// 원래 단어의 맨 위 스택을 temp_word에 저장

				if (SIsEmpty(stack_word_original) || SIsEmpty(stack_sentence_original))	// 만약 원래 단어나 원래 문장이 비어있다면
					break;
			}	// 결론적으로 원래 문장과 원래 단어가 같은 스택들이 쌓여 temp_sentence와 temp_word에 각각 역순으로 저장되었을 것임
		}

		
		if (!SIsEmpty(stack_word_original))		// 원래 단어 스택이 비어있지 않다면
		{
			Sequencing_Data(&temp_sentence, stack_sentence_original);	// temp_sentence에 저장한 스택을 다시 원래 문장에 돌려넣음(원래 순서대로)
			Sequencing_Data(&temp_word, stack_word_original);			// temp_word에 저장한 스택을 다시 원래 단어에 돌려넣음(원래 순서대로)
		}

		else if (SIsEmpty(stack_word_original))		// 원래 단어 스택이 비어있다면
		{
			Sequencing_Data(&temp_word, stack_word_original);				// temp_word에 담아두었던 단어를 원래 단어 스택에 넣음(원래 순서대로)
			Sequencing_Data(stack_word_original, stack_word_new);	// 원래 단어 스택에 옮긴 단어를 새로운 단어 스택에 넣음(stack_word_original과는 역순으로)
			Sequencing_Data(stack_sentence_original, stack_sentence_new);	// 남은 원래 문장을 새로운 문장에 옮김(temp_sentence에 담은 스택 버림 & stack_sentence_original과는 역순으로)
		}
		
		if (!SIsEmpty(stack_sentence_original))		// 원래 문장이 비어있지 않다면 
			SPush(stack_sentence_new, SPop(stack_sentence_original));	// stack_sentence_original의 맨 위 스택을 stack_sentence_new로 옮기기
	
		else if (SIsEmpty(stack_sentence_original))		// 원래 문장이 비어있다면
		{
			Sequencing_Data(&temp_word, stack_word_original);				// temp_word에 담아두었던 단어를 원래 단어 스택에 넣음(원래 순서대로)
			Sequencing_Data(stack_word_original, stack_word_new);	// 원래 단어 스택에 옮긴 단어를 새로운 단어 스택에 넣음(steck_word_original과는 역순으로)
			break;		
		}
	}
	// stack_sentence_original과 stack_word_original은 비어있는 스택이 되고,
	// stack_sentence_new는 원래 문장의 맨 앞에 나오는 원래 단어를 제거한 원래 문장의 역순으로 저장이 되고, stack_word_new는 원래 단어의 역순으로 저장이 된다.
	
	if (original_sentence_length != SCount(stack_sentence_new))		// while문이 실행(stack_sentence_original이 비어있는 스택이)되기 전에 저장해두었던 원래 문장의 길이와 새로운 문장의 길이가 다르다면
	Remove_Data(stack_sentence_new, stack_sentence_original, stack_word_new, stack_word_original);		// 새로운 문장, 원래 문장, 새로운 단어, 원래 단어를 입력하는 재귀 함수를 생성한다.
	// 이렇게 하면 입력된 문장 맨 앞에서부터 입력된 단어를 순서대로 제거할 수 있고, 다음으로는 입력된 문장 맨 뒤에서부터 입력된 단어를 역순으로 제거할 수 있다.
	// 그리고 이 과정은 입력된 문장에서 입력된 단어들이 발견되지 않을 떄까지 진행된다.
}
