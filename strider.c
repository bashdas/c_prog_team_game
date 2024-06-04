#include "main.h"

/*
	경비병 관련 소스파일
*/

void stridercoord(struct strider* strider, struct player player) {
	int x, y;
	do {
		x = rand() % (MAP_WIDTH * 2 - 9) + 23;
		y = rand() % (MAP_HEIGHT - 9) + 5;
	} while (x >= player.x - player.sw && x <= player.x + player.sw &&
		y >= player.y - player.sh && y <= player.y + player.sh);

	strider->sx = x;
	strider->sy = y;
}

void drawLRStrider(int x, int y, int right, int left) {
	char strider[1][14] = {"o o o o"};
	int striderx = x, stridery = y;
	gotoxy1(striderx, stridery);
	for (int i = 0 + left; i < right; i++) {
		putchar(strider[0][i]);
		fflush(stdout);
	}
}

void drawUDStrider(int x, int y, int upper, int bottom) {
	char strider[4][2] = {
		"o",
		"o",
		"o",
		"o"
	};
	int striderx = x, stridery = y;
	for (int i = 0 + upper; i < bottom; i++) {
		gotoxy1(striderx, stridery);
		for (int j = 0; j < 2; j++) {
			putchar(strider[i][j]);
			fflush(stdout);
		}
		stridery += 1;
	}
}

void removeLRStrider(int x, int y, int right, int left) {
	char charsight[1][14] = {"       "};
	int striderx = x, stridery = y;
	gotoxy1(striderx, stridery);
	for (int i = 0 + left; i < right; i++) {
		putchar(charsight[0][i]);
		fflush(stdout);
	}
}

void removeUDStrider(int x, int y, int upper, int bottom) {
	char strider[4][2] = {
		" ",
		" ",
		" ",
		" "
	};
	int striderx = x, stridery = y;
	for (int i = 0 + upper; i < bottom; i++) {
		gotoxy1(striderx, stridery);
		for (int j = 0; j < 2; j++) {
			putchar(strider[i][j]);
			fflush(stdout);
		}
		stridery += 1;
	}
}

void moveLRStrider(struct strider* strider_info) {
	int striderx = strider_info[0].sx;
	int stridery = strider_info[0].sy;
	if (striderx <= MAP_X * 2 + 2) {
		removeLRStrider(striderx, stridery, 7, 0);
		strider_info[0].sy = rand() % (MAP_HEIGHT - 9) + 5;
		strider_info[0].sx = (MAP_WIDTH * 2 - 8) + MAP_X * 2 - 1;
		drawLRStrider(strider_info[0].sx, strider_info[0].sy, 7, 0);
	}
	else if (striderx <= (MAP_WIDTH * 2 - 8) + MAP_X * 2 && striderx > MAP_X * 2 + 2) {
		removeLRStrider(striderx + 5, stridery, 7, 5);
		strider_info[0].sx -= 2;
		drawLRStrider(strider_info[0].sx, stridery, 2, 0);
	}
	if (strider_info[2].on == 0) {
		int striderx1 = strider_info[2].sx;
		int stridery1 = strider_info[2].sy;
		if (striderx1 <= MAP_X * 2 + 2) {
			removeLRStrider(striderx1, stridery1, 7, 0);
			strider_info[2].sy = rand() % (MAP_HEIGHT - 9) + 5;
			strider_info[2].sx = (MAP_WIDTH * 2 - 8) + MAP_X * 2 - 1;
			drawLRStrider(strider_info[2].sx, strider_info[2].sy, 7, 0);
		}
		else if (striderx1 <= (MAP_WIDTH * 2 - 8) + MAP_X * 2 && striderx1 > MAP_X * 2 + 2) {
			removeLRStrider(striderx1 + 5, stridery1, 7, 5);
			strider_info[2].sx -= 2;
			drawLRStrider(strider_info[2].sx, stridery1, 2, 0);
		}
	}
}

