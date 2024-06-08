#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <locale.h>
#include <wchar.h>
#include <stdbool.h>
#pragma comment(lib, "winmm.lib")

extern int theme;
int HP;
float timek;
/* ***********************��ȣ ���*********************** */

// Ű �� ����  //
#define LEFT1 75
#define RIGHT1 77
#define UP1 72
#define DOWN1 80
#define PAUSE 112
#define BACK 113
#define ESC 27

// MAP ��
#define MAP_X 11 // 3 2
#define MAP_Y 2
#define MAP_WIDTH 39  // 30 20
#define MAP_HEIGHT 26

// keyboard value
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // ����(Ű)

// stoty cols, rows
#define MAX_ROWS 16
#define MAX_COLS 50

// ���� �޴�
#define GAMESTART 100
#define GAMERULE 200
#define OPTION 300
#define ITEM_EX 721

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

// ����
#define HOME 500
#define CLEAR_V 700
#define FAIL_V 600


#define EASY 0
#define NORMAL 1
#define HARD 2


#define MAX_PLAYERS 1 // �÷��̾� ��
#define MAX_ITEMS 7 // ������ ��

#define MAX_ITEMS_NAME 10 // ������ �̸� ����(NULL ����)
#define PLAYER_X MAP_X * 2 + 7  // ĳ������ X ��ǥ
#define PLAYER_Y MAP_HEIGHT / 2 + 5   // ĳ������ Y ��ǥ

#define MAX_STRIDER 3

struct player
{
	int x;	// ĳ���� x��ǥ
	int y;  // ĳ���� y��ǥ
	int sw;	// ĳ���� �þ߳ʺ� �븻
	int sh;	// ĳ���� �þ߳��� �븻
	int swh; // ĳ���� �þ߳ʺ� �ϵ�
	int shh; // ĳ���� �þ߳��� �ϵ�
};

struct items
{
	int x;	// ������ x��ǥ
	int y;  // ������ y��ǥ
	char skill[MAX_ITEMS_NAME]; // ������ �ɷ�

};

struct strider {
	int sx;
	int sy;
	int on;
};

/* *********************** �Լ� ���� *********************** */
/* ************ main.c ************ */
int main(void);

/* ************ map.c ************ */
void drawMap(void);                         // �� �׵θ��� �׸�
void gameMapDraw(void);                     // ���� ���� �׸�
void reset(void);                           // �ܼ� ȭ���� ���� �� �� �׵θ��� �ٽ� �׸�
void resetMapInner(void);                   // ���� �� ���θ� ����
void resetMapTitle(void);                   // ���� �� ���(��� â)�� ����
void resetMapMain(void);                    // �����÷����ϴ� �ʸ� ����
void resetMapBottom(void);                  // ���� �� �ϴ�(��ȣ�ۿ�)�� ����
void titleBoxDraw(void);                    // ������ ���(����)
void gameExit(void);			            // ���α׷� ����

/* ************ system.c ************ */
void Setcolor(WORD color);                  // �� ����
void gotoxy(int x, int y, const char* s);   // x,y��ǥ, ��¹��ڿ�
void gotoxy1(int x, int y);                 // x,y��ǥ
int keyControl1(void);			            // keyboard value ��ȯ
void slowPrint(const wchar_t story[][MAX_COLS], int x, int y, int rowcount); // ���丮�迭, x,y��ǥ, �� �� ��



/* ************ title.c ************ */
void title(void);				            // ���� ����ȭ�� 

/* ************ menuselect.c ************ */
int menuDraw1(void);			            // GAMESTART, GAMERULE, OPTION, ITEM_EX GAMEEXIT ��ȯ
void menuDraw1Content(void);                // ����ڿ� ��ȣ�ۿ� ���� �޴� ��¹�
void menuDraw2Content(int c1, int c2, int c3, int c4, int c5); // ����ڿ� ��ȣ�ۿ��� �ִ� �޴� ��¹�

/* ************ option.c ************ */
void initOption(void);                      // ȯ�漳�� ����
int selectOption(void);                     // ����� Ű �Է� ��ȣ�ۿ� OPTION1, OPTION2 ��ȯ
void selectOptionContent(void);
void selectOptionContent2(int c1, int c2);
int setMusic(void);                         // ���� ����, BACK��ȯ
int selectMusic(void);                      // MUSIC1,MUSIC2,MUSIC3,MUSIC4 ��ȯ
void selectMusicContent(void);
void selectMusicContent2(int c1, int c2, int c3, int c4);
int setTheme(void);                         // �׸� ����, BACK��ȯ
int selectTheme(void);                      // THEME1, THEME2, THEME3, THEME4, THEME5 ��ȯ
void selectThemeContent(void);
void selectThemeContent2(int c1, int c2, int c3, int c4, int c5);

/* ************ gamerule.c ************ */
void gameRulesDraw(void);


void item_ex(void);


/* ************ gamemode.c ************ */
int modeSelect(void);			// EASY(0), NORMAL(1), HARD(1) ��ȯ
void modeSelectContentDraw(void);
void modeSelectContentDraw1(int c1, int c2, int c3);  // �÷��� �Ű�����
void modeSelectContentDraw2(int c1, int c2, int c3);

/* ************ story.c ************ */
void titleStory(void);
void easyStory(void);
void normalStory(void);
void hardStory(void);
int clearStory(void);                       // HOME ��ȯ
int failStory(void);                        // HOME ��ȯ

/* ************ gameresult.c ************ */
void clearEasy(void);
void clearNormal(void);
void clearStorybg(void);
void failStorybg(void);


/* portal.c */
void draw_portal(void);
void remove_portal(void);
void function_portal(int* x, int* y, int n);
void function_portal_Hard(int* x, int* y, int n);

int minigame(void);
void Edgem();
bool is_valid_input(int input, int ranks[]);

/* ************ game.c ************ */
int gameDraw(void);				// HOME ��ȯ
int easyMode(void);				// BACK, NORMAL, FAIL ��ȯ
int normalMode(void);			// BACK, HARD, FAIL ��ȯ
int hardMode(void);				// BACK, CLEAR, FAIL ��ȯ
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
int CDStrider(int px, int py, struct strider* strider_info);


/* ************ player.c ************ */
void drawPlayer(int x, int y);
void removePlayer(int x, int y);
void drawPlayerSight(int x, int y, int bottom, int right, int upper, int left);
void removePlayerSight(int x, int y, int bottom, int right, int upper, int left);

/* ************ item.c ************ */
void drawItem(int x, int y);
void removeItem(int x, int y);
void Itemcoord(struct items* item, struct player player);// ������ �迭 ����ü�� ���� ��ǥ�� �ִ� �Լ�.
void initItem(struct items* item_array, int playerx, int playery, int i);// �þ� ������ ������ ������ ���. �浹 ��  initItem ȣ��
void judge_item(int i, struct strider* s);// ������ �迭 ����ü (i) ������ ���� �Ǵ� �Լ�
void judge_easy_item(int i);
void eatItem(struct player player_info, struct items* item_array, struct strider* s, int playerx, int playery);
void eatItemStrider(struct strider* strider_info, struct items* item_array, int mode);
void itemeatEasy(int playerx, int playery, struct items* item_array);
void itemeatNormal(int playerx, int playery, struct items* item_array, struct strider* s);


/* ************ playermove.c ************ */
int movePlayer(struct player* player_info, struct items* item_array, struct strider* strider_info);  // hard��� move
int playermoveNormal(struct player* player_info, struct items* item_array, struct strider* strider_info);
int playermoveEasy(struct player* player_info, struct items* item_array); // easy, normal��� move

/* ************ gameplay.c ************ */
void time_g(float timek);
int isClear(struct items* item_array);// key=���� �� �� CLEAR ��ȯ.

// ������ �����ϴ� �Լ�
int gameplay(void);
int gameplayEasy(void);
int gameplayNormal(void);
//*******************************************************************************************

//void timer(void);
