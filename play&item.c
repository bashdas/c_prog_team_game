#include "main.h"

#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 39
#define MAP_HEIGHT 26
int x[100], y[100]; //x,y ��ǥ���� ���� �� 100�� 
int x1[100], y1[100];

int item_x, item_y; //item�� ��ǥ���� ���� 
int length; //�����̸� ���


// Key�� ��ǥ  x: 4~40, y: 3~22
int key_x, key_y;

// poison�� ��ǥ
int poison_x, poison_y;

// ü��
int HP = 3;
int* pHP = &HP;


// ���� �ý���
int speed; //���� �ӵ� 
int score; //���� ����  --reset�Լ��� ���� �ʱ�ȭ��
int best_score = 0; //�ְ� ���� ���� --reset�Լ��� ���� �ʱ�ȭ ���� ���� 
int last_score = 0; //������ ���� ����  --reset�Լ��� ���� �ʱ�ȭ ���� ����
int dir; //�̵����� ���� 
int key; //�Է¹��� Ű ���� 
int status_on = 0; // �����ڿ� status ǥ��Ȱ��ȭ ����.. �����߿� SŰ�� ������ Ȱ�� 

void key_random(void);
void poison_random(void);
void preyer(void);

void gotoxy(int x, int y, const char* s) { //x���� 2x�� ����, ��ǥ���� �ٷ� ���ڿ��� �Է��� �� �ֵ��� printf�Լ� ����  
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);
}

void title(void); //���� ����ȭ�� 
void reset(void); //������ �ʱ�ȭ 
void draw_map(void); // ������ �׵θ��� �׸� 
int move(int dir); //�÷��̾ �̵� 
void pause(void); //�Ͻ����� 
void game_over(void); //���� ������ Ȯ�� 
void item(void); // ���� ���� 
void status(void); // �����ڿ� statusǥ��  

void HP_print(int HP) {


    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(MAP_X, MAP_Y + MAP_HEIGHT, " HP:"); //HPǥ��
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    switch (HP)
    {
    case 0:
        break;
    case 1:

        printf(" ��");
        break;
    case 2:
        printf(" �� ��");
        break;
    case 3:
        printf(" �� �� ��");
        break;
    case 4:
        printf(" �� �� �� ��");
        break;
    case 5:
        printf(" �� �� �� �� ��");
        break;
    case 6:
        printf(" �� �� �� �� �� ��");
        break;
    default:
        break;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + 10, MAP_Y + MAP_HEIGHT, " HP:"); //����ǥ��
    printf("%d", HP);

}

////////////////////////////MAIN START//////////////////////////////
int main() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    title();

    while (1) {
        if (_kbhit()) do { key = _getch(); } while (key == 224); //Ű �Է¹���
        Sleep(speed);

        switch (key) { //�Է¹��� Ű�� �ľ��ϰ� ����  
        case LEFT:
        case RIGHT:
        case UP:
        case DOWN:
            if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) ||
                (dir == DOWN && key != UP))//180ȸ���̵��� �����ϱ� ���� �ʿ�. 
                dir = key;
            key = 0; // Ű���� �����ϴ� �Լ��� reset 
            break;
        case PAUSE: // PŰ�� ������ �Ͻ����� 
            pause();
            break;
        case 115: //SŰ�� ������ �����ڿ� status�� Ȱ��ȭ ��Ŵ  
            if (status_on == 0) status_on = 1;
            else status_on = 0;
            key = 0;
            break;
        case ESC: //ESCŰ�� ������ ���α׷� ���� 
            system("cls");
            printf("������ �����ϴ�.");
            Sleep(500);
            exit(0);
        }
        int a = move(dir);

        HP_print(HP);



        if (a == -1)
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, " < GAME CLEAR > ");

            game_over();

        }




        if (status_on == 1); // statusǥ�� 
    }

}

///////////////////////////MAIN END////////////////////////////////

