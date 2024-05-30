#include "main.h"



/*
캐릭터 중심 그리기
  - 캐릭터 좌표 위치에 그리기,
  - 캐릭터 현재 위치 좌표
*/
void drawPlayer(int x, int y) {
    gotoxy1(x, y);
    Setcolor(4);
    printf("★\b");
    Setcolor(7);
}

/*
캐릭터 시야 그리기
  - 캐릭터 좌표 위치에서 일정 거리만큼 띄어지게 그리기
  - player 현재 위치 좌표
  - upper ~ bottom 까지
  - left ~ right 까지
*/
void drawPlayerSight(int x, int y, int bottom, int right, int upper, int left) {
    int sightx = x - 6;
    int sighty = y - 3;
    char charsight[7][14] = { // 중앙 6,3 -> 캐릭터 중심으로 부터 x-6, y-3위치부터 시야 그리기 시작
        "* * * * * * *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "* * * * * * *\0"
    };
    // 캐릭터 시야 그리기
    for (int i = 0 + upper; i < bottom; i++) {
        gotoxy1(sightx, sighty);
        for (int j = 0 + left; j < right; j++) {
            putchar(charsight[i][j]);
            fflush(stdout);
        }
        gotoxy1(x, y); // 마우스 커서 위치 변경
        sighty += 1;
    }
}

/*
캐릭터 시야 지우기 -> 캐릭터도 같이 지움
  - drawPlayerSight 동작원리 같음
*/
void removePlayerSight(int x, int y, int bottom, int right, int upper, int left) {
    int sightx = x - 6;
    int sighty = y - 3;
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
        gotoxy1(sightx, sighty);
        for (int j = 0 + left; j < right; j++) {
            putchar(charsight[i][j]);
            fflush(stdout);
        }
        gotoxy1(x, y); // 마우스 커서 위치 변경
        sighty += 1;
    }
}

void drawItem(int x, int y) {
    gotoxy1(x, y);
    printf("A");
}

void removeItem(int x, int y) {
    gotoxy1(x, y);
    printf(" ");
    gotoxy1(0, 0);
}

void initItem(struct player* player_info, struct items* item_array, int playerx, int playery, int i) {
    item_array[i].x = 0;
    item_array[i].y = 0;
    strcpy_s(item_array[i].skill, sizeof(item_array[i].skill), "None");
    removeItem(item_array[i].x, item_array[i].y);
    drawPlayer(playerx, playery);
}

void eatItem(struct player* player_info, struct items* item_array, int playerx, int playery) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (item_array[i].x <= playerx + player_info->sw && item_array[i].x >= playerx - player_info->sw
            && item_array[i].y <= playery + player_info->sh && item_array[i].y >= playery - player_info->sh) {
            drawItem(item_array[i].x, item_array[i].y); // 시야 범위에 들어오면 아이템 출력
            if (item_array[i].x == playerx && item_array[i].y == playery) {
                // 충돌 시 배열 0,0,None로 초기화, 아이템 지우고 캐릭터 다시 그리기
                initItem(player_info, item_array, playerx, playery, i);
            }
        }
        else {
            removeItem(item_array[i].x, item_array[i].y); // 시야 범위 밖에 나가면 아이템 지우기
        }
    }
}

int isClear(struct items* item_array) {
    if (item_array[0].x == 0 && item_array[0].y == 0 && item_array[1].x == 0 && item_array[1].y == 0) return CLEAR;
}


