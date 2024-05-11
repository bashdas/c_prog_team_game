#include "main.h"

// 게임 화면 출력
void gameDraw(void) {
	story();
	modeSelect();
}

void story(void) {
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
void modeSelect(void) {
	gameMapDraw();
	Setcolor(353);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "┌--------------------------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|        GAME   MODE       |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "└--------------------------┘");
	Setcolor(11);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 13, "|   EASY   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 15, MAP_Y + 14, "└----------┘");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 3, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 3, MAP_Y + 13, "|  NORMAL  |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 3, MAP_Y + 14, "└----------┘");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 12, "┌----------┐");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 13, "|   HARD   |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) + 9, MAP_Y + 14, "└----------┘");
	Sleep(10000000);
}

void easyStory(void) {

}

void normalStory(void) {

}

void hardStory(void) {

}

void easyMode(void) {

}

void normalMode(void) {

}

void hardMode(void) {

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