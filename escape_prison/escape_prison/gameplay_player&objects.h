#pragma once
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include "main.h"

#define MAP_X 3  // ?? main.h와 한번 더 비교해서 확인해보기 ?? 뭔가 예상했던 값과 다르다.


// 게임 시스템

int speed; //게임 속도 
int score; //점수 저장  --reset함수에 의해 초기화됨
int best_score = 0; //최고 점수 저장 --reset함수에 의해 초기화 되지 않음 
int last_score = 0; //마지막 점수 저장  --reset함수에 의해 초기화 되지 않음
int dir; //이동방향 저장 
int key; //입력받은 키 저장 
int status_on = 0; // 개발자용 status 표시활성화 변수.. 게임중에 S키를 누르면 활성 

// 길이
int length; // 플레이어의 꼬리
int length1=4;   // strider의 길이
int length2 =4;  // strider1의 길이


// 체력 [전역변수]
int HP = 3;
int* pHP = &HP;

// 플레이어의 좌표
int x[100], y[100]; 

// strider의 좌표
int x1[100], y1[100];   // strider 의 좌표를 저장
int x2[100], y2[100];   // strider2 의 좌표를 저장

// 아이템 요소들의 좌표 
int item_x, item_y;     // 속도 증가 함수 

int item0_x, item0_y;   // item0 게임속도 증가 + 
int item0a_x, item0a_y; // item0a 게임속도 증가 +

int item1_x, item1_y; // item1. 게임속도 감소 -
int item1a_x, item1a_y; // item1a. 게임속도 감소 -

/**************************************************************/
// 경비병

void strider() {
    
    x1[0] = 10;
    y1[0] = 24;  // 1~24
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(MAP_X + x1[0], MAP_Y + y1[0], "■"); // 머리 그림 

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

};

