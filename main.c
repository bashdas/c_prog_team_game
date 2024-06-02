#include "main.h"
//int x[100], y[100]; //x,y 좌표값을 저장 총 100개 
//int key; //입력받은 키 저장 
int speed; //게임 속도 
int theme = 7;

int main(void) {
	setlocale(LC_ALL, "korean"); // 한국어 코드 페이지
	int menuCode = 0;
	int gameCode = 0;
	srand((unsigned int)time(NULL));
	//system("mode con cols=100 lines=30"); //콘솔창 크기 조절
	while (1) {
		title();
		do {
			gameCode = 0;
			menuCode = menuDraw1(); // y - 15 = 1 ~ 4
			if (menuCode == GAMESTART) {
				gameCode = gameDraw();
			}
			else if (menuCode == GAMERULE) gameRulesDraw();
			else if (menuCode == OPTION) initOption();
			else if (menuCode == GAMEEXIT) {
				system("cls");
				gameExit();
			}
		} while (menuCode != BACK || gameCode == HOME);
	}
	return 0;
}
