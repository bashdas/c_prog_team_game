#include "main.h"
/*
	���丮 �ҽ�����
		- void titleStory(void)
		- void easyStory(void)
		- void normalStory(void)
		- void hardStory(void)
		- int clearStory(void) : HOME ��ȯ
		- int failStory(void) : HOME ��ȯ
*/

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
	Setcolor(7);
	printf("TITLE STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(titlestr, MAP_X * 2 + 4, MAP_Y + 4, 15);
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
	Setcolor(7);
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
	Setcolor(7);
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
	Setcolor(7);
	printf("HARD STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(hardstr, MAP_X * 2 + 4, MAP_Y + 4, 7);
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