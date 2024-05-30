#include "main.h"

// 惟績 号狛 竺誤 敗呪
void gameRulesDraw(void) {
	int x = 26, y = 8;
	resetMapInner();
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 2, "『『『『『『『『『『『『『『『『『『『『『『『『『『『『");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 3, "        GMAE    RULES       ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 4, "『『『『『『『『『『『『『『『『『『『『『『『『『『『『");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 6, "∴(w)  : Move to the Upward   ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 8, "♂(s)  : Move to the Downward ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 10, "∞(a)  : Move to the Left     ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 12, "≧(d)  : Move to the Right    ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 14, "P     : Pause to the Game    ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 16, "Q     : Back to the Menu     ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 18, "ESC   : Quit to the Program  ");
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 20, "ENTER, SPACE : Skip or Submit");
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 22, "PRESS \"Q\" or \"q\" TO BACK");
	Setcolor(7);
	while (keyControl1() != BACK);
}