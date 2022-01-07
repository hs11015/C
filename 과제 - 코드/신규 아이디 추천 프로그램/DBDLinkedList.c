/*제목: 신규 아이디 추천 프로그램 작성
 * 생성자 : 202012468 김현서
 * 생성날짜 : 2021-04-13*/

#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));	// 맨 앞, 맨 왼쪽에 더미노드 만들어주기

	plist->tail = (Node*)malloc(sizeof(Node));	// 맨 뒤, 맨 오른쪽에 더미노드 만들어주기


	
	plist->head->prev = NULL;			// head의 이전 노드가 존재하지 않음

	plist->head->next = plist->tail;	// head의 다음 노드는 tail임


	
	plist->tail->next = NULL;			// tail의 다음 노드가 존재하지 않음

	plist->tail->prev = plist->head;	// tail의 이전 노드는 head임


	
	plist->numOfData = 0;				// head와 tail은 더미노드이므로 초기화 했을 때의 노드 개수는 0개

}



void LInsert(List * plist, Data data) 
{

	Node * newNode = (Node*)malloc(sizeof(Node));	// newNode 동적할당으로 할당해주기

	newNode->data = data;	// newNode의 데이터는 LInsert 함수 내의 data와 같다


	
	newNode->prev = plist->tail->prev;	// newNode의 prev 포인터를 tail의 prev가 가리키는 노드와 연결

	plist->tail->prev->next = newNode;	// tail 이전 노드의 next 포인터는 newNode를 가리킴


	
	newNode->next = plist->tail;	// newNode의 next 포인터는 tail을 가리킴

	plist->tail->prev = newNode;	// tail의 prev 포인터는 newNode를 가리킴


	
	(plist->numOfData)++;	// newNode가 연결리스트에 추가되었으므로 1개 추가함

}



void LChange(List* plist, Data data)	// 같은 노드의 데이터를 변경하는 함수를 추가함
{

	Node* newNode = (Node*)malloc(sizeof(Node));	// newNode 동적할당으로 할당해주기

	newNode->data = data;	// newNode의 데이터는 LChange 함수 내의 data와 같다


	
	newNode->next = plist->cur->next;	// newNode의 next 포인터는 cur의 다음 노드를 가리킴

	plist->cur->next->prev = newNode;	// cur 다음 노드의 prev 포인터는 newNode를 가리킴


	
	newNode->prev = plist->cur;	// newNode의 prev 포인터를 cur(cur의 next)을 가리킴

	plist->cur->next = newNode;	// cur 노드의 next 포인터는 newNode를 가리킴


	
	plist->cur = plist->cur->next;	// cur 포인터를 newNode로 옮겨서 LNext를 실행했을 때 바로 다음 노드로 넘어가도록 함


	
	(plist->numOfData)++;	// newNode가 연결리스트에 추가되었으므로 1개 추가함

}


void LMultiply(List* plist)		// 현재 노드를 복사해주는 함수
{

	Data data = plist->cur->data;	// data에 현재 노드의 data 값을 집어넣음


	LChange(plist, data);	// cur 이후에 바로 data 값을 갖는 함수를 삽입해주는 함수

}



int LFirst(List * plist, Data * pdata)
{

	if(plist->head->next == plist->tail)

		return FALSE;


	plist->cur = plist->head->next;

	*pdata = plist->cur->data;

	return TRUE;

}


int LNext(List * plist, Data * pdata)
{

	if(plist->cur->next == plist->tail)

		return FALSE;


	
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;

}


int LPrev(List* plist, Data* pdata)	// 이전 노드를 읽어들임
{

	if (plist->cur->prev == plist->head)	// cur의 이전 노드가 head를 가리키고 있는 경우 FALSE 반환

		return FALSE;


	
	plist->cur = plist->cur->prev;	// cur 포인터를 cur의 prev 포인터가 가리키고 있는 노드로 옮김

	*pdata = plist->cur->data;		// pdata를 cur의 data로 지정

	return TRUE;

}


int LLast(List* plist, Data* pdata)		// 새로 추가한 함수. 마지막 값을 알 수 있음
{

	if (plist->tail->prev == plist->head)	// tail의 이전 노드가 head라면 빈 연결리스트이기 때문에 FALSE 반환

		return FALSE;


	
	plist->cur = plist->tail->prev;		// cur 포인터를 tail의 이전 노드로 옮김

	*pdata = plist->cur->data;	// *pdata는 cur이 가리키고 있는 data를 의미함

	return TRUE;

}


Data LRemove(List * plist)	// 현재 노드를 없애는 함수
{

	Node * rpos = plist->cur;

	Data remv = rpos->data;


	
	plist->cur->prev->next = plist->cur->next;	// cur 이전 노드의 next는 cur의 next와 같다

	plist->cur->next->prev = plist->cur->prev;	// cur 다음 노드의 prev는 cur의 prev와 같다


	
	plist->cur = plist->cur->prev;    // cur의 위치를 재조정


	
	free(rpos);

	(plist->numOfData)--;

	return remv;

}

int LCount(List * plist)
{

	return plist->numOfData;

}