void move_strider() {
    if (y1[0] <= 24 && y1[0] >=1) // 1~24
    {
        gotoxy(MAP_X + x1[length1 - 1], MAP_Y + y1[length1 - 1], "  "); //몸통 마지막을 지움 
        for (int i = length1 - 1; i > 0; i--) { //몸통좌표를 한칸씩 옮김 
            x1[i] = x1[i - 1];
            y1[i] = y1[i - 1];
        }
        //몸통 마지막을 지움 
       
        y1[0]-=1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        gotoxy(MAP_X + x1[0], MAP_Y + y1[0], "■"); // 머리 그림 

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    if (y1[0] <= 0)
        strider();

};

void strider1() {

    x2[0] = 1;
    y2[0] = 15;  // 1~24

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(MAP_X + x2[0], MAP_Y + y2[0], "■"); // 머리 그림 

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

};

void move_strider1() {
    if (x2[0] <= 37 && x2[0] >= 1) // 1~24
    {
        gotoxy(MAP_X + x2[length2 - 1], MAP_Y + y2[length2 - 1], "  "); //몸통 마지막을 지움 
        for (int i = length2 - 1; i > 0; i--) { //몸통좌표를 한칸씩 옮김 
            x2[i] = x2[i - 1];
            y2[i] = y2[i - 1];
        }
        //몸통 마지막을 지움 

        x2[0]++;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        gotoxy(MAP_X + x2[0], MAP_Y + y2[0], "■"); // 머리 그림 

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    if (x2[0]>37)
        strider1();

};
/**************************************************************/
// 아이템(게임 속도 증가)

void item0(void) {
    int i;

    int item0_crush_on = 0;//item이 플레이어의 좌표에 생길 경우 on 
    int r = 0; //난수 생성에 사동되는 변수 


    while (1) {
        item0_crush_on = 0;
        srand((unsigned)time(NULL) + r); //난수표생성 
        item0_x = rand() % 22 + 8; // 0~25 (5~30) 28개 나머지 0~36
        item0_y = rand() % 14 + 4; // 0~15 (4~19) 20개 나머지 0~19   //난수를 좌표값에 넣음 


        for (i = 0; i < length; i++) { // item과 플레이어가 겹치는지 확인  
            if (item0_x == x[i] && item0_y == y[i]) {
                item0_crush_on = 1; //겹치면 item_crush_on 를 on 
                r++;
                item0_x = rand() % 22 + 8; // 0~25 (5~30) 28개 나머지 0~36
                item0_y = rand() % 14 + 4; // 0~15 (4~19) 20개 나머지 0~19
                break;
            }
        }

        if (item0_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        gotoxy(MAP_X + item0_x, MAP_Y + item0_y, "♪"); //안겹쳤을 경우 좌표값에item를 찍고 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        speed -= 3; //속도 증가 
        break;

    }
}

void item0_crush() {
    // 플레이어와 충돌
    if (item0_x == x[0] && item0_y == y[0])
    {
        item0();
        speed=speed-20;
    }
    // strider와 충돌
    if (item0_x == x1[0] && item0_y == y1[0])
    {
        item0();
    }
};

void item0a(void) {
    int i;

    int item0a_crush_on = 0;//item이 플레이어의 좌표에 생길 경우 on 
    int r = 0; //난수 생성에 사동되는 변수 


    while (1) {
        item0a_crush_on = 0;
        srand((unsigned)time(NULL) + r); //난수표생성 
        item0a_x = rand() % 24 + 5; // 0~25 (5~30) 28개 나머지 0~36
        item0a_y = rand() % 13 + 4; // 0~15 (4~19) 20개 나머지 0~19   //난수를 좌표값에 넣음 


        for (i = 0; i < length; i++) { // item과 플레이어가 겹치는지 확인  
            if (item0a_x == x[i] && item0a_y == y[i]) {
                item0a_crush_on = 1; //겹치면 item_crush_on 를 on 
                r++;
                item0a_x = rand() % 22 + 8; // 0~25 (5~30) 28개 나머지 0~36
                item0a_y = rand() % 14 + 4; // 0~15 (4~19) 20개 나머지 0~19
                break;
            }
        }

        if (item0a_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        gotoxy(MAP_X + item0a_x, MAP_Y + item0a_y, "♪"); //안겹쳤을 경우 좌표값에item를 찍고 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        speed -= 3; //속도 증가 
        break;

    }
}

void item0a_crush() {
    // 플레이어와 충돌
    if (item0a_x == x[0] && item0a_y == y[0])
    {
        item0a();
        speed = speed - 20;
    }
    // strider와 충돌
    if (item0a_x == x1[0] && item0a_y == y1[0])
    {
        item0a();
    }
    // strider와 충돌
    if (item0a_x == x2[0] && item0a_y == y2[0])
    {
        item0a();
    }
    // item (speed 0)와 같은 위치
    if (item0a_x == item0_x && item0a_y == item0_y)
    {
        item0a();
    }
};

/**************************************************************/
// 아이템(게임 속도 감소)

void item1(void) {
    int i;

    int item0_crush_on = 0;//item이 플레이어의 좌표에 생길 경우 on 
    int r = 0; //난수 생성에 사동되는 변수 


    while (1) {
        item0_crush_on = 0;
        srand((unsigned)time(NULL) + r); //난수표생성 
        item1_x = rand() % 27 + 6; // 0~25 (5~30) 28개 나머지 0~36
        item1_y = rand() % 15 + 4; // 0~15 (4~19) 20개 나머지 0~19   //난수를 좌표값에 넣음 


        for (i = 0; i < length; i++) { // item과 플레이어가 겹치는지 확인  
            if (item1_x == x[i] && item1_y == y[i]) {
                item0_crush_on = 1; //겹치면 item_crush_on 를 on 
                r++;
                item1_x = rand() % 22 + 8; // 0~25 (5~30) 28개 나머지 0~36
                item1_y = rand() % 14 + 4; // 0~15 (4~19) 20개 나머지 0~19
                break;
            }
        }

        if (item0_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        gotoxy(MAP_X + item1_x, MAP_Y + item1_y, "♪"); //안겹쳤을 경우 좌표값에item를 찍고 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        speed -= 3; //속도 증가 
        break;

    }
};
void item1_crush() {
    // 플레이어와 충돌
    if (item1_x == x[0] && item1_y == y[0])
    {
        item1();
        speed = speed + 20;
    }
    // strider와 충돌
    if (item1_x == x1[0] && item1_y == y1[0])
    {
        item1();
    }
    if (item1_x == x2[0] && item1_y == y2[0])
    {
        item1();
    }
    // item (speed 0)와 같은 위치
    if (item1_x == item0_x && item1_y == item0_y)
    {
        item1();
    }
    if (item1_x == item0a_x && item1_y == item0a_y)
    {
        item1();
    }
};

/************************************************************/
void player_crush() {
    if (x1[0] == x[0] && y1[0] == y[0])
    {
        HP--;
        strider();
    }
    if (x1[0] == x[0] && y1[0] == y[0]-1)
    {
        HP--;
        strider();
    }
    if (x1[0] == x[0] && y1[0] == y[0]+1)
    {
        HP--;
        strider();
    }


};

/**************************************************************/
// 아이템(길이 증가)  뭔가 이상하다다.....?


void item(void) {
    int i;

    int item_crush_on = 0;//item이 플레이어의 좌표에 생길 경우 on 
    int r = 0; //난수 생성에 사동되는 변수 


    while (1) {
        item_crush_on = 0;
        srand((unsigned)time(NULL) + r); //난수표생성 
        item_x = rand() % 24+ 5; // 0~25 (5~30) 28개 나머지 0~36
        item_y = rand() % 13 + 5; // 0~15 (4~19) 20개 나머지 0~19   //난수를 좌표값에 넣음 


        for (i = 0; i < length; i++) { // item과 플레이어가 겹치는지 확인  
            if (item_x == x[i] && item_y == y[i]) {
                item_crush_on = 1; //겹치면 item_crush_on 를 on 
                r++;
                item_x = rand() % 20 + 5; // 0~25 (5~30) 28개 나머지 0~36
                item_y = rand() % 13 +3; // 0~15 (4~19) 20개 나머지 0~19
                break;
            }
        }

        if (item_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        gotoxy(MAP_X + item_x, MAP_Y + item_y, "★"); //안겹쳤을 경우 좌표값에item를 찍고 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        //속도 증가 
        
        break;
    }
};

void item_crush() {
    // 플레이어와 충돌
    if (item_x == x[0] && item_y == y[0])
    {
        item();
        length+=4;
    }
    // strider와 충돌
    if (item_x == x1[0] && item_y == y1[0])
    {
        item();
    }
    if (item_x == x2[0] && item_y == y2[0])
    {
        item();
    }
    // item (speed 0)와 같은 위치
    if (item_x == item0_x && item_y == item0_y)
    {
        item();
    }
    if (item_x == item0a_x && item_y == item0a_y)
    {
        item();
    }
};

/**************************************************************/
// HP 전역 변수를 출력하는 함수

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












