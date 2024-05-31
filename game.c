#include "main.h"



// ���� ȭ�� ���
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
			if (stageCode == CLEAR || stageCode == FAIL) break;
		}
		if (stageCode == FAIL) {
			gameCode = failStory();
			break;
		}
		if (stageCode == CLEAR) {
			gameCode = clearStory();
			break;
		}
	} while ((gameCode != BACK));
	return gameCode; // ���� Ŭ���� �Ǵ� ���� �� HOME ��ȯ�ؾ���
}

void titleStory(void) {
	wchar_t titlestr[MAX_ROWS][MAX_COLS] = {
		L"�츮�� �Ǳ��̴� ���� �ӿ� ������",
		L"�ִٴ� �ҽ��� ��� ������ ã����",
		L"ȥ�ڼ� ���� Ž���� �����մϴ�...",
		L"���� ������ ã���� �Ǳ��̴� ����",
		L"�����ϰ� ���� ������ ���ϴ�.",
		L"�� ����... ��!!!!! ö��!",
		L"��𼱰� ���� ö���� ����������",
		L"�Ǳ��̴� ���ϰ����� �������ϴ�.",
		L"***\'���ϰ���\'***",
		L"���͸��� ������ ������ ���̷�",
		L"���ϰ����̶�� �۱Ͱ� ���̰�",
		L"�Ǳ��̴� ������ �� ��� ����",
		L"�����̾����� ���ݽ��ϴ�",
		L"�Ǳ��̰� ������ Ż���� �� �ֵ���",
		L"��������!"
	};
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 2, MAP_Y + 1);
	printf("TITLE STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(titlestr, MAP_X * 2 + 4, MAP_Y + 4, 15);
}

// x ��ġ�� ���� ������
int modeSelect(void) {
	int x = MAP_X + (MAP_WIDTH / 2) - 2, y = 24; // �ʱ� ��ġ
	modeSelectMapDraw();
	modeSelectMapDraw1(2, 7, 7);
	modeSelectMapDraw2(11, 7, 7);
	gotoxy1(x, y);
	printf("��\b\b");
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
					modeSelectMapDraw1(2, 7, 7);
					modeSelectMapDraw2(11, 7, 7);
				}
				else if (x == MAP_X + (MAP_WIDTH / 2) + 22) {
					modeSelectMapDraw1(7, 2, 7);
					modeSelectMapDraw2(7, 14, 7);
				}
				gotoxy1(x, y);
				printf("��\b\b");
			}
			break;
		case RIGHT:
			if (x < MAP_X + (MAP_WIDTH / 2) + 46) {
				gotoxy1(x, y);
				printf(" ");
				x += 24;
				if (x == MAP_X + (MAP_WIDTH / 2) + 22) {
					modeSelectMapDraw1(7, 2, 7);
					modeSelectMapDraw2(7, 14, 7);
				}
				else if (x == MAP_X + (MAP_WIDTH / 2) + 46) {
					modeSelectMapDraw1(7, 7, 2);
					modeSelectMapDraw2(7, 7, 12);
				}
				gotoxy1(x, y);
				printf("��\b\b");
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

// Ÿ��Ʋ ��, easy ��, normla ��, hard ���� ���ڷ� ����
void modeSelectMapDraw(void) {
	resetMapTitle();
	resetMapMain();
	resetMapBottom();
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 5, "�ءءءءءءءءءءءءءءءءءءءءءءءءءءء�");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 6, "         GAME   MODE       ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 7, "�ءءءءءءءءءءءءءءءءءءءءءءءءءءء�");
}

void modeSelectMapDraw1(int c1, int c2, int c3) {
	Setcolor(c1);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 12, "��----------��");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 13, "|   EASY   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 14, "��----------��");
	Setcolor(c2);
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 12, "��----------��");
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 13, "|  NORMAL  |");
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2, MAP_Y + 14, "��----------��");
	Setcolor(c3);
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 12, "��----------��");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 13, "|   HARD   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 14, "��----------��");
	Setcolor(7);
}

