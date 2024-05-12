#include "main.h"

// 환경설정 실행 함수
void initOption() {
	int optionCode = 0, subjectCode = -1;
	do {
		optionCode = selectOption();
		if (optionCode == BACK) {
			break;
		}
		subjectCode = -1;
		while (subjectCode != BACK) {
			if (optionCode == 1) {
				subjectCode = setMusic();

			}
			else if (optionCode == 2) {
				subjectCode = setTheme();
			}
		}
	} while (optionCode != BACK);
}

// 사용자 입력 메뉴 반환
int selectOption() {
	int x = 24, y = 16;
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇  배경음악 설정  w(UP)");   // 선택하면 난이도 선택 화면으로 이동
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("   테마 설정      a(LEFT)");     // 난이도 별 실행 및 조작법 출력
	gotoxy1(MAP_X * 2, MAP_Y + 17);
	printf("■      **** spacebar to select ****     ");

	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, --y);
				printf("◇\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 15) {
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, ++y);
				printf("◇\b");
			}
			break;
		}
		case BACK:
			return BACK;
		case SUBMIT: {
			return y - 15;
		}
		}
	}
}

// 음악 설정 기능
int setMusic() {
	resetMapInner();
	int keyInput;
	keyInput = selectMusic();
	switch (keyInput) {
	case 1:
		printf("1번 실행됨\n");
		break;
	case 2:
		printf("2번 실행\n");
		break;
	}
	return BACK;
}

// 사용자 입력 노래 반환
int selectMusic() {
	int x = 24, y = 16;
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇  1번음악  w(UP)");   // 선택하면 난이도 선택 화면으로 이동
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("   2번음악      a(LEFT)");     // 난이도 별 실행 및 조작법 출력
	gotoxy1(MAP_X * 2, MAP_Y + 17);
	printf("■      **** spacebar to select ****     ");

	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, --y);
				printf("◇\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 15) {
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, ++y);
				printf("◇\b");
			}
			break;
		}
		case BACK:
			return BACK;
		case SUBMIT: {
			return y - 15;
		}
		}
	}
}

// 테마 설정 기능
int setTheme() {
	resetMapInner();
	int keyInput;
	keyInput = selectTheme();
	switch (keyInput) {
	case 1:
		printf("1번 실행됨\n");
		break;
	case 2:
		printf("2번 실행\n");
		break;
	}
	return BACK;
}

// 사용자 입력 테마 반환
int selectTheme() {
	int x = 24, y = 16;
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇  1번테마  w(UP)");   // 선택하면 난이도 선택 화면으로 이동
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("   2번테마     a(LEFT)");     // 난이도 별 실행 및 조작법 출력
	gotoxy1(MAP_X * 2, MAP_Y + 17);
	printf("■      **** spacebar to select ****     ");

	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, --y);
				printf("◇\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 15) {
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, y);
				printf(" ");
				gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, ++y);
				printf("◇\b");
			}
			break;
		}
		case BACK:
			return BACK;
		case SUBMIT: {
			return y - 15;
		}
		}
	}
}
