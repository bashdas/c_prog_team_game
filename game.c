#include "main.h"
/*
	게임 관련 소스파일
*/

// 게임 이동
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
			if (gameCode == EASY && stageCode == NORMAL) { clearEasy();  gameCode = NORMAL; }
			if (gameCode == NORMAL && stageCode == HARD) { clearNormal();  gameCode = HARD; }
			if (stageCode == CLEAR_V || stageCode == FAIL_V) break;
		}
		if (stageCode == FAIL_V) {
			gotoxy(0, 2, "d");
			gameCode = failStory();
			break;
		}
		if (stageCode == CLEAR_V) {
			gameCode = clearStory();
			break;
		}
	} while ((gameCode != BACK));
	return gameCode; // 게임 클리어 또는 실패 시 HOME 반환해야함
}


// BACK, NORMAL, FAIL 반환 // 하트 4개 얻고 Clear
int easyMode(void) {
	int keyvalue; // BACK, -1
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "EASY");
	HP = 0;
	timek = 0;

	keyvalue = gameplayEasy(); // gameplay를 실행. HP_print.

	if (keyvalue == BACK) return BACK; // modeSelct로 복귀
	if (keyvalue == CLEAR_V) return NORMAL;
	if (keyvalue == FAIL_V) return FAIL_V;

	return 0;
}


// BACK, HARD, FAIL 반환
int normalMode(void) {
	int keyvalue;
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "NORMAL");
	HP = 0;
	timek = 0;

	keyvalue = gameplayNormal();

	if (keyvalue == BACK) return BACK; // modeSelct로 복귀
	if (keyvalue == CLEAR_V) return HARD;
	if (keyvalue == FAIL_V) return FAIL_V;
	return 0;
}

// BACK, CLEAR, FAIL 반환
int hardMode(void) {
	int keyvalue;
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "HARD");
	HP = 0;
	timek = 0;


	keyvalue = gameplay();
	if (keyvalue == BACK) return BACK; // modeSelct로 복귀
	if (keyvalue == CLEAR_V) return CLEAR_V;
	if (keyvalue == FAIL_V) return FAIL_V;
	return 0;
}


void HP_print(int HP) {


	{
		Setcolor(7);

		gotoxy(MAP_X + MAP_WIDTH - 11, MAP_Y + 1, " SCORE:"); //HP표시

	}
	Setcolor(4);

	switch (HP)
	{
	case 0:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "  ");
		Setcolor(7);
		break;
	case 1:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "      "); //HP표시
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " ♥"); //HP표시
		Setcolor(7);
		break;

	case 2:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "        "); //HP표시

		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " ♥ ♥"); //HP표시
		Setcolor(7);
		break;
	case 3:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "           "); //HP표시
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " ♥ ♥ ♥"); //HP표시
		Setcolor(7);
		break;
	case 4:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "           "); //HP표시
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " ♥ ♥ ♥ ♥"); //HP표시
		Setcolor(7);
		break;
	case 5:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "           "); //HP표시
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " ♥ ♥ ♥ ♥ ♥"); //HP표시
		Setcolor(7);
		break;

	default:
		break;
	}

}
