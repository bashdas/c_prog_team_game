#include "main.h"

#include "game_oper.h"



/*
ĳ���� �߽� �׸���
  - ĳ���� ��ǥ ��ġ�� �׸���,
  - ĳ���� ���� ��ġ ��ǥ
*/
void drawPlayer(int x, int y) {
    gotoxy1(x, y);
    Setcolor(4);
    printf("��\b");
    Setcolor(7);
}

void removePlayer(int x, int y) {
    gotoxy1(x, y);
    Setcolor(4);
    printf(" ");
    Setcolor(7);
}

/*
ĳ���� �þ� �׸���
  - ĳ���� ��ǥ ��ġ���� ���� �Ÿ���ŭ ������� �׸���
  - player ���� ��ġ ��ǥ
  - upper ~ bottom ����
  - left ~ right ����
*/
void drawPlayerSight(int x, int y, int bottom, int right, int upper, int left) {
    int sightx = x - 6;
    int sighty = y - 3;
    char charsight[7][14] = { // �߾� 6,3 -> ĳ���� �߽����� ���� x-6, y-3��ġ���� �þ� �׸��� ����
        "* * * * * * *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "* * * * * * *\0"
    };
    // ĳ���� �þ� �׸���
    for (int i = 0 + upper; i < bottom; i++) {
        gotoxy1(sightx, sighty);
        for (int j = 0 + left; j < right; j++) {
            putchar(charsight[i][j]);
            fflush(stdout);
        }
        gotoxy1(x, y); // ���콺 Ŀ�� ��ġ ����
        sighty += 1;
    }
}

/*
ĳ���� �þ� ����� -> ĳ���͵� ���� ����
  - drawPlayerSight ���ۿ��� ����
*/
void removePlayerSight(int x, int y, int bottom, int right, int upper, int left) {
    int sightx = x - 6;
    int sighty = y - 3;
    char charsight[7][14] = {
        "             \0",
        "             \0",
        "             \0",
        "             \0",
        "             \0",
        "             \0",
        "             \0",
    };
    for (int i = 0 + upper; i < bottom; i++) {
        gotoxy1(sightx, sighty);
        for (int j = 0 + left; j < right; j++) {
            putchar(charsight[i][j]);
            fflush(stdout);
        }
        gotoxy1(x, y); // ���콺 Ŀ�� ��ġ ����
        sighty += 1;
    }
}

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
    int sw, sh, mode = NORMAL;
    if (mode == NORMAL) {
        sw = player_info.sw;
        sh = player_info.sh;
    }
    else if (mode == HARD) {
        sw = player_info.sw;
        sh = player_info.sh;
    }
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

void itemeatEasy(int playerx, int playery, struct items* item_array)
{
    for (int i = 0; i < MAX_ITEMS; i++) {


        if (item_array[i].x == playerx && item_array[i].y == playery)
        {
            initItem(item_array, playerx, playery, i);
        }
    }
}

int isClear(struct items* item_array) {
    if (item_array[5].x == 0 && item_array[5].y == 0 && item_array[6].x == 0 && item_array[6].y == 0) 
        return CLEAR;
}


/*
�÷��̾� �̵�
- �÷��̾� ��ǥ ������ ������ ����
- ������ ��ǥ �ʿ� -> �̵��ϸ鼭 �÷��̾� ��ǥ�� ������ ��ǥ ���� ������ ������ ������ ���, �浹 �� �����

*/

