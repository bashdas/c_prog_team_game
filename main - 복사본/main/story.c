#include "main.h"
/*
	스토리 소스파일
		- void titleStory(void)
		- void easyStory(void)
		- void normalStory(void)
		- void hardStory(void)
		- int clearStory(void) : HOME 반환
		- int failStory(void) : HOME 반환
*/

void titleStory(void) {
	wchar_t titlestr[MAX_ROWS][MAX_COLS] = {
		L"우리의 건국이는 동굴 속에 보물이",
		L"있다는 소식을 듣고 보물을 찾으러",
		L"혼자서 동굴 탐험을 시작합니다...",
		L"귀한 보물을 찾으러 건국이는 점점",
		L"으슥하고 깊은 곳으로 들어갑니다.",
		L"그 순간... 쿵!!!!! 철컥!",
		L"어디선가 생긴 철문이 내려오더니",
		L"건국이는 지하감옥에 갇히고맙니다.",
		L"***\'지하감옥\'***",
		L"배터리가 떨어진 손정든 사이로",
		L"지하감옥이라는 글귀가 보이고",
		L"건국이는 그제야 이 모든 것이",
		L"함정이었음을 깨닫습니다",
		L"건국이가 무사히 탈출할 수 있도록",
		L"도와주자!"
	};
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 2, MAP_Y + 1);
	Setcolor(7);
	printf("TITLE STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(titlestr, MAP_X * 2 + 4, MAP_Y + 4, 15);
}

void easyStory(void) {
	wchar_t easystr[MAX_ROWS][MAX_COLS] = {
		L"건국이가 들고온 손전등의 배터리가",
		L"얼마 남지 않았다...!",
		L"손전등이 꺼지기 전에 경비병들을",
		L"피해 열쇠 2개를 찾아 탈출하자!",
		L"목숨은 5개이다!"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 2, MAP_Y + 1);
	Setcolor(7);
	printf("EASY STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(easystr, MAP_X * 2 + 4, MAP_Y + 4, 5);
}

void normalStory(void) {
	wchar_t normalstr[MAX_ROWS][MAX_COLS] = {
		L"얼마나 지났을까.....",
		L"손정등이 많이 어두워지고 배에서는",
		L"꼬르륵.. 소리가 계속 들려온다.",
		L"목숨도 4개밖에 남지 않았다.",
		L"어서 경비병들을 피해 탈출하자!",
		L"열쇠를 2개를 찾아 탈출하자!!"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 2, MAP_Y + 1);
	Setcolor(7);
	printf("NORMAL STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(normalstr, MAP_X * 2 + 4, MAP_Y + 4, 6);
}

void hardStory(void) {
	wchar_t hardstr[MAX_ROWS][MAX_COLS] = {
		L"감옥에 갇힌지 오래.....",
		L"바깥세상이 너무나 그립다.",
		L"이제 손전등은 거의 꺼져간다.",
		L"체력이 바닥나 목숨이 3개밖에 없다.",
		L"시야가 넓어진 경비병들을 피해",
		L"아이템을 잘 활용하여",
		L"열쇠 2개를 모으자!"
	};
	resetMapMain();
	resetMapBottom();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 2, MAP_Y + 1);
	Setcolor(7);
	printf("HARD STORY");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(hardstr, MAP_X * 2 + 4, MAP_Y + 4, 7);
}

int clearStory(void) {
	wchar_t clearstr[MAX_ROWS][MAX_COLS] = {
		L"햇빛이 건국이를 환하게 비춘다.",
		L"오랜 노력 끝에 탈출에 성공했다!"
	};
	resetMapMain();
	resetMapBottom();
	resetMapTitle();
	gameMapDraw();
	clearStorybg();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	slowPrint(clearstr, MAP_X * 2 + MAP_WIDTH / 2, MAP_Y + 13, 2);
	return HOME;
}

int failStory(void) {
	wchar_t failstr[MAX_ROWS][MAX_COLS] = {
		L"건국이의 체력이 다 소모되어",
		L"탈출에 실패했다.",
		L"쉬었다가 다시 도전해야겠다!"
	};
	resetMapMain();
	resetMapBottom();
	resetMapTitle();
	gameMapDraw();
	gotoxy1(MAP_X * 2 + 25, MAP_Y + MAP_HEIGHT - 3);
	Setcolor(8);
	printf("**** spacebar to skip ****");
	Setcolor(7);
	failStorybg();
	slowPrint(failstr, MAP_X * 2 + MAP_WIDTH / 2, MAP_Y + 13, 3);
	return HOME;
}