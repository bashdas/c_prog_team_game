#include "main.h"

void draw_portal(void)
{
	gotoxy1(22, 20);
	Setcolor(2);
	printf("P");
	gotoxy1(80, 4);
	printf("P");
	Setcolor(15);
}

void remove_portal(void) {
	gotoxy1(22, 21);
	Setcolor(15);
	printf("*");
	gotoxy1(80, 4);
	Setcolor(15);
	printf("*");
}

void function_portal(int* x, int* y, int n)
{

	if (*x == 23 && *y == 20 && n == LEFT)
	{
		*x = 81;
		*y = 5;
		removePlayer(23, 20);
		timek -= 1;
		printf(" ");
	}
	if (*x == 80 && *y == 5 && n == UP)
	{
		*x = 23;
		*y = 21;
		removePlayer(80, 5);
		timek -= 1;
		printf(" ");
	}
}

void function_portal_Hard(int* x, int* y, int n)
{
	if (*x == 23 && *y == 20 && n == LEFT)
	{
		*x = 81;
		*y = 5;
		gotoxy1(23, 21);
		resetMapInner();
		gameMapDraw();
		draw_portal();
		timek -= 1;
		printf(" ");
	}
	if (*x == 80 && *y == 5 && n == UP)
	{
		*x = 24;
		*y = 21;
		gotoxy1(80, 5);
		resetMapInner();
		gameMapDraw();
		draw_portal();
		timek -= 1;
		printf(" ");
	}
}
