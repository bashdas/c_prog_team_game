#include "main.h"
/*
	게임 결과 관련 소스파일
		- void clearEasy(void): 이지모드 클리어
		- void clearNormal(void): 노말모드 클리어
		- void clearStorybg(void): 하드모드 클리어(전체 스토리 클리어)
		- void failStorybg(void): 게임 실패
*/

void clearEasy(void) {
	resetMapMain();
	resetMapTitle();
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 5, "########  #         ########  ########  ########");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 6, "#         #         #         #      #  #      #");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 7, "#         #         ########  ########  ########");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 8, "#         #         #         #      #  #     #");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 9, "########  ########  ########  #      #  #     #");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 12, "########  ########  ########  ##    ##");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 13, "#         #      #  #           #  #");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 14, "########  ########  ########     ##");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 15, "#         #      #         #     ##");
	gotoxy(MAP_X + (MAP_WIDTH - 22) / 2, MAP_Y + 16, "########  #      #  ########    ####");
	Setcolor(7);
	Sleep(2000);
}

void clearNormal(void) {
	resetMapMain();
	resetMapTitle();
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 5, "########  #         ########  ########  ########");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 6, "#         #         #         #      #  #      #");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 7, "#         #         ########  ########  ########");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 8, "#         #         #         #      #  #     #");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 9, "########  ########  ########  #      #  #     #");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 12, "#####  #  ########  ########  #########  ########  #");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 13, "#   #  #  #      #  #      #  #   #   #  #      #  #");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 14, "#   #  #  #      #  ########  #   #   #  ########  #");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 15, "#   #  #  #      #  #     #   #   #   #  #      #  #");
	gotoxy(MAP_X + (MAP_WIDTH - 28) / 2, MAP_Y + 16, "#   ####  ########  #     #   #   #   #  #      #  ########");
	Setcolor(7);
	Sleep(2000);
}


void clearStorybg(void) {
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 5, "########  ########  ########  ###### ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 6, "#         #      #  #      #  #     ##");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 7, "#    ###  #      #  #      #  #      #");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 8, "#      #  #      #  #      #  #     ##");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 9, "########  ########  ########  ###### ");
	Setcolor(7);
}




void failStorybg(void) {
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 5, "########  ########  #####  # ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 6, "#         #      #    #    #");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 7, "########  ########    #    #");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 8, "#         #      #    #    #");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 9, "#         #      #  #####  ###### # # #");
	Setcolor(7);
}