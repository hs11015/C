/*제목 : 길찾기 게임 문제(과제 5)
 * 생성자 : 김현서(202012468)
 * 생성날짜 : 2021-05-25*/

#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

void TreeInit(Tree* ptree) {		// 트리 초기화

	ptree->head = NULL;				// 트리의 head 포인터 초기화

	ptree->before = NULL;			// 트리의 before 포인터 초기화

	ptree->cur = NULL;				// 트리의 cur 포인터 초기화

	ptree->tail = NULL;				// 트리의 tail 포인터 초기화
}


void TreeFInsert(Tree* ptree, BTData data, NodeInfo xpos, NodeInfo ypos) {	// 트리 노드 입력

	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));	// 새 노드 생성

	newNode->data = data;		// 새 노드에 데이터 저장

	newNode->xpos = xpos;		// 새 노드에 x좌표 저장

	newNode->ypos = ypos;		// 새 노드에 y좌표 저장


	
	newNode->left = NULL;		// left와 right 모두 NULL

	newNode->right = NULL;


	
	ptree->head = newNode;		// head 포인터를 새 노드로(첫 노드이자 루트 노드)

	ptree->tail = newNode;		// tail 포인터를 새 노드로(마지막 노드)

	ptree->before = ptree->cur;	// 현재 cur이 가리키는 노드 -> before이 가리킴(NULL)

	ptree->cur = ptree->tail;	// 현재 tail이 가리키는 노드 -> cur이 가리킴(새 노드)

}


void TreeInsert(Tree* ptree, BTData data, NodeInfo xpos, NodeInfo ypos) {	// 트리 노드 입력

	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));	// 새 노드 생성

	newNode->data = data;		// 새 노드에 데이터 저장

	newNode->xpos = xpos;		// 새 노드에 x좌표 저장

	newNode->ypos = ypos;		// 새 노드에 y좌표 저장


	
	newNode->left = NULL;	// left와 right 모두 NULL

	newNode->right = NULL;


	
	ptree->tail = newNode;		// tail은 newnode

	ptree->before = ptree->cur;	// 이전 노드를 가리키는 포인터 before로 이동 전의 cur을 가리킴

	ptree->cur = ptree->tail;	// cur 포인터를 tail로 옮김(새 노드)

}



BTreeNode* TFirst(Tree* ptree) {	// 트리의 1번째 노드 데이터 조회

	ptree->cur = ptree->head;	// cur이 첫 번째 노드를 가리키게 함

	return ptree->cur;

}



