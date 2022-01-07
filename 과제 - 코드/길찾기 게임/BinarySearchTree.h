/*제목 : 길찾기 게임 문제(과제 5)
 * 생성자 : 김현서(202012468)
 * 생성날짜 : 2021-05-25*/

#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

typedef int BTData;		// 숫자 데이터(index)

typedef int NodeInfo;		// x좌표와 y좌표의 정보를 넣어주기 위해 첨가

typedef struct _bTreeNode	// 이진 트리의 노드를 표현한 구조체
{

	BTData data;

	NodeInfo xpos;			// 이진탐색에서 키가 된다.

	NodeInfo ypos;			// 이진탐색에서 키가 된다.

	struct _bTreeNode* left;	// 왼쪽으로 가는 포인터

	struct _bTreeNode* right;	// 오른쪽으로 가는 포인터

} BTreeNode;

typedef struct _bTree	// 이진 트리 표현 구조체
{

	BTreeNode* head;	// tree 내에서 사용할 수 있는 포인터 만듦. 이건 맨 처음 노드를 마킹 해줌

	BTreeNode* cur;		// tree 내에서 사용할 수 있는 포인터 만듦. 이건 현재 보고 있는 노드를 마킹해줌

	BTreeNode* before;	// tree 내에서 사용할 수 있는 포인터 만듦. 이건 cur 이전에 본 노드를 마킹해줌

	BTreeNode* tail;	// tree 내에서 사용할 수 있는 포인터 만듦. 이건 새로 만든 노드를 마킹해줌

} BTree;


typedef BTree Tree;		// 연결리스트 때 배웠던 것을 응용. Tree 구조체 선언,


void TreeInit(Tree* ptree);		// 트리 초기화

void TreeFInsert(Tree* ptree, BTData data, NodeInfo xpos, NodeInfo ypos);	// 첫 번째 트리 노드 입력

void TreeInsert(Tree* ptree, BTData data, NodeInfo xpos, NodeInfo ypos);	// 트리 노드 입력



BTreeNode* TFirst(Tree* ptree);	// 트리의 1번째 노드 데이터 조회

void TSearch(Tree* ptree, BTData target, NodeInfo xpos, NodeInfo ypos);	// 필요한 데이터 찾기

void MakeLeftSubTree(Tree* ptree);	// 매개변수 sub로 전달된 트리 또는 노드를 매개변수 main으로 전달된 노드의 왼쪽 서브 트리로 연결
void MakeRightSubTree(Tree* ptree);	// 매개변수 sub로 전달된 트리 또는 노드를 매개변수 main으로 전달된 노드의 오른쪽 서브 트리로 연결

void PreorderTraverse(BTreeNode* bt);	// 전위 순회 함수

void PostorderTraverse(BTreeNode* bt);	// 후위 순회 함수

#endif

