#include "main.h"
/*
	title ȭ�� ��� �ҽ�����
		- title(): ���� ���� ��� ����� Ű �Է��� ���� �� ������ �̵�
*/

void title(void) {
	int key = 0;
	while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 

	reset();    //�� �׵θ��� �׸� 
	Setcolor(12);
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 3, "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 4, "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 5, "$$$     $$      $$     $      $       $    $$ $$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 6, "$$$ $$$ $$ $$$$ $$$$ $$$ $$$$$$ $$$$$ $ $$ $$ $$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 7, "$$$     $$      $$$$ $$$$  $$$$ $$$$$ $ $$ $$ $$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 8, "$$$ $$$$$$ $$$ $$$$$ $$$$$$  $$ $$$$$ $ $$ $$ $$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 9, "$$$ $$$$$$ $$$ $$$$$ $$$$$$$$ $ $$$$$ $ $$ $$ $$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 10, "$$$ $$$$$$ $$$ $$$     $      $       $ $$    $$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 11, "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 12, "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 18, " < PRESS ANY KEY TO START > ");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 5) / 2, MAP_HEIGHT - 3, "ESC : Quit");

	while (1) {
		if (_kbhit()) { //Ű�Է¹��� 
			key = _getch();
			if (key == ESC) {
				system("cls");
				gameExit(); // ESCŰ�� ���� 
			}
			else break; //�ƴϸ� �׳� ��� ���� 
		}
		Setcolor(2);
		gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 18, " < PRESS ANY KEY TO START > ");
		gotoxy1(MAP_X * 2 + (MAP_WIDTH + 14) / 2 - 2, MAP_Y + 18);
		Sleep(300);
		Setcolor(7);
		gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 18, "                            ");
		gotoxy1(MAP_X * 2 + (MAP_WIDTH + 14) / 2 - 2, MAP_Y + 18);
		Sleep(600);

	}
	resetMapInner();
}