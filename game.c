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
	wchar_t titlestr[MAX_ROWS][MAX_COLS] = {
		L"우리의 건국이는 동굴 속에 보물이",
		L"있다는 소식을 듣고 보물을 찾으러",
		L"혼자서 동굴 탐험을 시작합니다...",
		L"귀한 보물을 찾으러 건국이는 점점",
		L"으슥하고 깊은 곳으로 들어갑니다.",
		L"그 순간... 쿵!!!!! 철컥!",
		L"어디선가 생긴 철문이 내려오더니",
		L"건국이는 지하감옥에 갇히고맙니다.",
		L"***\'지하감옥\'***",
		L"배터리가 떨어진 손정든 사이로",
		L"지하감옥이라는 글귀가 보이고",
		L"건국이는 그제야 이 모든 것이",
		L"함정이었음을 깨닫습니다",
		L"건국이가 무사히 탈출할 수 있도록",
		L"도와주자!"
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
	wchar_t easystr[MAX_ROWS][MAX_COLS] = {
		L"건국이가 들고온 손정든의 배터리가",
		L"얼마 남지 않았다...!",
		L"손전등이 꺼지기 전에 경비병들을",
		L"피해 열쇠 2개를 찾아 탈출하자!",
		L"목숨은 5개이다!"
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
	wchar_t normalstr[MAX_ROWS][MAX_COLS] = {
		L"얼마나 지났을까.....",
		L"손정등이 많이 어두워지고 배에서는",
		L"꼬르륵.. 소리가 계속 들려온다.",
		L"목숨도 4개밖에 남지 않았다.",
		L"어서 경비병들을 피해 탈출하자!",
		L"열쇠를 2개를 찾아 탈출하자!!"
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
	wchar_t hardstr[MAX_ROWS][MAX_COLS] = {
		L"감옥에 갇힌지 오래.....",
		L"바깥세상이 너무나 그립다.",
		L"이제 손전등은 거의 꺼져간다.",
		L"체력이 바닥나 목숨이 3개밖에 없다.",
		L"시야가 넓어진 경비병들을 피해",
		L"아이템을 잘 활용하여",
		L"열쇠 2개를 모으자!"
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
	wchar_t clearstr[MAX_ROWS][MAX_COLS] = {
		L"햇빛이 건국이를 환하게 비춘다.",
		L"오랜 노력 끝에 탈출에 성공했다!"    
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
	wchar_t failstr[MAX_ROWS][MAX_COLS] = {
		L"건국이의 체력이 다 소모되어",
		L"탈출에 실패했다.",
		L"쉬었다가 다시 도전해야겠다!"
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