#include "main.h"

int x[100], y[100]; //x,y ��ǥ���� ���� �� 100�� 
int key; //�Է¹��� Ű ���� 
int speed; //���� �ӵ� 

int main(void) {
	int menuCode = 0;
	while (1) {
		title();
		do {
			menuCode = menuDraw1(); // y - 15 = 1 ~ 4
			if (menuCode == 1) gameDraw();
			else if (menuCode == 2) gameRulesDraw();
			else if (menuCode == 3) {
				printf("������ �޴�: %d\n", menuCode);
			}
			else if (menuCode == 4) exit(0);
		} while (menuCode != BACK);
	}

	while (1) {
		if (_kbhit()) do { key = _getch(); } while (key == 224); //Ű �Է¹���
		Sleep(speed);


	}
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

	drawMap();    //�� �׵θ��� �׸� 
	
	Setcolor(4);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "��--------------------------��");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     DUNGEON  RUNNER      |");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "��--------------------------��");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, " < PRESS ANY KEY TO START > ");

	gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 17, "  �� ��(a),��(d),��(w),��(s) : Move    ");
	gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 18, "  �� ESC : Quit              ");

	gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 20, "   KU CSE REPRESENT ");

	while (1) {
		if (_kbhit()) { //Ű�Է¹��� 
			key = _getch();
			if (key == ESC) exit(0); // ESCŰ�� ���� 
			else break; //�ƴϸ� �׳� ��� ���� 
		}
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, " < PRESS ANY KEY TO START > ");
		Sleep(300);
		gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, "                            ");
		Sleep(600);

	}
	reset();
}

//�� �׵θ� �׸��� �Լ� 

void drawMap(void) {
	int i,j;
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y, "��");
	}
	for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
		gotoxy(MAP_X, i, "��");
		gotoxy(MAP_X + MAP_WIDTH - 1, i, "��");
	}
	for (i = 0; i < MAP_WIDTH; i++) {
		gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "��");
	}
	for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
		for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
	}
}

//ȭ�� ����� �Լ�

void reset(void) {
	system("cls"); //ȭ���� ���� 
	drawMap(); //�� �׵θ��� �׸�
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
	reset();
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y + 14);
	printf("�� ���ӽ���        w(UP)");   // �����ϸ� ���̵� ���� ȭ������ �̵�
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 15);
	printf("���ӹ��        a(LEFT)");     // ���̵� �� ���� �� ���۹� ���
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 16);
	printf("ȯ�漳��        s(DOWN)");
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 17);
	printf("  ����          d(RIGHT)\n\n\n");

	printf("      ��      **** spacebar to select ****     ");
	
	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, --y);
				printf("��\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 17) {
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, ++y);
				printf("��\b");
			}
			break;
		}
		case BACK: {
			return BACK;
		}
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
		return -1; // �ٸ� Ű�� ������ ��� ó��
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
	}///
	if (ch = SUBMIT) {
		gameMapDraw();
		gotoxy1(x, y);
		for (int i = 0; s[i] != '\0'; i++) {
			putchar(s[i]);
		}
	}
}