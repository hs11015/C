// main.c
#include "header.h"

int main(void)
{
    int row = 2, col = 1;
    char level;
    CursorView(0);
    GotoXY(XP, YP - 3);
    printf("미로 찾기 게임\n");
    GotoXY(XP, YP - 2);
    printf("난이도를 선택하세요. (1, 2, 3) : ");
    scanf("%c", &level);    // 헤더파일에서 #define _CRT_SECURE_NO_WARNINGS 써줌
    start = clock();    // 시작 시간
    LoadMaze(level);

    while (1)
    {
        PrintMazeGame();
        MoveMaze(&row, &col);
    }
}