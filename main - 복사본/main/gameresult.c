#include "main.h"
/*
	���� ��� ���� �ҽ�����
		- void clearEasy(void): ������� Ŭ����
		- void clearNormal(void): �븻��� Ŭ����
		- void clearStorybg(void): �ϵ��� Ŭ����(��ü ���丮 Ŭ����)
		- void failStorybg(void): ���� ����
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