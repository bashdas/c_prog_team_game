#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define MAP_SIZE 10
#define VISIBLE_SIZE 3
#define NUM_KEYS 3
#define NUM_ITEMS 5

// ���� ����ϴ� �Լ�
void printMap(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
    system("cls"); // ȭ���� �����
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
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
void initializeMap(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = ' '; // �� �������� �ʱ�ȭ
        }
    }

    srand(time(NULL));

    for (int i = 0; i < NUM_ITEMS; i++) {
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        map[x][y] = 'I';
    }
}

// �÷��̾� ������
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

