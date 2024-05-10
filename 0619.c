#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// 키 값 정의  //
#define LEFT1 75
#define RIGHT1 77
#define UP1 72
#define DOWN1 80
#define PAUSE1 112
#define ESC 27

// MAP 값
#define MAP_X 3 // 3 2
#define MAP_Y 2
#define MAP_WIDTH 39  // 30 20
#define MAP_HEIGHT 26

// keyboard value
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // 선택(키)

int x[100], y[100]; //x,y 좌표값을 저장 총 100개 
int key; //입력받은 키 저장 
int speed; //게임 속도 





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

void title(void); //게임 시작화면 
void reset(void); //게임을 초기화 
void draw_map(void); // 게임판 테두리를 그림 
void load_menu(void); // 메뉴를 불러오는 함수.



void gotoxy1(int x, int y);

int menuDraw1();
int keyControl1();




int main() {
    title();

    while (1) {
        if (_kbhit()) do { key = _getch(); } while (key == 224); //키 입력받음
        Sleep(speed);


    }
}


// 

void title(void) {
    int i, j;

    while (_kbhit()) _getch(); //버퍼에 있는 키값을 버림 

    draw_map();    //맵 테두리를 그림 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // 맵 테두리 안쪽을 빈칸으로 채움 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
    }
    Setcolor(4);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|     DUNGEON  RUNNER      |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");
    Setcolor(7);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, " < PRESS ANY KEY TO START > ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 17, "   ◇ ←(a),→(d),↑(w),↓(s) : Move    ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 18, "   ◇ P : Pause             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 8, MAP_Y + 19, "   ◇ ESC : Quit              ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 21, "   KU CSE REPRESENT ");

    while (1) {
        if (_kbhit()) { //키입력받음 
            key = _getch();
            if (key == ESC) exit(0); // ESC키면 종료 
            else break; //아니면 그냥 계속 진행 
        }
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, " < PRESS ANY KEY TO START > ");
        Sleep(300);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, "                            ");
        Sleep(600);

    }
    reset(); // 게임을 초기화  
}

//맵 테두리 그리는 함수 

void draw_map(void) {
    int i, j;
    for (i = 0; i < MAP_WIDTH; i++) {
        gotoxy(MAP_X + i, MAP_Y, "■");
    }
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) {
        gotoxy(MAP_X, i, "■");
        gotoxy(MAP_X + MAP_WIDTH - 1, i, "■");
    }
    for (i = 0; i < MAP_WIDTH; i++) {
        gotoxy(MAP_X + i, MAP_Y + MAP_HEIGHT - 1, "■");
    }
}

//화면 지우기 함수

void reset(void) {
    int i;
    system("cls"); //화면을 지움 
    draw_map(); //맵 테두리를 그림 
	
	

	int menuCode = menuDraw1();
	printf("선택한 메뉴: %d\n", menuCode);


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
	printf("> 게임시작        w(UP)");   // 선택하면 난이도 선택 화면으로 이동
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 15);
	printf("게임방법        a(LEFT)");     // 난이도 별 실행 및 조작법 출력
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 16);
	printf("환경설정        s(DOWN)");
	gotoxy1(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 17);
	printf("  종료          d(RIGHT)\n\n\n");

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
