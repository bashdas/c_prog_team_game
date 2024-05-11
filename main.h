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
#define BACK 113
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
void drawMap(void); // 게임판 테두리를 그림 
// void load_menu(void); // 메뉴를 불러오는 함수.
void reset(void);
void gotoxy1(int x, int y);
int menuDraw1(void);
int keyControl1(void);
void slowPrint(const char* s, int x, int y);


/* game */
void gameDraw(void);
void story(void);
void modeSelect(void);
void easyStory(void);
void normalStory(void);
void hardStory(void);
void easyMode(void);
void normalMode(void);
void hardMode(void);
void gameMapDraw(void);

/* gamerule */
#define EASY 0;
#define NOMAL 1;
#define HARD 2;
void gameRulesDraw(void);
