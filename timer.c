#include "main.h"

#define TOTAL_TIME 10

int timer(void) {
    clock_t start_time, current_time;
    double elapsed_time;

    // 타이머 시작 시간 기록
    start_time = clock();

    // 실시간 타이머 출력
    while (1) {
        current_time = clock();
        elapsed_time = ((double)(current_time - start_time)) / CLOCKS_PER_SEC;
        // 경과된 시간 출력
        gotoxy1(MAP_X * 2 + MAP_WIDTH - 4, MAP_Y + 1);
        printf("%.2f 초", 10 - elapsed_time);
        gotoxy1(MAP_X * 2 + MAP_WIDTH - 4, MAP_Y + 1);
        fflush(stdout);  // 출력 버퍼를 비워서 실시간으로 출력

        // 1초 대기
        Sleep(50);

        // 종료 조건 예시 (10초 후 종료)
        if (TOTAL_TIME - elapsed_time <= -0.01) {
            break;
        }
    }
    return FAIL;
}
