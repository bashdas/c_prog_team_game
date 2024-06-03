#include "main.h"

/*
캐릭터 중심 그리기
  - 캐릭터 좌표 위치에 그리기,
  - 캐릭터 현재 위치 좌표
*/
void drawPlayer(int x, int y) {
    gotoxy1(x, y);
    Setcolor(4);
    printf("◆\b");
    Setcolor(7);
}

void removePlayer(int x, int y) {
    gotoxy1(x, y);
    Setcolor(4);
    printf(" ");
    Setcolor(7);
}

/*
캐릭터 시야 그리기
  - 캐릭터 좌표 위치에서 일정 거리만큼 띄어지게 그리기
  - player 현재 위치 좌표
  - upper ~ bottom 까지
  - left ~ right 까지
*/
void drawPlayerSight(int x, int y, int bottom, int right, int upper, int left) {
    int sightx = x - 6;
    int sighty = y - 3;
    char charsight[7][14] = { // 중앙 6,3 -> 캐릭터 중심으로 부터 x-6, y-3위치부터 시야 그리기 시작
        "* * * * * * *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "*           *\0",
        "* * * * * * *\0"
    };
    // 캐릭터 시야 그리기
    for (int i = 0 + upper; i < bottom; i++) {
        gotoxy1(sightx, sighty);
        for (int j = 0 + left; j < right; j++) {
            putchar(charsight[i][j]);
            fflush(stdout);
        }
        gotoxy1(x, y); // 마우스 커서 위치 변경
        sighty += 1;
    }
}

/*
캐릭터 시야 지우기 -> 캐릭터도 같이 지움
  - drawPlayerSight 동작원리 같음
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
        gotoxy1(x, y); // 마우스 커서 위치 변경
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


    // 실시간 타이머 출력
    while (1) {
        current_time = clock();
        elapsed_time = ((double)(current_time - start_time)) / CLOCKS_PER_SEC;
        gotoxy(MAP_X + MAP_WIDTH - 11, MAP_Y + 1, "HP: ♥ ♥ ♥ ♥"); //HP표시
        // 경과된 시간 출력
        gotoxy(10, 10, " ");
        printf("\r경과된 시간: %.2f 초", 10 - elapsed_time);
        fflush(stdout);  // 출력 버퍼를 비워서 실시간으로 출력

        // 1초 대기
        Sleep(50);

        // 종료 조건 예시 (10초 후 종료)
        if (10 - elapsed_time <= -0.001) {
            break;
        }
    }

    printf("\n타이머 종료!\n");

}
*/