/*
플레이어 이동
- 플레이어 좌표 저장할 포인터 변수
- 아이템 좌표 필요 -> 이동하면서 플레이어 좌표가 아이템 좌표 일정 범위에 들어오면 아이템 출력, 충돌 시 지우기

*/
int movePlayer(struct player* player_info, struct items* item_array) {
    int playerx = player_info[0].x;	// 플레이어 x 좌표
    int playery = player_info[0].y; // 플레이어 y 좌표
    int curx = playerx; // 설정 좌표 x
    int cury = playery; // 설정 좌표  y // MAP_X * 2 + 7, MAP_HEIGHT / 2 + 5
    int upper = 0, bottom = 7, left = 0, right = 14; // 플레이어 시야 배열을 얼만큼 돌릴 지
    drawPlayerSight(playerx, playery, bottom, right, upper, left);
    drawPlayer(playerx, playery);

    while (1)
    {
        int n = keyControl1();
        switch (n) {
        case UP: {
            if (playery <= MAP_Y + 3) playery = MAP_Y + 3;
            else if (playery <= MAP_Y + 6 && playery >= MAP_Y + 4) { //맵 위로 이동
                curx = playerx, cury = MAP_Y + 6, left = 0, right = 14;
                if (playery == MAP_Y + 6) upper = 0;
                if (playery == MAP_Y + 5) upper = 1;
                if (playery == MAP_Y + 4) upper = 2;
                if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // 왼쪽에서 위로 갈 때 겹치는 부분
                    if (playerx == MAP_X * 2 + 6) left = 1;
                    if (playerx == MAP_X * 2 + 5) left = 2;
                    if (playerx == MAP_X * 2 + 4) left = 3;
                    if (playerx == MAP_X * 2 + 3) left = 4;
                    if (playerx == MAP_X * 2 + 2) left = 5;
                    if (playerx == MAP_X * 2 + 1) left = 6;
                    curx = MAP_X * 2 + 7;
                }
                else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { // 오른쪽에서 위로 갈 때 겹치는 부분
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                }
                removePlayerSight(curx, cury, bottom, right, upper, left);
                drawPlayerSight(curx, cury, bottom, right, ++upper, left);
                drawPlayer(playerx, --playery);
            }
            else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // 맵 아래에서 위로 이동
                curx = playerx, left = 0, right = 14, upper = 0;
                if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // 왼쪽에서 아래로 갈 때 겹치는 부분
                    if (playerx == MAP_X * 2 + 6) left = 1;
                    if (playerx == MAP_X * 2 + 5) left = 2;
                    if (playerx == MAP_X * 2 + 4) left = 3;
                    if (playerx == MAP_X * 2 + 3) left = 4;
                    if (playerx == MAP_X * 2 + 2) left = 5;
                    if (playerx == MAP_X * 2 + 1) left = 6;
                    curx = MAP_X * 2 + 7;
                }
                else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { // 오른쪽에서 아래로 갈 때 겹치는 부분
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                }
                removePlayerSight(curx, playery, bottom, right, upper, left);
                drawPlayerSight(curx, --playery, ++bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // 맵 왼 쪽에서 위로 이동
                curx = MAP_X * 2 + 7, bottom = 7, right = 14, upper = 0;
                if (playerx == MAP_X * 2 + 6) left = 1;
                if (playerx == MAP_X * 2 + 5) left = 2;
                if (playerx == MAP_X * 2 + 4) left = 3;
                if (playerx == MAP_X * 2 + 3) left = 4;
                if (playerx == MAP_X * 2 + 2) left = 5;
                if (playerx == MAP_X * 2 + 1) left = 6;
                removePlayerSight(curx, playery, bottom, right, upper, left);
                drawPlayerSight(curx, --playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { //맵 오른쪽에서 위로 이동
                bottom = 7, left = 0, upper = 0;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(playerx, --playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else { // 맵 내부
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(playerx, --playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            break;
        }
        case DOWN: {
            if (playery >= MAP_HEIGHT / 2 + 8) playery = MAP_HEIGHT / 2 + 8;
            else if (playery < MAP_HEIGHT / 2 + 8 && playery >= MAP_HEIGHT / 2 + 5) { // 맵 경계 아래로 이동
                curx = playerx, left = 0, right = 14;
                if (playery == MAP_HEIGHT / 2 + 5) bottom = 7;
                if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // 왼쪽에서 아래로 갈 때 겹치는 부분
                    if (playerx == MAP_X * 2 + 6) left = 1;
                    if (playerx == MAP_X * 2 + 5) left = 2;
                    if (playerx == MAP_X * 2 + 4) left = 3;
                    if (playerx == MAP_X * 2 + 3) left = 4;
                    if (playerx == MAP_X * 2 + 2) left = 5;
                    if (playerx == MAP_X * 2 + 1) left = 6;
                    curx = MAP_X * 2 + 7;
                }
                else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { // 오른쪽에서 아래로 갈 때 겹치는 부분
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                }
                removePlayerSight(curx, playery, bottom, right, 0, left);
                drawPlayerSight(curx, ++playery, --bottom, right, 0, left);
                drawPlayer(playerx, playery);
            }
            else if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // 맵 위에서 아래로 이동
                curx = playerx, cury = MAP_Y + 6, bottom = 7, left = 0, right = 14;
                if (playery == MAP_Y + 3) upper = 3;
                if (playery == MAP_Y + 4) upper = 2;
                if (playery == MAP_Y + 5) upper = 1;
                if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // 왼쪽에서 아래로 갈 때 겹치는 부분
                    if (playerx == MAP_X * 2 + 6) left = 1;
                    if (playerx == MAP_X * 2 + 5) left = 2;
                    if (playerx == MAP_X * 2 + 4) left = 3;
                    if (playerx == MAP_X * 2 + 3) left = 4;
                    if (playerx == MAP_X * 2 + 2) left = 5;
                    if (playerx == MAP_X * 2 + 1) left = 6;
                    curx = MAP_X * 2 + 7;
                }
                else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { // 오른쪽에서 아래로 갈 때 겹치는 부분
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                }
                removePlayerSight(curx, cury, bottom, right, upper, left);
                drawPlayerSight(curx, cury, bottom, right, --upper, left);
                drawPlayer(playerx, ++(playery));
            }
            else if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // 맵 왼 쪽에서 위로 이동
                curx = MAP_X * 2 + 7, bottom = 7, right = 14, upper = 0;
                if (playerx == MAP_X * 2 + 6) left = 1;
                if (playerx == MAP_X * 2 + 5) left = 2;
                if (playerx == MAP_X * 2 + 4) left = 3;
                if (playerx == MAP_X * 2 + 3) left = 4;
                if (playerx == MAP_X * 2 + 2) left = 5;
                if (playerx == MAP_X * 2 + 1) left = 6;
                removePlayerSight(curx, playery, bottom, right, upper, left);
                drawPlayerSight(curx, ++playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { //맵 오른쪽에서 위로 이동
                bottom = 7, left = 0, upper = 0;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 8;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 9;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 11;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 12;
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(playerx, ++playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else { // 맵 내부
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(playerx, ++playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            break;
        }
        case LEFT: {
            if (playerx <= MAP_X * 2 + 1) playerx = MAP_X * 2 + 1;
            else if (playerx <= MAP_X * 2 + 7 && playerx > MAP_X * 2 + 1) { // 맵 왼쪽으로 이동
                curx = MAP_X * 2 + 7, cury = playery, bottom = 7, right = 14, upper = 0;
                if (playerx == MAP_X * 2 + 7) left = 1;
                if (playerx == MAP_X * 2 + 6) left = 2;
                if (playerx == MAP_X * 2 + 5) left = 3;
                if (playerx == MAP_X * 2 + 4) left = 4;
                if (playerx == MAP_X * 2 + 3) left = 5;
                if (playerx == MAP_X * 2 + 2) left = 6;
                if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // 위쪽에서 왼쪽으로 갈 때 겹치는 부분
                    if (playery == MAP_Y + 3) upper = 3;
                    if (playery == MAP_Y + 4) upper = 2;
                    if (playery == MAP_Y + 5) upper = 1;
                    cury = MAP_Y + 6;
                }
                else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // 아래쪽에서 왼쪽으로 갈 때 겹치는 부분
                    if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                    if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                    if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                }
                removePlayerSight(curx, cury, bottom, right, upper, 0);
                drawPlayerSight(curx, cury, bottom, right, upper, left);
                drawPlayer(--playerx, playery);
            }
            else if (playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2 && playerx > (MAP_X + MAP_WIDTH - 1) * 2 - 7) { // 맵 오른쪽에서 왼쪽으로 이동
                cury = playery, upper = 0, bottom = 7, right = 14, left = 0;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // 위쪽에서 왼쪽으로 갈 때 겹치는 부분
                    if (playery == MAP_Y + 3) upper = 3;
                    if (playery == MAP_Y + 4) upper = 2;
                    if (playery == MAP_Y + 5) upper = 1;
                    cury = MAP_Y + 6;
                }
                else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // 아래쪽에서 왼쪽으로 갈 때 겹치는 부분
                    if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                    if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                    if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                }
                removePlayerSight(playerx, cury, bottom, right, upper, left);
                drawPlayerSight(--playerx, cury, bottom, ++right, upper, left);
                drawPlayer(playerx, playery);

            }
            else if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // 맵 위에서 왼쪽으로 이동
                cury = MAP_Y + 6, bottom = 7, left = 0, right = 14;
                if (playery == MAP_Y + 3) upper = 3;
                if (playery == MAP_Y + 4) upper = 2;
                if (playery == MAP_Y + 5) upper = 1;
                removePlayerSight(playerx, cury, bottom, right, upper, left);
                drawPlayerSight(--playerx, cury, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // 맵 아래에서 왼쪽으로 이동
                right = 14, upper = 0, left = 0;
                if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(--playerx, playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else { // 맵 내부
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(--playerx, playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            break;
        }
        case RIGHT: {
            if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 2) playerx = (MAP_X + MAP_WIDTH - 1) * 2 - 2;
            else if (playerx < (MAP_X + MAP_WIDTH - 1) * 2 - 2 && playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 7) { // 맵 오른쪽으로 이동
                cury = playery, bottom = 7, upper = 0, left = 0;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 7) right = 13;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // 위쪽에서 오른쪽으로 갈 때 겹치는 부분
                    if (playery == MAP_Y + 3) upper = 3;
                    if (playery == MAP_Y + 4) upper = 2;
                    if (playery == MAP_Y + 5) upper = 1;
                    cury = MAP_Y + 6;
                }
                else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // 아래쪽에서 오른쪽으로 갈 때 겹치는 부분
                    if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                    if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                    if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                }
                removePlayerSight(playerx, cury, bottom, right, upper, left);
                drawPlayerSight(++(playerx), cury, bottom, --right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playerx <= MAP_X * 2 + 6 && playerx >= MAP_X * 2 + 1) { // 맵 왼쪽에서 오른쪽으로 이동
                curx = MAP_X * 2 + 7, bottom = 7, right = 14, upper = 0, cury = playery, left = 0;
                if (playerx == MAP_X * 2 + 6) left = 0;
                if (playerx == MAP_X * 2 + 5) left = 1;
                if (playerx == MAP_X * 2 + 4) left = 2;
                if (playerx == MAP_X * 2 + 3) left = 3;
                if (playerx == MAP_X * 2 + 2) left = 4;
                if (playerx == MAP_X * 2 + 1) left = 5;
                if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // 위쪽에서 오른쪽으로 갈 때 겹치는 부분
                    if (playery == MAP_Y + 3) upper = 3;
                    if (playery == MAP_Y + 4) upper = 2;
                    if (playery == MAP_Y + 5) upper = 1;
                    cury = MAP_Y + 6;
                }
                else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // 아래쪽에서 오른쪽으로 갈 때 겹치는 부분
                    if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                    if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                    if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                }
                removePlayerSight(curx, cury, bottom, right, upper, 0);
                drawPlayerSight(curx, cury, bottom, right, upper, left);
                drawPlayer(++playerx, playery);
            }
            else if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // 맵 위에서 오른쪽으로 이동
                cury = MAP_Y + 6, bottom = 7, left = 0, right = 14;
                if (playery == MAP_Y + 3) upper = 3;
                if (playery == MAP_Y + 4) upper = 2;
                if (playery == MAP_Y + 5) upper = 1;
                removePlayerSight(playerx, cury, bottom, right, upper, left);
                drawPlayerSight(++playerx, cury, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // 맵 아래에서 오른쪽으로 이동
                right = 14, upper = 0, left = 0;
                if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(++playerx, playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else { // 맵 내부
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(++playerx, playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            break;
        }
        case BACK:
            return BACK;
        /*
        case SUBMIT: {
            return SUBMIT; // 처리 해야함 
        
        }*/
        }
        // 시야 범위에 들어오면 아이템 출력
        // 아이템과 플레이어 충돌 시 아이템 획득 처리
        eatItem(player_info, item_array, playerx, playery);

        /* 참고 하려고 적음 나중에 삭제 해야함 */
        gotoxy1(0, 0);
        printf("PLAYER: %d %d ", playerx, playery);
        gotoxy1(0, 2);
        printf("MAP_X: %d ~ %d ", MAP_X * 2 + 1, (MAP_X + MAP_WIDTH - 1) * 2 - 2);
        gotoxy1(0, 4);
        printf("MAP_Y: %d ~ %d ", MAP_Y + 3, MAP_HEIGHT / 2 + 8);
        gotoxy1(0, 6);
        printf("ITEMS COORD");
        for (int i = 0; i < MAX_ITEMS; i++) {
            gotoxy1(0, 7 + i);
            printf("%d] (%d, %d) %s\n", i + 1, item_array[i].x, item_array[i].y, item_array[i].skill);
        }
        
        // 클리어 -> 클리어 반환 return CLEAR;
        // 열쇠 획득 시 게임 성공
        if (isClear(item_array) == CLEAR) return CLEAR;
        
        // 실패 -> 실패 반환 returb FAIL;
        // 제한 시간 끝나면 -1 목숨, 제한 시간 추가 부여
        
    }
}

void Itemcoord(struct items* item, struct player* player) {
    int x, y;
    do {
        x = rand() % (MAP_WIDTH * 2 - 4) + 23;
        y = rand() % (MAP_HEIGHT - 9) + 5;
    } while (x >= player->x - player->sw && x <= player->x + player->sw &&
        y >= player->y - player->sh && y <= player->y + player->sh);

    item->x = x;
    item->y = y;
}




int gameplay(void) {
    char input, time;
    struct player player[MAX_PLAYERS] = { {PLAYER_X, PLAYER_Y, 6, 3} };  // x,y,시야너비, 시야높이;
    struct items items[MAX_ITEMS] = { {0,0,"key"},{0,0,"key"},{0,0,'\0'},{0,0,'\0'},{0,0,'\0'}};

    
    for (int i = 0; i < MAX_ITEMS; i++) {
        Itemcoord(&items[i], player);
    }

    while (1) {
        time = timer();
        if (time == FAIL) return FAIL;
        input = movePlayer(player, items);
        if (input == BACK) return BACK;
        if (input == CLEAR) return CLEAR;
        //  if (input == FAIL) return FAIL;
        // if (input == SUBMIT) return BACK;
    }
    return 0;
}
