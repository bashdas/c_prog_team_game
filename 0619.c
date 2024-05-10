#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>


// Ű �� ����  //
#define LEFT1 75
#define RIGHT1 77
#define UP1 72
#define DOWN1 80
#define PAUSE1 112
#define ESC 27

// MAP ��
#define MAP_X 3 // 3 2
#define MAP_Y 2
#define MAP_WIDTH 39  // 30 20
#define MAP_HEIGHT 26

// keyboard value
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // ����(Ű)

int x[100], y[100]; //x,y ��ǥ���� ���� �� 100�� 
int key; //�Է¹��� Ű ���� 
int speed; //���� �ӵ� 





void Setcolor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y, const char* s)
{
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);
}

void title(void); //���� ����ȭ�� 
void reset(void); //������ �ʱ�ȭ 
void draw_map(void); // ������ �׵θ��� �׸� 
void load_menu(void); // �޴��� �ҷ����� �Լ�.



void gotoxy1(int x, int y);

int menuDraw1();
int keyControl1();




int main() {
    title();

    while (1) {
        if (_kbhit()) do { key = _getch(); } while (key == 224); //Ű �Է¹���
        Sleep(speed);


    }
}


// 

void title(void) {
    int i, j;

    while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 

    draw_map();    //�� �׵θ��� �׸� 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
    }
    Setcolor(4);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     DUNGEON  RUNNER      |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");
    Setcolor(7);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, " < PRESS ANY KEY TO START > ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 17, "   �� ��(a),��(d),��(w),��(s) : Move    ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 18, "   �� P : Pause             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 19, "   �� ESC : Quit              ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 21, "   KU CSE REPRESENT ");

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
    reset(); // ������ �ʱ�ȭ  
}

//�� �׵θ� �׸��� �Լ� 

void draw_map(void) {
    int i, j;
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
}

//ȭ�� ����� �Լ�

void reset(void) {
    int i;
    system("cls"); //ȭ���� ���� 
    draw_map(); //�� �׵θ��� �׸� 
	
	

	int menuCode = menuDraw1();
	printf("������ �޴�: %d\n", menuCode);


}





void gotoxy1(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw1()
{
	int x = 24, y = 16;
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y + 14);
	printf("> ���ӽ���        w(UP)");   // �����ϸ� ���̵� ���� ȭ������ �̵�
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 15);
	printf("���ӹ��        a(LEFT)");     // ���̵� �� ���� �� ���۹� ���
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 16);
	printf("ȯ�漳��        s(DOWN)");
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 17);
	printf("  ����          d(RIGHT)\n\n\n");

	printf("             **** spacebar to select ****     ");
	
	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 17) {
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH / 2) - 9, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 14;
		}
		}
	}

}

int keyControl1()
{
	char a = _getch();

	if (a == 'w')
		return UP;
	else if (a == 'a')
	{
		return LEFT;
	}
	else if (a == 's')
	{
		return DOWN;
	}
	else if (a == 'd')
	{
		return RIGHT;
	}
	else if (a == ' ')
		return SUBMIT;

}