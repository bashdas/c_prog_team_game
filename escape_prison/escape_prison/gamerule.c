#include "main.h"

// 게임 방법 설명 함수
int gameRulesDraw(void) {
	int x = 26, y = 8;
	reset();
    Setcolor(4);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 2, "┌--------------------------┐");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 3, "|       GMAE    RULES      |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 4, "└--------------------------┘");
    Setcolor(7);
    gotoxy(MAP_X + 2, MAP_Y + 6,  "   ◇  ↑(w) : Move to the Upward   ");
    gotoxy(MAP_X + 2, MAP_Y + 8,  "      ↓(s) : Move to the Downward ");
    gotoxy(MAP_X + 2, MAP_Y + 10, "      ←(a) : Move to the Left     ");
    gotoxy(MAP_X + 2, MAP_Y + 12, "      →(d) : Move to the Right    ");
    gotoxy(MAP_X + 2, MAP_Y + 14, "      S    : Skip                 ");
    gotoxy(MAP_X + 2, MAP_Y + 16, "      P    : Pause to the Game    ");
    gotoxy(MAP_X + 2, MAP_Y + 18, "      Q    : Back to the Menu     ");
    gotoxy(MAP_X + 2, MAP_Y + 20, "      ESC  : Quit to the Program  ");
    gotoxy(MAP_X + 2, MAP_Y + 23, "      PRESS \"Q\" TO BACK         ");
	while (1)
	{
		
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 6) {
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, y = y - 2);
				printf("◇\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 20) {
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, y= y+2);
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
