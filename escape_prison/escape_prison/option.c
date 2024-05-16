#include "main.h"

void playMusic(const char* address);
void setConsoleTheme(int textColor, int bgColor);


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
	printf("  배경음악 설정");   
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("  테마 설정");  
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
		//playMusic("첫번째 음악 /주소/주소/주소");//전체 브금 요소 끄고 첫 번째 브금 실행
		break;
	case 2:
		//playMusic("두번째 음악 /주소/주소/주소");//전체 브금 요소 끄고 두 번째 브금 실행
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
	printf("◇ 1번음악");   
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("  2번음악");    


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
		setConsoleTheme(1, 0);// 첫 번째 테마(글자색, 배경색)
		break;
	case 2:
		setConsoleTheme(0, 7);// 두 번째 테마 (글자색, 배경색)
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
	printf("◇  1번테마");   
	gotoxy1(MAP_X + (MAP_WIDTH - 9) / 2, MAP_Y + 15);
	printf("   2번테마");    
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

// 음악 파일에 접근하여 재생하는 함수 
void playMusic(const char* address) { // 음악 파일의 주소를 인수로 받는다.
	mciSendString("stop music", NULL, 0, NULL);
	mciSendString("close music", NULL, 0, NULL);// 기존에 재생되던 음악을 종료
	char command[256];
	snprintf(command, sizeof(command), "open \"%s\" type mpegvideo alias music", address);
	mciSendString(command, NULL, 0, NULL);
	mciSendString("play music repeat", NULL, 0, NULL);
}

// 콘솔의 배경과 글자색을 변경하는 함수 - 불변의 색을 정하고 싶다면 전역변수를 이용하여 고정할 것..
void setConsoleTheme(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));
}
