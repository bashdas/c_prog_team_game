#include "function.h"
#include "item_tail.h"


/////////////////////////////////////////////////////////////////////////////
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

        if (speed <= 0)
        {
            game_over();
        }

     


  // move(dir) ��ȯ��  -1 / 3


    }

}
