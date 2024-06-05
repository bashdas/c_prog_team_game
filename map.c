#include "main.h"
/*
	���� �ʰ� ���õ� �ҽ� ����
		- drawMap(): �� �׵θ��� �׸�
		- gameMapDraw(): ���� ���� �׸�
		- reset(): �ܼ� ȭ���� ���� �� �� �׵θ��� �ٽ� �׸�
		- resetMapInner(): ���� �� ���θ� ����
		- resetMapTitle(): ���� �� ���(��� â)�� ����
		- resetMapMain(): �����÷����ϴ� �ʸ� ����
		- resetMapBottom(): ���� �� �ϴ�(��ȣ�ۿ�)�� ����
		- titleBoxDraw(): ������ ���(����)
		- gameExit(): ���α׷� ����
*/

void drawMap(void) {
	int i;
	Setcolor(theme);
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y, "N");
	}
	for (i = MAP_Y + 1; i < MAP_HEIGHT + 1; i++) {
		gotoxy(MAP_X, i, "Z");
		gotoxy(MAP_X + MAP_WIDTH - 1, i, "Z");
	}
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "N");
	}
	fflush(stdout);
	resetMapInner();
}

void gameMapDraw(void) {
	int i;
	resetMapInner();
	Setcolor(theme);
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + 2, "N");
	}
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 6, "N");
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
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 3, "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 9, "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu");
}

void gameExit(void) {
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 5, "########  ########  ########  ###### ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 6, "#         #      #  #      #  #     ##");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 7, "#    ###  #      #  #      #  #      #");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 8, "#      #  #      #  #      #  #     ##");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 9, "########  ########  ########  ###### ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 13, "#######     ##    ##    ########");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 14, "#      #      #  #      ##      ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 15, "#######        ##       ########");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 16, "#      #       ##       ##      ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 17, "#######       ####      ########  #  #  #");
	Setcolor(7);
	Sleep(1000);
	system("cls");
	exit(0);
}