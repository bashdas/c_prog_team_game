#include "main.h"
/*
	게임 맵과 관련된 소스 파일
		- drawMap(): 맵 테두리를 그림
		- gameMapDraw(): 게임 맵을 그림
		- reset(): 콘솔 화면을 지운 후 맵 테두리를 다시 그림
		- resetMapInner(): 게임 맵 내부만 지움
		- resetMapTitle(): 게임 맵 상단(목숨 창)만 지움
		- resetMapMain(): 게임플레이하는 맵만 지움
		- resetMapBottom(): 게임 맵 하단(상호작용)만 지움
		- titleBoxDraw(): 디자인 요소(통일)
		- gameExit(): 프로그램 종료
*/

void drawMap(void) {
	int i;
	Setcolor(theme);
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y, "■");
	}
	for (i = MAP_Y + 1; i < MAP_HEIGHT + 1; i++) {
		gotoxy(MAP_X, i, "■");
		gotoxy(MAP_X + MAP_WIDTH - 1, i, "■");
	}
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "■");
	}
	fflush(stdout);
	resetMapInner();
}

void gameMapDraw(void) {
	int i;
	resetMapInner();
	Setcolor(theme);
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + 2, "■");
	}
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 6, "■");
	}
}

void reset(void) {
	system("cls");
	drawMap();
}

void resetMapInner(void) {
	for (int i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}

void resetMapTitle(void) {
	gotoxy1(MAP_X * 2 + 1, MAP_Y + 1);
	printf("                                                                           ");
}

void resetMapMain(void) {
	for (int i = MAP_Y + 3; i < MAP_Y + MAP_HEIGHT - 6; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}

void resetMapBottom(void) {
	for (int i = MAP_Y + MAP_HEIGHT - 5; i < MAP_Y + MAP_HEIGHT - 1; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}

void titleBoxDraw(void) {
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 3, "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 9, "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
}

void gameExit(void) {
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 5, "■■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■ ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 6, "■         ■      ■  ■      ■  ■     ■■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 7, "■    ■■■  ■      ■  ■      ■  ■      ■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 8, "■      ■  ■      ■  ■      ■  ■     ■■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 9, "■■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■ ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 13, "■■■■■■■     ■■    ■■    ■■■■■■■■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 14, "■      ■      ■  ■      ■■      ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 15, "■■■■■■■        ■■       ■■■■■■■■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 16, "■      ■       ■■       ■■      ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 17, "■■■■■■■       ■■■■      ■■■■■■■■  ■  ■  ■");
	Setcolor(7);
	Sleep(1000);
	system("cls");
	exit(0);
}


void draw_portal(void)
{
	gotoxy1(22, 21);
	Setcolor(2);
	printf("■");
	gotoxy1(80, 4);
	printf("■");
	Setcolor(15);
}

void remove_portal(void) {
	gotoxy1(22, 21);
	Setcolor(15);
	printf("■");
	gotoxy1(80, 4);
	Setcolor(15);
	printf("■");
}

void function_portal(int* x, int* y, int n)
{

	if (*x == 23 & *y == 21)
	{
		*x = 80;
		*y = 5;
		gotoxy1(23, 21);

		timek -= 15;
		printf(" ");
	}
	if ((*x == 81 || *x == 80) && *y == 5 && n == UP)
	{
		*x = 24;
		*y = 21;
		gotoxy1(81, 5);
		timek -= 15;
		printf(" ");
		gotoxy1(80, 5);
		printf(" ");

	}
}
