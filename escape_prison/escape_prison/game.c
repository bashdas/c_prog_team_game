#include "main.h"

// 게임 화면 출력
int gameDraw(void) {
	int gameCode = 0, stageCode;
	titleStory();
	do {
		gameCode = modeSelect();
		stageCode = 0;
		while (stageCode != BACK) {
			if (gameCode == EASY) {
				easyStory();
				stageCode = easyMode();
			}
			else if (gameCode == NORMAL) {
				normalStory();
				stageCode = normalMode();
			}
			else if (gameCode == HARD) {
				hardStory();
				stageCode = hardMode();
			}
			else stageCode = BACK;
		}
	} while ((gameCode != BACK));
}

void titleStory(void) {
	char titlestr[MAX_ROWS][MAX_COLS] = {
		"story.......................1\0",
		"story.......................2\0",
		"story.......................3\0",
		"story.......................4\0",
		"story.......................5\0",
		"story.......................6\0",
		"story.......................7\0"
	};
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(titlestr, MAP_X * 2 + 4, MAP_Y + 4);
}

// x 위치에 따라 색반전
int modeSelect(void) {
	int x = MAP_X + (MAP_WIDTH / 2) - 2, y = 24; // 초기 위치
	modeSelectMapDraw(4, 2, 7, 7);
	gotoxy1(x, y);
	printf("☞\b");
	Sleep(300);
	while (1) {
		int n = keyControl1();
		switch (n) {
		case LEFT:
			if (x > MAP_X + (MAP_WIDTH / 2) - 2) {
				gotoxy1(x, y);
				printf(" ");
				x -= 24;
				if (x == MAP_X + (MAP_WIDTH / 2) - 2) modeSelectMapDraw(4, 2, 7, 7);
				else if (x == MAP_X + (MAP_WIDTH / 2) + 22) modeSelectMapDraw(4, 7, 2, 7);
				gotoxy1(x, y);
				printf("☞\b");
			}
			break;
		case RIGHT:
			if (x < MAP_X + (MAP_WIDTH / 2) + 46) {
				gotoxy1(x, y);
				printf(" ");
				x += 24;
				if (x == MAP_X + (MAP_WIDTH / 2) + 22) modeSelectMapDraw(4, 7, 2, 7);
				else if (x == MAP_X + (MAP_WIDTH / 2) + 46) modeSelectMapDraw(4, 7, 7, 2);
				gotoxy1(x, y);
				printf("☞\b");
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
void modeSelectMapDraw(int c1, int c2, int c3, int c4) {
	resetMapTitle();
	resetMapMain();
	resetMapBottom();
	Setcolor(c1);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 5, "※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 6, "         GAME   MODE       ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 7, "※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
	Setcolor(c2);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 13, "|   EASY   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 14, "└----------┘");
	Setcolor(c3);
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 13, "|  NORMAL  |");
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 14, "└----------┘");
	Setcolor(c4);
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 13, "|   HARD   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 14, "└----------┘");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 22, "1. (●'v'●)");
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 22, "2. (○｀ 3′○)");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 22, "3. ┗|｀O′|┛");
}


void easyStory(void) {
	char easystr[MAX_ROWS][MAX_COLS] = {
		"estory.......................1\0",
		"estory.......................2\0",
		"estory.......................3\0",
		"estory.......................4\0",
		"estory.......................5\0",
		"estory.......................6\0",
		"estory.......................7\0"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(easystr, MAP_X * 2 + 4, MAP_Y + 4);
}

void normalStory(void) {
	char normalstr[MAX_ROWS][MAX_COLS] = {
		"nstory.......................1\0",
		"nstory.......................2\0",
		"nstory.......................3\0",
		"nstory.......................4\0",
		"nstory.......................5\0",
		"nstory.......................6\0",
		"nstory.......................7\0"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(normalstr, MAP_X * 2 + 4, MAP_Y + 4);
}

void hardStory(void) {
	char hardstr[MAX_ROWS][MAX_COLS] = {
		"hstory.......................1\0",
		"hstory.......................2\0",
		"hstory.......................3\0",
		"hstory.......................4\0",
		"hstory.......................5\0",
		"hstory.......................6\0",
		"hstory.......................7\0"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(hardstr, MAP_X * 2 + 4, MAP_Y + 4);
}
// BACK, -1, HOME 반환
int easyMode(void) {
	int keyvalue; // BACK, -1
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "EASY");
	Setcolor(4);
	gotoxy(MAP_X + MAP_WIDTH - 4, MAP_Y + 1, "♥ ♥ ♥");
	Setcolor(7);
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
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "NORMAL");
	Setcolor(4);
	gotoxy(MAP_X + MAP_WIDTH - 4, MAP_Y + 1, "♥ ♥ ♥");
	Setcolor(7);
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
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "HARD");
	Setcolor(4);
	gotoxy(MAP_X + MAP_WIDTH - 4, MAP_Y + 1, "♥ ♥ ♥");
	Setcolor(7);
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
	resetMapInner();
	Setcolor(theme);
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + 2, "■");
	}
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 6, "■");
	}
}
