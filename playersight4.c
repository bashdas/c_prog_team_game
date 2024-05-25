#include "main.h"

#define range 2
#define range_ 3
#define NUM_ITEMS 5

// 커서 위치 정보를 가져오는 함수
void getCursorPos(int* x, int* y) {
    CONSOLE_SCREEN_BUFFER_INFO cur;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur)) {
        *x = cur.dwCursorPosition.X;
        *y = cur.dwCursorPosition.Y;
    }
}

void drawCharStar(int x, int y) {
    gotoxy1(x + 6, y + 3);
    Setcolor(3);
    printf("★\b");
    Setcolor(7);
}

void drawChar(int x, int y, int bottom, int right, int upper, int left) {
    int x1 = x;
    int y1 = y;
    char charsight[7][15] = {
        "* * * * * * *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "* * * * * * *\0"
    };
    for (int i = 0 + upper; i < bottom; i++) {
        gotoxy1(x1, y1);
        for (int j = 0 + left; j < right; j++) {
            putchar(charsight[i][j]);
            fflush(stdout);
        }
        gotoxy1(x + 5, y + 3);
        y1 += 1;
    }
}

void removeChar(int x, int y, int bottom, int right, int upper, int left) {
    int x1 = x;
    int y1 = y;
    char charsight[7][15] = {
        "             \0",
        "             \0",
        "             \0",
        "             \0",
        "             \0",
        "             \0",
        "             \0",
    };
    for (int i = 0 + upper; i < bottom; i++) {
        gotoxy1(x1, y1);
        for (int j = 0 + left; j < right; j++) {
            putchar(charsight[i][j]);
            fflush(stdout);
        }
        gotoxy1(x + 5, y + 3);
        y1 += 1;
    }
}

