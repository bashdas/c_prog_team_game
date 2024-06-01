#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <locale.h>
#include <wchar.h>
#pragma comment(lib, "winmm.lib")

extern int theme;
int HP;
float timek;
/* ***********************기호 상수*********************** */

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

// 게임 메뉴
#define GAMESTART 100
#define GAMERULE 200
#define OPTION 300
#define OPTION1 310
#define MUSIC1 311
#define MUSIC2 319
#define OPTION2 320
#define THEME1 321
#define THEME2 323
#define THEME3 325
#define THEME4 327
#define THEME0 329
#define GAMEEXIT 400

// 게임
#define HOME 500
#define CLEAR_V 700
#define FAIL_V 600


#define EASY 0
#define NORMAL 1
#define HARD 2


#define MAX_PLAYERS 1 // 플레이어 수
#define MAX_ITEMS 7 // 아이템 수

#define MAX_ITEMS_NAME 10 // 아이템 이름 길이(NULL 포함)
#define PLAYER_X MAP_X * 2 + 7  // 캐릭터의 X 좌표
#define PLAYER_Y MAP_HEIGHT / 2 + 5   // 캐릭터의 Y 좌표

#define MAX_STRIDER 3

struct player
{
    int x;	// 캐릭터 x좌표
    int y;  // 캐릭터 y좌표
    int sw;	// 캐릭터 시야너비 노말
    int sh;	// 캐릭터 시야높이 노말
    int swh; // 캐릭터 시야너비 하드
    int shh; // 캐릭터 시야높이 하드
};

struct items
{
    int x;	// 아이템 x좌표
    int y;  // 아이템 y좌표
    char skill[MAX_ITEMS_NAME]; // 아이템 능력

};

struct strider {
    int sx;
    int sy;
    int on;
};

/* *********************** 함수 선언 *********************** */
/* ************ main.c ************ */
int main(void);

/* ************ map.c ************ */
void drawMap(void);                         // 맵 테두리를 그림
void gameMapDraw(void);                     // 게임 맵을 그림
void reset(void);                           // 콘솔 화면을 지운 후 맵 테두리를 다시 그림
void resetMapInner(void);                   // 게임 맵 내부만 지움
void resetMapTitle(void);                   // 게임 맵 상단(목숨 창)만 지움
void resetMapMain(void);                    // 게임플레이하는 맵만 지움
void resetMapBottom(void);                  // 게임 맵 하단(상호작용)만 지움
void titleBoxDraw(void);                    // 디자인 요소(통일)
void gameExit(void);			            // 프로그램 종료

/* ************ system.c ************ */
void Setcolor(WORD color);                  // 색 숫자
void gotoxy(int x, int y, const char* s);   // x,y좌표, 출력문자열
void gotoxy1(int x, int y);                 // x,y좌표
int keyControl1(void);			            // keyboard value 반환
void slowPrint(const wchar_t story[][MAX_COLS], int x, int y, int rowcount); // 스토리배열, x,y좌표, 총 행 수



/* ************ title.c ************ */
void title(void);				            // 게임 시작화면 

/* ************ menuselect.c ************ */
int menuDraw1(void);			            // GAMESTART, GAMERULE, OPTION, GAMEEXIT 반환
void menuDraw1Content(void);                // 사용자와 상호작용 없는 메뉴 출력물
void menuDraw2Content(int c1, int c2, int c3, int c4); // 사용자와 상호작용이 있는 메뉴 출력물

/* ************ option.c ************ */
void initOption(void);                      // 환경설정 실행
int selectOption(void);                     // 사용자 키 입력 상호작용 OPTION1, OPTION2 반환
int selectOptionContent(void);
int selectOptionContent2(int c1, int c2);
int setMusic(void);                         // 음악 설정, BACK반환
int selectMusic(void);                      // MUSIC1,MUSIC2,MUSIC3,MUSIC4 반환
void selectMusicContent(void);
void selectMusicContent2(int c1, int c2, int c3, int c4);
int setTheme(void);                         // 테마 설정, BACK반환
int selectTheme(void);                      // THEME1, THEME2, THEME3, THEME4, THEME5 반환
void selectThemeContent(void);
void selectThemeContent2(int c1, int c2, int c3, int c4, int c5);

/* ************ gamerule.c ************ */
void gameRulesDraw(void);


/* ************ gamemode.c ************ */
int modeSelect(void);			// EASY(0), NORMAL(1), HARD(1) 반환
void modeSelectContentDraw(void);
void modeSelectContentDraw1(int c1, int c2, int c3);  // 컬러색 매개변수
void modeSelectContentDraw2(int c1, int c2, int c3);

/* ************ story.c ************ */
void titleStory(void);
void easyStory(void);
void normalStory(void);
void hardStory(void);
int clearStory(void);                       // HOME 반환
int failStory(void);                        // HOME 반환

/* ************ gameresult.c ************ */
void clearEasy(void);
void clearNormal(void);
void clearStorybg(void);
void failStorybg(void);


/* ************ game.c ************ */
int gameDraw(void);				// HOME 반환
int easyMode(void);				// BACK, NORMAL, FAIL 반환
int normalMode(void);			// BACK, HARD, FAIL 반환
int hardMode(void);				// BACK, CLEAR, FAIL 반환
void HP_print(int HP);

/* ************ gameplay.c ************ */


/* ************ strider.c ************ */
void stridercoord(struct strider* strider, struct player player);
void drawLRStrider(int x, int y, int right, int left);
void removeLRStrider(int x, int y, int right, int left);
void moveLRStrider(struct strider* strider_info);
void drawUDStrider(int x, int y, int upper, int bottom);
void removeUDStrider(int x, int y, int upper, int bottom);
void moveUDStrider(struct strider* strider_info);
void CDStrider(int px, int py, struct strider* strider_info);


/* ************ player.c ************ */
void drawPlayer(int x, int y);
void removePlayer(int x, int y);
void drawPlayerSight(int x, int y, int bottom, int right, int upper, int left);
void removePlayerSight(int x, int y, int bottom, int right, int upper, int left);

/* ************ item.c ************ */
void drawItem(int x, int y);
void removeItem(int x, int y);
void Itemcoord(struct items* item, struct player player);// 아이템 배열 구조체에 랜덤 좌표를 넣는 함수.
void initItem(struct items* item_array, int playerx, int playery, int i);// 시야 범위에 들어오면 아이템 출력. 충돌 시  initItem 호출
void judge_item(int i, struct strider* s);// 아이템 배열 구조체 (i) 아이템 종류 판단 함수
void judge_easy_item(int i);
void eatItem(struct player player_info, struct items* item_array, struct strider* s, int playerx, int playery);
void eatItemStrider(struct strider* strider_info, struct items* item_array);
void itemeatEasy(int playerx, int playery, struct items* item_array);
void itemeatNormal(int playerx, int playery, struct items* item_array, struct strider* s);


/* ************ playermove.c ************ */
int movePlayer(struct player* player_info, struct items* item_array, struct strider* strider_info);  // hard모드 move
int playermoveNormal(struct player* player_info, struct items* item_array, struct strider* strider_info);
int playermoveEasy(struct player* player_info, struct items* item_array); // easy, normal모드 move

/* ************ gameplay.c ************ */
void time_g(float timek);
int isClear(struct items* item_array);// key=열쇠 일 때 CLEAR 반환.

// 게임을 진행하는 함수
int gameplay(void);
int gameplayEasy(void);
int gameplayNormal(void);
//*******************************************************************************************

//void timer(void);
