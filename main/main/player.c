#include "main.h"

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