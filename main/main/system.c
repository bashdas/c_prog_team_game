#include "main.h"
/*
	�ý����� ��ҿ� ���õ� �ҽ�����
		- Setcolor() : �ؽ�Ʈ �� ����
		- gotoxy() : Ŀ�� ��ġ ���� �� ���
		- gotoxy1() : Ŀ�� ��ġ�� ����
		- keyControl1() : ����� ���� Ű �Է�
		- slowPrint() : ���丮 ��¿��� ��� ��ŵ ���
*/

/*
	Setcolor �Լ�
	�Ű�����: color -> �ؽ�Ʈ �� ����
	SetConsoleTextAttribute �Լ� ȣ�� -> �ؽ�Ʈ �Ӽ� ����(�ܼ� â �ؽ�Ʈ ��, ��� ��...)
	GetStdHandle(STD_OUTPUT_HANDLE) �Լ� ȣ�� -> �ܼ� â ����
*/
void Setcolor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*
	gotoxy �Լ�
	COORD ����ü ��� -> ����� ��ġ ����(��ǥ)
	2 * x �� ������ ���� ���� ��� ó���ϱ� ���ؼ�
	SetConsoleCursorPosition �Լ� ȣ�� �ܼ� â�� Ŀ�� ��ġ ����
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
		return -1; // �ٸ� Ű�� ������ ��� ó��
	}
}

void slowPrint(const wchar_t story[][MAX_COLS], int x, int y, int rowcount) {
	char ch = 0;
	int x1 = x, y1 = y;
	Setcolor(7);
	// �ܼ� ��� ��带 �����ڵ� ���� ����
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