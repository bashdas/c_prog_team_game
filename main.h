#pragma once
#pragma once
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
//#include <io.h>
//#include <fcntl.h>
#include <locale.h>
#include <wchar.h>
#pragma comment(lib, "winmm.lib")

/* main */

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

float timek;
void time_g(float timek);
void timer(void);







void Setcolor(WORD color);
void gotoxy(int x, int y, const char* s);
void title(void);				// ���� ����ȭ�� 
void reset(void);				// ������ �ʱ�ȭ
void resetMapInner(void);		// �� �׵θ� ���θ� ����
void resetMapTitle(void);		// ���â�� ����
void resetMapMain(void);		// ����â�� ����
void resetMapBottom(void);		// ��ȣ�ۿ�â�� ����
void drawMap(void);				// ������ �׵θ��� �׸� 
void titleBoxDraw(void);		// titlebox�� �׸�
void gotoxy1(int x, int y);
int menuDraw1(void);			// BACK, y- 15(1~4) ��ȯ
void menuDraw1Content(void);
void menuDraw2Content(int c1, int c2, int c3, int c4);
int keyControl1(void);			// keyboard value ��ȯ
void slowPrint(const wchar_t story[][MAX_COLS], int x, int y, int rowcount);
void gameExit(void);			// ���� �������� �����ִ� ȭ��


/* game */
#define HOME 5					// �������� ���� �Ǵ� ���� �� �������� ����
#define CLEAR 7                // �������� ����
#define FAIL 6                // �������� ����
int gameDraw(void);				// HOME ��ȯ
void titleStory(void);
int modeSelect(void);			// EASY(0), NORMAL(1), HARD(1) ��ȯ
void modeSelectMapDraw(void);
void modeSelectMapDraw1(int c1, int c2, int c3);  // �÷��� �Ű�����
void modeSelectMapDraw2(int c1, int c2, int c3);
void easyStory(void);
void normalStory(void);
void hardStory(void);
void clearEasy(void);
void clearNormal(void);
int clearStory(void);
void clearStorybg(void);
int failStory(void);
void failStorybg(void);
int easyMode(void);				// BACK, NORMAL, FAIL ��ȯ
int normalMode(void);			// BACK, HARD, FAIL ��ȯ
int hardMode(void);				// BACK, CLEAR, FAIL ��ȯ
void gameMapDraw(void);


/* player */

//*******************************************************************************************
void player_crush(void); // strider�� strider1 �浹 ����. HP ����

void HP_print(int HP);
int HP;

   // �������� HP�� ���� ���� HP�� �ٸ��� �����. HP=0�̸� game_over(). speed�� ��� ����
int move(int dir);       // �÷��̾��� Ȱ�� ���� ����
// �÷��̾��� ����Ű�� ���� �÷��̾ �����
// player_crush(), item0_crush(),  time0a_crush(), item1_crush(), item_crush()�� �浹 �Ǵ�


//*******************************************************************************************

void reset_stage(void);  // HP, ����, �ӵ�, ����, ��(second) �ʱ�ȭ. �÷��̾� ���� ��ġ �ʱ�

   // �� �������� ���� �Լ�. ?????

//*******************************************************************************************

/* item, ��� ���� �Լ� */

//*******************************************************************************************

void strider(void);       // ���1 ���. ���� ��ġ ����
void move_strider(void);  //  ���1 �̵� �Լ�. 

void strider1(void);     // ��� 2 ���. ���� ��ġ ����. 
void move_strider1(void);  // ��� 2 �̵� �Լ�. 

//*******************************************************************************************

void item0(void);      // ������(���Ӽӵ� ���� +)
void item0_crush();    // �÷��̾�, strider���� �浹 �Ǵ�. �÷��̾�� �浹�ϸ� speed�� ����. 
//������ ���� �����
void item0a(void);     // ������a(���Ӽӵ� ���� +)
void item0a_crush();   // �÷��̾�� �浹 �� speed �� ����. ������ ��쿡�� �����.
// strider, strider1�� �浹, �����

//*******************************************************************************************

void item1(void);    // ������(���Ӽӵ� ����-)
void item1_crush(void); // �÷��̾�� �浹�� speed �� ����. ������ ��� ��쿡���� �����

//*******************************************************************************************

/* ��ġ�� ������ �ذ�.������ �����*/

void item(void);         // ������(strider���� ���� ����)
void item_crush(void);   // �÷��̾�� �浹 �� length +4. ������ ��쿡���� �����. 

//*******************************************************************************************

/* gamerule */
#define EASY 0
#define NORMAL 1
#define HARD 2
void gameRulesDraw(void);

/*theme*/
extern int theme;
// static int* ptheme = &theme;


/*
0	: ������
1	: �Ķ���
2	: �ʷϻ�
3	: û�ϻ�
4	: ������
5	: ���ֻ�
6	: �����
7	: ���
8	: ȸ��
9	: ���� �Ķ���
10	: ���� �ʷϻ�
11	: ���� û�ϻ�
12	: ���� ������
13	: ���� ���ֻ�
14	: ���� �����
15	: ���� ���
*/


/* option */
// �� �ٲ� ���� ���Ŀ�
int setTheme(void);
int setMusic(void);
void selectMusicContent(void);
void selectMusicContent2(int c1, int c2, int c3, int c4);
int selectTheme(void);
void selectThemeContent(void);
void selectThemeContent2(int c1, int c2, int c3, int c4, int c5);
int selectOption(void);
int selectOptionContent(void);
int selectOptionContent2(int c1, int c2);
void initOption(void);

/* play&item.c */

/* pause.c */
void pause(void);   // pŰ�� ������ ��� ������ �Ͻ� �����Ѵ�. 

/* playersight4 */
#define MAX_PLAYERS 1 // �÷��̾� ��
#define MAX_ITEMS 5 // ������ ��

#define MAX_ITEMS_NAME 10 // ������ �̸� ����(NULL ����)
#define PLAYER_X MAP_X * 2 + 7  // ĳ������ X ��ǥ
#define PLAYER_Y MAP_HEIGHT / 2 + 5   // ĳ������ Y ��ǥ


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


void drawPlayer(int x, int y);
void drawPlayerSight(int x, int y, int bottom, int right, int upper, int left);
void removePlayerSight(int x, int y, int bottom, int right, int upper, int left);
void drawItem(int x, int y);
void drawItem1(int x, int y);

void removeItem(int x, int y);
void removeItem1(int x, int y);

void initItem(struct items* item_array, int playerx, int playery, int i);
void eatItem(struct player player_info, struct items* item_array, int playerx, int playery);
int movePlayer(struct player* player_info, struct items* item_array);
void Itemcoord(struct items* item, struct player* player);
int gameplay(void);
int isClear(struct items* item_array);
