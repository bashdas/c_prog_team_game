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
void title(void);				// 게임 시작화면 
void reset(void);				// 게임을 초기화 
void drawMap(void);				// 게임판 테두리를 그림 
void reset(void);
void gotoxy1(int x, int y);
int menuDraw1(void);			// BACK, y- 15(1~4) 반환
int keyControl1(void);			// keyboard value 반환
void slowPrint(const char* s, int x, int y);


/* game */
#define HOME 5					// 스테이지 성공 또는 실패 시 메인으로 복귀
int gameDraw(void);				// HOME 반환
void titleStory(void);
char modeSelect(void);			// EASY(0), NORMAL(1), HARD(1) 반환
void modeSelectMapDraw(int ctitle, int ceasy, int cnormal, int chard);  // 컬러색 매개변수
void easyStory(void);
void normalStory(void);
void hardStory(void);
int easyMode(void);				// BACK, -1, HOME 반환
int normalMode(void);			// BACK, -1, HOME 반환
int hardMode(void);				// BACK, -1, HOME 반환
int playerMove(void);			// BACK, -1, HOME 반환
void gameMapDraw(void);

/* gamerule */
#define EASY 0
#define NORMAL 1
#define HARD 2
void gameRulesDraw(void);
