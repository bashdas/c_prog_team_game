#include "main.h"
//int x[100], y[100]; //x,y 좌표값을 저장 총 100개 
int key; //입력받은 키 저장 
int speed; //게임 속도 
int theme = 7;

int main(void) {
	setlocale(LC_ALL, "korean"); // 한국어 코드 페이지
	int menuCode = 0;
	int gameCode = 0;
	srand((unsigned int)time(NULL));
	//system("mode con cols=100 lines=30"); //콘솔창 크기 조절
	while (1) {
		title();
		do {
			gameCode = 0;
			gotoxy1(0, 20);
			printf("%d   ", gameCode);
			menuCode = menuDraw1(); // y - 15 = 1 ~ 4
			if (menuCode == 1) {
				gameCode = gameDraw();
			}
			else if (menuCode == 2) gameRulesDraw();
			else if (menuCode == 3) initOption();
			else if (menuCode == 4) {
				system("cls");
				gameExit();
			}
		} while (menuCode != BACK || gameCode == HOME);
	}
	/*
	while (1) {
	if (_kbhit()) do { key = _getch(); } while (key == 224); //키 입력받음
	Sleep(speed);
	}*/
	return 0;
}

/*
	Setcolor 함수
	매개변수: color -> 텍스트 색 결정
	SetConsoleTextAttribute 함수 호출 -> 텍스트 속성 설정(콘솔 창 텍스트 색, 배경 색...)
	GetStdHandle(STD_OUTPUT_HANDLE) 함수 호출 -> 콘솔 창 제어
*/
void Setcolor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*
	gotoxy 함수
	COORD 구조체 사용 -> 출력할 위치 설정(좌표)
	2 * x 인 이유는 문자 단위 계산 처리하기 위해서
	SetConsoleCursorPosition 함수 호출 콘솔 창의 커서 위치 설정
*/
void gotoxy(int x, int y, const char* s) {
	COORD pos = { 2 * x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", s);
}

/*
	title 함수: 시작 화면 표시
	_kbhit() 함수: 키보드 버퍼에 있는 입력 값을 버림

*/
void title(void) {
	while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림 

	reset();    //맵 테두리를 그림 
	Setcolor(12);
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 3, "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 4, "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 5, "▒▒▒     ▒▒      ▒▒     ▒      ▒       ▒    ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 6, "▒▒▒ ▒▒▒ ▒▒ ▒▒▒▒ ▒▒▒▒ ▒▒▒ ▒▒▒▒▒▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 7, "▒▒▒     ▒▒      ▒▒▒▒ ▒▒▒▒  ▒▒▒▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 8, "▒▒▒ ▒▒▒▒▒▒ ▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒▒  ▒▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 9, "▒▒▒ ▒▒▒▒▒▒ ▒▒▒ ▒▒▒▒▒ ▒▒▒▒▒▒▒▒ ▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 10, "▒▒▒ ▒▒▒▒▒▒ ▒▒▒ ▒▒▒     ▒      ▒       ▒ ▒▒    ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 11, "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 12, "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
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

//맵 테두리 그리는 함수 

void drawMap(void) {
	int i;
	Setcolor(theme);
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y, "■");
	}
	for (i = MAP_Y + 1; i < MAP_HEIGHT + 1; i++) {
		gotoxy(MAP_X, i, "■");
		gotoxy(MAP_X + MAP_WIDTH - 1, i, "■");
	}
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "■");
	}
	fflush(stdout);
	resetMapInner();
}

//화면 지우기 함수
void reset(void) {
	system("cls"); //화면을 지움 
	drawMap(); //맵 테두리를 그림
}

