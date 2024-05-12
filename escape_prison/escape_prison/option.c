#include "main.h"

// 환경설정 실행 함수
void initOption() {
	int optionCode = 0;
	do {
		optionCode = selectOption();	// 사용자 입력(1: 배경음악 설정, 2: 테마 설정, 3: 뒤로가기)
	} while (optionCode < 1 || optionCode >3);

	while (1) {
		do {
			optionCode = menuDraw1(); // y - 15 = 1 ~ 4
			if (optionCode == 1) {
				setMusic();
			}
			else if (optionCode == 2) {
				setTheme();
			}
			else if (optionCode == 3) {
				//main에서는 title()만 호출하고 모드선택 프롬프트는 따로 
			}
		} while (optionCode != BACK);
	}
}

// 사용자 입력 메뉴 반환
int selectOption() {
	int x = 24, y = 16;
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇  배경음악 설정  w(UP)");   // 선택하면 난이도 선택 화면으로 이동
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("   테마 설정      a(LEFT)");     // 난이도 별 실행 및 조작법 출력
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 16);
	printf("   뒤로가기       s(DOWN)");
	gotoxy1(MAP_X * 2, MAP_Y + 18);
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
			if (y < MAP_Y + 16) {
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
void setMusic() {
	printf("음악 설정 기능");
}

// 테마 설정 기능
void setTheme() {
	printf("테마 설정 기능");
}

// 뒤로 가기
void back() {
	printf("뒤로가기");
}
