#pragma once
#include "main.h"

// x: 23~96   y: 5~21

int item1_x, item1_y;
/*
void item1(void) {
    int i;

    int item_crush_on = 0;//item이 플레이어의 좌표에 생길 경우 on 
    int r = 0; //난수 생성에 사동되는 변수 


    while (1) {
        item_crush_on = 0;
        srand((unsigned)time(NULL) + r); //난수표생성 
        item1_x = rand()%30+20;      //난수를 좌표값에 넣음 
        item1_y = rand()%15+5;

        
        

        if (item_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 
        Setcolor(15);
        gotoxy(item1_x,item1_y, "♪"); //안겹쳤을 경우 좌표값에item를 찍고 
        
        break;

    }
}

int movePlayer_e(struct player* player_info, struct items* item_array) {
    int playerx = player_info[0].x;	// 플레이어 x 좌표
    int playery = player_info[0].y; // 플레이어 y 좌표
    int curx = playerx; // 설정 좌표 x
    int cury = playery; // 설정 좌표  y // MAP_X * 2 + 7, MAP_HEIGHT / 2 + 5
  
    
    drawPlayer(playerx, playery);

    while (1)
    {
        time_g(timek);
        HP_print(HP);
        int n = keyControl1();
        switch (n) {
        case UP: {
         
        }
        case DOWN: {
     
        }
        case LEFT: {
       
        }
        case RIGHT: {
         
        }
        case BACK:
            return BACK;
            /*
            case SUBMIT: {
                return SUBMIT; // 처리 해야함

            }
        }
        // 시야 범위에 들어오면 아이템 출력





        // 아이템과 플레이어 충돌 시 아이템 획득 처리
        eatItem(*player_info, item_array, playerx, playery);



        timek = timek + 0.25;

        // 참고 하려고 적음 나중에 삭제 해야함 
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

        gotoxy1(0, 6);
        printf("%d", HP);

        // 클리어 -> 클리어 반환 return CLEAR;
        // 열쇠 획득 시 게임 성공 
        if (isClear(item_array) == CLEAR) return CLEAR;


        if (100 - timek <= 0)
        {
            Sleep(500);
            failStory();
            Sleep(700);
            return BACK;
        }
        // 실패 -> 실패 반환 returb FAIL;
        // 
        // 제한 시간 끝나면 -1 목숨, 제한 시간 추가 부여
*/
    






