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
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("  배경음악 설정 ");
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("  테마 설정  ");
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
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇ 1번음악 ");
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("  2번음악  ");
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 16);
	printf("  3번음악  ");
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 17);
	printf("  4번음악  ");

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
			if (y < MAP_Y + 17) {
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
	resetMapInner();
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 14);
	printf("◇  사파이어 ");
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("   자수정 ");
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 16);
	printf("   토파즈 ");
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 17);
	printf("   다이아몬드");
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
			if (y < MAP_Y + 17) {
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
