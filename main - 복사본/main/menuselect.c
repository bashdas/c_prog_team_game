#include "main.h"
/*
	게임 메뉴 선택 소스파일
		- menuDraw1(): 게임 메뉴 출력 + 사용자 상호작용
			- 반환값 int형
				- 게임 시작 GAMESTART 100
				- 게임 방법 GAMERULE 200
				- 환경 설정 OPTION 300
				- 아이템    ITEM_EX 721
				- 게임 종료 GAMEEXIT 400

		- menuDraw1Content(): 사용자 상호작용 없으므로 처음만 그림

		- menuDraw2Content(): 사용자 상호작용 있으므로 해당 부분만 덮음
*/


int menuDraw1(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14, result = 0;
	menuDraw1Content();
	menuDraw2Content(2, 7, 7, 7, 7);
	gotoxy1((MAP_X + 13) * 2, y);
	printf(">\b\b");
	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1((MAP_X + 13) * 2, y);
				printf(" ");
				y--;
				if (y == MAP_Y + 14) menuDraw2Content(2, 7, 7, 7, 7);
				else if (y == MAP_Y + 15) menuDraw2Content(7, 2, 7, 7, 7);
				else if (y == MAP_Y + 16) menuDraw2Content(7, 7, 2, 7, 7);
				else if (y == MAP_Y + 17) menuDraw2Content(7, 7, 7, 2, 7);
				else if (y == MAP_Y + 18) menuDraw2Content(7, 7, 7, 7, 2);
				gotoxy1((MAP_X + 13) * 2, y);
				printf(">\b\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 18) {
				gotoxy1((MAP_X + 13) * 2, y);
				printf(" ");
				y++;
				if (y == MAP_Y + 15) menuDraw2Content(7, 2, 7, 7, 7);
				else if (y == MAP_Y + 16) menuDraw2Content(7, 7, 2, 7, 7);
				else if (y == MAP_Y + 17) menuDraw2Content(7, 7, 7, 2, 7);
				else if (y == MAP_Y + 18) menuDraw2Content(7, 7, 7, 7, 2);
				gotoxy1((MAP_X + 13) * 2, y);
				printf(">\b\b");
			}
			break;
		}
		case BACK:
			return BACK;
		case SUBMIT: {
			if (y == MAP_Y + 14) return GAMESTART;
			else if (y == MAP_Y + 15) return GAMERULE;
			else if (y == MAP_Y + 16) return OPTION;
			else if (y == MAP_Y + 17) return ITEM_EX;

			else return GAMEEXIT;
		}
		}
	}

}

void menuDraw1Content(void) {
	resetMapInner();
	titleBoxDraw();

	Setcolor(15);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 6, MAP_Y + 5, " !WELCOME TO!");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 1, MAP_Y + 7, "Get out of the underground prison");
	Setcolor(8);
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "&  Select from the menu  &");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

void menuDraw2Content(int c1, int c2, int c3, int c4, int c5) {
	Setcolor(c1);

	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 14);
	printf("   게임시작    START");
	if (c1 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("<");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		printf(" ");
	}


	Setcolor(c2);
	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 15);
	printf("   게임방법    RULE");
	if (c2 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		Setcolor(7);
		printf("<");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		printf(" ");
	}
	Setcolor(c3);


	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 16);
	printf("   환경설정    OPTION");
	if (c3 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		Setcolor(7);
		printf("<");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(c4);

	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 17);
	printf("   아이템종류  ITEMS");
	if (c4 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		Setcolor(7);
		printf("<");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		printf(" ");
	}
	Setcolor(c5);







	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 18);
	printf("   종료        EXIT");
	if (c4 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 18);
		Setcolor(7);

	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 18);
		printf(" ");
	}





	Setcolor(7);
}