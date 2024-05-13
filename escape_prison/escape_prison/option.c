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
int selectOption(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("  배경음악 설정  w(UP)");   
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("  테마 설정      a(LEFT)");  
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
int setMusic(void) {
	resetMapInner();
	int keyInput;
	keyInput = selectMusic();
	switch (keyInput) {
	case 1:
		printf("  1번 실행됨\n");// 첫 번째 브금 실행// 첫 번째 브금 실행
		break;
	case 2:
		printf("  2번 실행\n");// 두 번째 브금 실행문 추가 예정
		// 브금 종류 추가 시 case 추가 후 select Music에 3번 음악 목록 추가
	}
	return BACK;
}

// 사용자 입력 노래 반환
int selectMusic(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇ 1번음악  w(UP)");   
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("  2번음악      a(LEFT)");    


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
int setTheme(void) {
	resetMapInner();
	int keyInput;
	keyInput = selectTheme();
	switch (keyInput) {
	case 1:
		printf("1번 실행됨\n");// 첫 번째 테마 실행문 추가 예정
		break;
	case 2:
		printf("2번 실행\n");// 두 번째 테마 실행문 추가 예정
		break;
		// 테마 종류 추가 시 case 추가 후 selectTheme에 3번 음악 목록 추가
	}
	return BACK;
}

// 사용자 입력 테마 반환
int selectTheme(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇  1번테마  w(UP)");   
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("   2번테마     a(LEFT)");    
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
