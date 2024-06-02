#include "main.h"

// void playMusic(const char* address);

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
			if (optionCode == OPTION1) {
				subjectCode = setMusic();

			}
			else if (optionCode == OPTION2) {
				subjectCode = setTheme();
			}
		}
	} while (optionCode != BACK);
}

// 사용자 키 입력 상호작용 OPTION1, OPTION2 반환
int selectOption(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	selectOptionContent();
	selectOptionContent2(2, 7);
	gotoxy1((MAP_X + 14) * 2, y);
	printf("☞\b\b");
	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1((MAP_X + 14) * 2, y);
				printf(" ");
				y -= 2;
				if (y == MAP_Y + 14) selectOptionContent2(2, 7);
				gotoxy1((MAP_X + 14) * 2, y);
				printf("☞\b\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 16) {
				gotoxy1((MAP_X + 14) * 2, y);
				printf(" ");
				y += 2;
				if (y == MAP_Y + 16) selectOptionContent2(7, 2);
				gotoxy1((MAP_X + 14) * 2, y);
				printf("☞\b\b");
			}
			break;
		}
		case BACK:
			return BACK;
		case SUBMIT: {
			if (y == MAP_Y + 14) return OPTION1;
			else if (y == MAP_Y + 16) return OPTION2;
			else return BACK;
		}
		}
	}
}

int selectOptionContent(void) {
	resetMapInner();
	titleBoxDraw();
	Setcolor(15);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 6, MAP_Y + 5, "!Option Menu!");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 2, MAP_Y + 7, "You can change the game option");
	Setcolor(8);
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "▼  Select from the menu  ▼");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 18);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

int selectOptionContent2(int c1, int c2) {
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH + 4, MAP_Y + 14);
	printf("배경 음악 설정");
	if (c1 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 82) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 82) / 2, MAP_Y + 14);
		printf(" ");
	}
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH + 6, MAP_Y + 16);
	printf("테마 설정");
	if (c2 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 82) / 2, MAP_Y + 16);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 82) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(7);
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
	selectMusicContent();
	selectMusicContent2(2, 7, 7, 7);
	gotoxy1((MAP_X + 16) * 2, y);
	printf("☞\b\b");

	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1((MAP_X + 16) * 2, y);
				printf(" ");
				--y;
				if (y == MAP_Y + 14) selectMusicContent2(2, 7, 7, 7);
				else if (y == MAP_Y + 15) selectMusicContent2(7, 2, 7, 7);
				else if (y == MAP_Y + 16) selectMusicContent2(7, 7, 2, 7);
				gotoxy1((MAP_X + 16) * 2, y);
				printf("☞\b\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 17) {
				gotoxy1((MAP_X + 16) * 2, y);
				printf(" ");
				y++;
				if (y == MAP_Y + 15) selectMusicContent2(7, 2, 7, 7);
				else if (y == MAP_Y + 16) selectMusicContent2(7, 7, 2, 7);
				else if (y == MAP_Y + 17) selectMusicContent2(7, 7, 7, 2);
				gotoxy1((MAP_X + 16) * 2, y);
				printf("☞\b\b");
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

void selectMusicContent(void) {
	resetMapInner();
	titleBoxDraw();
	Setcolor(15);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 6, MAP_Y + 5, " !Music Menu!");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 2, MAP_Y + 7, "You can change the game music");
	Setcolor(8);
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "▼  Select from the menu  ▼");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

void selectMusicContent2(int c1, int c2, int c3, int c4) {
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH + 8, MAP_Y + 14);
	printf("1번음악");
	if (c1 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 14);
		printf(" ");
	}
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH + 8, MAP_Y + 15);
	printf("2번음악");
	if (c2 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 15);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 15);
		printf(" ");
	}
	Setcolor(c3);
	gotoxy1(MAP_X + MAP_WIDTH + 8, MAP_Y + 16);
	printf("3번음악");
	if (c3 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 16);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(c4);
	gotoxy1(MAP_X + MAP_WIDTH + 8, MAP_Y + 17);
	printf("4번음악");
	if (c4 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 17);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 17);
		printf(" ");
	}
	Setcolor(7);
}