// �þ߰� ���Ե� �Լ�.
int movePlayer(struct player* player_info, struct items* item_array) {
    int playerx = player_info[0].x;	// �÷��̾� x ��ǥ
    int playery = player_info[0].y; // �÷��̾� y ��ǥ
    int curx = playerx; // ���� ��ǥ x
    int cury = playery; // ���� ��ǥ  y // MAP_X * 2 + 7, MAP_HEIGHT / 2 + 5
    int upper = 0, bottom = 7, left = 0, right = 14; // �÷��̾� �þ� �迭�� ��ŭ ���� ��
    drawPlayerSight(playerx, playery, bottom, right, upper, left);
    drawPlayer(playerx, playery);

    while (1)
    {
        time_g(timek);
        HP_print(HP);



        int n = keyControl1();
        
        
        
        switch (n) 
        { case UP: {
            if (playery <= MAP_Y + 3) playery = MAP_Y + 3;
            else if (playery <= MAP_Y + 6 && playery >= MAP_Y + 4) { //�� ���� �̵�
                curx = playerx, cury = MAP_Y + 6, left = 0, right = 14;
                if (playery == MAP_Y + 6) upper = 0;
                if (playery == MAP_Y + 5) upper = 1;
                if (playery == MAP_Y + 4) upper = 2;
                if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // ���ʿ��� ���� �� �� ��ġ�� �κ�
                    if (playerx == MAP_X * 2 + 6) left = 1;
                    if (playerx == MAP_X * 2 + 5) left = 2;
                    if (playerx == MAP_X * 2 + 4) left = 3;
                    if (playerx == MAP_X * 2 + 3) left = 4;
                    if (playerx == MAP_X * 2 + 2) left = 5;
                    if (playerx == MAP_X * 2 + 1) left = 6;
                    curx = MAP_X * 2 + 7;
                }
                else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { // �����ʿ��� ���� �� �� ��ġ�� �κ�
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                }
                removePlayerSight(curx, cury, bottom, right, upper, left);
                drawPlayerSight(curx, cury, bottom, right, ++upper, left);
                drawPlayer(playerx, --playery);
            }
            else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // �� �Ʒ����� ���� �̵�
                curx = playerx, left = 0, right = 14, upper = 0;
                if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // ���ʿ��� �Ʒ��� �� �� ��ġ�� �κ�
                    if (playerx == MAP_X * 2 + 6) left = 1;
                    if (playerx == MAP_X * 2 + 5) left = 2;
                    if (playerx == MAP_X * 2 + 4) left = 3;
                    if (playerx == MAP_X * 2 + 3) left = 4;
                    if (playerx == MAP_X * 2 + 2) left = 5;
                    if (playerx == MAP_X * 2 + 1) left = 6;
                    curx = MAP_X * 2 + 7;
                }
                else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { // �����ʿ��� �Ʒ��� �� �� ��ġ�� �κ�
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                }
                removePlayerSight(curx, playery, bottom, right, upper, left);
                drawPlayerSight(curx, --playery, ++bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // �� �� �ʿ��� ���� �̵�
                curx = MAP_X * 2 + 7, bottom = 7, right = 14, upper = 0;
                if (playerx == MAP_X * 2 + 6) left = 1;
                if (playerx == MAP_X * 2 + 5) left = 2;
                if (playerx == MAP_X * 2 + 4) left = 3;
                if (playerx == MAP_X * 2 + 3) left = 4;
                if (playerx == MAP_X * 2 + 2) left = 5;
                if (playerx == MAP_X * 2 + 1) left = 6;
                removePlayerSight(curx, playery, bottom, right, upper, left);
                drawPlayerSight(curx, --playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { //�� �����ʿ��� ���� �̵�
                bottom = 7, left = 0, upper = 0;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(playerx, --playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else { // �� ����
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(playerx, --playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            break;
        }
        case DOWN: {
            if (playery >= MAP_HEIGHT / 2 + 8) playery = MAP_HEIGHT / 2 + 8;
            else if (playery < MAP_HEIGHT / 2 + 8 && playery >= MAP_HEIGHT / 2 + 5) { // �� ��� �Ʒ��� �̵�
                curx = playerx, left = 0, right = 14;
                if (playery == MAP_HEIGHT / 2 + 5) bottom = 7;
                if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // ���ʿ��� �Ʒ��� �� �� ��ġ�� �κ�
                    if (playerx == MAP_X * 2 + 6) left = 1;
                    if (playerx == MAP_X * 2 + 5) left = 2;
                    if (playerx == MAP_X * 2 + 4) left = 3;
                    if (playerx == MAP_X * 2 + 3) left = 4;
                    if (playerx == MAP_X * 2 + 2) left = 5;
                    if (playerx == MAP_X * 2 + 1) left = 6;
                    curx = MAP_X * 2 + 7;
                }
                else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { // �����ʿ��� �Ʒ��� �� �� ��ġ�� �κ�
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                }
                removePlayerSight(curx, playery, bottom, right, 0, left);
                drawPlayerSight(curx, ++playery, --bottom, right, 0, left);
                drawPlayer(playerx, playery);
            }
            else if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // �� ������ �Ʒ��� �̵�
                curx = playerx, cury = MAP_Y + 6, bottom = 7, left = 0, right = 14;
                if (playery == MAP_Y + 3) upper = 3;
                if (playery == MAP_Y + 4) upper = 2;
                if (playery == MAP_Y + 5) upper = 1;
                if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // ���ʿ��� �Ʒ��� �� �� ��ġ�� �κ�
                    if (playerx == MAP_X * 2 + 6) left = 1;
                    if (playerx == MAP_X * 2 + 5) left = 2;
                    if (playerx == MAP_X * 2 + 4) left = 3;
                    if (playerx == MAP_X * 2 + 3) left = 4;
                    if (playerx == MAP_X * 2 + 2) left = 5;
                    if (playerx == MAP_X * 2 + 1) left = 6;
                    curx = MAP_X * 2 + 7;
                }
                else if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { // �����ʿ��� �Ʒ��� �� �� ��ġ�� �κ�
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                    if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                }
                removePlayerSight(curx, cury, bottom, right, upper, left);
                drawPlayerSight(curx, cury, bottom, right, --upper, left);
                drawPlayer(playerx, ++(playery));
            }
            else if (playerx >= MAP_X * 2 + 1 && playerx < MAP_X * 2 + 7) { // �� �� �ʿ��� ���� �̵�
                curx = MAP_X * 2 + 7, bottom = 7, right = 14, upper = 0;
                if (playerx == MAP_X * 2 + 6) left = 1;
                if (playerx == MAP_X * 2 + 5) left = 2;
                if (playerx == MAP_X * 2 + 4) left = 3;
                if (playerx == MAP_X * 2 + 3) left = 4;
                if (playerx == MAP_X * 2 + 2) left = 5;
                if (playerx == MAP_X * 2 + 1) left = 6;
                removePlayerSight(curx, playery, bottom, right, upper, left);
                drawPlayerSight(curx, ++playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 6 && playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 2) { //�� �����ʿ��� ���� �̵�
                bottom = 7, left = 0, upper = 0;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 8;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 9;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 11;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 12;
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(playerx, ++playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else { // �� ����
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(playerx, ++playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            break;
        }
        case LEFT: {
            if (playerx <= MAP_X * 2 + 1) playerx = MAP_X * 2 + 1;
            else if (playerx <= MAP_X * 2 + 7 && playerx > MAP_X * 2 + 1) { // �� �������� �̵�
                curx = MAP_X * 2 + 7, cury = playery, bottom = 7, right = 14, upper = 0;
                if (playerx == MAP_X * 2 + 7) left = 1;
                if (playerx == MAP_X * 2 + 6) left = 2;
                if (playerx == MAP_X * 2 + 5) left = 3;
                if (playerx == MAP_X * 2 + 4) left = 4;
                if (playerx == MAP_X * 2 + 3) left = 5;
                if (playerx == MAP_X * 2 + 2) left = 6;
                if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // ���ʿ��� �������� �� �� ��ġ�� �κ�
                    if (playery == MAP_Y + 3) upper = 3;
                    if (playery == MAP_Y + 4) upper = 2;
                    if (playery == MAP_Y + 5) upper = 1;
                    cury = MAP_Y + 6;
                }
                else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // �Ʒ��ʿ��� �������� �� �� ��ġ�� �κ�
                    if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                    if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                    if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                }
                removePlayerSight(curx, cury, bottom, right, upper, 0);
                drawPlayerSight(curx, cury, bottom, right, upper, left);
                drawPlayer(--playerx, playery);
            }
            else if (playerx <= (MAP_X + MAP_WIDTH - 1) * 2 - 2 && playerx > (MAP_X + MAP_WIDTH - 1) * 2 - 7) { // �� �����ʿ��� �������� �̵�
                cury = playery, upper = 0, bottom = 7, right = 14, left = 0;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 2) right = 8;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // ���ʿ��� �������� �� �� ��ġ�� �κ�
                    if (playery == MAP_Y + 3) upper = 3;
                    if (playery == MAP_Y + 4) upper = 2;
                    if (playery == MAP_Y + 5) upper = 1;
                    cury = MAP_Y + 6;
                }
                else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // �Ʒ��ʿ��� �������� �� �� ��ġ�� �κ�
                    if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                    if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                    if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                }
                removePlayerSight(playerx, cury, bottom, right, upper, left);
                drawPlayerSight(--playerx, cury, bottom, ++right, upper, left);
                drawPlayer(playerx, playery);

            }
            else if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // �� ������ �������� �̵�
                cury = MAP_Y + 6, bottom = 7, left = 0, right = 14;
                if (playery == MAP_Y + 3) upper = 3;
                if (playery == MAP_Y + 4) upper = 2;
                if (playery == MAP_Y + 5) upper = 1;
                removePlayerSight(playerx, cury, bottom, right, upper, left);
                drawPlayerSight(--playerx, cury, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // �� �Ʒ����� �������� �̵�
                right = 14, upper = 0, left = 0;
                if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(--playerx, playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else { // �� ����
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(--playerx, playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            break;
        }
        case RIGHT: {
            if (playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 2) playerx = (MAP_X + MAP_WIDTH - 1) * 2 - 2;
            else if (playerx < (MAP_X + MAP_WIDTH - 1) * 2 - 2 && playerx >= (MAP_X + MAP_WIDTH - 1) * 2 - 7) { // �� ���������� �̵�
                cury = playery, bottom = 7, upper = 0, left = 0;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 7) right = 13;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 6) right = 12;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 5) right = 11;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 4) right = 10;
                if (playerx == (MAP_X + MAP_WIDTH - 1) * 2 - 3) right = 9;
                if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // ���ʿ��� ���������� �� �� ��ġ�� �κ�
                    if (playery == MAP_Y + 3) upper = 3;
                    if (playery == MAP_Y + 4) upper = 2;
                    if (playery == MAP_Y + 5) upper = 1;
                    cury = MAP_Y + 6;
                }
                else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // �Ʒ��ʿ��� ���������� �� �� ��ġ�� �κ�
                    if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                    if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                    if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                }
                removePlayerSight(playerx, cury, bottom, right, upper, left);
                drawPlayerSight(++(playerx), cury, bottom, --right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playerx <= MAP_X * 2 + 6 && playerx >= MAP_X * 2 + 1) { // �� ���ʿ��� ���������� �̵�
                curx = MAP_X * 2 + 7, bottom = 7, right = 14, upper = 0, cury = playery, left = 0;
                if (playerx == MAP_X * 2 + 6) left = 0;
                if (playerx == MAP_X * 2 + 5) left = 1;
                if (playerx == MAP_X * 2 + 4) left = 2;
                if (playerx == MAP_X * 2 + 3) left = 3;
                if (playerx == MAP_X * 2 + 2) left = 4;
                if (playerx == MAP_X * 2 + 1) left = 5;
                if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // ���ʿ��� ���������� �� �� ��ġ�� �κ�
                    if (playery == MAP_Y + 3) upper = 3;
                    if (playery == MAP_Y + 4) upper = 2;
                    if (playery == MAP_Y + 5) upper = 1;
                    cury = MAP_Y + 6;
                }
                else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // �Ʒ��ʿ��� ���������� �� �� ��ġ�� �κ�
                    if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                    if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                    if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                }
                removePlayerSight(curx, cury, bottom, right, upper, 0);
                drawPlayerSight(curx, cury, bottom, right, upper, left);
                drawPlayer(++playerx, playery);
            }
            else if (playery <= MAP_Y + 5 && playery >= MAP_Y + 3) { // �� ������ ���������� �̵�
                cury = MAP_Y + 6, bottom = 7, left = 0, right = 14;
                if (playery == MAP_Y + 3) upper = 3;
                if (playery == MAP_Y + 4) upper = 2;
                if (playery == MAP_Y + 5) upper = 1;
                removePlayerSight(playerx, cury, bottom, right, upper, left);
                drawPlayerSight(++playerx, cury, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else if (playery <= MAP_HEIGHT / 2 + 8 && playery > MAP_HEIGHT / 2 + 5) { // �� �Ʒ����� ���������� �̵�
                right = 14, upper = 0, left = 0;
                if (playery == MAP_HEIGHT / 2 + 8) bottom = 4;
                if (playery == MAP_HEIGHT / 2 + 7) bottom = 5;
                if (playery == MAP_HEIGHT / 2 + 6) bottom = 6;
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(++playerx, playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            else { // �� ����
                removePlayerSight(playerx, playery, bottom, right, upper, left);
                drawPlayerSight(++playerx, playery, bottom, right, upper, left);
                drawPlayer(playerx, playery);
            }
            break;
        }
        case BACK:
            return BACK;
        }  /*
            case SUBMIT: {
                return SUBMIT; // ó�� �ؾ���

            }*/
        
        // �þ� ������ ������ ������ ���
         
        
        
        
        
        // �����۰� �÷��̾� �浹 �� ������ ȹ�� ó��
        eatItem(*player_info, item_array, playerx, playery);
        
        
        
        timek = timek +0.25;

        /* ���� �Ϸ��� ���� ���߿� ���� �ؾ��� */
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

    }
}

void Itemcoord(struct items* item, struct player* player) {
    int x, y;
    do {
        x = rand() % (MAP_WIDTH * 2 - 4) + 23;
        y = rand() % (MAP_HEIGHT - 9) + 5;
    } while (x >= player->x - player->sw && x <= player->x + player->sw &&
        y >= player->y - player->sh && y <= player->y + player->sh);

    item->x = x;
    item->y = y;
}

// ������ ���������� �� ó�� �����ϴ� �Լ�

int gameplay(void) {
    char input;
    struct player player[MAX_PLAYERS] = { {PLAYER_X, PLAYER_Y, 6, 3} };  // x,y,�þ߳ʺ�, �þ߳���;
    struct items items[MAX_ITEMS] = { {0,0,"b-"},{0,0,"hp+"}, {0,0,"b+"},{0,0,"b"},{0,0,'l'},{0,0,'k'},{0,0,'k'} };
    HP = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        Itemcoord(&items[i], player);
        drawItem(items[i].x, items[i].y);
    }

    while (1) {



        input = movePlayer(player, items);

        if (input == BACK) return BACK;
        if (input == CLEAR) return CLEAR;
        //  if (input == FAIL) return FAIL;
        // if (input == SUBMIT) return BACK;

    }
    return 0;
}
int gameplayNormal(void) {
    char input;
    struct player player[MAX_PLAYERS] = { {PLAYER_X, PLAYER_Y, 6, 3} };  // x,y,�þ߳ʺ�, �þ߳���;
    struct items items[MAX_ITEMS] = { {0,0,"b-"},{0,0,"hp+"}, {0,0,"b+"},{0,0,"b"},{0,0,'l'},{0,0,'k'},{0,0,'k'} };
    HP = 0;

    for (int i = 0; i < MAX_ITEMS; i++) {
        Itemcoord(&items[i], player);
        drawItem(items[i].x, items[i].y);
    }

    while (1) {
        
     
    
        input = playermoveEasy(player, items);
       
        if (input == BACK) return BACK;
        if (input == CLEAR) return CLEAR;
        //  if (input == FAIL) return FAIL;
        // if (input == SUBMIT) return BACK;
        
    }
    return 0;
}


int gameplayEasy(void) {
    char input;
    struct player player[MAX_PLAYERS] = { {PLAYER_X, PLAYER_Y} };  // x,y,�þ߳ʺ�, �þ߳���;
    struct items items[MAX_ITEMS] = { {0,0,"b-"},{0,0,"hp+"}, {0,0,"b+"},{0,0,"b"},{0,0,'l'},{0,0,'k'},{0,0,'k'} };
    HP = 0;
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        Itemcoord(&items[i], player);
        drawItem(items[i].x, items[i].y);
    }

    while (1) {



        input = playermoveEasy(player, items);

        if (input == BACK) return BACK;
        if (input == CLEAR) return CLEAR;
        //  if (input == FAIL) return FAIL;
        // if (input == SUBMIT) return BACK;

    }
    return 0;
}

