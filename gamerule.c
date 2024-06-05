#include "main.h"

// 게임 방법 설명 함수
void gameRulesDraw(void) {
	int x = 26, y = 8;
	resetMapInner();
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 2, "nnnnnnnnnnnnnnnnnnnnnnnnnnnn");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 3, "        GAME    RULES       ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 4, "uuuuuuuuuuuuuuuuuuuuuuuuuuuu");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 6, "↑(w)  : Move to the Upward   ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 8, "↓(s)  : Move to the Downward ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 10, "←(a)  : Move to the Left     ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 12, "→(d)  : Move to the Right    ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 14, "Q     : Back to the Menu     ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 16, "ESC   : Quit to the Program  ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 18, "ENTER, SPACE : Skip or Submit");
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 23, "PRESS \"Q\" or \"q\" TO BACK");
	Setcolor(7);
	while (keyControl1() != BACK);
}


void item_ex(void) {
	int x = 26, y = 8;
	resetMapInner();
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 2, "nnnnnnnnnnnnnnnnnnnnnnnnnnnn");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 3, "        ITEMS / MAP         ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 4, "uuuuuuuuuuuuuuuuuuuuuuuuuuuu");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 6, "BATTERY + / -  ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 8, "MORE STRIDER | oooo |  ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 10,"HP");
	
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2+2, MAP_Y + 10, "♥");

	Setcolor(7); gotoxy(MAP_X + (MAP_WIDTH - 14) / 2 + 4, MAP_Y + 10, "+");


	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 11, "PORTAL");

	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2 + 3, MAP_Y + 11, "■"); Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2 + 5, MAP_Y + 11, "TRNSPORT TO CONNECTED PORTAL");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2-3, MAP_Y + 13, "_______________________________________________");

	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2-3, MAP_Y + 14, "|                              	     	       |");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2-3, MAP_Y + 15, "| EASY MODE     bettery -                      | ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2-3, MAP_Y + 16, "| NORMAL MODE   bettery - strider0             | ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2-3, MAP_Y + 17, "| HARD MODE     bettery - strider0  low vision | ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2-3, MAP_Y + 18, "|______________________________________________|");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2-3, MAP_Y + 20, "ENTER, SPACE : Skip or Submit");
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 23, "PRESS \"Q\" or \"q\" TO BACK");
	Setcolor(7);
	while (keyControl1() != BACK);
}