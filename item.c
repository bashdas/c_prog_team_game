#include "main.h"

void drawItem(int x, int y) {
    gotoxy1(x, y);
    Setcolor(9);
    printf("��");
    Setcolor(15);
}


void removeItem(int x, int y) {
    gotoxy1(x, y);
    printf(" ");
    gotoxy1(0, 0);
}

void Itemcoord(struct items* item, struct player player) {
    int x, y;
    do {
        x = rand() % (MAP_WIDTH * 2 - 4) + 23;
        y = rand() % (MAP_HEIGHT - 9) + 5;
    } while (x >= player.x - player.sw && x <= player.x + player.sw &&
        y >= player.y - player.sh && y <= player.y + player.sh);

    item->x = x;
    item->y = y;
}

// �������� �浹�Ǿ��� �� ȣ��Ǵ� �Լ�
void initItem(struct items* item_array, int playerx, int playery, int i) {
    item_array[i].x = 0;
    item_array[i].y = 0;
    strcpy_s(item_array[i].skill, sizeof(item_array[i].skill), "None");

    judge_item(i);

    removeItem(item_array[i].x, item_array[i].y);
    drawPlayer(playerx, playery);
}

// ���޹��� i���� ���� �ٸ� ����� ����ϴ� �Լ�

void judge_item(int i)
{
    switch (i)
    {
    case 0:
        timek += 12; // ���͸� ����
        break;
    case 1:
        HP += 1;  // HP�� �����Ѵ�.
        break;


    case 2:
    case 3:
        timek -= 20; // ���͸� ���� 
        break;

    case 4:
        break; // length ���� (hard��忡����,,,,)

    default:
        break;

    };
}

void eatItem(struct player player_info, struct items* item_array, int playerx, int playery) {
    int sw = player_info.sw;
    int sh = player_info.sh;
    for (int i = 0; i < MAX_ITEMS; i++) {

        if (item_array[i].x <= playerx + player_info.sw && item_array[i].x >= playerx - player_info.sw
            && item_array[i].y <= playery + player_info.sh && item_array[i].y >= playery - player_info.sh)
        {
            drawItem(item_array[i].x, item_array[i].y); // �þ� ������ ������ ������ ���

            if (item_array[i].x == playerx && item_array[i].y == playery) {
                // �浹 �� �迭 0,0,None�� �ʱ�ȭ, ������ ����� ĳ���� �ٽ� �׸���
                initItem(item_array, playerx, playery, i);

            }
        }

        else {
            removeItem(item_array[i].x, item_array[i].y); // �þ� ���� �ۿ� ������ ������ �����

        }
    }
}

void eatItemStrider(struct strider* strider_info, struct items* item_array, int tail) {
    if (tail == 1) {
        for (int i = 0; i < MAX_ITEMS; i++) {

            if ((strider_info[0].sx <= item_array[i].x &&
                strider_info[0].sx + 12 >= item_array[i].x &&
                strider_info[0].sy == item_array[i].y) ||
                (strider_info[1].sx == item_array[i].x &&
                    strider_info[1].sy <= item_array[i].y &&
                    strider_info[1].sy + 6 >= item_array[i].y)
                )
            {
                item_array[i].x = rand() % (MAP_WIDTH * 2 - 4) + 23;
                item_array[i].y = rand() % (MAP_HEIGHT - 9) + 5;
                drawItem(item_array[i].x, item_array[i].y); // �þ� ������ ������ ������ ���
            }
        }
    }
    else {
        for (int i = 0; i < MAX_ITEMS; i++) {

            if ((strider_info[0].sx <= item_array[i].x &&
                strider_info[0].sx + 6 >= item_array[i].x &&
                strider_info[0].sy == item_array[i].y) ||
                (strider_info[1].sx == item_array[i].x &&
                    strider_info[1].sy <= item_array[i].y &&
                    strider_info[1].sy + 3 >= item_array[i].y)
                )
            {
                item_array[i].x = rand() % (MAP_WIDTH * 2 - 4) + 23;
                item_array[i].y = rand() % (MAP_HEIGHT - 9) + 5;
                drawItem(item_array[i].x, item_array[i].y); // �þ� ������ ������ ������ ���
            }
        }
    }
}

void itemeatEasy(int playerx, int playery, struct items* item_array)
{
    for (int i = 0; i < MAX_ITEMS; i++) {


        if (item_array[i].x == playerx && item_array[i].y == playery)
        {
            initItem(item_array, playerx, playery, i);
        }
    }
}