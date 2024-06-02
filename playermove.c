#include "main.h"

/*
�÷��̾� �̵�
- �÷��̾� ��ǥ ������ ������ ����
- ������ ��ǥ �ʿ� -> �̵��ϸ鼭 �÷��̾� ��ǥ�� ������ ��ǥ ���� ������ ������ ������ ���, �浹 �� �����

*/

// �þ߰� ���Ե� �Լ�.
int movePlayer(struct player* player_info, struct items* item_array, struct strider* strider_info) {
    int playerx = player_info[0].x;	// �÷��̾� x ��ǥ
    int playery = player_info[0].y; // �÷��̾� y ��ǥ
    int curx = playerx; // ���� ��ǥ x
    int cury = playery; // ���� ��ǥ  y // MAP_X * 2 + 7, MAP_HEIGHT / 2 + 5
    int upper = 0, bottom = 7, left = 0, right = 14; // �÷��̾� �þ� �迭�� ��ŭ ���� ��


    drawPlayerSight(playerx, playery, bottom, right, upper, left);
    drawPlayer(playerx, playery);

    gotoxy1(0, 21);
    printf("%d", strider_info[0].sx);

    while (1)
    {
        time_g(timek);
        HP_print(HP);
        int n = keyControl1();
        switch (n) {
        case UP: {
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
            /*
            case SUBMIT: {
                return SUBMIT; // ó�� �ؾ���

            }*/
        }

        // �����۰� �÷��̾� �浹 �� ������ ȹ�� ó��
        eatItem(*player_info, item_array, strider_info, playerx, playery);
        eatItemStrider(strider_info, item_array, HARD);
        // Ű �Է� �� ��񺴵� �̵�
        moveLRStrider(strider_info);
        moveUDStrider(strider_info);
        CDStrider(playerx, playery, strider_info);


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

        gotoxy1(0, 5);
        printf("HP: %d", HP);
        gotoxy1(0, 15);
        printf("S1: %d %d\n", strider_info[0].sx, strider_info[0].sy);
        printf("S2: %d %d", strider_info[1].sx, strider_info[1].sy);
       

        // Ŭ���� -> Ŭ���� ��ȯ return CLEAR;
        // ���� ȹ�� �� ���� ���� 
        if (isClear(item_array) == CLEAR_V) return CLEAR_V;


        if (100 - timek <= 0) return FAIL_V;
        // ���� -> ���� ��ȯ returb FAIL;
        // 
        // ���� �ð� ������ -1 ���, ���� �ð� �߰� �ο�

    }
}

int playermoveNormal(struct player* player_info, struct items* item_array, struct strider* strider_info)
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
        moveLRStrider(strider_info);
        moveUDStrider(strider_info);
        CDStrider(playerx, playery, strider_info);
        itemeatNormal(playerx, playery, item_array, strider_info);
        eatItemStrider(strider_info, item_array, NORMAL);
        timek = timek + 0.25;
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

        gotoxy1(0, 5);
        printf("HP: %d", HP);
        gotoxy1(0, 15);
        printf("S1: %d %d\n", strider_info[0].sx, strider_info[0].sy);
        printf("S2: %d %d", strider_info[1].sx, strider_info[1].sy);
        if (isClear(item_array) == CLEAR_V) return CLEAR_V;

        if (100 - timek <= 0) return FAIL_V;
    }
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
        timek = timek + 0.5;

        if (isClear(item_array) == CLEAR_V) return CLEAR_V;

        if (100 - timek <= 0) return FAIL_V;
    }
}