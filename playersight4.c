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
    gotoxy1(x+6, y+3);
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
    for (int i = 0; i < bottom; i++) {
        gotoxy1(x1, y1);
        for (int j = 0; j < right; j++) {
            putchar(charsight[i+upper][j+left]);
            fflush(stdout);
        }
        gotoxy1(x + 5, y + 3);
        y1 += 1;
    }
    drawCharStar(x, y);
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
    for (int i = 0; i < bottom; i++) {
        gotoxy1(x1, y1);
        for (int j = 0; j < right; j++) {
            putchar(charsight[i + upper][j + left]);
            fflush(stdout);
        }
        gotoxy1(x + 5, y + 3);
        y1 += 1;
    }
}

int movechar(void) {
    int x = MAP_X * 2 + 2, y = MAP_Y + 3;
    int upper = 0;
    drawChar(x,y,7,15,0,0);
    while (1)
    {
        int n = keyControl1();
        switch (n) {
        case UP: {
            if (y > MAP_Y + 3) {
                removeChar(x,y,7,15,0,0);
                drawChar(x,--y,7,15,0,0);
            }
            if (y <= MAP_Y + 3 && y > MAP_Y) {
                removeChar(x, --y,7,15, upper, 0);
                upper++;
                drawChar(x, --y, 7, 15, upper, 0);
            }
            break;
        }
        case DOWN: {
            if (y < MAP_Y + 13) {
                removeChar(x, y,7,15,0,0);
                drawChar(x, ++y,7,15,0,0);
            }
            break;
        }
        case LEFT: {
            if (x > MAP_X*2 + 1) {
                removeChar(x, y,7,15,0,0);
                drawChar(--x, y,7,15,0,0);
            }

            break;
        }
        case RIGHT: {
            if (x < (MAP_X + MAP_HEIGHT + 5)*2+1) {
                removeChar(x, y,7,15,0,0);
                drawChar(++x, y,7,15,0,0);
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

int gameplay() {

    char map[MAP_HEIGHT][MAP_WIDTH];
    int cursorX = MAP_HEIGHT / 2;
    int cursorY = MAP_WIDTH / 2;

    initializeMap(map);
    drawMap();
    while (1) {
        //printMap(map, cursorX, cursorY);

        char input = _getch();
        if (input == BACK) return BACK;
        //moveCursor(&cursorX, &cursorY, input);
        movechar();
    }

    return 0;
}
