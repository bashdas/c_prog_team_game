#include "main.h"
/*
	���� ���� �ҽ�����
*/

// ���� �̵�
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
			gameCode = failStory();
			break;
		}
		if (stageCode == CLEAR_V) {
			gameCode = clearStory();
			break;
		}
	} while ((gameCode != BACK));
	return gameCode; // ���� Ŭ���� �Ǵ� ���� �� HOME ��ȯ�ؾ���
}


// BACK, NORMAL, FAIL ��ȯ // ��Ʈ 4�� ��� Clear
int easyMode(void) {
	int keyvalue; // BACK, -1
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "EASY");
	HP = 0;
	timek = 0;

	keyvalue = gameplayEasy(); // gameplay�� ����. HP_print.
	if (keyvalue == BACK) return BACK; // modeSelct�� ����
	if (keyvalue == CLEAR_V) return NORMAL;
	if (keyvalue == FAIL_V) return FAIL_V;

	return 0;
}


// BACK, HARD, FAIL ��ȯ
int normalMode(void) {
	int keyvalue;
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "NORMAL");
	HP = 0;
	timek = 0;

	keyvalue = gameplayNormal();

	if (keyvalue == BACK) return BACK; // modeSelct�� ����
	if (keyvalue == CLEAR_V) return HARD;
	if (keyvalue == FAIL_V) return FAIL_V;
	return 0;
}

// BACK, CLEAR, FAIL ��ȯ
int hardMode(void) {
	int keyvalue;
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "HARD");
	HP = 0;
	timek = 0;

	keyvalue = gameplay();
	if (keyvalue == BACK) return BACK; // modeSelct�� ����
	if (keyvalue == CLEAR_V) return CLEAR_V;
	if (keyvalue == FAIL_V) return FAIL_V;
	return 0;
}


void HP_print(int HP) {


	{
		Setcolor(7);

		gotoxy(MAP_X + MAP_WIDTH - 11, MAP_Y + 1, " HP:"); //HPǥ��

	}
	Setcolor(4);

	switch (HP)
	{
	case 0:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "           ");
		Setcolor(7);
		break;
	case 1:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "           "); //HPǥ��
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " ��"); //HPǥ��
		Setcolor(7);
		break;

	default:
		break;
	}

}