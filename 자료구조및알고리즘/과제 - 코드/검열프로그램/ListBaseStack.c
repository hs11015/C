/*중간고사 대체 과제 : 검열 프로그램 작성
 * 생성날짜 : 2021-05-04
 * 생성자 : 김현서*/

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)	// 시작
{
	pstack->head = NULL;	// 포인터 변수 head는 NULL로 초기화한다
	pstack->numOfData = 0;
}

int SIsEmpty(Stack* pstack)		// 비어있는지 확인
{
	if (pstack->head == NULL)	// 스택이 비면 head에는 NULL이 저장된다
		return TRUE;		// numOfData == 0으로 해도 됨
	else	// pstack->head != NULL
		return FALSE;
}

void SPush(Stack* pstack, Data data)	// 리스트의 머리에 새 노드를 추가
{
	Node* newNode = (Node*)malloc(sizeof(Node));	// 새 노드 생성

	newNode->data = data;			// 새 노드에 데이터 저장
	newNode->next = pstack->head;		// 새 노드가 최근에 추가된 노드를 가리킴

	pstack->head = newNode;			// 포인터 변수 head가 새 노드를 가리킴
	(pstack->numOfData)++;
}

Data SPop(Stack* pstack)	// head가 가리키는 노드 소멸, 소멸된 노드 데이터 반환
{
	Data rdata;
	Node* rnode;	// 지울 노드를 가리키는 Node(remove Node)

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!!");
		exit(-1);
	}

	rdata = pstack->head->data;		// 삭제할 노드의 데이터를 임시로 저장
	rnode = pstack->head;			// 삭제할 노드의 주소 값을 임시로 저장

	pstack->head = pstack->head->next;	// 삭제할 노드의 다음 노드를 head가 가리킴

	free(rnode);	// 노드 삭제

	(pstack->numOfData)--;

	return rdata;	// 삭제된 노드의 데이터 반환
}

Data SPeek(Stack* pstack)	// head가 가리키는 노드 데이터를 읽어옴
{
	if (SIsEmpty(pstack)) {		// stack이 0만 아니면 됨
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;	// head가 가리키는 노드에 저장된 데이터 반환
}

int SCount(Stack* pstack)		// 스택에 쌓인 데이터의 개수를 의미
{
	return pstack->numOfData;	// 스택의 개수를 반환
}
