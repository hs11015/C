/*제목: 신규 아이디 추천 프로그램 작성
 * 생성자 : 202012468 김현서
 * 생성날짜 : 2021-04-13*/

#ifndef __DBD_LINKED_LIST_H__
#define __DBD_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	
	struct _node * next;

	struct _node * prev;
} Node;

typedef struct _dbDLinkedList
{

	Node * head;

	Node * tail;	// Dummy Node를 추가하기 위해 tail 포인터를 추가함

	Node * cur;

	int numOfData;

} DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);
void LChange(List* plist, Data data);	// 같은 노드의 데이터를 변경하는 것을 말함
void LMultiply(List* plist);	// 노드를 복사해주는 함수

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrev(List* plist, Data* pdata);	// 이전 노드를 읽어들임
int LLast(List* plist, Data* pdata);	// 맨 마지막 노드를 읽어들임(tail 앞)

Data LRemove(List * plist);	// LPrevious 대신 쓰임.

int LCount(List * plist);

#endif
