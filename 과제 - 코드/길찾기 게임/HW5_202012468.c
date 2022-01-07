/*제목 : 길찾기 게임 문제(과제 5)
 * 생성자 : 김현서(202012468)
 * 생성날짜 : 2021-05-25*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BinarySearchTree.h"


int main() {

	char arrays[10000] = { 0, };

	int cnt = 0, j = 0;	// cnt는 데이터 개수, i, j는 index


	
	printf("입력 : ");



	fflush(stdin);	// stdin 비워주기

	fgets(arrays, 10000, stdin);	// arrays에 입력


	
	int arrLen = strlen(arrays);

	int nodeinfo[10000][3] = { {0, 0, 0}, };	// 문제에서 사용하라고 나온 이차원배열(nodeinfo)


	for (int i = 0; i <= arrLen; i++) {
	
		int temp_x = 0, temp_y = 0;		// temp_x, temp_y 초기화


		
		while (arrays[i] >= 48 && arrays[i] <= 57) {	// ASCII code 48 = 10진수 '0' ~ ASCII code 57 = 10진수 '9'

			temp_x = temp_x * 10 + arrays[i] - 48;	// 한 자리수씩 올라가기 때문에 (이전 수 *10), 48을 빼주는 이유는 아스키 코드에서 정수로 바꾸기 위함

			i++;
		}


		if (arrays[i] == ',') {

			nodeinfo[j][0] = temp_x;

			i++;

		}


		
		if (arrays[i] == ' ') {	// 띄어쓰기 포함일 경우. 포함하지 않더라도 이 부분은 if문이라 영향 없음

			i++;

		}


		
		while (arrays[i] >= 48 && arrays[i] <= 57) {	// ASCII code 48 = 10진수 '0' ~ ASCII code 57 = 10진수 '9'

			temp_y = temp_y * 10 + arrays[i] - 48;	// 한 자리수씩 올라가기 때문에 (이전 수 *10), 48을 빼주는 이유는 아스키 코드에서 정수로 바꾸기 위함

			i++;
		}

		if (arrays[i] == ']') {
			
			nodeinfo[j][1] = temp_y;

			j++;

			i++;

			if (arrays[i] == ']')	// 만약 닫히는 괄호가 두 번 나올 경우, 이후 입력된 것이 없을 것이기 떄문에 break 해줌

				break;

		}

	}

	int node_num = j;	// 여기서 j의 수는 nodeinfo의 행의 개수와 같음(마지막에 j에 1을 더해줘서)


	for (int k = 0; k < node_num; k++) {

		nodeinfo[k][2] = k+1;	// 각 노드가 갖는 data를 nodeinfo 이차원 배열에 넣어줌

	}


	for (int i = 0; i < node_num; i++) {

		for (int j = 0; j < (node_num - 1); j++) {

			if (nodeinfo[j][1] < nodeinfo[j + 1][1]) {	// nodeinfo를 ypos 값에 따라 내림차순 정렬

				for (int m = 0; m < 3; m++) {			// 단, 행의 순서만 바꿀 것이기 때문에 ypos 값에 따라 모든 열을 한 번에 이동시켜줌.

					int temp = nodeinfo[j][m];			// 바꿀 타일 임시 저장

					nodeinfo[j][m] = nodeinfo[j + 1][m];

					nodeinfo[j + 1][m] = temp;

				}

			}

		}

	}

	for (int i = 0; i < node_num; i++) {
		
		for (int j = 0; j < (node_num - 1); j++) {

			if ((nodeinfo[j][1] == nodeinfo[j + 1][1]) && (nodeinfo[j][0] > nodeinfo[j + 1][0])) {	// 만약 ypos의 값이 같은 경우 xpos 값에 따라 오름차순 정렬

				for (int m = 0; m < 3; m++) {			// 이 역시 행의 순서만 바꿀 것이기 떄문에 xpos 값에 따라 모든 열을 한 번에 이동시켜줌

					int temp = nodeinfo[j][m];			// 바꿀 타일 임시 저장

					nodeinfo[j][m] = nodeinfo[j + 1][m];

					nodeinfo[j + 1][m] = temp;

				}

			}

		}

	}	// 이때 순서는 y에 대해 내림차순, y가 같을 경우 x에 대해 오름차순. nodeinfo[i][2]는 그 노드의 data를 나타냄.


	Tree tree;	// tree 선언

	TreeInit(&tree);	// tree 초기화(아무 노드도 없음)

	
	TreeFInsert(&tree, nodeinfo[0][2], nodeinfo[0][0], nodeinfo[0][1]);	// nodeinfo[0][2]를 data로 갖고, xpos : nodeinfo[0][0], ypos : nodeinfo[0][1]인 1번째 노드 입력



	for (int k = 1; k < node_num; k++) {	// k가 node_num-1일때까지

		TreeInsert(&tree, nodeinfo[k][2], nodeinfo[k][0], nodeinfo[k][1]);	// nodeinfo[k][2]를 data로 갖고, xpos : nodeinfo[k][0], ypos : nodeinfo[k][1]인 노드 입력



		int temp_original_y = nodeinfo[0][1], temp_original_x = nodeinfo[0][0], temp_n = 0;	// y좌표, x좌표 임시저장(가장 큰 root노드, 1번째 노드를 첫 값으로 지정)

		for (int n = 0; n < k; n++) {

			if (nodeinfo[n][1] > nodeinfo[k][1]) {		// 새 노드의 y좌표보다 큰 이전 노드들

				if (temp_original_y >= nodeinfo[n][1]) {	// 새 노드보다 한 단계 더 큰 y좌표를 갖는 노드들

					temp_original_y = nodeinfo[n][1];

					if (temp_original_x > (nodeinfo[n][0] - nodeinfo[k][0])) {	// 그 중 새 노드에 가까운 x좌표

						temp_original_x = abs(nodeinfo[n][0] - nodeinfo[k][0]);

						temp_n = n;

					}

				}

			}

		}


		TSearch(&tree, nodeinfo[temp_n][2], nodeinfo[temp_n][0], nodeinfo[temp_n][1]);	// nodeinfo[temp_n][2]를 data로 갖고, xpos : nodeinfo[temp_n][0], ypos : nodeinfo[temp_n][1]인 노드 찾아 cur로 가리키기


		
		if (nodeinfo[k][0] - nodeinfo[temp_n][0] > 0)	// 만약 찾은 노드의 xpos 값이 새로 입력한 노드의 xpos보다 작다면
		
			MakeRightSubTree(&tree);	// 찾은 노드의 오른쪽 서브 노드에 새 노드를 이어줌

		else if (nodeinfo[k][0] - nodeinfo[temp_n][0] < 0)	// 만약 찾은 노드의 xpos 값이 새로 입력한 노드의 xpos보다 크다면

			MakeLeftSubTree(&tree);		// 찾은 노드의 왼쪽 서브 노드에 새 노드를 이어줌



	}


	printf("출력 : [[");
	
	PreorderTraverse(TFirst(&tree));
	
	printf("\b],[");	// \b는 마지막 반점 하나 지워주기 위함

	PostorderTraverse(TFirst(&tree));

	printf("\b]]\n");	// \b는 마지막 반점 하나 지워주기 위함


	
	return 0;
}
