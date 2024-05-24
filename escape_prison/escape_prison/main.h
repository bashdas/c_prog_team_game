#pragma once
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

/* main */

// 키 값 정의  //
#define LEFT1 75
#define RIGHT1 77
#define UP1 72
#define DOWN1 80
#define PAUSE 112
#define BACK 113
#define ESC 27

// MAP 값
#define MAP_X 11 // 3 2
#define MAP_Y 2
#define MAP_WIDTH 39  // 30 20
#define MAP_HEIGHT 26

// keyboard value
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // 선택(키)

// stoty cols, rows
#define MAX_ROWS 16
#define MAX_COLS 50

void Setcolor(WORD color);
void gotoxy(int x, int y, const char* s);
void title(void);				// 게임 시작화면 
void reset(void);				// 게임을 초기화
void resetMapInner(void);		// 맵 테두리 내부만 지움
void resetMapTitle(void);		// 목숨창만 지움
void resetMapMain(void);		// 게임창만 지움
void resetMapBottom(void);		// 상호작용창만 지움
void drawMap(void);				// 게임판 테두리를 그림 
void titleBoxDraw(void);		// titlebox를 그림
void gotoxy1(int x, int y);
int menuDraw1(void);			// BACK, y- 15(1~4) 반환
void menuDraw1Content(int c1, int c2, int c3, int c4, int c5, int c6);
int keyControl1(void);			// keyboard value 반환
void slowPrint(const char story[][MAX_COLS], int x, int y);
void gameExit(void);			// 게임 끄기전에 보여주는 화면


/* game */
#define HOME 5					// 스테이지 성공 또는 실패 시 메인으로 복귀
int gameDraw(void);				// HOME 반환
void titleStory(void);
int modeSelect(void);			// EASY(0), NORMAL(1), HARD(1) 반환
void modeSelectMapDraw(int ctitle, int ceasy, int cnormal, int chard);  // 컬러색 매개변수
void easyStory(void);
void normalStory(void);
void hardStory(void);
int easyMode(void);				// BACK, -1, HOME 반환
int normalMode(void);			// BACK, -1, HOME 반환
int hardMode(void);				// BACK, -1, HOME 반환
int playerMove(void);			// BACK, -1, HOME 반환
void gameMapDraw(void);


/* player */

void HP_print(int HP);   // 전역변수 HP의 값에 따라 HP를 다르게 출력함. HP=0이면 game_over(). speed도 출력 가능
int move(int dir);       // 플레이어의 활동 범위 정의
                         // 플레이어의 방향키에 따라 플레이어를 출력함
                         // player_crush(), item0_crush(),  time0a_crush(), item1_crush(), item_crush()로 충돌 판단


void reset_stage(void);  // HP, 방향, 속도, 길이, 초(second) 초기화. 플레이어 시작 위치 초기

void game_over(void);    // 각 스테이지 종료 함수. 


/* item, 경비병 생성 함수 */

void strider(void);       // 경비병1 출력. 시작 위치 정함
void move_strider(void);  //  경비병1 이동 함수. 

void strider1(void);     // 경비병 2 출력. 시작 위치 정함. 
void move_strider1(void);  // 경비병 2 이동 함수. 




/* gamerule */
#define EASY 0
#define NORMAL 1
#define HARD 2
void gameRulesDraw(void);

/*theme*/
extern int theme;
// static int* ptheme = &theme;


/*
0	: 검은색
1	: 파란색
2	: 초록색
3	: 청록색
4	: 빨간색
5	: 자주색
6	: 노란색
7	: 흰색
8	: 회색  
9	: 밝은 파란색
10	: 밝은 초록색
11	: 밝은 청록색
12	: 밝은 빨간색
13	: 밝은 자주색
14	: 밝은 노란색
15	: 밝은 흰색
*/


/* option */
// 색 바꿀 변수 추후에
int setTheme(void);
int setMusic(void);
void selectMusicContent(int c1, int c2, int c3, int c4);
int selectTheme(void);
void selectThemeContent(int c1, int c2, int c3, int c4, int c5);
int selectOption(void);
int selectOptionContent(int c1, int c2);
void initOption(void);

/* play&item.c */

/* pause.c */
void pause(void);   // p키를 눌렀을 경우 게임을 일시 정지한다. 
