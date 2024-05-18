#include "main.h"

void playMusic(const char* address);


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
	selectOptionContent(2, 7);
	gotoxy1((MAP_X+1) * 2, y);
	printf("\b");
	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1((MAP_X + 1) * 2, y);
				printf(" ");
				y--;
				if (y == MAP_Y + 14) selectOptionContent(2, 7);
				gotoxy1((MAP_X + 1) * 2, y);
				printf("\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 15) {
				gotoxy1((MAP_X + 1) * 2, y);
				printf(" ");
				y++;
				if (y == MAP_Y + 15) selectOptionContent(7, 2);
				gotoxy1((MAP_X + 1) * 2, y);
				printf("\b");
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

int selectOptionContent(int c1, int c2) {
	resetMapInner();
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 3, "♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 4, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 5, "♣           !Option Menu!            ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 6, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 7, "♣  You can change the game option    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 8, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 9, "♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣");
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "▼  Select from the menu  ▼");
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH + 4, MAP_Y + 14);
	printf("배경 음악 설정");
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH + 6, MAP_Y + 16);
	printf("테마 설정");
	Setcolor(7);
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 18);
	printf("**** spacebar to select ****");
}

// 음악 설정 기능
int setMusic(void) {
	resetMapInner();
	int keyInput;
	keyInput = selectMusic();
	switch (keyInput) {
	case 1:
		PlaySound(TEXT("c_team_bgm1.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//첫 번째 브금 실행
		break;
	case 2:
		PlaySound(TEXT("c_team_bgm2.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//두 번째 브금 실행
		break;
	case 3:
		PlaySound(TEXT("c_team_bgm3.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//두 번째 브금 실행
		break;
	case 4:
		PlaySound(TEXT("c_team_bgm4.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//두 번째 브금 실행
		break;

		// 브금 종류 추가 시 case 추가 후 select Music에 3번 음악 목록 추가
	}
	return BACK;
}

// 사용자 입력 노래 반환
int selectMusic(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	selectMusicContent(2,7,7,7);
	gotoxy1((MAP_X + 1) * 2, y);
	printf("\b");

	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1((MAP_X + 1) * 2, y);
				printf(" ");
				--y;
				if (y == MAP_Y + 14) selectMusicContent(2, 7, 7, 7);
				else if (y == MAP_Y + 15) selectMusicContent(7, 2, 7, 7);
				else if (y == MAP_Y + 16) selectMusicContent(7, 7, 2, 7);
				gotoxy1((MAP_X + 1) * 2, y);
				printf("\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 17) {
				gotoxy1((MAP_X + 1) * 2, y);
				printf(" ");
				y++;
				if (y == MAP_Y + 15) selectMusicContent(7, 2, 7, 7);
				else if (y == MAP_Y + 16) selectMusicContent(7, 7, 2, 7);
				else if (y == MAP_Y + 17) selectMusicContent(7, 7, 7, 2);
				gotoxy1((MAP_X + 1) * 2, y);
				printf("\b");
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

void selectMusicContent(int c1, int c2, int c3, int c4) {
	resetMapInner();
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 3, "♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 4, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 5, "♣            !Music Menu!            ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 6, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 7, "♣   You can change the game music    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 8, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 9, "♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣");
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "▼  Select from the menu  ▼");
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH+8, MAP_Y + 14);
	printf("1번음악");
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH+8, MAP_Y + 15);
	printf("2번음악");
	Setcolor(c3);
	gotoxy1(MAP_X + MAP_WIDTH+8, MAP_Y + 16);
	printf("3번음악");
	Setcolor(c4);
	gotoxy1(MAP_X + MAP_WIDTH+8, MAP_Y + 17);
	printf("4번음악");
	Setcolor(7);
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
}

// 테마 설정 기능
int setTheme() {
	resetMapInner();
	int keyInput;
	keyInput = selectTheme();
	switch (keyInput) {
	case 1:
		*ptheme = 1;//파란색
		break;
	case 2:
		*ptheme = 5;//자주색
		break;
	case 3:
		*ptheme = 6;//노란색
		break;
	case 4:
		*ptheme = 15;//밝은 흰색
		break;
	}
	return BACK;
}

// 사용자 입력 테마 반환
int selectTheme(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	selectThemeContent(1, 7, 7, 7);
	gotoxy1((MAP_X + 1) * 2, y);
	printf("\b");

	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1((MAP_X + 1) * 2, y);
				printf(" ");
				--y;
				if (y == MAP_Y + 14) selectThemeContent(1, 7, 7, 7);
				else if (y == MAP_Y + 15) selectThemeContent(7, 5, 7, 7);
				else if (y == MAP_Y + 16) selectThemeContent(7, 7, 6, 7);
				gotoxy1((MAP_X + 1) * 2, y);
				printf("\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 17) {
				gotoxy1((MAP_X + 1) * 2, y);
				printf(" ");
				y++;
				if (y == MAP_Y + 15) selectThemeContent(7, 5, 7, 7);
				else if (y == MAP_Y + 16) selectThemeContent(7, 7, 6, 7);
				else if (y == MAP_Y + 17) selectThemeContent(7, 7, 7, 15);
				gotoxy1((MAP_X + 1) * 2, y);
				printf("\b");
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

void selectThemeContent(int c1, int c2, int c3, int c4) {
	resetMapInner();
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 3, "♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 4, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 5, "♣            !Theme Menu!            ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 6, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 7, "♣   You can change the game Theme    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 8, "♣                                    ♣");
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2, MAP_Y + 9, "♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣");
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "▼  Select from the menu  ▼");
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 14);
	printf("사파이어");
	Setcolor(1);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 14);
	printf("■");
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 15);
	printf("자수정 ");
	Setcolor(5);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 15);
	printf("■");
	Setcolor(c3);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 16);
	printf("토파즈 ");
	Setcolor(6);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 16);
	printf("■");
	Setcolor(c4);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 17);
	printf("다이아몬드");
	Setcolor(15);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 17);
	printf("■");
	Setcolor(7);
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
}

/*
// 음악 파일에 접근하여 재생하는 함수
void playMusic(const char* address) { // 음악 파일의 주소를 인수로 받는다.
	char command[256];
	snprintf(command, sizeof(command), "%s", address);
	printf("%s", command);
	PlaySound(command, NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);
	while (1) {
		Sleep(10000);
	}
}
*/
