#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define MAP_SIZE 10
#define VISIBLE_SIZE 3
#define NUM_KEYS 3
#define NUM_ITEMS 5

// 맵을 출력하는 함수
void printMap(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
    system("cls"); // 화면을 지우기
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
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
void initializeMap(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = ' '; // 빈 공간으로 초기화
        }
    }

    srand(time(NULL));

    for (int i = 0; i < NUM_ITEMS; i++) {
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        map[x][y] = 'I';
    }
}

// 플레이어 움직임
void movePlayer(int* playerX, int* playerY, char direction) {
    switch (direction) {
    case 'w':
        if (*playerX > 0) (*playerX)--;
        break;
    case 's':
        if (*playerX < MAP_SIZE - 1) (*playerX)++;
        break;
    case 'a':
        if (*playerY > 0) (*playerY)--;
        break;
    case 'd':
        if (*playerY < MAP_SIZE - 1) (*playerY)++;
        break;
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    int playerX = MAP_SIZE / 2;
    int playerY = MAP_SIZE / 2;
    char input;

    initializeMap(map);

    while (1) {
        printMap(map, playerX, playerY);

        input = _getch();

        if (input == 'q') break;

        movePlayer(&playerX, &playerY, input);
    }

    return 0;
}

