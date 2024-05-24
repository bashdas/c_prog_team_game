#pragma once
#include "appendix.h"
#include "item_tail.h"

int move(int dir);
void game_over(void);
void HP_print(int HP);
void reset_stage(void);

int move(int dir);





void reset_stage(void){
    int i;
    system("cls"); //화면을 지움 
    draw_map(); //맵 테두리를 그림 
    gotoxy(MAP_X, MAP_Y, "■");
    while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림 
    
    HP = 3;
    dir = RIGHT; // 방향 초기화  
    speed = 200; // 속도 초기화 
    length = 2; // 길이 초기화 
    score = 0; //점수 초기화 
    x[0] = 5;
    y[0] = 5;

    // 빨간색 플레이어
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    gotoxy(MAP_X + x[0], MAP_Y + y[0], "■"); // 머리 그림 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


    /* item생성 함수의 위치 */
    strider();
    strider1();
    item0();
    item0a();
    item1();
    item();
   
   
    Sleep(200);
}


// item 과 플레이어가 충돌한 경우의 함수

int move(int dir) {
    int i;

    if (x[0] == MAP_X*2+1 || x[0] == MAP_X+MAP_WIDTH-1 || y[0] == MAP_Y+3 || y[0] == MAP_Y+MAP_HEIGHT-6) { //벽과 충돌했을 경우 
        game_over();
        return 0; //game_over에서 게임을 다시 시작하게 되면 여기서부터 반복되므로 
        //return을 사용하여 move의 나머지 부분이 실행되지 않도록 합니다. 
    }
    player_crush();
    item0_crush();
    item0a_crush();
    item_crush();
    item1_crush();

    gotoxy(MAP_X + x[length - 1], MAP_Y + y[length - 1], "  "); //몸통 마지막을 지움 
    for (i = length - 1; i > 0; i--) { //몸통좌표를 한칸씩 옮김 
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    if (dir == LEFT) x[0]-=1; //방향에 따라 새로운 머리좌표(x[0],y[0])값을 변경 
    if (dir == RIGHT) x[0]+=1;
    if (dir == UP) y[0]-=1;
    if (dir == DOWN) y[0]+=1;
    gotoxy(MAP_X + x[i], MAP_Y + y[i], "■"); //새로운 머리좌표값에 머리를 그림 

    move_strider();
    move_strider1();
    /* 좌표와 충돌 판단 */
    
    return 0;
}

void game_over(void) { //게임종료 함수 
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    draw_map();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      GAME OVER..     |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " : ");
    printf("%d", HP);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, " < Press any keys to restart..> ");

    if (score > best_score) {
        best_score = score;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 4, MAP_Y + 10, "☆ BEST SCORE ☆");
    }
    Sleep(500);
    while (_kbhit()) _getch();
    key = _getch();

    title();
}

void HP_print(int HP) {


    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(MAP_X, MAP_Y + MAP_HEIGHT, " HP:"); //HP표시

    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    switch (HP)
    {
    case 0:
        game_over();
        break;
    case 1:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "                  "); //HP표시
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " ♥"); //HP표시
        break;

    case 2:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "              "); //HP표시

        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " ♥ ♥"); //HP표시
        break;
    case 3:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "                   "); //HP표시
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " ♥ ♥ ♥"); //HP표시
        break;
    case 4:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "              "); //HP표시
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " ♥ ♥ ♥ ♥"); //HP표시
        break;
    case 5:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "               "); //HP표시
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " ♥ ♥ ♥ ♥ ♥"); //HP표시
        break;
    case 6:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "                  "); //HP표시
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " ♥ ♥ ♥ ♥ ♥ ♥"); //HP표시
        break;
    default:
        break;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + 10, MAP_Y + MAP_HEIGHT, " SPEED:"); //점수표시
    gotoxy(MAP_X + 15, MAP_Y + MAP_HEIGHT, "             ");
    gotoxy(MAP_X + 14, MAP_Y + MAP_HEIGHT, "");
    printf("%d", 201-speed);
};