void title(void) {
    int i, j;

    while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 

    draw_map();    //�� �׵θ��� �׸� 
    for (i = MAP_Y + 1; i < MAP_Y + MAP_HEIGHT - 1; i++) { // �� �׵θ� ������ ��ĭ���� ä�� 
        for (j = MAP_X + 1; j < MAP_X + MAP_WIDTH - 1; j++) gotoxy(j, i, "  ");
    }

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 5, "+--------------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 6, "|   |   |    |    |   |    |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 7, "+--------------------------+");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, " < PRESS ANY KEY TO START > ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 11, "   �� ��,��,��,�� : Move    ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, "   �� Settings              ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 13, "   �� ESC : Quit             ");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 14, "   �� P : Pause             ");

    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 17, "         KU CSE  ");

    while (1) {
        if (_kbhit()) { //Ű�Է¹��� 
            key = _getch();
            if (key == ESC) exit(0); // ESCŰ�� ���� 
            else break; //�ƴϸ� �׳� ��� ���� 
        }
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, " < PRESS ANY KEY TO START > ");
        Sleep(400);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 9, "                            ");
        Sleep(400);

    }
    reset(); // ������ �ʱ�ȭ  

}

void reset(void) {
    int i;
    system("cls"); //ȭ���� ���� 
    draw_map(); //�� �׵θ��� �׸� 
    gotoxy(MAP_X, MAP_Y, "��");
    while (_kbhit()) _getch(); //���ۿ� �ִ� Ű���� ���� 

    dir = RIGHT; // ���� �ʱ�ȭ  
    speed = 200; // �ӵ� �ʱ�ȭ 
    length = 2; // ���� �ʱ�ȭ 
    score = 0; //���� �ʱ�ȭ 
    x[0] = 5;
    y[0] = 5;

    // ������ �÷��̾�
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    gotoxy(MAP_X + x[0], MAP_Y + y[0], "��"); // �Ӹ� �׸� 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    preyer();
    item(); // item ���� 

    key_random();
    poison_random();
    Sleep(200);
}
// ȸ�� �÷��̾�
void preyer() {
    x1[0] = 10;
    y1[0] = 10;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

    gotoxy(MAP_X + x1[0], MAP_Y + y1[0], "��"); // �Ӹ� �׸� 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

};


void draw_map(void) { //�� �׵θ� �׸��� �Լ� 
    int i, j;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
    HP = 3;
}



// item �� �÷��̾ �浹�� ����� �Լ�

int move(int dir) {
    int i;

    if (x[0] == item_x && y[0] == item_y) { //item �� �浹���� ��� 
        return -1;
    }
    if (x[0] == 0 || x[0] == MAP_WIDTH - 1 || y[0] == 0 || y[0] == MAP_HEIGHT - 1) { //���� �浹���� ��� 
        game_over();
        return 0; //game_over���� ������ �ٽ� �����ϰ� �Ǹ� ���⼭���� �ݺ��ǹǷ� 
        //return�� ����Ͽ� move�� ������ �κ��� ������� �ʵ��� �մϴ�. 
    }
    if (x[0] == key_x && y[0] == key_y)
    {
        HP += 1;
        key_random();

    }
    if (x[0] == poison_x && y[0] == poison_y)
    {

        HP = HP - 1;
        poison_random();
    }

    /*for (i = 1; i < length; i++) { //�ڱ���� �浹�ߴ��� �˻�
        if (x[0] == x[i] && y[0] == y[i]) {
            game_over();
            return 0;
        }
    }*/

    gotoxy(MAP_X + x[length - 1], MAP_Y + y[length - 1], "  "); //���� �������� ���� 
    for (i = length - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű� 
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    if (dir == LEFT) --x[0]; //���⿡ ���� ���ο� �Ӹ���ǥ(x[0],y[0])���� ���� 
    if (dir == RIGHT) ++x[0];
    if (dir == UP) --y[0];
    if (dir == DOWN) ++y[0];
    gotoxy(MAP_X + x[i], MAP_Y + y[i], "��"); //���ο� �Ӹ���ǥ���� �Ӹ��� �׸� 




    ///////////////////////////////////////*
   /* gotoxy(MAP_X + x1[length - 1], MAP_Y + y1[length - 1], "  "); //���� �������� ����
    for (i = length - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű�
        x1[i] = x1[i - 1];
        y1[i] = y1[i - 1];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    if (x1[0] >= 2)
    {
        --x1[0];
    } //���⿡ ���� ���ο� �Ӹ���ǥ(x[0],y[0])���� ����

    else if (x1[0] < 15)
    {
        ++x[0];
    }

    gotoxy(MAP_X + x1[i], MAP_Y + y1[i], "��"); //���ο� �Ӹ���ǥ���� �Ӹ��� �׸� */


}


void pause(void) { // pŰ�� ������ ��� ������ �Ͻ� ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    while (1) {
        if (key == PAUSE) {
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
            Sleep(400);
            gotoxy(MAP_X + (MAP_WIDTH / 2) - 9, MAP_Y, "                                    ");
            Sleep(400);
        }
        else {
            draw_map();
            return;
        }
        if (_kbhit()) {

            do {
                key = _getch();
            } while (key == 224);
        }

    }
}