void modeSelectMapDraw2(int c1, int c2, int c3) {
	Setcolor(c1);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 14, MAP_Y + 22, "(��'v'��)");
	Setcolor(c2);
	gotoxy(MAP_X + (MAP_WIDTH - 6) / 2 + 1, MAP_Y + 22, "(�ۣ� 3�ǡ�)");
	Setcolor(c3);
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9 + 1, MAP_Y + 22, "��|��O��|��");
	Setcolor(7);
}


void easyStory(void) {
	wchar_t easystr[MAX_ROWS][MAX_COLS] = {
		L"�Ǳ��̰� ���� �������� ���͸���",
		L"�� ���� �ʾҴ�...!",
		L"�������� ������ ���� ��񺴵���",
		L"���� ���� 2���� ã�� Ż������!",
		L"����� 5���̴�!"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 2, MAP_Y + 1);
	printf("EASY STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(easystr, MAP_X * 2 + 4, MAP_Y + 4, 5);
}

void normalStory(void) {
	wchar_t normalstr[MAX_ROWS][MAX_COLS] = {
		L"�󸶳� ��������.....",
		L"�������� ���� ��ο����� �迡����",
		L"������.. �Ҹ��� ��� ����´�.",
		L"����� 4���ۿ� ���� �ʾҴ�.",
		L"� ��񺴵��� ���� Ż������!",
		L"���踦 2���� ã�� Ż������!!"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 2, MAP_Y + 1);
	printf("NORMAL STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(normalstr, MAP_X * 2 + 4, MAP_Y + 4, 6);
}

void hardStory(void) {
	wchar_t hardstr[MAX_ROWS][MAX_COLS] = {
		L"������ ������ ����.....",
		L"�ٱ������� �ʹ��� �׸���.",
		L"���� �������� ���� ��������.",
		L"ü���� �ٴڳ� ����� 3���ۿ� ����.",
		L"�þ߰� �о��� ��񺴵��� ����",
		L"�������� �� Ȱ���Ͽ�",
		L"���� 2���� ������!"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 2, MAP_Y + 1);
	printf("HARD STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(hardstr, MAP_X * 2 + 4, MAP_Y + 4, 7);
}

void clearEasy(void) {
	resetMapMain();
	resetMapTitle();
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 5, "���������  ��         ���������  ���������  ���������");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 6, "��         ��         ��         ��      ��  ��      ��");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 7, "��         ��         ���������  ���������  ���������");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 8, "��         ��         ��         ��      ��  ��     ��");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 9, "���������  ���������  ���������  ��      ��  ��     ��");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 12, "���������  ���������  ���������  ���    ���");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 13, "��         ��      ��  ��           ��  ��");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 14, "���������  ���������  ���������     ���");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 15, "��         ��      ��         ��     ���");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 16, "���������  ��      ��  ���������    �����");
	Setcolor(7);
	Sleep(2000);
}

void clearNormal(void) {
	resetMapMain();
	resetMapTitle();
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 5, "���������  ��         ���������  ���������  ���������");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 6, "��         ��         ��         ��      ��  ��      ��");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 7, "��         ��         ���������  ���������  ���������");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 8, "��         ��         ��         ��      ��  ��     ��");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 9, "���������  ���������  ���������  ��      ��  ��     ��");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 12, "������  ��  ���������  ���������  ����������  ���������  ��");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 13, "��   ��  ��  ��      ��  ��      ��  ��   ��   ��  ��      ��  ��");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 14, "��   ��  ��  ��      ��  ���������  ��   ��   ��  ���������  ��");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 15, "��   ��  ��  ��      ��  ��     ��   ��   ��   ��  ��      ��  ��");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 16, "��   �����  ���������  ��     ��   ��   ��   ��  ��      ��  ���������");
	Setcolor(7);
	Sleep(2000);
}

