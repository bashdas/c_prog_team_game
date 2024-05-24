#pragma once
#include "appendix.h"
#include "item_tail.h"



int move(int dir);
void reset(void);
void title(void);
void game_over(void);
void HP_print(int HP);






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
    
    HP = 3;
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


    /* item���� �Լ��� ��ġ */
    strider();
    strider1();
    item0();
    item0a();
    item1();
    item();
   
   
    Sleep(200);
}


// item �� �÷��̾ �浹�� ����� �Լ�

int move(int dir) {
    int i;

    if (x[0] == MAP_X*2+1 || x[0] == MAP_X+MAP_WIDTH-1 || y[0] == MAP_Y+3 || y[0] == MAP_Y+MAP_HEIGHT-6) { //���� �浹���� ��� 
        game_over();
        return 0; //game_over���� ������ �ٽ� �����ϰ� �Ǹ� ���⼭���� �ݺ��ǹǷ� 
        //return�� ����Ͽ� move�� ������ �κ��� ������� �ʵ��� �մϴ�. 
    }
    player_crush();
    item0_crush();
    item0a_crush();
    item_crush();
    item1_crush();

    gotoxy(MAP_X + x[length - 1], MAP_Y + y[length - 1], "  "); //���� �������� ���� 
    for (i = length - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű� 
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    if (dir == LEFT) x[0]-=1; //���⿡ ���� ���ο� �Ӹ���ǥ(x[0],y[0])���� ���� 
    if (dir == RIGHT) x[0]+=1;
    if (dir == UP) y[0]-=1;
    if (dir == DOWN) y[0]+=1;
    gotoxy(MAP_X + x[i], MAP_Y + y[i], "��"); //���ο� �Ӹ���ǥ���� �Ӹ��� �׸� 

    move_strider();
    move_strider1();
    /* ��ǥ�� �浹 �Ǵ� */
    
    return 0;
}

void game_over(void) { //�������� �Լ� 
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    draw_map();
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 5, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 6, "|      GAME OVER..     |");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 7, "+----------------------+");
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 6, MAP_Y + 8, " : ");
    printf("%d", HP);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + (MAP_WIDTH / 2) - 7, MAP_Y + 12, " < Press any keys to restart..> ");

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

void HP_print(int HP) {


    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(MAP_X, MAP_Y + MAP_HEIGHT, " HP:"); //HPǥ��

    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    switch (HP)
    {
    case 0:
        game_over();
        break;
    case 1:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "                  "); //HPǥ��
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " ��"); //HPǥ��
        break;

    case 2:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "              "); //HPǥ��

        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " �� ��"); //HPǥ��
        break;
    case 3:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "                   "); //HPǥ��
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " �� �� ��"); //HPǥ��
        break;
    case 4:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "              "); //HPǥ��
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " �� �� �� ��"); //HPǥ��
        break;
    case 5:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "               "); //HPǥ��
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " �� �� �� �� ��"); //HPǥ��
        break;
    case 6:
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, "                  "); //HPǥ��
        gotoxy(MAP_X + 3, MAP_Y + MAP_HEIGHT, " �� �� �� �� �� ��"); //HPǥ��
        break;
    default:
        break;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(MAP_X + 10, MAP_Y + MAP_HEIGHT, " SPEED:"); //����ǥ��
    gotoxy(MAP_X + 15, MAP_Y + MAP_HEIGHT, "             ");
    gotoxy(MAP_X + 14, MAP_Y + MAP_HEIGHT, "");
    printf("%d", 201-speed);
};
