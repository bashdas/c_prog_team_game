#include "main.h"

int x[100], y[100]; //x,y 좌표값을 저장 총 100개 
int key; //입력받은 키 저장 
int speed; //게임 속도 

int main(void) {
	int menuCode = 0;
	int gameCode = 0;
	while (1) {
		title();
		do {
			menuCode = menuDraw1(); // y - 15 = 1 ~ 4
			if (menuCode == 1) {
				gameCode = gameDraw();
			}
			else if (menuCode == 2) gameRulesDraw();
			else if (menuCode == 3) {
				printf("선택한 메뉴: %d\n", menuCode);
			}
			else if (menuCode == 4) exit(0);
		} while (menuCode != BACK || gameCode == HOME);
	}

	while (1) {
		if (_kbhit()) do { key = _getch(); } while (key == 224); //키 입력받음
		Sleep(speed);


	}
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
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 3,  "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 4,  "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 5,  "▒▒▒     ▒▒      ▒▒     ▒      ▒       ▒    ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 6,  "▒▒▒ ▒▒▒ ▒▒ ▒▒▒▒ ▒▒▒▒ ▒▒▒ ▒▒▒▒▒▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 7,  "▒▒▒ ▒▒▒ ▒▒ ▒▒▒▒ ▒▒▒▒ ▒▒▒ ▒▒▒▒▒▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 8,  "▒▒▒     ▒▒      ▒▒▒▒ ▒▒▒▒  ▒▒▒▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 9,  "▒▒▒ ▒▒▒▒▒▒ ▒▒▒▒ ▒▒▒▒ ▒▒▒▒▒▒  ▒▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 10, "▒▒▒ ▒▒▒▒▒▒ ▒▒▒▒ ▒▒▒▒ ▒▒▒▒▒▒▒▒ ▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 11, "▒▒▒ ▒▒▒▒▒▒ ▒▒▒▒ ▒▒▒▒ ▒▒▒▒▒▒▒▒ ▒ ▒▒▒▒▒ ▒ ▒▒ ▒▒ ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 12, "▒▒▒ ▒▒▒▒▒▒ ▒▒▒▒ ▒▒     ▒      ▒       ▒ ▒▒    ▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 13, "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 14, "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH -14) / 2, MAP_Y + 18, " < PRESS ANY KEY TO START > ");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 5) / 2, MAP_HEIGHT - 3, "ESC : Quit");

	while (1) {
		if (_kbhit()) { //키입력받음 
			key = _getch();
			if (key == ESC) exit(0); // ESC키면 종료 
			else break; //아니면 그냥 계속 진행 
		}
		Setcolor(2);
		gotoxy(MAP_X + (MAP_WIDTH - 14) / 2 , MAP_Y + 18, " < PRESS ANY KEY TO START > ");
		gotoxy1(MAP_X * 2 + (MAP_WIDTH + 14) / 2 - 2, MAP_Y + 18);
		Sleep(300);
		Setcolor(7);
		gotoxy(MAP_X + (MAP_WIDTH - 14) / 2, MAP_Y + 18,  "                            ");
		gotoxy1(MAP_X * 2 + (MAP_WIDTH + 14) / 2 - 2, MAP_Y + 18);
		Sleep(600);

	}
	resetMapInner();
}

//맵 테두리 그리는 함수 

void drawMap(void) {
	int i,j;
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
	resetMapInner();
}

//화면 지우기 함수
void reset(void) {
	system("cls"); //화면을 지움 
	drawMap(); //맵 테두리를 그림
}

// 화면 내부만 지우기
// 이중 중첩으로 하면 안지워 지는 거 있음
void resetMapInner(void) {
	for (int i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
		gotoxy(MAP_X, i, "■                                                                           ■");
	}
}
// 목숨창만 지우기
void resetMapTitle(void) {
	gotoxy(MAP_X, MAP_Y + 1, "■                                                                           ■");
}
// 게임창만 지우기 3 ~ MAP_Y + MAP_HEIGHT - 7
void resetMapMain(void) {
	for (int i = MAP_Y + 3; i < MAP_Y + MAP_HEIGHT - 6; i++)
		gotoxy(MAP_X, i, "■                                                                           ■");
}
// 상호작용창만 지우기
void resetMapBottom(void) {
	for (int i = MAP_Y + MAP_HEIGHT - 5; i < MAP_Y + MAP_HEIGHT - 1; i++)
		gotoxy(MAP_X, i, "■                                                                           ■");
}

void gotoxy1(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw1(void)
{
	int x = 24, y = 16;
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇ 게임시작        w(UP)");   // 선택하면 난이도 선택 화면으로 이동
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("  게임방법        a(LEFT)");     // 난이도 별 실행 및 조작법 출력
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 16);
	printf("  환경설정        s(DOWN)");
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 17);
	printf("  종료          d(RIGHT)");
	gotoxy1(MAP_X * 2, MAP_Y + 20);
	printf("■      **** spacebar to select ****     ");
	
	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, --y);
				printf("◇\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 17) {
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, ++y);
				printf("◇\b");
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


void slowPrint(const char* s, int x, int y) {
	char ch = 0;
	gotoxy1(x, y);
	for (int i = 0; s[i] != '\0'; i++) {
		putchar(s[i]);
		fflush(stdout);
		Sleep(50);
		if (_kbhit()) {
			ch = _getch();
			if (ch == '\r' || ch == ' ') break;
		}
	}
	if (ch = SUBMIT) {
		gotoxy1(x, y);
		for (int i = 0; s[i] != '\0'; i++) {
			putchar(s[i]);
		}
	}
}
