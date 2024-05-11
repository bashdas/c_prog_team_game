#include "main.h"

// 게임 방법 설명 함수
void gameRulesDraw(void) {
	int x = 26, y = 8;
	resetMapInner();
    Setcolor(4);
    gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 2, "┌--------------------------┐");
    gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 3, "|       GMAE    RULES      |");
    gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 4, "└--------------------------┘");
    Setcolor(7);
    gotoxy(MAP_X + 2, MAP_Y + 6,  "◇  ↑(w)  : Move to the Upward   ");
    gotoxy(MAP_X + 2, MAP_Y + 8,  "   ↓(s)  : Move to the Downward ");
    gotoxy(MAP_X + 2, MAP_Y + 10, "   ←(a)  : Move to the Left     ");
    gotoxy(MAP_X + 2, MAP_Y + 12, "   →(d)  : Move to the Right    ");
    gotoxy(MAP_X + 2, MAP_Y + 14, "   P     : Pause to the Game    ");
    gotoxy(MAP_X + 2, MAP_Y + 16, "   Q     : Back to the Menu     ");
    gotoxy(MAP_X + 2, MAP_Y + 18, "   ESC   : Quit to the Program  ");
	gotoxy(MAP_X + 2, MAP_Y + 20, "   ENTER, SPACE : Skip or Submit");
    gotoxy(MAP_X + 2, MAP_Y + 23, "   PRESS \"Q\" or \"q\" TO BACK ");
	while (1)
	{
		
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 6) {
				gotoxy1((MAP_X + 2) * 2, y);
				printf(" ");
				gotoxy1((MAP_X + 2) * 2, y = y - 2);
				printf("◇\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 20) {
				gotoxy1((MAP_X + 2) * 2, y);
				printf(" ");
				gotoxy1((MAP_X + 2) * 2, y= y+2);
				printf("◇\b");
			}
			break;
		}
		/*
		case SUBMIT: {
			return y - 7;
		}*/
		case BACK: {
			break;
		}
		} // switch
		if (n == BACK) break;
	}
}
