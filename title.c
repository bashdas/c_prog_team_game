#include "main.h"
/*
	title 화면 출력 소스파일
		- title(): 게임 제목 출력 사용자 키 입력을 받은 후 페이지 이동
*/

void title(void) {
	int key = 0;
	while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림 

	reset();    //맵 테두리를 그림 
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
		if (_kbhit()) { //키입력받음 
			key = _getch();
			if (key == ESC) {
				system("cls");
				gameExit(); // ESC키면 종료 
			}
			else break; //아니면 그냥 계속 진행 
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