// 테마 설정 기능
int setTheme(void) {
	int keyInput;
	keyInput = selectTheme();
	printf("%d", keyInput);
	switch (keyInput) {
	case THEME1:
		theme = 1;//파란색
		break;
	case THEME2 :
		theme = 5;//자주색
		break;
	case THEME3:
		theme = 6;//노란색
		break;
	case THEME4:
		theme = 15;//밝은 흰색
		break;
	case THEME0:
		theme = 7;//기본 흰색
		break;
	}
	reset();
	return BACK;
}

// 사용자 입력 테마 반환
int selectTheme(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	selectThemeContent();
	selectThemeContent2(1, 7, 7, 7, 7);
	gotoxy1((MAP_X + 13) * 2, y);
	printf("☞\b\b");

	while (1)
	{
		int n = keyControl1();
		switch (n) {
		case UP: {
			if (y > MAP_Y + 14) {
				gotoxy1((MAP_X + 13) * 2, y);
				printf(" ");
				--y;
				if (y == MAP_Y + 14) selectThemeContent2(1, 7, 7, 7, 7);
				else if (y == MAP_Y + 15) selectThemeContent2(7, 5, 7, 7, 7);
				else if (y == MAP_Y + 16) selectThemeContent2(7, 7, 6, 7, 7);
				else if (y == MAP_Y + 17) selectThemeContent2(7, 7, 7, 15, 7);
				gotoxy1((MAP_X + 13) * 2, y);
				printf("☞\b\b");
			}
			break;
		}
		case DOWN: {
			if (y < MAP_Y + 18) {
				gotoxy1((MAP_X + 13) * 2, y);
				printf(" ");
				y++;
				if (y == MAP_Y + 15) selectThemeContent2(7, 5, 7, 7, 7);
				else if (y == MAP_Y + 16) selectThemeContent2(7, 7, 6, 7, 7);
				else if (y == MAP_Y + 17) selectThemeContent2(7, 7, 7, 15, 7);
				else if (y == MAP_Y + 18) selectThemeContent2(7, 7, 7, 7, 8);
				gotoxy1((MAP_X + 13) * 2, y);
				printf("☞\b\b");
			}
			break;
		}
		case BACK:
			return BACK;
		case SUBMIT: {
			if (y == MAP_Y + 14) return THEME1;
			else if (y == MAP_Y + 15) return THEME2;
			else if (y == MAP_Y + 16) return THEME3;
			else if (y == MAP_Y + 17) return THEME4;
			else if (y == MAP_Y + 18) return THEME0;
			else return BACK;
		}
		}
	}
}

void selectThemeContent(void) {
	resetMapInner();
	titleBoxDraw();
	Setcolor(15);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 6, MAP_Y + 5, " !Theme Menu!");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 2, MAP_Y + 7, "You can change the game Theme");
	Setcolor(8);
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "▼  Select from the menu  ▼");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

void selectThemeContent2(int c1, int c2, int c3, int c4, int c5) {
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 14);
	printf("사파이어");
	Setcolor(1);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 14);
	printf("■");
	if (c1 == 1) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		printf(" ");
	}
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 15);
	printf("자수정 ");
	Setcolor(5);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 15);
	printf("■");
	if (c2 == 5) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		printf(" ");
	}
	Setcolor(c3);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 16);
	printf("토파즈 ");
	Setcolor(6);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 16);
	printf("■");
	if (c3 == 6) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(c4);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 17);
	printf("다이아몬드");
	Setcolor(15);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 17);
	printf("■");
	if (c4 == 15) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		printf(" ");
	}
	Setcolor(c5);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 18);
	printf("기본배경");
	Setcolor(7);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 18);
	printf("■");
	if (c5 == 8) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 18);
		Setcolor(7);
		printf("☜");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 18);
		printf(" ");
	}
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
