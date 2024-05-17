#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

#define VISIBLE_SIZE 3
#define NUM_KEYS 3
#define NUM_ITEMS 5

// 맵을 출력하는 함수
void printMap(char map[MAP_WIDTH][MAP_HEIGHT], int playerX, int playerY) {
    system("cls"); // 화면을 지우기
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            // 시야 범위 내인지 확인
            if (i >= playerX - 1 && i <= playerX + 1 && j >= playerY - 1 && j <= playerY + 1)
                printf("%c ", map[i][j]);
            else if ((i == playerX - 2 || i == playerX + 2) && (j >= playerY - 2 && j <= playerY + 2) ||
                (j == playerY - 2 || j == playerY + 2) && (i >= playerX - 2 && i <= playerX + 2)) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("＊");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// 랜덤아이템 배치
void initializeMap(char map[MAP_WIDTH][MAP_HEIGHT]) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = ' '; // 빈 공간으로 초기화
        }
    }

    srand(time(NULL));

    for (int i = 0; i < NUM_ITEMS; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map[x][y] = 'l';
    }
}

int main() {
    char map[MAP_WIDTH][MAP_HEIGHT];
    int* location = playermove();
    int playerX = location[0];
    int playerY = location[1];

    initializeMap(map);

    while (1) {
        printMap(map, playerX, playerY);
    }

    return 0;
}