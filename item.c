#include "main.h"

void drawItem(int x, int y) {
	gotoxy1(x, y);
	Setcolor(9);
	printf("X");
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

// 아이템이 충돌되었을 때 호출되는 함수
void initItem(struct items* item_array, int playerx, int playery, int i) {
	item_array[i].x = 0;
	item_array[i].y = 0;
	strcpy_s(item_array[i].skill, sizeof(item_array[i].skill), "None");

	removeItem(item_array[i].x, item_array[i].y);
	drawPlayer(playerx, playery);
}

// 전달받은 i값에 따라서 다른 결과를 출력하는 함수

void judge_item(int i, int m, struct strider* s)
{
	int a;
	switch (i)
	{
	case 0:
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("배터리가 감소합니다");
		Sleep(500);
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("                   ");
		timek += 12; // 배터리 감소
		break;
	case 1:
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("HP가 증가합니다");
		Sleep(500);
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("                   ");
		HP += 1;  // HP가 증가한다.
		break;


	case 2:
	case 3:
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("배터리가 증가합니다");
		Sleep(500);
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("                   ");
		timek -= 20; // 배터리 증가 
		break;

	case 4:
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("경비병이 증가합니다");
		Sleep(500);
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("                   ");
		s[2].on = 0;
		break;

	case 5:
	case 6:
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("열쇠를 찾았습니다!");
		Sleep(500);
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("                  ");
		break;
	default:
		a = minigame(m);

		if (a >= 1)
			break;
		else
		{
			gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
			printf("(-. - ) 쯧쯧..... 운이 없네요");
			Sleep(1000);
			gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
			printf("                                  ");
			break;
		}

	};
}

void judge_easy_item(int i)
{
	int a;
	switch (i)
	{
	case 1:
	case 2:
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("(-. - ) 꽝! 열쇠 위치가 바뀌네요");
		Sleep(500);
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("                                  ");
		break;
	case 5:
	case 6:
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("열쇠를 찾았습니다!");
		Sleep(500);
		gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
		printf("                  ");
		break;
	default:
		a = minigame(0);

		if (a >= 1)
			break;
		else
		{
			gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
			printf("(-. - ) 쯧쯧..... 운이 없네요");
			Sleep(1000);
			gotoxy1(MAP_X * 2 + 4, MAP_Y + MAP_HEIGHT - 4);
			printf("                                  ");
			break;
		}
	};
}

void eatItem(struct player player_info, struct items* item_array, struct strider* s, int playerx, int playery) {
	int sw = player_info.sw;
	int sh = player_info.sh;
	for (int i = 0; i < MAX_ITEMS; i++) {

		if (item_array[i].x <= playerx + player_info.sw && item_array[i].x >= playerx - player_info.sw
			&& item_array[i].y <= playery + player_info.sh && item_array[i].y >= playery - player_info.sh)
		{
			//gotoxy(0, 28, "FIND");
			drawItem(item_array[i].x, item_array[i].y); // 시야 범위에 들어오면 아이템 출력
			if (item_array[i].x == playerx && item_array[i].y == playery) {
				// 충돌 시 배열 0,0,None로 초기화, 아이템 지우고 캐릭터 다시 그리기
				judge_item(i, 2, s);
				initItem(item_array, playerx, playery, i);
			}
		}
		else {
			removeItem(item_array[i].x, item_array[i].y); // 시야 범위 밖에 나가면 아이템 지우기

		}
	}
}

void eatItemStrider(struct strider* strider_info, struct items* item_array, int mode) {
	int new_x, new_y;
	int unique;
	for (int i = 0; i < MAX_ITEMS; i++) {
		if ((strider_info[0].sx <= item_array[i].x &&
			strider_info[0].sx + 6 >= item_array[i].x &&
			strider_info[0].sy == item_array[i].y) ||
			(strider_info[1].sx == item_array[i].x &&
				strider_info[1].sy <= item_array[i].y &&
				strider_info[1].sy + 3 >= item_array[i].y) ||
			(strider_info[2].sx <= item_array[i].x &&
				strider_info[2].sx + 6 >= item_array[i].x &&
				strider_info[2].sy == item_array[i].y)
			)
		{
			do {
				new_x = rand() % (MAP_WIDTH * 2 - 4) + 23;
				new_y = rand() % (MAP_HEIGHT - 9) + 5;
				unique = 1; // 중복되지 않을 때

				// 아이템 배열에서 중복 여부 확인
				for (int j = 0; j < MAX_ITEMS; j++) {
					if (i != j && item_array[j].x == new_x && item_array[j].y == new_y) {
						unique = 0; // 중복 있으면 다시 반복문
						break;
					}
				}
			} while (!unique); // 중복이 없을 때까지 반복
			item_array[i].x = new_x;
			item_array[i].y = new_y;

			if (mode == NORMAL) drawItem(item_array[i].x, item_array[i].y); // 노멀 모드에서만 그림
		}
	}
}

void itemeatEasy(int playerx, int playery, struct items* item_array)
{
	for (int i = 0; i < MAX_ITEMS_E; i++) {
		if (item_array[i].x == playerx && item_array[i].y == playery)
		{
			for (int j = 0; j < MAX_ITEMS_E; j++) {
				removeItem(item_array[j].x, item_array[j].y);
			}
			judge_easy_item(i);
			for (int j = 0; j < MAX_ITEMS_E; j++) {
				if (j != i && (strcmp(item_array[j].skill, "None") != 0)) {
					item_array[j].x = rand() % (MAP_WIDTH * 2 - 4) + 23;
					item_array[j].y = rand() % (MAP_HEIGHT - 9) + 5;
					drawItem(item_array[j].x, item_array[j].y);
				}
			}
			initItem(item_array, playerx, playery, i);
		}
	}
}

void itemeatNormal(int playerx, int playery, struct items* item_array, struct strider* s)
{
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (item_array[i].x == playerx && item_array[i].y == playery)
		{
			judge_item(i, 1, s);
			initItem(item_array, playerx, playery, i);
		}
	}
}