int playermoveEasy(struct player* player_info, struct items* item_array)
{
    int playerx = player_info[0].x;	// �÷��̾� x ��ǥ
    int playery = player_info[0].y; // �÷��̾� y ��ǥ
    drawPlayer(playerx, playery);
    while (1)
    {
        time_g(timek);
        HP_print(HP);

        int n = keyControl1();
        switch (n)
        {
        case UP:
            if (playery > 5) {
                removePlayer(playerx, playery);
                playery--;
                drawPlayer(playerx, playery);
            }
            break;
        case DOWN:
            if (playery < 21) {
                removePlayer(playerx, playery);
                playery++;
                drawPlayer(playerx, playery);
            }
            break;
        case LEFT:
            if (playerx > 23) {
                removePlayer(playerx, playery);
                playerx--;
                drawPlayer(playerx, playery);
            }
            break;
        case RIGHT:
            if (playerx < 96) {
                removePlayer(playerx, playery);
                playerx++;
                drawPlayer(playerx, playery);
            }
            break;
        case BACK:
            return BACK;
            break;
        }


        itemeatEasy(playerx, playery, item_array);
        timek = timek + 0.25;

        if (isClear(item_array) == CLEAR) return CLEAR;

        if (100 - timek <= 0)
        {
            Sleep(500);
            failStory();
            Sleep(700);
            return BACK;
        }
    }  
}