void TSearch(Tree* ptree, BTData target, NodeInfo xpos, NodeInfo ypos) {	// 필요한 데이터 찾기



	ptree->cur = ptree->head;		// cur 포인터가 첫 번째 노드, 즉 트리의 루트 노드를 가리키도록 함


	
	while (1) {


		
		if (ptree->cur->ypos > ypos) {	// cur이 가리키고 있는 노드의 ypos가 TSearch 함수의 ypos보다 클 때

			if (ptree->cur->xpos > xpos) {	// cur이 가리키고 있는 노드의 xpos가 TSearch 함수의 xpos보다 클 때

				ptree->before = ptree->cur;	// before 포인터를 cur이 가리키고 있는 노드로 옮긴다

				ptree->cur = ptree->cur->left;	// 그리고 cur을 cur이 가키리고 있는 노드의 left 포인터를 따라 왼쪽 아래 서브 노드로 옮긴다

			}

			else if (ptree->cur->xpos < xpos) {	// cur이 가리키고 있는 xpos가 TSearch 함수의 xpos보다 작을 때

				ptree->before = ptree->cur;		// before 포인터를 cur이 가리키고 있는 노드로 옮긴다

				ptree->cur = ptree->cur->right;	// 그리고 cur을 cur이 가키리고 있는 노드의 right 포인터를 따라 오른쪽 아래 서브 노드로 옮긴다

			}

		}

		else if (ptree->cur->ypos <= ypos) {	// cur이 가리키고 있는 노드의 ypos가 TSearch 함수의 ypos보다 작거나 같을 때

			if (ptree->cur->xpos != xpos) {	// cur이 가리키고 있는 노드의 xpos가 TSearch 함수의 xpos와 같지 않다면

				ptree->cur = ptree->before;	// cur 포인터를 before이 가리키고 있는 노드로 옮긴다(이전 노드)

				if (ptree->cur->ypos > ypos) {	// cur이 가리키고 있는 노드의 ypos가 수의 ypos보다 작거나 클 때(이전과 같은 선택지에서)

					if (ptree->cur->xpos > xpos) {	// cur이 가리키고 있는 노드의 xpos가 TSearch 함수의 xpos보다 클 때

						ptree->before = ptree->cur;

						ptree->cur = ptree->cur->right;	// 전과는 다르게 cur이 right쪽으로 간다

					}

					else if (ptree->cur->xpos < xpos) {	// cur이 가리키고 있는 xpos가 TSearch 함수의 xpos보다 작을 때

						ptree->before = ptree->cur;

						ptree->cur = ptree->cur->left;	// 전과는 다르게 cur이 left쪽으로 간다

					}

				}

			}

			else {	//(ptree->cur->xpos == xpos) 만약 cur이 가리키고 있는 노드의 xpos와 TSearch 함수의 xpos가 같다면

				if (ptree->cur->data == target)		// cur이 가리키고 있는 노드의 data가 TSearch 함수의 target과 같은 것 확인하고

					break;	//while문을 벗어난다.

			}

		}

	}

}



void MakeLeftSubTree(Tree* ptree)	// 왼쪽 서브 트리를 연결

{

	if (ptree->cur->left != NULL)	// 만약 cur이 가리키는 노드의 left 포인터가 NULL이 아니라면

		free(ptree->cur->left);		// 동적 할당을 풀어준다.


	
	ptree->cur->left = ptree->tail;	// cur이 가리키는 노드의 left 포인터를 tail이 가리키는 노드로 옮긴다.

	ptree->before = ptree->cur;		// before 포인터를 cur이 가리키는 노드로 옮긴다.(부모 노드)

	ptree->cur = ptree->tail;		// cur 포인터를 tail이 가리키는 노드로 옮긴다.(서브 노드)

}



void MakeRightSubTree(Tree* ptree)	// 오른쪽 서브 트리를 연결

{

	if (ptree->cur->right != NULL)	// 만약 cur이 가리키는 노드의 right 포인터가 NULL이 아니라면

		free(ptree->cur->right);	// 동적 할당을 풀어준다.


	
	ptree->cur->right = ptree->tail;	// cur이 가리키는 노드의 right 포인터를 tail이 가리키는 노드로 옮긴다.

	ptree->before = ptree->cur;		// before 포인터를 cur이 가리키는 노드로 옮긴다.(부모 노드)

	ptree->cur = ptree->tail;		// cur 포인터를 tail이 가리키는 노드로 옮긴다.(서브 노드)

}



void PreorderTraverse(BTreeNode* bt)	// 전위 순회 함수

{

	if (bt == NULL)	// bt가 NULL이면 그만

		return;


	
	printf("%d,", bt->data);	 // 노드의 방문(print 하기)

	PreorderTraverse(bt->left);		// bt의 left 포인터가 가리키는 노드의 전위 순회 함수

	PreorderTraverse(bt->right);	// bt의 right 포인터가 가리키는 노드의 전위 순회 함수

}



void PostorderTraverse(BTreeNode* bt)	// 후위 순회 함수

{

	if (bt == NULL)	// bt가 NULL이면 그만

		return;


	
	PostorderTraverse(bt->left);	// bt의 left 포인터가 가리키는 노드의 후위 순회 함수

	PostorderTraverse(bt->right);	// bt의 right 포인터가 가리키는 노드의 후위 순회 함수

	printf("%d,", bt->data);	 // 노드의 방문(print 하기)

}
