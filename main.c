#include "main.h"
//int x[100], y[100]; //x,y ��ǥ���� ���� �� 100�� 
int key; //�Է¹��� Ű ���� 
int speed; //���� �ӵ� 
int theme = 7;

int main(void) {
	setlocale(LC_ALL, "korean"); // �ѱ��� �ڵ� ������
	int menuCode = 0;
	int gameCode = 0;
	srand((unsigned int)time(NULL));
	//system("mode con cols=100 lines=30"); //�ܼ�â ũ�� ����
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
	if (_kbhit()) do { key = _getch(); } while (key == 224); //Ű �Է¹���
	Sleep(speed);
	}*/
	return 0;
}

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

/*
	title �Լ�: ���� ȭ�� ǥ��
	_kbhit() �Լ�: Ű���� ���ۿ� �ִ� �Է� ���� ����

*/
void title(void) {
	while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 

	reset();    //�� �׵θ��� �׸� 
	Setcolor(12);
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 3, "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 4, "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 5, "�ƢƢ�     �Ƣ�      �Ƣ�     ��      ��       ��    �Ƣ� �ƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 6, "�ƢƢ� �ƢƢ� �Ƣ� �ƢƢƢ� �ƢƢƢ� �ƢƢ� �ƢƢƢƢƢ� �ƢƢƢƢ� �� �Ƣ� �Ƣ� �ƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 7, "�ƢƢ�     �Ƣ�      �ƢƢƢ� �ƢƢƢ�  �ƢƢƢ� �ƢƢƢƢ� �� �Ƣ� �Ƣ� �ƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 8, "�ƢƢ� �ƢƢƢƢƢ� �ƢƢ� �ƢƢƢƢ� �ƢƢƢƢƢ�  �Ƣ� �ƢƢƢƢ� �� �Ƣ� �Ƣ� �ƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 9, "�ƢƢ� �ƢƢƢƢƢ� �ƢƢ� �ƢƢƢƢ� �ƢƢƢƢƢƢƢ� �� �ƢƢƢƢ� �� �Ƣ� �Ƣ� �ƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 10, "�ƢƢ� �ƢƢƢƢƢ� �ƢƢ� �ƢƢ�     ��      ��       �� �Ƣ�    �ƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 11, "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
	gotoxy(MAP_X + (MAP_WIDTH - 24) / 2, MAP_Y + 12, "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
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

//�� �׵θ� �׸��� �Լ� 

void drawMap(void) {
	int i;
	Setcolor(theme);
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y, "��");
	}
	for (i = MAP_Y + 1; i < MAP_HEIGHT + 1; i++) {
		gotoxy(MAP_X, i, "��");
		gotoxy(MAP_X + MAP_WIDTH - 1, i, "��");
	}
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "��");
	}
	fflush(stdout);
	resetMapInner();
}

//ȭ�� ����� �Լ�
void reset(void) {
	system("cls"); //ȭ���� ���� 
	drawMap(); //�� �׵θ��� �׸�
}

// ȭ�� ���θ� �����
void resetMapInner(void) {
	for (int i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}
// ���â�� �����
void resetMapTitle(void) {
	gotoxy1(MAP_X * 2 + 1, MAP_Y + 1);
	printf("                                                                           ");
}
// ����â�� ����� 3 ~ MAP_Y + MAP_HEIGHT - 7
void resetMapMain(void) {
	for (int i = MAP_Y + 3; i < MAP_Y + MAP_HEIGHT - 6; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}
// ��ȣ�ۿ�â�� �����
void resetMapBottom(void) {
	for (int i = MAP_Y + MAP_HEIGHT - 5; i < MAP_Y + MAP_HEIGHT - 1; i++) {
		gotoxy1(MAP_X * 2 + 1, i);
		printf("                                                                           ");
	}
}

// titlebox �Լ�
void titleBoxDraw(void) {
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 3, "�ءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءء�");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 9, "�ءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءءء�");
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
	printf("��\b\b");
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
				printf("��\b\b");
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
				printf("��\b\b");
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
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "��  Select from the menu  ��");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

void menuDraw2Content(int c1, int c2, int c3, int c4) {
	Setcolor(c1);
	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 14);
	printf("   ���ӽ���    START");   // �����ϸ� ���̵� ���� ȭ������ �̵�
	if (c1 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		printf(" ");
	}
	Setcolor(c2);
	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 15);
	printf("   ���ӹ��    RULE");     // ���̵� �� ���� �� ���۹� ���
	if (c2 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		printf(" ");
	}
	Setcolor(c3);
	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 16);
	printf("   ȯ�漳��    OPTION");
	if (c3 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(c4);
	gotoxy1(MAP_X + (MAP_WIDTH + 38) / 2, MAP_Y + 17);
	printf("   ����        EXIT");
	if (c4 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		Setcolor(7);
		printf("��");
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

void gameExit(void) {
	Setcolor(2);
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 5, "���������  ���������  ���������  ������� ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 6, "��         ��      ��  ��      ��  ��     ���");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 7, "��    ����  ��      ��  ��      ��  ��      ��");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 8, "��      ��  ��      ��  ��      ��  ��     ���");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 9, "���������  ���������  ���������  ������� ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 13, "��������     ���    ���    ���������");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 14, "��      ��      ��  ��      ���      ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 15, "��������        ���       ���������");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 16, "��      ��       ���       ���      ");
	gotoxy(MAP_X + (MAP_WIDTH - 18) / 2, MAP_Y + 17, "��������       �����      ���������  ��  ��  ��");
	Setcolor(7);
	Sleep(1000);
	system("cls");
	exit(0);
}