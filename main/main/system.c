#include "main.h"
/*
	시스템적 요소와 관련된 소스파일
		- Setcolor() : 텍스트 색 변경
		- gotoxy() : 커서 위치 설정 후 출력
		- gotoxy1() : 커서 위치만 변경
		- keyControl1() : 사용자 게임 키 입력
		- slowPrint() : 스토리 출력에서 사용 스킵 기능
*/

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

void gotoxy1(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
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