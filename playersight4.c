#include "main.h"

#define NUM_ITEMS 5

void drawCharStar(int x, int y) {
    gotoxy1(x + 6, y + 3);
    Setcolor(3);
    printf("★\b");
    Setcolor(7);
}

void drawChar(int x, int y, int bottom, int right, int upper, int left) {
    int x1 = x;
    int y1 = y;
    char charsight[7][14] = {
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
    char charsight[7][14] = {
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
    int x = MAP_X * 2 + 2, y = MAP_Y + 3, upper,bottom, left, right,x1,y1;
    drawChar(x, y, 7, 14, 0, 0);
    drawCharStar(x, y);
    while (1)
    {
        int n = keyControl1();
        switch (n) {
        case UP: {
            if (y <= MAP_Y) { y = MAP_Y; } // 한계 범위 초기화
            else if (y <= MAP_Y + 3 && y >= MAP_Y+1) { // 맵 위 쪽으로 이동
                x1 = x, left = 0, right = 14;
                if (y == MAP_Y + 3) upper = 0;
                if (y == MAP_Y + 2) upper = 1;
                if (y == MAP_Y + 1) upper = 2;
                if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 왼쪽에서 위로 갈 때 겹치는 부분
                    if (x == MAP_X * 2 - 5) left = 6;
                    if (x == MAP_X * 2 - 4) left = 5;
                    if (x == MAP_X * 2 - 3) left = 4;
                    if (x == MAP_X * 2 - 2) left = 3;
                    if (x == MAP_X * 2 - 1) left = 2;
                    if (x == MAP_X * 2) left = 1;
                    x1 = MAP_X * 2 + 1;
                }
                else if (x <= (MAP_X + MAP_WIDTH) * 2 - 10 && x >= (MAP_X + MAP_WIDTH) * 2 - 16) { // 오른쪽에서 위로 갈 때 겹치는 부분
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 10) right = 8;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 15) right = 13;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 16) right = 14;
                }
                removeChar(x1, MAP_Y + 3, 7, right, upper, left);
                drawChar(x1, MAP_Y + 3, 7, right, ++upper, left);
                drawCharStar(x, --y);
            }
            else if (y >= (MAP_Y + MAP_HEIGHT) - 12 && y <= (MAP_Y + MAP_HEIGHT) - 10) { // 맵 아래에서 위로 이동
                x1 = x, left = 0, right = 14;
                if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 4;
                if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 5;
                if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 왼쪽에서 위로 갈 때 겹치는 부분
                    if (x == MAP_X * 2 - 5) left = 6;
                    if (x == MAP_X * 2 - 4) left = 5;
                    if (x == MAP_X * 2 - 3) left = 4;
                    if (x == MAP_X * 2 - 2) left = 3;
                    if (x == MAP_X * 2 - 1) left = 2;
                    if (x == MAP_X * 2) left = 1;
                    x1 = MAP_X * 2 + 1;
                }
                else if (x <= (MAP_X + MAP_WIDTH) * 2 - 10 && x >= (MAP_X + MAP_WIDTH) * 2 - 16) { // 오른쪽에서 위로 갈 때 겹치는 부분
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 10) right = 8;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 15) right = 13;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 16) right = 14;
                }
                removeChar(x1, y, bottom, right, 0, left);
                drawChar(x1, --y, ++bottom, right, 0, left);
                drawCharStar(x, y);
            }
            else if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 맵 왼 쪽에서 위로 이동
                if (x == MAP_X * 2 - 5) left = 6;
                if (x == MAP_X * 2 - 4) left = 5;
                if (x == MAP_X * 2 - 3) left = 4;
                if (x == MAP_X * 2 - 2) left = 3;
                if (x == MAP_X * 2 - 1) left = 2;
                if (x == MAP_X * 2) left = 1;
                removeChar(MAP_X * 2 + 1, y, 7, 14, 0, left);
                drawChar(MAP_X * 2 + 1, --y, 7, 14, 0, left);
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
                removeChar(x, y, 7, 14, 0, 0);
                drawChar(x, --y, 7, 14, 0, 0);
                drawCharStar(x, y);
            }
            break;
        }
        case DOWN: {
            if (y > (MAP_Y + MAP_HEIGHT) - 11) { y = (MAP_Y + MAP_HEIGHT) - 10; } // 한계 범위 초기화
            else if (y >= (MAP_Y + MAP_HEIGHT) - 13 && y <= (MAP_Y + MAP_HEIGHT) - 11) { // 맵 아래로 이동
                x1 = x, left = 0, right = 14;
                if (y == (MAP_Y + MAP_HEIGHT) - 13) bottom = 7;
                if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 5;
                if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 왼쪽에서 아래로 갈 때 겹치는 부분
                    if (x == MAP_X * 2 - 5) left = 6;
                    if (x == MAP_X * 2 - 4) left = 5;
                    if (x == MAP_X * 2 - 3) left = 4;
                    if (x == MAP_X * 2 - 2) left = 3;
                    if (x == MAP_X * 2 - 1) left = 2;
                    if (x == MAP_X * 2) left = 1;
                    x1 = MAP_X * 2 + 1;
                }
                else if (x <= (MAP_X + MAP_WIDTH) * 2 - 10 && x >= (MAP_X + MAP_WIDTH) * 2 - 16) { // 오른쪽에서 아래로 갈 때 겹치는 부분
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 10) right = 8;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 15) right = 13;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 16) right = 14;
                }
                removeChar(x1, y, bottom, right, 0, left);
                drawChar(x1, ++y, --bottom, right, 0, left);
                drawCharStar(x, y);
            }
            else if (y >= MAP_Y && y <= MAP_Y + 2) { // 맵 위에서 아래로 이동
                x1 = x, left = 0, right = 14;
                if (y == MAP_Y) upper = 3;
                if (y == MAP_Y + 1) upper = 2;
                if (y == MAP_Y + 2) upper = 1;
                if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 왼쪽에서 위로 갈 때 겹치는 부분
                    if (x == MAP_X * 2 - 5) left = 6;
                    if (x == MAP_X * 2 - 4) left = 5;
                    if (x == MAP_X * 2 - 3) left = 4;
                    if (x == MAP_X * 2 - 2) left = 3;
                    if (x == MAP_X * 2 - 1) left = 2;
                    if (x == MAP_X * 2) left = 1;
                    x1 = MAP_X * 2 + 1;
                }
                else if (x <= (MAP_X + MAP_WIDTH) * 2 - 10 && x >= (MAP_X + MAP_WIDTH) * 2 - 16) { // 오른쪽에서 위로 갈 때 겹치는 부분
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 10) right = 8;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 15) right = 13;
                    if (x == (MAP_X + MAP_WIDTH) * 2 - 16) right = 14;
                }
                removeChar(x1, MAP_Y + 3, 7, right, upper, left);
                drawChar(x1, MAP_Y + 3, 7, right, --upper, left);
                drawCharStar(x, ++y);
            }
            else if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 맵 왼 쪽에서 아래로 이동
                if (x == MAP_X * 2 - 5) left = 6;
                if (x == MAP_X * 2 - 4) left = 5;
                if (x == MAP_X * 2 - 3) left = 4;
                if (x == MAP_X * 2 - 2) left = 3;
                if (x == MAP_X * 2 - 1) left = 2;
                if (x == MAP_X * 2) left = 1;
                removeChar(MAP_X * 2 + 1, y, 7, 14, 0, 0);
                drawChar(MAP_X * 2 + 1, ++y, 7, 14, 0, left);
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
                removeChar(x, y, 7, 14, 0, 0);
                drawChar(x, ++y, 7, 14, 0, 0);
                drawCharStar(x, y);
            }
            break;
        }
        case LEFT: {
            if (x <= MAP_X * 2 - 5) { x = MAP_X * 2 - 5; }
            else if (x >= MAP_X * 2 - 4 && x <= MAP_X * 2 + 1) { // 맵 왼 쪽으로 이동
                y1 = y, upper = 0, bottom = 7;
                if (x == MAP_X * 2 - 4) left = 6;
                if (x == MAP_X * 2 - 3) left = 5;
                if (x == MAP_X * 2 - 2) left = 4;
                if (x == MAP_X * 2 - 1) left = 3;
                if (x == MAP_X * 2) left = 2;
                if (x == MAP_X * 2 + 1) left = 1;
                if (y <= MAP_Y + 2 && y >= MAP_Y){ // 위쪽에서 왼쪽으로 갈 때 겹치는 부분
                    if (y == MAP_Y + 2) upper = 1;
                    if (y == MAP_Y + 1) upper = 2;
                    if (y == MAP_Y) upper = 3;
                    y1 = MAP_Y + 3;
                }
                else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 아래쪽에서 왼쪽으로 갈 때 겹치는 부분
                    if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 4;
                    if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 5;
                    if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                }
                removeChar(MAP_X * 2 + 1, y1, bottom, 14, upper, 0);
                drawChar(MAP_X * 2 + 1, y1, bottom, 14, upper, left);
                drawCharStar(--x, y);
            }
            else if (x <= (MAP_X + MAP_WIDTH) * 2 - 10 && x >= (MAP_X + MAP_WIDTH) * 2 - 14) { // 맵 오른쪽에서 왼쪽으로 이동
                y1 = y, upper = 0, bottom = 7, right = 14;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 10) right = 8;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                if (y <= MAP_Y + 2 && y >= MAP_Y) { // 위쪽에서 왼쪽으로 갈 때 겹치는 부분
                    if (y == MAP_Y + 2) upper = 1;
                    if (y == MAP_Y + 1) upper = 2;
                    if (y == MAP_Y) upper = 3;
                    y1 = MAP_Y + 3;
                }
                else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 아래쪽에서 왼쪽으로 갈 때 겹치는 부분
                    if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 4;
                    if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 5;
                    if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                }
                removeChar(x, y1, bottom, right, upper, 0);
                drawChar(--x, y1, bottom, ++right, upper, 0);
                drawCharStar(x, y);
                
            }
            else if (y >= MAP_Y && y <= MAP_Y + 2) { // 맵 위에서 왼쪽으로 이동
                if (y == MAP_Y) upper = 3;
                if (y == MAP_Y+1) upper = 2;
                if (y == MAP_Y+2) upper = 1;
                removeChar(x, MAP_Y + 3, 7, 14, upper, 0);
                drawChar(--x, MAP_Y + 3, 7, 14, upper, 0);
                drawCharStar(x, y);
            }
            else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 맵 아래에서 왼쪽으로 이동
                if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 4;
                if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 5;
                if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                removeChar(x, y, bottom, 14, 0, 0);
                drawChar(--x, y, bottom, 14, 0, 0);
                drawCharStar(x, y);
            }
            else { // 맵 안에서
                removeChar(x, y, 7, 14, 0, 0);
                drawChar(--x, y, 7, 14, 0, 0);
                drawCharStar(x, y);
            }
            break;
        }
        case RIGHT: {
            if (x >= (MAP_X + MAP_WIDTH) * 2 - 10) { x = (MAP_X + MAP_WIDTH) * 2 - 10; }
            else if (x >= (MAP_X + MAP_WIDTH) * 2 - 15 && x <= (MAP_X + MAP_WIDTH) * 2 - 11) { // 맵 오른쪽으로 이동
                y1 = y, bottom = 7,upper=0;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 15) right = 13;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 14) right = 12;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 13) right = 11;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 12) right = 10;
                if (x == (MAP_X + MAP_WIDTH) * 2 - 11) right = 9;
                if (y <= MAP_Y + 2 && y >= MAP_Y) { // 위쪽에서 오른쪽으로 갈 때 겹치는 부분
                    if (y == MAP_Y + 2) upper = 1;
                    if (y == MAP_Y + 1) upper = 2;
                    if (y == MAP_Y) upper = 3;
                    y1 = MAP_Y + 3;
                }
                else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 아래쪽에서 오른쪽으로 갈 때 겹치는 부분
                    if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 4;
                    if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 5;
                    if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                }
                removeChar(x, y1, bottom, right, upper, 0);
                drawChar(++x, y1, bottom, --right, upper, 0);
                drawCharStar(x, y);
            }
            else if (x >= MAP_X * 2 - 5 && x <= MAP_X * 2) { // 맵 왼쪽에서 오른쪽으로 이동
                y1 = y, bottom = 7, upper = 0, left=0;
                if (x == MAP_X * 2 - 5) left = 5;
                if (x == MAP_X * 2 - 4) left = 4;
                if (x == MAP_X * 2 - 3) left = 3;
                if (x == MAP_X * 2 - 2) left = 2;
                if (x == MAP_X * 2 - 1) left = 1;
                if (x == MAP_X * 2) left = 0;
                if (y <= MAP_Y + 2 && y >= MAP_Y) { // 위쪽에서 오른쪽으로 갈 때 겹치는 부분
                    if (y == MAP_Y + 2) upper = 1;
                    if (y == MAP_Y + 1) upper = 2;
                    if (y == MAP_Y) upper = 3;
                    y1 = MAP_Y + 3;
                }
                else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 아래쪽에서 오른쪽으로 갈 때 겹치는 부분
                    if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 4;
                    if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 5;
                    if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 6;
                }
                removeChar(MAP_X * 2 + 1, y1, bottom, 14, upper, 0);
                drawChar(MAP_X * 2 + 1, y1, bottom, 14, upper, left);
                drawCharStar(++x, y);
            }
            else if (y >= MAP_Y && y <= MAP_Y + 2) { // 맵 위에서 오른쪽으로 이동
                if (y == MAP_Y) upper = 3;
                if (y == MAP_Y + 1) upper = 2;
                if (y == MAP_Y + 2) upper = 1;
                removeChar(x, MAP_Y + 3, 7, 14, upper, 0);
                drawChar(++x, MAP_Y + 3, 7, 14, upper, 0);
                drawCharStar(x, y);
            }
            else if (y <= (MAP_Y + MAP_HEIGHT) - 10 && y >= (MAP_Y + MAP_HEIGHT) - 12) { // 맵 아래에서 오른쪽으로 이동
                if (y == (MAP_Y + MAP_HEIGHT) - 10) bottom = 5;
                if (y == (MAP_Y + MAP_HEIGHT) - 11) bottom = 6;
                if (y == (MAP_Y + MAP_HEIGHT) - 12) bottom = 7;
                removeChar(x, y, --bottom, 14, 0, 0);
                drawChar(++x, y, bottom, 14, 0, 0);
                drawCharStar(x, y);
            }
            else { // 맵 안에서
                removeChar(x, y, 7, 14, 0, 0);
                drawChar(++x, y, 7, 14, 0, 0);
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


// 랜덤아이템 배치
void initializeMap(char map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = ' '; // 빈 공간으로 초기화
        }
    }

    for (int i = 0; i < NUM_ITEMS; i++) {
        int x = rand() % MAP_HEIGHT;
        int y = rand() % MAP_WIDTH;
        map[x][y] = '＠';
    }
}

int main() {
    srand((unsigned int)time(NULL));
    char map[MAP_HEIGHT][MAP_WIDTH];
    int cursorX = MAP_HEIGHT / 2;
    int cursorY = MAP_WIDTH / 2;
    char input;
    drawMap();
    gameMapDraw();
    //initializeMap(map);
    while (1) {
        
        input = movechar();
        //initializeMap(map);
        if (input == BACK) return BACK; 
    }

    return 0;
}