int movechar(void) {
    int x = MAP_X * 2 + 2, y = MAP_Y + 3, upper,bottom, left, right;
    drawChar(x, y, 7, 15, 0, 0);
    drawCharStar(x, y);
    while (1)
    {
        int n = keyControl1();
        switch (n) {
        case UP: {
            if (y <= MAP_Y + 1) { // 한계 범위
                removeChar(x, MAP_Y + 3, 7, 15, 2, 0);
                drawChar(x, MAP_Y + 3, 7, 15, 3, 0);
                y = MAP_Y;
                drawCharStar(x, y);
            }
            else if (y <= MAP_Y + 3 && y >= MAP_Y + 1) { // 맵 위 쪽으로 이동
                if (y == MAP_Y + 3) upper = 0;
                if (y == MAP_Y + 2) upper = 1;
                if (y == MAP_Y + 1) upper = 2;
                removeChar(x, MAP_Y + 3, 7, 15, upper, 0);
                drawChar(x, MAP_Y + 3, 7, 15, ++upper, 0);
                drawCharStar(x, --y);
            }
            else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 맵 아래에서 위로 이동
                if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 4;
                if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 5;
                if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                removeChar(x, y, bottom, 15, 0, 0);
                drawChar(x, --y, ++bottom, 15, 0, 0);
                drawCharStar(x, y);
            }
            else if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 맵 왼 쪽에서 위로 이동
                if (x == MAP_X * 2 - 5) left = 6;
                if (x == MAP_X * 2 - 4) left = 5;
                if (x == MAP_X * 2 - 3) left = 4;
                if (x == MAP_X * 2 - 2) left = 3;
                if (x == MAP_X * 2 - 1) left = 2;
                if (x == MAP_X * 2) left = 1;
                removeChar(MAP_X * 2 + 1, y, 7, 15, 0, 0);
                drawChar(MAP_X * 2 + 1, --y, 7, 15, 0, left);
                drawCharStar(x, y);
            }
            else if (x <= (MAP_X + MAP_WIDTH) * 2 - 10 && x >= (MAP_X + MAP_WIDTH) * 2 - 16) { //맵 오른쪽에서 위로 이동
                if (x == (MAP_X + MAP_WIDTH) * 2 - 10) right = 8;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 15) right = 13;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 16) right = 14;
                removeChar(x, y, 7, right, 0, 0);
                drawChar(x, --y, 7, right, 0, 0);
                drawCharStar(x, y);
            }
            else { // 맵 안에서
                removeChar(x, y, 7, 15, 0, 0);
                drawChar(x, --y, 7, 15, 0, 0);
                drawCharStar(x, y);
            }
            break;
        }
        case DOWN: {
            if (y >= (MAP_Y + MAP_HEIGHT) - 11) { // 한계 범위
                removeChar(x, (MAP_Y + MAP_HEIGHT) - 11, 5, 15, 0, 0);
                drawChar(x, (MAP_Y + MAP_HEIGHT) - 10, 4, 15, 0, 0);
                y = (MAP_Y + MAP_HEIGHT) - 10;
                drawCharStar(x, y);
            }
            else if (y >= MAP_Y && y <= MAP_Y+2) { // 맵 위에서 아래로 이동
                if (y == MAP_Y) upper = 3;
                if (y == MAP_Y+1) upper = 2;
                if (y == MAP_Y+2) upper = 1;
                removeChar(x, MAP_Y + 3, 7, 15, upper, 0);
                drawChar(x, MAP_Y + 3, 7, 15, --upper, 0);
                drawCharStar(x, ++y);
            }
            else if (y == (MAP_Y + MAP_HEIGHT) - 13 || y == (MAP_Y + MAP_HEIGHT) - 12) { // 맵 아래로 이동
                if (y == (MAP_Y + MAP_HEIGHT) - 13) bottom = 7;
                if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                removeChar(x, y, bottom, 15, 0, 0);
                drawChar(x, ++y, --bottom, 15, 0, 0);
                drawCharStar(x, y);
            }
            else if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 맵 왼 쪽에서 아래로 이동
                if (x == MAP_X * 2 - 5) left = 6;
                if (x == MAP_X * 2 - 4) left = 5;
                if (x == MAP_X * 2 - 3) left = 4;
                if (x == MAP_X * 2 - 2) left = 3;
                if (x == MAP_X * 2 - 1) left = 2;
                if (x == MAP_X * 2) left = 1;
                removeChar(MAP_X * 2 + 1, y, 7, 15, 0, 0);
                drawChar(MAP_X * 2 + 1, ++y, 7, 15, 0, left);
                drawCharStar(x, y);
            }
            else if (x <= (MAP_X + MAP_WIDTH) * 2 - 10 && x >= (MAP_X + MAP_WIDTH) * 2 - 16) { //맵 오른쪽에서 아래로 이동
                if (x == (MAP_X + MAP_WIDTH) * 2 - 10) right = 8;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 15) right = 13;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 16) right = 14;
                removeChar(x, y, 7, right, 0, 0);
                drawChar(x, ++y, 7, right, 0, 0);
                drawCharStar(x, y);
            }
            else { // 맵 안에서
                removeChar(x, y, 7, 15, 0, 0);
                drawChar(x, ++y, 7, 15, 0, 0);
                drawCharStar(x, y);
            }
            break;
        }
        case LEFT: {
            if (x <= MAP_X * 2 - 4) { // 한계 범위
                removeChar(MAP_X * 2 + 1, y, 7, 15, 0, 0);
                drawChar(MAP_X * 2 + 1, y, 7, 15, 0, 6);
                x = MAP_X * 2 - 5;
                drawCharStar(x, y);
            }
            else if (x >= MAP_X * 2 - 3 && x <= MAP_X * 2 + 1) { // 맵 왼 쪽으로 이동
                if (x == MAP_X * 2 - 3) left = 5;
                if (x == MAP_X * 2 - 2) left = 4;
                if (x == MAP_X * 2 - 1) left = 3;
                if (x == MAP_X * 2) left = 2;
                if (x == MAP_X * 2 + 1) left = 1;
                removeChar(MAP_X * 2 + 1, y, 7, 15, 0, 0);
                drawChar(MAP_X * 2 + 1, y, 7, 15, 0, left);
                drawCharStar(--x, y);
            }
            else if (x <= (MAP_X + MAP_WIDTH) * 2 - 10 && x >= (MAP_X + MAP_WIDTH) * 2 - 14) { // 맵 오른쪽에서 왼쪽으로 이동
                if (x == (MAP_X + MAP_WIDTH) * 2 - 10) right = 8;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                removeChar(x, y, 7, right, 0, 0);
                drawChar(--x, y, 7, ++right, 0, 0);
                drawCharStar(x, y);
            }
            else if (y >= MAP_Y && y <= MAP_Y + 2) { // 맵 위에서 왼쪽으로 이동
                if (y == MAP_Y) upper = 3;
                if (y == MAP_Y+1) upper = 2;
                if (y == MAP_Y+2) upper = 1;
                removeChar(x, MAP_Y + 3, 7, 15, upper, 0);
                drawChar(--x, MAP_Y + 3, 7, 15, upper, 0);
                drawCharStar(x, y);
            }
            else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 맵 아래에서 왼쪽으로 이동
                if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 5;
                if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 6;
                if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 7;
                removeChar(x, y, --bottom, 15, 0, 0);
                drawChar(--x, y, bottom, 15, 0, 0);
                drawCharStar(x, y);
            }
            else { // 맵 안에서
                removeChar(x, y, 7, 15, 0, 0);
                drawChar(--x, y, 7, 15, 0, 0);
                drawCharStar(x, y);
            }
            break;
        }
        case RIGHT: {
            if (x >= (MAP_X + MAP_WIDTH) * 2 - 11) { // 한계 범위
                removeChar((MAP_X + MAP_WIDTH) * 2 - 11, y, 7, 9, 0, 0);
                drawChar((MAP_X + MAP_WIDTH) * 2 - 10, y, 7, 8, 0, 0);
                x = (MAP_X + MAP_WIDTH) * 2 - 10;
                drawCharStar(x, y);
            }
            else if (x >= (MAP_X + MAP_WIDTH) * 2 - 15 && x <= (MAP_X + MAP_WIDTH) * 2 - 12) { // 맵 오른쪽으로 이동
                if (x == (MAP_X + MAP_WIDTH) * 2 - 15) right = 13;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                removeChar(x, y, 7, right, 0, 0);
                drawChar(++x, y, 7, --right, 0, 0);
                drawCharStar(x, y);
            }
            else if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 맵 왼쪽에서 오른쪽으로 이동
                if (x == MAP_X * 2 - 5) left = 5;
                if (x == MAP_X * 2 - 4) left = 4;
                if (x == MAP_X * 2 - 3) left = 3;
                if (x == MAP_X * 2 - 2) left = 2;
                if (x == MAP_X * 2 - 1) left = 1;
                if (x == MAP_X * 2) left = 0;
                removeChar(MAP_X * 2 + 1, y, 7, 15, 0, 0);
                drawChar(MAP_X * 2 + 1, y, 7, 15, 0, left);
                drawCharStar(++x, y);
            }
            else if (y >= MAP_Y && y <= MAP_Y + 2) { // 맵 위에서 오른쪽으로 이동
                if (y == MAP_Y) upper = 3;
                if (y == MAP_Y + 1) upper = 2;
                if (y == MAP_Y + 2) upper = 1;
                removeChar(x, MAP_Y + 3, 7, 15, upper, 0);
                drawChar(++x, MAP_Y + 3, 7, 15, upper, 0);
                drawCharStar(x, y);
            }
            else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 맵 아래에서 오른쪽으로 이동
                if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 5;
                if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 6;
                if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 7;
                removeChar(x, y, --bottom, 15, 0, 0);
                drawChar(++x, y, bottom, 15, 0, 0);
                drawCharStar(x, y);
            }
            else { // 맵 안에서
                removeChar(x, y, 7, 15, 0, 0);
                drawChar(++x, y, 7, 15, 0, 0);
                drawCharStar(x, y);
            }
            break;
        }
        case BACK:
            return BACK;
        case SUBMIT: {
            return y - 15;
        }
        }
    }
}

// 맵을 출력하는 함수
void printMap(char map[MAP_HEIGHT][MAP_WIDTH], int cursorX, int cursorY) {
    // system("cls"); // 화면을 지우기
    resetMapMain();
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            // 커서 위치에 '★' 출력
            if (i == cursorX && j == cursorY) {
                printf("★ ");
            }
            // 시야 범위 내인지 확인
            else if (i >= cursorX - range && i <= cursorX + range && j >= cursorY - range && j <= cursorY + range) {
                printf("%c ", map[i][j]);
            }
            else if ((i == cursorX - range_ || i == cursorX + range_) && (j >= cursorY - range_ && j <= cursorY + range_) ||
                (j == cursorY - range_ || j == cursorY + range_) && (i >= cursorX - range_ && i <= cursorX + range_)) {
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
void initializeMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = ' '; // 빈 공간으로 초기화
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
    drawMap();
    gameMapDraw();
    while (1) {
        //printMap(map, cursorX, cursorY);

        char input = _getch();
        if (input == BACK) return BACK;
        //moveCursor(&cursorX, &cursorY, input);
        movechar();
    }

    return 0;
}
