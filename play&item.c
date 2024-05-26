#include "main.h"

#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 39
#define MAP_HEIGHT 26
int x[100], y[100]; //x,y 좌표값을 저장 총 100개 
int x1[100], y1[100];

int item_x, item_y; //item의 좌표값을 저장 
int length; //몸길이를 기억


// Key의 좌표  x: 4~40, y: 3~22
int key_x, key_y;

// poison의 좌표
int poison_x, poison_y;

// 체력
int HP = 3;
int* pHP = &HP;


// 게임 시스템
int speed; //게임 속도 
int score; //점수 저장  --reset함수에 의해 초기화됨
int best_score = 0; //최고 점수 저장 --reset함수에 의해 초기화 되지 않음 
int last_score = 0; //마지막 점수 저장  --reset함수에 의해 초기화 되지 않음
int dir; //이동방향 저장 
int key; //입력받은 키 저장 
int status_on = 0; // 개발자용 status 표시활성화 변수.. 게임중에 S키를 누르면 활성 

void key_random(void);
void poison_random(void);
void preyer(void);

void gotoxy(int x, int y, const char* s) { //x값을 2x로 변경, 좌표값에 바로 문자열을 입력할 수 있도록 printf함수 삽입  
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);
}

void title(void); //게임 시작화면 
void reset(void); //게임을 초기화 
void draw_map(void); // 게임판 테두리를 그림 
int move(int dir); //플레이어를 이동 
void pause(void); //일시정지 
void game_over(void); //게임 오버를 확인 
void item(void); // 음식 생성 
void status(void); // 개발자용 status표시  

void HP_print(int HP) {


    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(MAP_X, MAP_Y + MAP_HEIGHT, " HP:"); //HP표시
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    switch (HP)
    {
    case 0:
        break;
    case 1:

        printf(" ♥");
        break;
    case 2:
        printf(" ♥ ♥");
        break;
    case 3:
        printf(" ♥ ♥ ♥");
        break;
    case 4:
        printf(" ♥ ♥ ♥ ♥");
        break;
    case 5:
        printf(" ♥ ♥ ♥ ♥ ♥");
        break;
    case 6:
        printf(" ♥ ♥ ♥ ♥ ♥ ♥");
        break;
    default:
        break;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + 10, MAP_Y + MAP_HEIGHT, " HP:"); //점수표시
    printf("%d", HP);

}

////////////////////////////MAIN START//////////////////////////////
int main() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    title();

    while (1) {
        if (_kbhit()) do { key = _getch(); } while (key == 224); //키 입력받음
        Sleep(speed);

        switch (key) { //입력받은 키를 파악하고 실행  
        case LEFT:
        case RIGHT:
        case UP:
        case DOWN:
            if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) ||
                (dir == DOWN && key != UP))//180회전이동을 방지하기 위해 필요. 
                dir = key;
            key = 0; // 키값을 저장하는 함수를 reset 
            break;
        case PAUSE: // P키를 누르면 일시정지 
            pause();
            break;
        case 115: //S키를 누르면 개발자용 status를 활성화 시킴  
            if (status_on == 0) status_on = 1;
            else status_on = 0;
            key = 0;
            break;
        case ESC: //ESC키를 누르면 프로그램 종료 
            system("cls");
            printf("게임을 끝냅니다.");
            Sleep(500);
            exit(0);
        }
        int a = move(dir);

        HP_print(HP);



        if (a == -1)
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, " < GAME CLEAR > ");

            game_over();

        }




        if (status_on == 1); // status표시 
    }

}

///////////////////////////MAIN END////////////////////////////////

void title(void) {
    int i, j;

    while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림 

    draw_map();    //맵 테두리를 그림 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // 맵 테두리 안쪽을 빈칸으로 채움 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
    }

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|   |   |    |    |   |    |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, " < PRESS ANY KEY TO START > ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "   ◇ ←,→,↑,↓ : Move    ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   ◇ Settings              ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   ◇ ESC : Quit             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, "   ◇ P : Pause             ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 17, "         KU CSE  ");

    while (1) {
        if (_kbhit()) { //키입력받음 
            key = _getch();
            if (key == ESC) exit(0); // ESC키면 종료 
            else break; //아니면 그냥 계속 진행 
        }
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, " < PRESS ANY KEY TO START > ");
        Sleep(400);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "                            ");
        Sleep(400);

    }
    reset(); // 게임을 초기화  

}

void reset(void) {
    int i;
    system("cls"); //화면을 지움 
    draw_map(); //맵 테두리를 그림 
    gotoxy(MAP_X, MAP_Y, "■");
    while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림 

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

    preyer();
    item(); // item 생성 

    key_random();
    poison_random();
    Sleep(200);
}
// 회색 플레이어
void preyer() {
    x1[0] = 10;
    y1[0] = 10;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

    gotoxy(MAP_X + x1[0], MAP_Y + y1[0], "■"); // 머리 그림 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

};


void draw_map(void) { //맵 테두리 그리는 함수 
    int i, j;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    for (i = 0; i < MAP_WIDTH; i++) {
        gotoxy(MAP_X + i, MAP_Y, "■");
    }
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
        gotoxy(MAP_X, i, "■");
        gotoxy(MAP_X + MAP_WIDTH - 1, i, "■");
    }
    for (i = 0; i < MAP_WIDTH; i++) {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "■");
    }
    HP = 3;
}



// item 과 플레이어가 충돌한 경우의 함수

