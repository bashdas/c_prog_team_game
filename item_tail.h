#pragma once
#include "function.h"
#include "appendix.h"

/**************************************************************/
// ���

void strider() {
    
    x1[0] = 10;
    y1[0] = 24;  // 1~24
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(MAP_X + x1[0], MAP_Y + y1[0], "��"); // �Ӹ� �׸� 

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

};

void move_strider() {
    if (y1[0] <= 24 && y1[0] >=1) // 1~24
    {
        gotoxy(MAP_X + x1[length1 - 1], MAP_Y + y1[length1 - 1], "  "); //���� �������� ���� 
        for (int i = length1 - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű� 
            x1[i] = x1[i - 1];
            y1[i] = y1[i - 1];
        }
        //���� �������� ���� 
       
        y1[0]-=1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        gotoxy(MAP_X + x1[0], MAP_Y + y1[0], "��"); // �Ӹ� �׸� 

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    if (y1[0] <= 0)
        strider();

};

void strider1() {

    x2[0] = 1;
    y2[0] = 15;  // 1~24

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(MAP_X + x2[0], MAP_Y + y2[0], "��"); // �Ӹ� �׸� 

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

};

void move_strider1() {
    if (x2[0] <= 37 && x2[0] >= 1) // 1~24
    {
        gotoxy(MAP_X + x2[length2 - 1], MAP_Y + y2[length2 - 1], "  "); //���� �������� ���� 
        for (int i = length2 - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű� 
            x2[i] = x2[i - 1];
            y2[i] = y2[i - 1];
        }
        //���� �������� ���� 

        x2[0]++;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        gotoxy(MAP_X + x2[0], MAP_Y + y2[0], "��"); // �Ӹ� �׸� 

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    if (x2[0]>37)
        strider1();

};
/**************************************************************/
// ������(���� �ӵ� ����)

void item0(void) {
    int i;

    int item0_crush_on = 0;//item�� �÷��̾��� ��ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 


    while (1) {
        item0_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        item0_x = rand() % 22 + 8; // 0~25 (5~30) 28�� ������ 0~36
        item0_y = rand() % 14 + 4; // 0~15 (4~19) 20�� ������ 0~19   //������ ��ǥ���� ���� 


        for (i = 0; i < length; i++) { // item�� �÷��̾ ��ġ���� Ȯ��  
            if (item0_x == x[i] && item0_y == y[i]) {
                item0_crush_on = 1; //��ġ�� item_crush_on �� on 
                r++;
                item0_x = rand() % 22 + 8; // 0~25 (5~30) 28�� ������ 0~36
                item0_y = rand() % 14 + 4; // 0~15 (4~19) 20�� ������ 0~19
                break;
            }
        }

        if (item0_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        gotoxy(MAP_X + item0_x, MAP_Y + item0_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        speed -= 3; //�ӵ� ���� 
        break;

    }
}

void item0_crush() {
    // �÷��̾�� �浹
    if (item0_x == x[0] && item0_y == y[0])
    {
        item0();
        speed=speed-20;
    }
    // strider�� �浹
    if (item0_x == x1[0] && item0_y == y1[0])
    {
        item0();
    }
};

void item0a(void) {
    int i;

    int item0a_crush_on = 0;//item�� �÷��̾��� ��ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 


    while (1) {
        item0a_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        item0a_x = rand() % 24 + 5; // 0~25 (5~30) 28�� ������ 0~36
        item0a_y = rand() % 13 + 4; // 0~15 (4~19) 20�� ������ 0~19   //������ ��ǥ���� ���� 


        for (i = 0; i < length; i++) { // item�� �÷��̾ ��ġ���� Ȯ��  
            if (item0a_x == x[i] && item0a_y == y[i]) {
                item0a_crush_on = 1; //��ġ�� item_crush_on �� on 
                r++;
                item0a_x = rand() % 22 + 8; // 0~25 (5~30) 28�� ������ 0~36
                item0a_y = rand() % 14 + 4; // 0~15 (4~19) 20�� ������ 0~19
                break;
            }
        }

        if (item0a_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        gotoxy(MAP_X + item0a_x, MAP_Y + item0a_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        speed -= 3; //�ӵ� ���� 
        break;

    }
}

void item0a_crush() {
    // �÷��̾�� �浹
    if (item0a_x == x[0] && item0a_y == y[0])
    {
        item0a();
        speed = speed - 20;
    }
    // strider�� �浹
    if (item0a_x == x1[0] && item0a_y == y1[0])
    {
        item0a();
    }
    // strider�� �浹
    if (item0a_x == x2[0] && item0a_y == y2[0])
    {
        item0a();
    }
    // item (speed 0)�� ���� ��ġ
    if (item0a_x == item0_x && item0a_y == item0_y)
    {
        item0a();
    }
};

/**************************************************************/
// ������(���� �ӵ� ����)

void item1(void) {
    int i;

    int item0_crush_on = 0;//item�� �÷��̾��� ��ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 


    while (1) {
        item0_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        item1_x = rand() % 27 + 6; // 0~25 (5~30) 28�� ������ 0~36
        item1_y = rand() % 15 + 4; // 0~15 (4~19) 20�� ������ 0~19   //������ ��ǥ���� ���� 


        for (i = 0; i < length; i++) { // item�� �÷��̾ ��ġ���� Ȯ��  
            if (item1_x == x[i] && item1_y == y[i]) {
                item0_crush_on = 1; //��ġ�� item_crush_on �� on 
                r++;
                item1_x = rand() % 22 + 8; // 0~25 (5~30) 28�� ������ 0~36
                item1_y = rand() % 14 + 4; // 0~15 (4~19) 20�� ������ 0~19
                break;
            }
        }

        if (item0_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        gotoxy(MAP_X + item1_x, MAP_Y + item1_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        speed -= 3; //�ӵ� ���� 
        break;

    }
};
void item1_crush() {
    // �÷��̾�� �浹
    if (item1_x == x[0] && item1_y == y[0])
    {
        item1();
        speed = speed + 20;
    }
    // strider�� �浹
    if (item1_x == x1[0] && item1_y == y1[0])
    {
        item1();
    }
    if (item1_x == x2[0] && item1_y == y2[0])
    {
        item1();
    }
    // item (speed 0)�� ���� ��ġ
    if (item1_x == item0_x && item1_y == item0_y)
    {
        item1();
    }
    if (item1_x == item0a_x && item1_y == item0a_y)
    {
        item1();
    }
};

/************************************************************/
void player_crush() {
    if (x1[0] == x[0] && y1[0] == y[0])
    {
        HP--;
        strider();
    }
    if (x1[0] == x[0] && y1[0] == y[0]-1)
    {
        HP--;
        strider();
    }
    if (x1[0] == x[0] && y1[0] == y[0]+1)
    {
        HP--;
        strider();
    }
};

/**************************************************************/
// ������(���� ����)


void item(void) {
    int i;

    int item_crush_on = 0;//item�� �÷��̾��� ��ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 


    while (1) {
        item_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        item_x = rand() % 24+ 5; // 0~25 (5~30) 28�� ������ 0~36
        item_y = rand() % 13 + 5; // 0~15 (4~19) 20�� ������ 0~19   //������ ��ǥ���� ���� 


        for (i = 0; i < length; i++) { // item�� �÷��̾ ��ġ���� Ȯ��  
            if (item_x == x[i] && item_y == y[i]) {
                item_crush_on = 1; //��ġ�� item_crush_on �� on 
                r++;
                item_x = rand() % 24 + 5; // 0~25 (5~30) 28�� ������ 0~36
                item_y = rand() % 13 + 5; // 0~15 (4~19) 20�� ������ 0~19
                break;
            }
        }

        if (item_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        gotoxy(MAP_X + item_x, MAP_Y + item_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        //�ӵ� ���� 
        

    }
};

void item_crush() {
    // �÷��̾�� �浹
    if (item_x == x[0] && item_y == y[0])
    {
        item();
        length+=4;
    }
    // strider�� �浹
    if (item_x == x1[0] && item_y == y1[0])
    {
        item();
    }
    if (item_x == x2[0] && item_y == y2[0])
    {
        item();
    }
    // item (speed 0)�� ���� ��ġ
    if (item_x == item0_x && item_y == item0_y)
    {
        item();
    }
    if (item_x == item0a_x && item_y == item0a_y)
    {
        item();
    }
};