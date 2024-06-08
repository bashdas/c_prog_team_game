#include "main.h"
//int x[100], y[100]; //x,y ��ǥ���� ���� �� 100�� 
//int key; //�Է¹��� Ű ���� 
int speed; //���� �ӵ� 
int theme = 7;


int main(void) {
	setlocale(LC_ALL, "korean"); // �ѱ��� �ڵ� ������
	int menuCode = 0;
	int gameCode = 0;
	srand((unsigned int)time(NULL));
	//system("mode con cols=100 lines=30"); //�ܼ�â ũ�� ����
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
			else if (menuCode == ITEM_EX) item_ex();
			else if (menuCode == GAMEEXIT) {
				system("cls");
				gameExit();
			}
		} while (menuCode != BACK || gameCode == HOME);
	}
	return 0;
}