#include "main.h"

//플레이어 움직임
int playermove(void)
{
	int x = MAP_X + 1, y = MAP_Y + MAP_HEIGHT - 7;
	while (1)
	{
		gotoxy1(x, y);
		Setcolor(6);
		printf("★\b");
		int ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			switch (ch)
			{
			case UP1:
				y--;
				break;
			case DOWN1:
				y++;
				break;
			case LEFT1:
				x--;
				break;
			case RIGHT1:
				x++;
				break;
			case BACK:
				return BACK;
				break;
			case SUBMIT:
				return SUBMIT;
				break;
			default:
				return -1;
				break;
			}
		}
		printf(" ");
	}
}