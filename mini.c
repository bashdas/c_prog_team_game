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

//공룡 관련 함수
void draw_dino(int);
void earase_dino();
void earase_foot();

//나무 관련 함수
void tree();
void draw_tree();
void erase_tree();


int treeX = TREE_X;
int dinoX = DINO_X;
int dinoY = DINO_Y;

int key = 0; //키보드 입력 받기

int minigame()
{
	int tic = 0; //게임 내 시간 단위이자 점수 결정 요소
	int crash = 0; //충돌 체크

	setting();
	start();

	while (1) {

		tic = game(tic);
		if (2 * tic >= 800)
			break;
		//'스페이스 바' 누르면 점프
		if (_kbhit()) {
			key = _getch();
			if (key == 32 && dinoY - 15 == 0) { //'스페이스 바'가 눌리고 공룡이 바닥에 있을 때

				int h = 0; //점프 높이 초기화

				while (h < 8) { //y축으로 8칸 상승
					earase_dino();
					dinoY--;
					tic = game(tic);
					crash = crashing();
					if (crash == -1)
						break;
					h++;
				}

				while (h > 0) { //y축으로 8칸 하강
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
		if (crash == -1) //충돌 시 탈출
			break;

	}

	end(tic);

	if (crash == -1)
		return 1;
	else
		return 0;
}
int game(int tic) { //게임화면 메인 요소
	score(tic);
	tree();
	draw_dino(tic);

	Sleep(2); //0.02초		//딜레이 예상
	tic++;

	return tic;
}

int crashing() { //충돌 판정	//난이도 '하'
	// (가로1 && 가로2) && 세로
	// 가로1: 나무가 가로 11칸보다 뒤에 있음
	// 가로2: 나무가 가로 15칸보다 앞에 있음
	// 가로1 && 가로2: 나무가 가로 11칸과 15칸 사이에 있음
	// 세로: 공룡 발 3칸이 나무 5칸 보다 높이가 같거나 낮을 때
	if ((dinoX + 6 <= treeX + 2 && dinoX + 10 >= treeX + 2) && dinoY + 12 >= TREE_Y + 2)
		return -1;
	else
		return 0;
}

void draw_dino(int tic) { //공룡 그리기

	int toc = tic % 8;

	//몸통
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


	//발 구르기 구현
	if (toc >= 0 && toc <= 3) //4tic 동안 유지
	{
		earase_foot();
		gotoxy1(dinoX, dinoY + 13); //발 그리기
		printf("         @    @@@\n");
		printf("         @@");
	}
	else
	{
		earase_foot();
		gotoxy1(dinoX, dinoY + 13); //발 그리기
		printf("         @@@  @\n");
		printf("              @@");
	}
}

void earase_foot() { //발 지우기
	gotoxy1(dinoX, dinoY + 13);
	printf("                 \n");
	printf("                 ");
}

void earase_dino() { //공룡 지우기
	for (int i = 0; i < 24; i++) {
		gotoxy1(dinoX, 6 + i);
		printf("                              ");
	}
	earase_foot();
}


void draw_tree() { //나무 그리기
	gotoxy1(treeX + 2, TREE_Y);			printf("##\n");
	gotoxy1(treeX, TREE_Y + 1);		  printf("# ## #\n");
	gotoxy1(treeX, TREE_Y + 2);		  printf("######\n");
	gotoxy1(treeX + 2, TREE_Y + 3);		printf("##\n");
	gotoxy1(treeX + 2, TREE_Y + 4);		printf("##");
}

void erase_tree() { //나무 지우기
	gotoxy1(treeX + 3, TREE_Y);		  printf("  \n");
	gotoxy1(treeX + 1, TREE_Y + 1);	printf("      \n");
	gotoxy1(treeX + 1, TREE_Y + 2);	printf("      \n");
	gotoxy1(treeX + 3, TREE_Y + 3);	  printf("  \n");
	gotoxy1(treeX + 3, TREE_Y + 4); 	  printf("  ");
}

void tree() { //나무 오른쪽에서 왼쪽으로 이동
	treeX--; //왼쪽으로 한 칸 이동
	erase_tree(); //지우고
	draw_tree(); //그리기

	if (treeX == 0)
		treeX = TREE_X; //나무가 왼쪽 끝으로 이동하면 초기화
}


void setting() {
	//콘솔창 설정
	system("title Jumping Dino by.woo");
	system("mode con:cols=100 lines=30");

	//커서 설정
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.dwSize = 1;
	ConsoleCursor.bVisible = 0; //커서 숨김
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void start() { //시작 화면

	gotoxy1(30, 10);
	printf("** PRESS [SPACE BAR] TO JUMP **");
	draw_dino(0);
}

void score(int tic) { //점수 출력
	gotoxy1(45, 1);
	printf("score : %4d", tic / 5 * 10); // tic/5 당 10점		//필드 폭 4칸 확보 (n천점까지)
}

void end(int tic) { //엔딩 화면
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
	printf("final score : %4d", tic / 5 * 10); //최종 점수
}