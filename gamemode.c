#include "main.h"
/*
	게임 모드 선택 소스파일
		- int modeSelect(void): EASY(0), NORMAL(1), HARD(1) 반환
		- void modeSelectContentDraw(void): 게임 모드 선택 출력
		- void modeSelectContentDraw1(int c1, int c2, int c3): 출력물 1
		- void modeSelectContentDraw2(int c1, int c2, int c3): 출력물 2
*/


// x 위치에 따라 색반전
int modeSelect(void) {
	int x = MAP_X + (MAP_WIDTH / 2) - 2, y = 24; // 초기 위치
	modeSelectContentDraw();
	modeSelectContentDraw1(2, 7, 7);
	modeSelectContentDraw2(11, 7, 7);
	gotoxy1(x, y);
	printf("☞\b\b");
	Sleep(300);
	while (1) {
		int n = keyControl1();
		switch (n) {
		case LEFT:
			if (x > MAP_X + (MAP_WIDTH / 2) - 2) {
				gotoxy1(x, y);
				printf(" ");
				x -= 24;
				if (x == MAP_X + (MAP_WIDTH / 2) - 2) {
					modeSelectContentDraw1(2, 7, 7);
					modeSelectContentDraw2(11, 7, 7);
				}
				else if (x == MAP_X + (MAP_WIDTH / 2) + 22) {
					modeSelectContentDraw1(7, 2, 7);
					modeSelectContentDraw2(7, 14, 7);
				}
				gotoxy1(x, y);
				printf("☞\b\b");
			}
			break;
		case RIGHT:
			if (x < MAP_X + (MAP_WIDTH / 2) + 46) {
				gotoxy1(x, y);
				printf(" ");
				x += 24;
				if (x == MAP_X + (MAP_WIDTH / 2) + 22) {
					modeSelectContentDraw1(7, 2, 7);
					modeSelectContentDraw2(7, 14, 7);
				}
				else if (x == MAP_X + (MAP_WIDTH / 2) + 46) {
					modeSelectContentDraw1(7, 7, 2);
					modeSelectContentDraw2(7, 7, 12);
				}
				gotoxy1(x, y);
				printf("☞\b\b");
			}
			break;
		case BACK:
			return BACK;
		case SUBMIT:
			if (x == MAP_X + (MAP_WIDTH / 2) - 2) {
				x = EASY;
			}
			else if (x == MAP_X + (MAP_WIDTH / 2) + 22) {
				x = NORMAL;
			}
			else if (x == MAP_X + (MAP_WIDTH / 2) + 46) {
				x = HARD;
			}
			return x;
		}
	}
}

// 타이틀 색, easy 색, normla 색, hard 색을 인자로 받음
void modeSelectContentDraw(void) {
	resetMapTitle();
	resetMapMain();
	resetMapBottom();
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 5, "※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 6, "         GAME   MODE       ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 7, "※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
}

void modeSelectContentDraw1(int c1, int c2, int c3) {
	Setcolor(c1);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 13, "|   EASY   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 14, "└----------┘");
	Setcolor(c2);
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 13, "|  NORMAL  |");
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 14, "└----------┘");
	Setcolor(c3);
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 13, "|   HARD   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 14, "└----------┘");
	Setcolor(7);
}

void modeSelectContentDraw2(int c1, int c2, int c3) {
	Setcolor(c1);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 14, MAP_Y + 22, "(●'v'●)");
	Setcolor(c2);
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2 + 1, MAP_Y + 22, "(○｀ 3′○)");
	Setcolor(c3);
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9 + 1, MAP_Y + 22, "┗|｀O′|┛");
	Setcolor(7);
}
