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
	return gameCode; // 게임 클리어 또는 실패 시 HOME 반환해야함
}

void titleStory(void) {
	char titlestr[MAX_ROWS][MAX_COLS] = {
		"우리의 건국이는 동굴 속에 보물이\0",
		"있다는 소식을 듣고 보물을 찾으러\0",
		"혼자서 동굴 탐험을 시작합니다...\0",
		"귀한 보물을 찾으러 건국이는 점점\0",
		"으슥하고 깊은 곳으로 들어갑니다.\0",
		"그 순간... 쿵!!!!! 철컥!\0",
		"어디선가 생긴 철문이 내려오더니\0",
		"건국이는 지하감옥에 갇히고맙니다.\0",
		"***\'지하감옥\'***\0",
		"배터리가 떨어진 손정든 사이로\0",
		"지하감옥이라는 글귀가 보이고\0",
		"건국이는 그제야 이 모든 것이\0",
		"함정이었음을 깨닫습니다\0",
		"건국이가 무사히 탈출할 수 있도록\0",
		"도와주자!"
	};
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(titlestr, MAP_X * 2 + 4, MAP_Y + 4,15);
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
		"건국이가 들고온 손정든의 배터리가\0",
		"얼마 남지 않았다...!\0",
		"손전등이 꺼지기 전에 경비병들을\0",
		"피해 열쇠 2개를 찾아 탈출하자!\0",
		"목숨은 5개이다!\0"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(easystr, MAP_X * 2 + 4, MAP_Y + 4,5);
}

void normalStory(void) {
	char normalstr[MAX_ROWS][MAX_COLS] = {
		"얼마나 지났을까.....\0",
		"손정등이 많이 어두워지고 배에서는\0",
		"꼬르륵.. 소리가 계속 들려온다.\0",
		"목숨도 4개밖에 남지 않았다.\0",
		"어서 경비병들을 피해 탈출하자!\0",
		"열쇠를 2개를 찾아 탈출하자!!\0"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(normalstr, MAP_X * 2 + 4, MAP_Y + 4,6);
}

void hardStory(void) {
	char hardstr[MAX_ROWS][MAX_COLS] = {
		"감옥에 갇힌지 오래.....\0",
		"바깥세상이 너무나 그립다.\0",
		"이제 손전등은 거의 꺼져간다.\0",
		"체력이 바닥나 목숨이 3개밖에 없다.\0",
		"시야가 넓어진 경비병들을 피해\0",
		"아이템을 잘 활용하여\0",
		"열쇠 2개를 모으자!\0"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(hardstr, MAP_X * 2 + 4, MAP_Y + 4,7);
}

void clearStory(void) {
	char clearstr[MAX_ROWS][MAX_COLS] = {
		"햇빛이 건국이를 환하게 비춘다.\0",
		"오랜 노력 끝에 탈출에 성공했다!\0"    
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(clearstr, MAP_X * 2 + 4, MAP_Y + 4,2);
}

void failStory(void) {
	char failstr[MAX_ROWS][MAX_COLS] = {
		"건국이의 체력이 다 소모되어\0",
		"탈출에 실패했다.\0",
		"쉬었다가 다시 도전해야겠다!\0"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(failstr, MAP_X * 2 + 4, MAP_Y + 4,3);
}

// BACK, -1, HOME 반환
int easyMode(void) {
	int keyvalue; // BACK, -1
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "EASY");
	Setcolor(4);
	gotoxy(MAP_X + MAP_WIDTH - 6, MAP_Y + 1, "♥ ♥ ♥ ♥ ♥");
	Setcolor(7);
	gameplay();
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
	gotoxy(MAP_X + MAP_WIDTH - 5, MAP_Y + 1, "♥ ♥ ♥ ♥");
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