int move(int dir) {
    int i;

    if (x[0] == item_x && y[0] == item_y) { //item 와 충돌했을 경우 
        return -1;
    }
    if (x[0] == 0 || x[0] == MAP_WIDTH - 1 || y[0] == 0 || y[0] == MAP_HEIGHT - 1) { //벽과 충돌했을 경우 
        game_over();
        return 0; //game_over에서 게임을 다시 시작하게 되면 여기서부터 반복되므로 
        //return을 사용하여 move의 나머지 부분이 실행되지 않도록 합니다. 
    }
    if (x[0] == key_x && y[0] == key_y)
    {
        HP += 1;
        key_random();

    }
    if (x[0] == poison_x && y[0] == poison_y)
    {

        HP = HP - 1;
        poison_random();
    }

    /*for (i = 1; i < length; i++) { //자기몸과 충돌했는지 검사
        if (x[0] == x[i] && y[0] == y[i]) {
            game_over();
            return 0;
        }
    }*/

    gotoxy(MAP_X + x[length - 1], MAP_Y + y[length - 1], "  "); //몸통 마지막을 지움 
    for (i = length - 1; i > 0; i--) { //몸통좌표를 한칸씩 옮김 
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    if (dir == LEFT) --x[0]; //방향에 따라 새로운 머리좌표(x[0],y[0])값을 변경 
    if (dir == RIGHT) ++x[0];
    if (dir == UP) --y[0];
    if (dir == DOWN) ++y[0];
    gotoxy(MAP_X + x[i], MAP_Y + y[i], "■"); //새로운 머리좌표값에 머리를 그림 




    ///////////////////////////////////////*
   /* gotoxy(MAP_X + x1[length - 1], MAP_Y + y1[length - 1], "  "); //몸통 마지막을 지움
    for (i = length - 1; i > 0; i--) { //몸통좌표를 한칸씩 옮김
        x1[i] = x1[i - 1];
        y1[i] = y1[i - 1];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    if (x1[0] >= 2)
    {
        --x1[0];
    } //방향에 따라 새로운 머리좌표(x[0],y[0])값을 변경

    else if (x1[0] < 15)
    {
        ++x[0];
    }

    gotoxy(MAP_X + x1[i], MAP_Y + y1[i], "■"); //새로운 머리좌표값에 머리를 그림 */


}


void pause(void) { // p키를 눌렀을 경우 게임을 일시 정지
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (1) {
        if (key == PAUSE) {
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
            Sleep(400);
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "                                    ");
            Sleep(400);
        }
        else {
            draw_map();
            return;
        }
        if (_kbhit()) {

            do {
                key = _getch();
            } while (key == 224);
        }

    }
}

void game_over(void) { //게임종료 함수 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      GAME OVER..     |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " YOUR SCORE : ");
    for (int k = 0; k < HP; k++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf(" ♥");
    };
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, " Press any keys to restart.. ");

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

void item(void) {
    int i;

    int item_crush_on = 0;//item이 플레이어의 좌표에 생길 경우 on 
    int r = 0; //난수 생성에 사동되는 변수 


    while (1) {
        item_crush_on = 0;
        srand((unsigned)time(NULL) + r); //난수표생성 
        item_x = (rand() % (MAP_WIDTH - 2)) + 1;    //난수를 좌표값에 넣음 
        item_y = (rand() % (MAP_HEIGHT - 2)) + 1;

        for (i = 0; i < length; i++) { // item과 플레이어가 겹치는지 확인  
            if (item_x == x[i] && item_y == y[i]) {
                item_crush_on = 1; //겹치면 item_crush_on 를 on 
                r++;

                break;
            }
        }

        if (item_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 

        gotoxy(MAP_X + item_x, MAP_Y + item_y, "♪"); //안겹쳤을 경우 좌표값에item를 찍고 
        speed -= 3; //속도 증가 
        break;

    }
}

void key_random(void)
{
    // x,y좌표의 범위  // (MAP_X + 1) ~ (MAP_X + 37)       (MAP_Y+1) ~ (MAP_Y+20)

    int i;
    int k = 1;
    int HP_crush_on = 0;

    while (1) {
        srand((unsigned)time(NULL) + k);
        key_x = rand() % 23 + 5; // 0~25 (5~30) 28개 나머지 0~36
        key_y = rand() % 14 + 4; // 0~15 (4~19) 20개 나머지 0~19

        for (i = 0; i < length; i++) { // item과 플레이어가 겹치는지 확인  
            if (item_x == x[i] && item_y == y[i]) {
                HP_crush_on = 1; //겹치면 item_crush_on 를 on 
                HP += 1;
                k++;
                break;
            }
        }

        if (HP_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        gotoxy(MAP_X + key_x, MAP_Y + key_y, "★"); //안겹쳤을 경우 좌표값에item를 찍고 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        break;

    }
}

void poison_random(void)
{
    // x,y좌표의 범위  // (MAP_X + 1) ~ (MAP_X + 37)       (MAP_Y+1) ~ (MAP_Y+20)

    int i;
    int k = 0;
    int poison_crush_on = 0;

    while (1) {
        srand((unsigned)time(NULL) + k);
        poison_x = rand() % 25 + 3; // 0~25 (5~30) 28개 나머지 0~36
        poison_y = rand() % 15 + 4; // 0~15 (4~19) 20개 나머지 0~19

        for (i = 0; i < length; i++) { // item과 플레이어가 겹치는지 확인  
            if (poison_x == x[i] && poison_y == y[i]) {
                poison_crush_on = 1; //겹치면 item_crush_on 를 on 
                HP += 1;
                k++;
                break;
            }
        }

        if (poison_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        gotoxy(MAP_X + poison_x, MAP_Y + poison_y, "★"); //안겹쳤을 경우 좌표값에item를 찍고 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        break;

    }
}