int clearStory(void) {
	wchar_t clearstr[MAX_ROWS][MAX_COLS] = {
		L"�޺��� �Ǳ��̸� ȯ�ϰ� �����.",
		L"���� ��� ���� Ż�⿡ �����ߴ�!"
	};
	resetMapMain();
	resetMapBottom();
	resetMapTitle();
	gameMapDraw();
	clearStorybg();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(clearstr, MAP_X * 2 + MAP_WIDTH / 2, MAP_Y + 13, 2);
	return HOME;
}
void clearStorybg(void) {
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 5, "���������  ���������  ���������  ������� ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 6, "��         ��      ��  ��      ��  ��     ���");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 7, "��    ����  ��      ��  ��      ��  ��      ��");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 8, "��      ��  ��      ��  ��      ��  ��     ���");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 9, "���������  ���������  ���������  ������� ");
	Setcolor(7);
}


int failStory(void) {
	wchar_t failstr[MAX_ROWS][MAX_COLS] = {
		L"�Ǳ����� ü���� �� �Ҹ�Ǿ�",
		L"Ż�⿡ �����ߴ�.",
		L"�����ٰ� �ٽ� �����ؾ߰ڴ�!"
	};
	resetMapMain();
	resetMapBottom();
	resetMapTitle();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	failStorybg();
	slowPrint(failstr, MAP_X * 2 + MAP_WIDTH / 2, MAP_Y + 13, 3);
	return HOME;
}

void failStorybg(void) {
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 5, "���������  ���������  ������  �� ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 6, "��         ��      ��    ��    ��");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 7, "���������  ���������    ��    ��");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 8, "��         ��      ��    ��    ��");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 9, "��         ��      ��  ������  ������� �� �� ��");
	Setcolor(7);
}

/************************************************************/

// ü�� [��������]









// BACK, NORMAL, FAIL ��ȯ // ��Ʈ 4�� ��� Clear
int easyMode(void) {
	int keyvalue; // BACK, -1
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "EASY");
	HP = 0;
	timek = 0;
	keyvalue = gameplay(); // gameplay�� ����. HP_print.

	
	if (keyvalue == BACK) return BACK; // modeSelct�� ����
	if (keyvalue == CLEAR) return NORMAL;
	if (keyvalue == FAIL) return BACK;
	
	return 0;
}





// BACK, HARD, FAIL ��ȯ
int normalMode(void) {
	int keyvalue;
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "NORMAL");
	HP = 4;

	keyvalue = gameplay();
	
	if (keyvalue == BACK) return BACK; // modeSelct�� ����
	if (keyvalue == CLEAR) return HARD;
	if (keyvalue == FAIL) return BACK;
	return 0;
}

// BACK, CLEAR, FAIL ��ȯ
int hardMode(void) {
	int keyvalue;
	gameMapDraw();
	Setcolor(7);
	gotoxy(MAP_X + 1, MAP_Y + 1, "HARD");
	HP = 3;


	keyvalue = gameplay();
	if (keyvalue == BACK) return BACK; // modeSelct�� ����
	if (keyvalue == CLEAR) return CLEAR;
	if (keyvalue == FAIL) return BACK;
	return 0;
}

void gameMapDraw(void) {
	int i;
	resetMapInner();
	Setcolor(theme);
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + 2, "��");
	}
	for (i = 1; i < MAP_WIDTH - 1; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 6, "��");
	}
}


void HP_print(int HP){


	{
		Setcolor(7);
		
		gotoxy(MAP_X + MAP_WIDTH - 11, MAP_Y + 1, " SCORE:"); //HPǥ��

	}
	Setcolor(4);

	switch (HP)
	{
	case 0:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "  ");
		Setcolor(7);
		break;
	case 1:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "      "); //HPǥ��
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " ��"); //HPǥ��
		Setcolor(7);
		break;

	case 2:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "        "); //HPǥ��

		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1 , " �� ��"); //HPǥ��
		Setcolor(7);
		break;
	case 3:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "           "); //HPǥ��
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " �� �� ��"); //HPǥ��
		Setcolor(7);
		break;
	case 4:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "           "); //HPǥ��
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " �� �� �� ��"); //HPǥ��
		Setcolor(7);
		break;
	case 5:
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, "           "); //HPǥ��
		gotoxy(MAP_X + MAP_WIDTH - 8, MAP_Y + 1, " �� �� �� �� ��"); //HPǥ��
		Setcolor(7); 
		break;
	
	default:
		break;
	}

}
