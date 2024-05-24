#include "function.h"
#include "item_tail.h"


/////////////////////////////////////////////////////////////////////////////
int main() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    title();


    while (1) {
        if (_kbhit()) do { key = _getch(); } while (key == 224); //키 입력받음
        Sleep(speed);

        switch (key) { //입력받은 키를 파악하고 실행  
        case LEFT:
        case RIGHT:
        case UP:
        case DOWN:
            if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) || (dir == UP && key != DOWN) ||
                (dir == DOWN && key != UP))//180회전이동을 방지하기 위해 필요. 
                dir = key;
            key = 0; // 키값을 저장하는 함수를 reset 
            break;
        case PAUSE: // P키를 누르면 일시정지 
            pause();
            break;
        case 115: //S키를 누르면 개발자용 status를 활성화 시킴  
            if (status_on == 0) status_on = 1;
            else status_on = 0;
            key = 0;
            break;
        case ESC: //ESC키를 누르면 프로그램 종료 
            system("cls");
            printf("게임을 끝냅니다.");
            Sleep(500);
            exit(0);
        }
        int a = move(dir);
        HP_print(HP);

        if (speed <= 0)
        {
            game_over();
        }

     


  // move(dir) 반환값  -1 / 3


    }

}
