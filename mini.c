#include "main.h"

#define DINO_X 0
#define DINO_Y 15
#define TREE_X 94
#define TREE_Y 25

void setting();

void start();
int game(int);
void score(int);
int crashing();
void end(int);

//���� ���� �Լ�
void draw_dino(int);
void earase_dino();
void earase_foot();

//���� ���� �Լ�
void tree();
void draw_tree();
void erase_tree();


int treeX = TREE_X;
int dinoX = DINO_X;
int dinoY = DINO_Y;

int key = 0; //Ű���� �Է� �ޱ�

int minigame()
{
	int tic = 0; //���� �� �ð� �������� ���� ���� ���
	int crash = 0; //�浹 üũ

	setting();
	start();

	while (1) {

		tic = game(tic);
		if (2 * tic >= 800)
			break;
		//'�����̽� ��' ������ ����
		if (_kbhit()) {
			key = _getch();
			if (key == 32 && dinoY - 15 == 0) { //'�����̽� ��'�� ������ ������ �ٴڿ� ���� ��

				int h = 0; //���� ���� �ʱ�ȭ

				while (h < 8) { //y������ 8ĭ ���
					earase_dino();
					dinoY--;
					tic = game(tic);
					crash = crashing();
					if (crash == -1)
						break;
					h++;
				}

				while (h > 0) { //y������ 8ĭ �ϰ�
					tic = game(tic);
					crash = crashing();
					if (crash == -1)
						break;
					dinoY++;
					earase_dino();
					h--;
				}
			}
		}
		crash = crashing();
		if (crash == -1) //�浹 �� Ż��
			break;

	}

	end(tic);

	if (crash == -1)
		return 1;
	else
		return 0;
}
int game(int tic) { //����ȭ�� ���� ���
	score(tic);
	tree();
	draw_dino(tic);

	Sleep(2); //0.02��		//������ ����
	tic++;

	return tic;
}

int crashing() { //�浹 ����	//���̵� '��'
	// (����1 && ����2) && ����
	// ����1: ������ ���� 11ĭ���� �ڿ� ����
	// ����2: ������ ���� 15ĭ���� �տ� ����
	// ����1 && ����2: ������ ���� 11ĭ�� 15ĭ ���̿� ����
	// ����: ���� �� 3ĭ�� ���� 5ĭ ���� ���̰� ���ų� ���� ��
	if ((dinoX + 6 <= treeX + 2 && dinoX + 10 >= treeX + 2) && dinoY + 12 >= TREE_Y + 2)
		return -1;
	else
		return 0;
}

void draw_dino(int tic) { //���� �׸���

	int toc = tic % 8;

	//����
	gotoxy1(dinoX, dinoY);			printf("              @@@@@@@@\n");
	gotoxy1(dinoX, dinoY + 1);		printf("             @@@@@@@@@@@\n");
	gotoxy1(dinoX, dinoY + 2);		printf("             @@@ @@@@@@@\n");
	gotoxy1(dinoX, dinoY + 3);		printf("             @@@@@@@@@@@\n");
	gotoxy1(dinoX, dinoY + 4);		printf("             @@@@@@\n");
	gotoxy1(dinoX, dinoY + 5);		printf("     *      @@@@@@@@@@\n");
	gotoxy1(dinoX, dinoY + 6);		printf("     @     @@@@@@\n");
	gotoxy1(dinoX, dinoY + 7);		printf("     @@  @@@@@@@@@@@@\n");
	gotoxy1(dinoX, dinoY + 8);		printf("     @@@@@@@@@@@@   @\n");
	gotoxy1(dinoX, dinoY + 9);		printf("     @@@@@@@@@@@@\n");
	gotoxy1(dinoX, dinoY + 10);		printf("      @@@@@@@@@@\n");
	gotoxy1(dinoX, dinoY + 11);		printf("       @@@@@@@@\n");
	gotoxy1(dinoX, dinoY + 12);		printf("         @@@@@@\n");


	//�� ������ ����
	if (toc >= 0 && toc <= 3) //4tic ���� ����
	{
		earase_foot();
		gotoxy1(dinoX, dinoY + 13); //�� �׸���
		printf("         @    @@@\n");
		printf("         @@");
	}
	else
	{
		earase_foot();
		gotoxy1(dinoX, dinoY + 13); //�� �׸���
		printf("         @@@  @\n");
		printf("              @@");
	}
}

