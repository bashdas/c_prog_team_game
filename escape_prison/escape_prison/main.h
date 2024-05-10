#pragma once
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

/* main */

// 키 값 정의  //
#define LEFT1 75
#define RIGHT1 77
#define UP1 72
#define DOWN1 80
#define PAUSE1 112
#define ESC 27

// MAP 값
#define MAP_X 3 // 3 2
#define MAP_Y 2
#define MAP_WIDTH 39  // 30 20
#define MAP_HEIGHT 26

// keyboard value
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // 선택(키)

void Setcolor(WORD color);
void gotoxy(int x, int y, const char* s);
void title(void); //게임 시작화면 
void reset(void); //게임을 초기화 
void draw_map(void); // 게임판 테두리를 그림 
void load_menu(void); // 메뉴를 불러오는 함수.
void gotoxy1(int x, int y);
int menuDraw1();
int keyControl1();


/* gamerule */

#define RULE_MOVE "1. Use arrow keys to move the character."
#define RULE_NAVIGATE "2. Navigate through different stages."

void showGameRules();
void displayRules();