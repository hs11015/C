/*중간고사 대체 과제 : 검열 프로그램 작성
 * 생성날짜 : 2021-05-04
 * 생성자 : 김현서*/

#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node	// 연결 리스트의 노드를 표현한 구조체
{
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack	// 연결 리스트 기반 스택을 표현한 구조체
{
	Node* head;
	int numOfData;		// 숫자 세기 위함
} ListStack;


typedef ListStack Stack;

void StackInit(Stack* pstack);		// 스택 초기화
int SIsEmpty(Stack* pstack);		// 스택이 비었는지 확인

void SPush(Stack* pstack, Data data);	// 스택의 push 연산(data를 pstack에 추가)
Data SPop(Stack* pstack);		// 스택의 pop 연산(pstack의 맨 위 스택을 return하고, 제거함)
Data SPeek(Stack* pstack);		// 스택의 peek 연산(pstack의 맨 위 스택을 읽어들여 return함)
int SCount(Stack* pstack);		// 스택의 count(숫자 세기) 연산(스택이 몇 개 있는지 세어 return함)

#endif
