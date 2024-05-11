#include "main.h"

// 게임 화면 출력
int gameDraw(void) {
	int gameCode = 0;
	titleStory();
	while (1) {
		gameCode = modeSelect();
		do {
			if (gameCode == EASY) {
				easyStory();
				gameCode = easyMode();
			}
			else if (gameCode == NORMAL) {
				normalStory();
				gameCode = normalMode();
			}
			else if (gameCode == HARD) {
				hardStory();
				gameCode = hardMode();
			}
			else exit(0);
		} while (gameCode != BACK);
	}
}

void titleStory(void) {
	gameMapDraw();
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 4);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 6);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 8);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 10);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 12);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 14);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 16);
}

// blue: 1, green: 2, skyblue:3,  red:4, purple:5, yellow:6, white:7, gray: 8, blue2:9 d에메랄드:11, 23: 배경색
// x 위치에 따라 색반전
char modeSelect(void) {
	int x = MAP_X + (MAP_WIDTH / 2) - 8, y = 24; // 초기 위치
	modeSelectMapDraw(353, 2, 7, 7);
	gotoxy1(x, y);
	printf("◇\b");
	while (1) {
		int n = keyControl1();
		switch (n) {
		case LEFT:
			if (x > MAP_X + (MAP_WIDTH / 2) - 8) {
				gotoxy1(x, y);
				printf(" ");
				x -= 24;
				if (x == MAP_X + (MAP_WIDTH / 2) - 8) modeSelectMapDraw(353, 2, 7, 7);
				else if (x == MAP_X + (MAP_WIDTH / 2) + 16) modeSelectMapDraw(353, 7, 2, 7);
				gotoxy1(x, y);
				printf("◇\b");
			}
			break;
		case RIGHT:
			if (x < MAP_X + (MAP_WIDTH / 2) + 40) {
				gotoxy1(x, y);
				printf(" ");
				x += 24;
				if (x == MAP_X + (MAP_WIDTH / 2) + 16) modeSelectMapDraw(353, 7, 2, 7);
				else if (x == MAP_X + (MAP_WIDTH / 2) + 40) modeSelectMapDraw(353, 7, 7, 2);
				gotoxy1(x, y);
				printf("◇\b");
			}
			break;
		case BACK:
			return 0; // 뒤로가기
		case SUBMIT:
			if (x = MAP_X + (MAP_WIDTH / 2) - 8) {
				x = EASY;
			}
			else if (x = MAP_X + (MAP_WIDTH / 2) + 16) {
				x = NORMAL;
			}
			else if (x = MAP_X + (MAP_WIDTH / 2) + 40) {
				x = HARD;
			}
			return x;
		}
	}
}

// 타이틀 색, easy 색, normla 색, hard 색을 인자로 받음
void modeSelectMapDraw(int ctitle, int ceasy, int cnormal, int chard) {
	gameMapDraw();
	Setcolor(ctitle);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "┌--------------------------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|        GAME   MODE       |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "└--------------------------┘");
	Setcolor(ceasy);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 13, "|   EASY   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 14, "└----------┘");
	Setcolor(cnormal);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 3, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 3, MAP_Y + 13, "|  NORMAL  |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 3, MAP_Y + 14, "└----------┘");
	Setcolor(chard);
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 13, "|   HARD   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 14, "└----------┘");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 22, "  1. EASY");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 3, MAP_Y + 22,  "  2. NORMAL");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 22,  "  3. HARD");
}


void easyStory(void) {
	gameMapDraw();
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 4);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 6);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 8);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 10);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 12);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 14);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 16);
}

void normalStory(void) {
	gameMapDraw();
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 4);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 6);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 8);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 10);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 12);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 14);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 16);
}

void hardStory(void) {
	gameMapDraw();
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 4);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 6);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 8);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 10);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 12);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 14);
	slowPrint("  stroy.......................   ", MAP_X + 5, MAP_Y + 16);
}
// BACK, -1, HOME 반환
int easyMode(void) {
	int keyvalue; // BACK, -1
	gameMapDraw();
	gotoxy(MAP_X + MAP_WIDTH - 7, MAP_Y + 1, "easy ♥ ♥ ♥");
	while (1) {
		keyvalue = playerMove();
		if (keyvalue == BACK) return BACK; // modeSelct로 복귀
	}
	// 클리어 성공하면 성공 화면 출력 하고 HOME 반환
	// 클리어 실패하면 다시 시도 하시겠습니까(BACK) OR 종료하시겠습니까 출력
	return 0;
}
// BACK, -1, HOME 반환
int normalMode(void) {
	int keyvalue;
	gameMapDraw();
	gotoxy(MAP_X + MAP_WIDTH - 7, MAP_Y + 1, "normal ♥ ♥ ♥");
	int n = keyControl1();
	while (1) {
		keyvalue = playerMove();
		if (keyvalue == BACK) return BACK; // modeSelct로 복귀
	}
	// 클리어 성공하면 성공 화면 출력 하고 HOME 반환
	// 클리어 실패하면 다시 시도 하시겠습니까(BACK) OR 종료하시겠습니까 출력
	return 0;
}
// BACK, -1, HOME 반환
int hardMode(void) {
	int keyvalue;
	gameMapDraw();
	gotoxy(MAP_X + MAP_WIDTH - 7, MAP_Y + 1, "hard ♥ ♥ ♥");
	while (1) {
		keyvalue = playerMove();
		if (keyvalue == BACK) return BACK; // modeSelct로 복귀
	}
	// 클리어 성공하면 성공 화면 출력 하고 HOME 반환
	// 클리어 실패하면 다시 시도 하시겠습니까(BACK) OR 종료하시겠습니까 출력
	return 0;
}
// BACK, -1 반환
int playerMove(void) {
	int n = keyControl1();
	switch (n)
	{
	case UP:		// 캐릭터 이동
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	case BACK:		// 뒤로가기
		return BACK;
	case SUBMIT:	// 상호작용
		break;
	default:
		return -1;
	}
	return 0;
}

void gameMapDraw(void) {
	int i;
	reset();
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + 2, "■");
	}
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 6, "■");
	}
}
