#pragma once
#include "main.h"

// x: 23~96   y: 5~21

int item1_x, item1_y;
/*
void item1(void) {
    int i;

    int item_crush_on = 0;//item�� �÷��̾��� ��ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 


    while (1) {
        item_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        item1_x = rand()%30+20;      //������ ��ǥ���� ���� 
        item1_y = rand()%15+5;

        
        

        if (item_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 
        Setcolor(15);
        gotoxy(item1_x,item1_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        
        break;

    }
}

int movePlayer_e(struct player* player_info, struct items* item_array) {
    int playerx = player_info[0].x;	// �÷��̾� x ��ǥ
    int playery = player_info[0].y; // �÷��̾� y ��ǥ
    int curx = playerx; // ���� ��ǥ x
    int cury = playery; // ���� ��ǥ  y // MAP_X * 2 + 7, MAP_HEIGHT / 2 + 5
  
    
    drawPlayer(playerx, playery);

    while (1)
    {
        time_g(timek);
        HP_print(HP);
        int n = keyControl1();
        switch (n) {
        case UP: {
         
        }
        case DOWN: {
     
        }
        case LEFT: {
       
        }
        case RIGHT: {
         
        }
        case BACK:
            return BACK;
            /*
            case SUBMIT: {
                return SUBMIT; // ó�� �ؾ���

            }
        }
        // �þ� ������ ������ ������ ���





        // �����۰� �÷��̾� �浹 �� ������ ȹ�� ó��
        eatItem(*player_info, item_array, playerx, playery);



        timek = timek + 0.25;

        // ���� �Ϸ��� ���� ���߿� ���� �ؾ��� 
        gotoxy1(0, 0);
        printf("PLAYER: %d %d ", playerx, playery);
        gotoxy1(0, 2);
        printf("MAP_X: %d ~ %d ", MAP_X * 2 + 1, (MAP_X + MAP_WIDTH - 1) * 2 - 2);
        gotoxy1(0, 4);
        printf("MAP_Y: %d ~ %d ", MAP_Y + 3, MAP_HEIGHT / 2 + 8);
        gotoxy1(0, 6);
        printf("ITEMS COORD");
        for (int i = 0; i < MAX_ITEMS; i++) {
            gotoxy1(0, 7 + i);
            printf("%d] (%d, %d) %s\n", i + 1, item_array[i].x, item_array[i].y, item_array[i].skill);
        };

        gotoxy1(0, 6);
        printf("%d", HP);

        // Ŭ���� -> Ŭ���� ��ȯ return CLEAR;
        // ���� ȹ�� �� ���� ���� 
        if (isClear(item_array) == CLEAR) return CLEAR;


        if (100 - timek <= 0)
        {
            Sleep(500);
            failStory();
            Sleep(700);
            return BACK;
        }
        // ���� -> ���� ��ȯ returb FAIL;
        // 
        // ���� �ð� ������ -1 ���, ���� �ð� �߰� �ο�
*/
    