// 화면 내부만 지우기
void resetMapInner(void) {
	for (int i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}
// 목숨창만 지우기
void resetMapTitle(void) {
	gotoxy1(MAP_X * 2 + 1, MAP_Y + 1);
	printf("                                                                           ");
}
// 게임창만 지우기 3 ~ MAP_Y + MAP_HEIGHT - 7
void resetMapMain(void) {
	for (int i = MAP_Y + 3; i < MAP_Y + MAP_HEIGHT - 6; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}
// 상호작용창만 지우기
void resetMapBottom(void) {
	for (int i = MAP_Y + MAP_HEIGHT - 5; i < MAP_Y + MAP_HEIGHT - 1; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}

// titlebox 함수
void titleBoxDraw(void) {
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 3, "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 9, "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※");
}

void gotoxy1(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw1(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	menuDraw1Content();
	menuDraw2Content(2, 7, 7, 7);
	gotoxy1((MAP_X + 13) * 2, y);
	printf("☞\b\b");
	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1((MAP_X + 13) * 2, y);
				printf(" ");
				y--;
				if (y == MAP_Y + 14) menuDraw2Content(2, 7, 7, 7);
				else if (y == MAP_Y + 15) menuDraw2Content(7, 2, 7, 7);
				else if (y == MAP_Y + 16) menuDraw2Content(7, 7, 2, 7);
				gotoxy1((MAP_X + 13) * 2, y);
				printf("☞\b\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 17) {
				gotoxy1((MAP_X + 13) * 2, y);
				printf(" ");
				y++;
				if (y == MAP_Y + 15) menuDraw2Content(7, 2, 7, 7);
				else if (y == MAP_Y + 16) menuDraw2Content(7, 7, 2, 7);
				else if (y == MAP_Y + 17) menuDraw2Content(7, 7, 7, 2);
				gotoxy1((MAP_X + 13) * 2, y);
				printf("☞\b\b");
			}
			break;
		}
		case BACK:
			return BACK;
		case SUBMIT: {
			return y - 15;
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
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "▼  Select from the menu  ▼");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

void menuDraw2Content(int c1, int c2, int c3, int c4) {
	Setcolor(c1);
	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 14);
	printf("   게임시작    START");   // 선택하면 난이도 선택 화면으로 이동
	if (c1 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		printf(" ");
	}
	Setcolor(c2);
	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 15);
	printf("   게임방법    RULE");     // 난이도 별 실행 및 조작법 출력
	if (c2 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		Setcolor(7);
		printf("☜");
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
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(c4);
	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 17);
	printf("   종료        EXIT");
	if (c4 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		printf(" ");
	}
	Setcolor(7);
}

int keyControl1(void) {
	char a = _getch();

	switch (a) {
	case 'W':
	case 'w':
	case UP1:
		return UP;
	case 'S':
	case 's':
	case DOWN1:
		return DOWN;
	case 'A':
	case 'a':
	case LEFT1:
		return LEFT;
	case 'D':
	case 'd':
	case RIGHT1:
		return RIGHT;
	case 'Q':
	case 'q':
		return BACK;
	case '\r':
	case ' ':
		return SUBMIT;
	default:
		return -1; // 다른 키를 눌렀을 경우 처리
	}
}

void slowPrint(const wchar_t story[][MAX_COLS], int x, int y, int rowcount) {
	char ch = 0;
	int x1 = x, y1 = y;
	Setcolor(7);
	// 콘솔 출력 모드를 유니코드 모드로 설정
	//_setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < rowcount; i++) {
		if (y1 > MAP_Y + 18) {
			x1 += 35;
			y1 = y;
		}
		gotoxy1(x1, y1);
		for (int j = 0; j < MAX_COLS && story[i][j] != '\0'; j++) {
			wprintf(L"%lc", story[i][j]);
			Sleep(20);
			if (_kbhit()) {
				ch = _getch();
				if (ch == '\r' || ch == ' ') {
					return;
				}
			}
		}
		y1 = y1 + 2;
		if (y1 > MAP_Y + 20) break;
	}
	Sleep(1000);
}

void gameExit(void) {
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 5, "■■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■ ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 6, "■         ■      ■  ■      ■  ■     ■■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 7, "■    ■■■  ■      ■  ■      ■  ■      ■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 8, "■      ■  ■      ■  ■      ■  ■     ■■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 9, "■■■■■■■■  ■■■■■■■■  ■■■■■■■■  ■■■■■■ ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 13, "■■■■■■■     ■■    ■■    ■■■■■■■■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 14, "■      ■      ■  ■      ■■      ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 15, "■■■■■■■        ■■       ■■■■■■■■");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 16, "■      ■       ■■       ■■      ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 17, "■■■■■■■       ■■■■      ■■■■■■■■  ■  ■  ■");
	Setcolor(7);
	Sleep(1000);
	system("cls");
	exit(0);
}