int playermoveNormal(struct player* player_info, struct items* item_array)
{
    int playerx = player_info[0].x;	// �÷��̾� x ��ǥ
    int playery = player_info[0].y; // �÷��̾� y ��ǥ
    drawPlayer(playerx, playery);
    while (1)
    {
        time_g(timek);
        HP_print(HP);

        int n = keyControl1();
        switch (n)
        {
        case UP:
            if (playery > 5) {
                removePlayer(playerx, playery);
                playery--;
                drawPlayer(playerx, playery);
            }
            break;
        case DOWN:
            if (playery < 21) {
                removePlayer(playerx, playery);
                playery++;
                drawPlayer(playerx, playery);
            }
            break;
        case LEFT:
            if (playerx > 23) {
                removePlayer(playerx, playery);
                playerx--;
                drawPlayer(playerx, playery);
            }
            break;
        case RIGHT:
            if (playerx < 96) {
                removePlayer(playerx, playery);
                playerx++;
                drawPlayer(playerx, playery);
            }
            break;
        case BACK:
            return BACK;
            break;
        }
        itemeatEasy(playerx, playery, item_array);
        timek = timek + 0.25;

        if (isClear(item_array) == CLEAR) return CLEAR;

        if (100 - timek <= 0)
        {
            Sleep(500);
            failStory();
            Sleep(700);
            return BACK;
        }
    }
}


void time_g(float time)
{
    gotoxy1(MAP_X + MAP_WIDTH - 14, MAP_Y + 1);
    printf("���� ���͸�: %.1f", (100- time));
    Setcolor(15);
}

/// <su
/// </summary>
/// <param name=""></param>
/// 
/*

void timer(void)
{
    clock_t start_time, current_time;
    double elapsed_time;

    start_time = clock();
    

    // �ǽð� Ÿ�̸� ���
    while (1) {
        current_time = clock();
        elapsed_time = ((double)(current_time - start_time)) / CLOCKS_PER_SEC;
        gotoxy(MAP_X + MAP_WIDTH - 11, MAP_Y + 1, "HP: �� �� �� ��"); //HPǥ��
        // ����� �ð� ���
        gotoxy(10, 10, " ");
        printf("\r����� �ð�: %.2f ��", 10 - elapsed_time);
        fflush(stdout);  // ��� ���۸� ����� �ǽð����� ���

        // 1�� ���
        Sleep(50);

        // ���� ���� ���� (10�� �� ����)
        if (10 - elapsed_time <= -0.001) {
            break;
        }
    }

    printf("\nŸ�̸� ����!\n");

}
*/