#include "main.h"


int isClear(struct items* item_array) {
    if (strcmp(item_array[5].skill, "None") == 0 && strcmp(item_array[6].skill, "None") == 0)
        return CLEAR_V;
}

void time_g(float time)
{
    gotoxy1(MAP_X + MAP_WIDTH - 14, MAP_Y + 1);
    printf("남은 배터리: %.1f", (100 - time));
    Setcolor(15);
}

// 게임의 스테이지를 맨 처음 시작하는 함수
int gameplay(void) {
    int input;
    struct player player[MAX_PLAYERS] = { {PLAYER_X, PLAYER_Y, 6, 3} };  // x,y,시야너비, 시야높이;
    struct items items[MAX_ITEMS] = { {0,0,"b-"},{0,0,"hp+"}, {0,0,"b+"},{0,0,"b+"},{0,0,"s+"},{0,0,"key"},{0,0,"key"} };
    struct strider strider[MAX_STRIDER] = { {0,0,0}, {0,0,0}, {0,0,1} };
    int HP = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        Itemcoord(&items[i], player[0]);
    }
    for (int i = 0; i < MAX_STRIDER; i++) {
        stridercoord(&strider[i], player[0]);
    }
    if (strider[1].sy >= 18) {
        strider[1].sy = rand() % (MAP_HEIGHT - 13) + 5;
    }

    drawUDStrider(strider[1].sx, strider[1].sy, 0, 4);
    drawLRStrider(strider[0].sx, strider[0].sy, 7, 0);



    while (1) {

        input = movePlayer(player, items, strider);

        if (input == BACK) return BACK;
        if (input == CLEAR_V) return CLEAR_V;
        if (input == FAIL_V) return FAIL_V;
        // if (input == SUBMIT) return BACK;

    }

    return 0;
}

int gameplayNormal(void) {
    int input;
    struct player player[MAX_PLAYERS] = { {PLAYER_X, PLAYER_Y, 6, 3} };  // x,y,시야너비, 시야높이;
    struct items items[MAX_ITEMS] = { {0,0,"b-"},{0,0,"hp+"}, {0,0,"b+"},{0,0,"b+"},{0,0,"s+"},{0,0,"key"},{0,0,"key"}};
    struct strider strider[MAX_STRIDER] = { {0,0,0}, {0,0,0}, {0,0,1} };
    HP = 0;
    for (int i = 0; i < MAX_STRIDER; i++) {
        stridercoord(&strider[i], player[0]);
    }
    if (strider[1].sy >= 18) {
        strider[1].sy = rand() % (MAP_HEIGHT - 13) + 5;
    }

    drawUDStrider(strider[1].sx, strider[1].sy, 0, 4);
    drawLRStrider(strider[0].sx, strider[0].sy, 7, 0);


    for (int i = 0; i < MAX_ITEMS; i++) {
        Itemcoord(&items[i], player[0]);
        drawItem(items[i].x, items[i].y);
    }

    while (1) {
        input = playermoveNormal(player, items, strider);
        if (input == BACK) return BACK;
        if (input == CLEAR_V) return CLEAR_V;
        if (input == FAIL_V) return FAIL_V;
        // if (input == SUBMIT) return BACK;

    }
    return 0;
}

int gameplayEasy(void) {
    int input;
    struct player player[MAX_PLAYERS] = { {PLAYER_X, PLAYER_Y} };  // x,y,시야너비, 시야높이;
    struct items items[MAX_ITEMS] = { {0,0,"\0"},{0,0,"\0"}, {0,0,"\0"},{0,0,"\0"},{0,0,"\0"},{0,0,"key"},{0,0,"key"}};
    HP = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        Itemcoord(&items[i], player[0]);
        drawItem(items[i].x, items[i].y);
    }

    while (1) {

        input = playermoveEasy(player, items);
        if (input == BACK) return BACK;
        if (input == CLEAR_V) return CLEAR_V;
        if (input == FAIL_V) return FAIL_V;
        // if (input == SUBMIT) return BACK;

    }
    return 0;
} //Easy
