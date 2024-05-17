#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

#define VISIBLE_SIZE 3
#define NUM_KEYS 3
#define NUM_ITEMS 5

// ���� ����ϴ� �Լ�
void printMap(char map[MAP_WIDTH][MAP_HEIGHT], int playerX, int playerY) {
    system("cls"); // ȭ���� �����
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            // �þ� ���� ������ Ȯ��
            if (i >= playerX - 1 && i <= playerX + 1 && j >= playerY - 1 && j <= playerY + 1)
                printf("%c ", map[i][j]);
            else if ((i == playerX - 2 || i == playerX + 2) && (j >= playerY - 2 && j <= playerY + 2) ||
                (j == playerY - 2 || j == playerY + 2) && (i >= playerX - 2 && i <= playerX + 2)) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                printf("��");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// ���������� ��ġ
void initializeMap(char map[MAP_WIDTH][MAP_HEIGHT]) {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = ' '; // �� �������� �ʱ�ȭ
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