void earase_foot() { //�� �����
	gotoxy1(dinoX, dinoY + 13);
	printf("                 \n");
	printf("                 ");
}

void earase_dino() { //���� �����
	for (int i = 0; i < 24; i++) {
		gotoxy1(dinoX, 6 + i);
		printf("                              ");
	}
	earase_foot();
}


void draw_tree() { //���� �׸���
	gotoxy1(treeX + 2, TREE_Y);			printf("##\n");
	gotoxy1(treeX, TREE_Y + 1);		  printf("# ## #\n");
	gotoxy1(treeX, TREE_Y + 2);		  printf("######\n");
	gotoxy1(treeX + 2, TREE_Y + 3);		printf("##\n");
	gotoxy1(treeX + 2, TREE_Y + 4);		printf("##");
}

void erase_tree() { //���� �����
	gotoxy1(treeX + 3, TREE_Y);		  printf("  \n");
	gotoxy1(treeX + 1, TREE_Y + 1);	printf("      \n");
	gotoxy1(treeX + 1, TREE_Y + 2);	printf("      \n");
	gotoxy1(treeX + 3, TREE_Y + 3);	  printf("  \n");
	gotoxy1(treeX + 3, TREE_Y + 4); 	  printf("  ");
}

void tree() { //���� �����ʿ��� �������� �̵�
	treeX--; //�������� �� ĭ �̵�
	erase_tree(); //�����
	draw_tree(); //�׸���

	if (treeX == 0)
		treeX = TREE_X; //������ ���� ������ �̵��ϸ� �ʱ�ȭ
}


void setting() {
	//�ܼ�â ����
	system("title Jumping Dino by.woo");
	system("mode con:cols=100 lines=30");

	//Ŀ�� ����
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.dwSize = 1;
	ConsoleCursor.bVisible = 0; //Ŀ�� ����
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void start() { //���� ȭ��

	gotoxy1(30, 10);
	printf("** PRESS [SPACE BAR] TO JUMP **");
	draw_dino(0);
}

void score(int tic) { //���� ���
	gotoxy1(45, 1);
	printf("score : %4d", tic / 5 * 10); // tic/5 �� 10��		//�ʵ� �� 4ĭ Ȯ�� (nõ������)
}

void end(int tic) { //���� ȭ��
	system("cls");
	int a = 10;
	gotoxy1(a, a);		printf(" #####      ##    ##   ##  #######            #####    ##  ##  #######   ######  \n");
	gotoxy1(a, a + 1);	printf("##   ##    ####   ### ###   ##  ##           ##   ##   ##  ##   ##  ##   ##  ##  \n");
	gotoxy1(a, a + 2);	printf("##        ##  ##  #######   ##               ##   ##   ##  ##   ##       ##  ##  \n");
	gotoxy1(a, a + 3);	printf("##        ######  ## # ##   ####             ##   ##   ##  ##   ####     #####   \n");
	gotoxy1(a, a + 4);	printf("##  ###   ##  ##  ##   ##   ##               ##   ##   ##  ##   ##       ####    \n");
	gotoxy1(a, a + 5);	printf("##   ##   ##  ##  ##   ##   ##  ##           ##   ##    ####    ##  ##   ## ##   \n");
	gotoxy1(a, a + 6);	printf(" #####    ##  ##  ##   ##  #######            #####      ##    #######   ###  ## \n");

	gotoxy1(40, 20);
	printf("final score : %4d", tic / 5 * 10); //���� ����
}