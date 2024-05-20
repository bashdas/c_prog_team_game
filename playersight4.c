#include "main.h"

#define _CRT_SECURE_NO_WARNINGS
#define range 2
#define range_ 3
#define NUM_ITEMS 5

// Ŀ�� ��ġ ������ �������� �Լ�
void getCursorPos(int* x, int* y) {
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi)) {
        *x = cbsi.dwCursorPosition.X;
        *y = cbsi.dwCursorPosition.Y;
    }
}

// ���� ����ϴ� �Լ�
void printMap(char map[MAP_HEIGHT][MAP_WIDTH], int cursorX, int cursorY) {
    system("cls"); // ȭ���� �����
    gotoxy1(MAP_X, MAP_Y);
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            // Ŀ�� ��ġ�� '��' ���
            if (i == cursorX && j == cursorY) {
                printf("�� ");
            }
            // �þ� ���� ������ Ȯ��
            else if (i >= cursorX - range && i <= cursorX + range && j >= cursorY - range && j <= cursorY + range) {
                printf("%c ", map[i][j]);
            }
            else if ((i == cursorX - range_ || i == cursorX + range_) && (j >= cursorY - range_ && j <= cursorY + range_) ||
                (j == cursorY - range_ || j == cursorY + range_) && (i >= cursorX - range_ && i <= cursorX + range_)) {
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
void initializeMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = ' '; // �� �������� �ʱ�ȭ
        }
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < NUM_ITEMS; i++) {
        int x = rand() % MAP_HEIGHT;
        int y = rand() % MAP_WIDTH;
        map[x][y] = 'l';
    }
}

void moveCursor(int* cursorX, int* cursorY, char direction) {
    switch (direction) {
    case 'w':
        if (*cursorX > 0) (*cursorX)--;
        break;
    case 's':
        if (*cursorX < MAP_HEIGHT - 1) (*cursorX)++;
        break;
    case 'a':
        if (*cursorY > 0) (*cursorY)--;
        break;
    case 'd':
        if (*cursorY < MAP_WIDTH - 1) (*cursorY)++;
        break;
    }
}

int main() {

    char map[MAP_HEIGHT][MAP_WIDTH];
    int cursorX = MAP_HEIGHT / 2;
    int cursorY = MAP_WIDTH / 2;

    initializeMap(map);

    while (1) {
        printMap(map, cursorX, cursorY);

        char input = _getch();
        if (input == BACK) return BACK;
        moveCursor(&cursorX, &cursorY, input);
    }

    return 0;
}