void game_over(void) { //�������� �Լ� 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      GAME OVER..     |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " YOUR SCORE : ");
    for (int k = 0; k < HP; k++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf(" ��");
    };
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, " Press any keys to restart.. ");

    if (score > best_score) {
        best_score = score;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(MAP_X + (MAP_WIDTH / 2) - 4, MAP_Y + 10, "�� BEST SCORE ��");
    }
    Sleep(500);
    while (_kbhit()) _getch();
    key = _getch();

    title();
}

void item(void) {
    int i;

    int item_crush_on = 0;//item�� �÷��̾��� ��ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 


    while (1) {
        item_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        item_x = (rand() % (MAP_WIDTH - 2)) + 1;    //������ ��ǥ���� ���� 
        item_y = (rand() % (MAP_HEIGHT - 2)) + 1;

        for (i = 0; i < length; i++) { // item�� �÷��̾ ��ġ���� Ȯ��  
            if (item_x == x[i] && item_y == y[i]) {
                item_crush_on = 1; //��ġ�� item_crush_on �� on 
                r++;

                break;
            }
        }

        if (item_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 

        gotoxy(MAP_X + item_x, MAP_Y + item_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        speed -= 3; //�ӵ� ���� 
        break;

    }
}

void key_random(void)
{
    // x,y��ǥ�� ����  // (MAP_X + 1) ~ (MAP_X + 37)       (MAP_Y+1) ~ (MAP_Y+20)

    int i;
    int k = 1;
    int HP_crush_on = 0;

    while (1) {
        srand((unsigned)time(NULL) + k);
        key_x = rand() % 23 + 5; // 0~25 (5~30) 28�� ������ 0~36
        key_y = rand() % 14 + 4; // 0~15 (4~19) 20�� ������ 0~19

        for (i = 0; i < length; i++) { // item�� �÷��̾ ��ġ���� Ȯ��  
            if (item_x == x[i] && item_y == y[i]) {
                HP_crush_on = 1; //��ġ�� item_crush_on �� on 
                HP += 1;
                k++;
                break;
            }
        }

        if (HP_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        gotoxy(MAP_X + key_x, MAP_Y + key_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        break;

    }
}

void poison_random(void)
{
    // x,y��ǥ�� ����  // (MAP_X + 1) ~ (MAP_X + 37)       (MAP_Y+1) ~ (MAP_Y+20)

    int i;
    int k = 0;
    int poison_crush_on = 0;

    while (1) {
        srand((unsigned)time(NULL) + k);
        poison_x = rand() % 25 + 3; // 0~25 (5~30) 28�� ������ 0~36
        poison_y = rand() % 15 + 4; // 0~15 (4~19) 20�� ������ 0~19

        for (i = 0; i < length; i++) { // item�� �÷��̾ ��ġ���� Ȯ��  
            if (poison_x == x[i] && poison_y == y[i]) {
                poison_crush_on = 1; //��ġ�� item_crush_on �� on 
                HP += 1;
                k++;
                break;
            }
        }

        if (poison_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        gotoxy(MAP_X + poison_x, MAP_Y + poison_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        break;

    }
}