void moveUDStrider(struct strider* strider_info) {
	int striderx = strider_info[1].sx;
	int stridery = strider_info[1].sy;
	if (stridery <= MAP_Y + 3) {
		removeUDStrider(striderx, stridery, 0, 4);
		strider_info[1].sx = rand() % (MAP_WIDTH * 2 - 9) + 23;
		strider_info[1].sy = MAP_Y + MAP_HEIGHT - 10;
		drawUDStrider(strider_info[1].sx, strider_info[1].sy, 0, 4);
	}
	else if (stridery <= MAP_Y + MAP_HEIGHT - 10 && stridery > MAP_Y + 3) {
		removeUDStrider(striderx, stridery, 0, 4);
		strider_info[1].sy -= 1;
		drawUDStrider(striderx, strider_info[1].sy, 0, 4);
	}
}

// 경비병과 플레이어 충돌 처리 함수
int CDStrider(int px, int py, struct strider* strider_info) {
	if (strider_info[0].sx - 6 <= px && strider_info[0].sx + 12 >= px && strider_info[0].sy - 3 <= py && strider_info[0].sy + 3 >= py)
	{
		// 1번 좌우 경비병이 플레이어 시야 범위에 들어온 경우
		drawLRStrider(strider_info[0].sx, strider_info[0].sy, 7, 0); // 해당 경비병을 다시 그림(지워지는거 방지)
		if ((strider_info[0].sx <= px && strider_info[0].sx + 7 >= px && strider_info[0].sy == py)|| // 1번 좌우 경비병의 범위에 들어옴
			(strider_info[1].sx == px && strider_info[1].sy <= py && strider_info[1].sy + 3 >= py)|| // 1번 상하 경비병의 범위에 들어옴
			(strider_info[2].sx <= px && strider_info[2].sx + 7 >= px && strider_info[2].sy == py)) { return FAIL_V; } // 2번 좌우 경비병의 범위에 들어옴 -> 충돌처리
		if ((strider_info[0].sx + 8 == px && strider_info[0].sy == py)) { drawPlayer(px, py); } // 플레이어 지워지는거 방지
		if (strider_info[1].sx == px && strider_info[1].sy + 4 == py) { drawPlayer(px, py); } // 플레이어 지워지는거 방지
		if ((strider_info[2].sx + 8 == px && strider_info[2].sy == py)) { drawPlayer(px, py); } // 플레이어 지워지는거 방지
	}
	else if (strider_info[1].sx - 6 <= px && strider_info[1].sx + 6 >= px && strider_info[1].sy -3 <= py && strider_info[1].sy +6>= py)
	{
		// 1번 상하 경비병이 플레이어 시야 범위에 들어온 경우
		drawUDStrider(strider_info[1].sx, strider_info[1].sy, 4, 0); // 해당 경비병을 다시 그림
		// 1번 좌우 경비병의 범위에 들어온 경우가 없는 이유는 이 경우 첫번째 조건문으로 가기 때문에
		if ((strider_info[1].sx == px && strider_info[1].sy <= py && strider_info[1].sy + 3 >= py)|| // 1번 상하 경비병의 범위에 들어옴
			(strider_info[2].sx <= px && strider_info[2].sx + 7 >= px && strider_info[2].sy == py)) { return FAIL_V; } // 2번 좌우 경비병에 범위에 들어옴 -> 충돌처리
		if (strider_info[1].sx == px && strider_info[1].sy + 4 == py) { drawPlayer(px,py); }
	}
	if (strider_info[2].on == 0) {
		// 2번 좌우 경비병이 생긴 경우에만 실행
		if (strider_info[2].sx - 6 <= px && strider_info[2].sx + 12 >= px && strider_info[2].sy - 3 <= py && strider_info[2].sy + 3 >= py)
		{
			drawLRStrider(strider_info[2].sx, strider_info[2].sy, 7, 0);
			if ((strider_info[2].sx <= px && strider_info[2].sx + 7 >= px && strider_info[2].sy == py)) { return FAIL_V; }
			if ((strider_info[2].sx + 8 == px && strider_info[2].sy == py)) { drawPlayer(px, py); }
		}
	}
	return 0;
}
