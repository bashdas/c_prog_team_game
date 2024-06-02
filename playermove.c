#include "main.h"

/*
플레이어 이동
- 플레이어 좌표 저장할 포인터 변수
- 아이템 좌표 필요 -> 이동하면서 플레이어 좌표가 아이템 좌표 일정 범위에 들어오면 아이템 출력, 충돌 시 지우기

*/

// 시야가 포함된 함수.
int movePlayer(struct player* player_info, struct items* item_array, struct strider* strider_info) {
    int playerx = player_info[0].x;	// 플레이어 x 좌표
    int playery = player_info[0].y; // 플레이어 y 좌표
    int curx = playerx; // 설정 좌표 x
    int cury = playery; // 설정 좌표  y // MAP_X * 2 + 7, MAP_HEIGHT / 2 + 5
    int upper = 0, bottom = 7, left = 0, right = 14; // 플레이어 시야 배열을 얼만큼 돌릴 지


    drawPlayerSight(playerx, playery, bottom, right, upper, left);
    drawPlayer(playerx, playery);

    gotoxy1(0, 21);
    printf("%d", strider_info[0].sx);

    while (1)
    {
        time_g(timek);
        HP_print(HP);
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

        // 아이템과 플레이어 충돌 시 아이템 획득 처리
        eatItem(*player_info, item_array, strider_info, playerx, playery);
        eatItemStrider(strider_info, item_array, HARD);
        // 키 입력 시 경비병도 이동
        moveLRStrider(strider_info);
        moveUDStrider(strider_info);
        CDStrider(playerx, playery, strider_info);


        timek = timek +0.25;

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
        };

        gotoxy1(0, 5);
        printf("HP: %d", HP);
        gotoxy1(0, 15);
        printf("S1: %d %d\n", strider_info[0].sx, strider_info[0].sy);
        printf("S2: %d %d", strider_info[1].sx, strider_info[1].sy);
       

        // 클리어 -> 클리어 반환 return CLEAR;
        // 열쇠 획득 시 게임 성공 
        if (isClear(item_array) == CLEAR_V) return CLEAR_V;


        if (100 - timek <= 0) return FAIL_V;
        // 실패 -> 실패 반환 returb FAIL;
        // 
        // 제한 시간 끝나면 -1 목숨, 제한 시간 추가 부여

    }
}

int playermoveNormal(struct player* player_info, struct items* item_array, struct strider* strider_info)
{
    int playerx = player_info[0].x;	// 플레이어 x 좌표
    int playery = player_info[0].y; // 플레이어 y 좌표

    drawPlayer(playerx, playery);
    while (1)
    {
        time_g(timek);
        HP_print(HP);

        int n = keyControl1();
        switch (n)
        {
        case UP:
            if (playery > 5) {
                removePlayer(playerx, playery);
                playery--;
                drawPlayer(playerx, playery);
            }
            break;
        case DOWN:
            if (playery < 21) {
                removePlayer(playerx, playery);
                playery++;
                drawPlayer(playerx, playery);
            }
            break;
        case LEFT:
            if (playerx > 23) {
                removePlayer(playerx, playery);
                playerx--;
                drawPlayer(playerx, playery);
            }
            break;
        case RIGHT:
            if (playerx < 96) {
                removePlayer(playerx, playery);
                playerx++;
                drawPlayer(playerx, playery);
            }
            break;
        case BACK:
            return BACK;
            break;
        }
        moveLRStrider(strider_info);
        moveUDStrider(strider_info);
        CDStrider(playerx, playery, strider_info);
        itemeatNormal(playerx, playery, item_array, strider_info);
        eatItemStrider(strider_info, item_array, NORMAL);
        timek = timek + 0.25;
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
        };

        gotoxy1(0, 5);
        printf("HP: %d", HP);
        gotoxy1(0, 15);
        printf("S1: %d %d\n", strider_info[0].sx, strider_info[0].sy);
        printf("S2: %d %d", strider_info[1].sx, strider_info[1].sy);
        if (isClear(item_array) == CLEAR_V) return CLEAR_V;

        if (100 - timek <= 0) return FAIL_V;
    }
}

int playermoveEasy(struct player* player_info, struct items* item_array)
{
    int playerx = player_info[0].x;	// 플레이어 x 좌표
    int playery = player_info[0].y; // 플레이어 y 좌표
    drawPlayer(playerx, playery);
    while (1)
    {
        time_g(timek);
        HP_print(HP);

        int n = keyControl1();
        switch (n)
        {
        case UP:
            if (playery > 5) {
                removePlayer(playerx, playery);
                playery--;
                drawPlayer(playerx, playery);
            }
            break;
        case DOWN:
            if (playery < 21) {
                removePlayer(playerx, playery);
                playery++;
                drawPlayer(playerx, playery);
            }
            break;
        case LEFT:
            if (playerx > 23) {
                removePlayer(playerx, playery);
                playerx--;
                drawPlayer(playerx, playery);
            }
            break;
        case RIGHT:
            if (playerx < 96) {
                removePlayer(playerx, playery);
                playerx++;
                drawPlayer(playerx, playery);
            }
            break;
        case BACK:
            return BACK;
            break;
        }
        itemeatEasy(playerx, playery, item_array);
        timek = timek + 0.5;

        if (isClear(item_array) == CLEAR_V) return CLEAR_V;

        if (100 - timek <= 0) return FAIL_V;
    }
}