#include "main.h"

void draw_portal(void)
{
	gotoxy1(22, 20);
	Setcolor(2);
	printf("P");
	gotoxy1(80, 4);
	printf("P");
	Setcolor(15);
}

void remove_portal(void) {
	gotoxy1(22, 20);
	Setcolor(theme);
	printf("*");
	gotoxy1(80, 4);
	Setcolor(theme);
	printf("*");
}

void function_portal(int* x, int* y, int n)
{

	if (*x == 23 && *y == 20 && n==LEFT)
	{
		*x = 81;
		*y = 5;
		removePlayer(23, 20);
		timek -= 1;
		printf(" ");
	}
	if (*x == 80 && *y == 5 && n == UP)
	{
		*x = 23;
		*y = 21;
		removePlayer(80, 5);
		timek -= 1;
		printf(" ");
	}
}

void function_portal_Hard(int* x, int* y, int n)
{
	if (*x == 23 && *y == 20 && n==LEFT)
	{
		*x = 81;
		*y = 5;
		gotoxy1(23, 21);
		resetMapInner();
		gameMapDraw();
		draw_portal();
		timek -= 1;
		printf(" ");
	}
	if (*x == 80 && *y == 5 && n == UP)
	{
		*x = 24;
		*y = 21;
		gotoxy1(80,5);
		resetMapInner();
		gameMapDraw();
		draw_portal();
		timek -= 1;
		printf(" ");
	}
}

/************************************************/
bool is_valid_input(int input, int ranks[]) {
    if (input < 1 || input > 5) {
        return false;
    }
    for (int i = 0; i < 5; i++) {
        if (ranks[i] == input) {
            return false;  // 중복된 입력이 있으면 false 반환
        }
    }
    return true;
}
void Edgem() {
	int i;
	int h = 0xa2;
	int v = 0xcc;



	// 메인 세로

	gotoxy1(23, 4);
	printf(" 보너스 스테이지 ** 당신의 운을 시험해보세요 **");

	gotoxy1(23, 7);
	printf("1. 경주마 5마리가 시합을 준비합니다.");
	gotoxy1(23, 9);
	printf("2. 1등부터 5등까지의 순위를 한번 예상해보세요!");
	gotoxy1(23, 11);
	printf("3. 당신의 예상이 많이 맞는다면 배터리를 얻고, ");
	gotoxy1(28, 12);
	printf("틀리다면 배터리가 줄어듭니다.");


	gotoxy1(24, 17);
	printf("^^^ 건구스의 가호가 당신과 함께하기를 ^^^");

	gotoxy1(3, 2);
	for (int i = 0; i < 80; i++)
	{
		printf("%c%c", h, v);
	};

	gotoxy1(3, 25);
	for (int i = 0; i < 80; i++)
	{
		printf("%c%c", h, v);
	};
	gotoxy1(23, 23);
	printf(" <<<  PRESS SPACEKEY TO START  >>>");

}

int minigame(void)
{
    system("cls");
    Edgem();
    while (_kbhit() == 0)
    {

    }
    system("cls");
    Sleep(10);
    gotoxy1(3, 2);
    int h = 0xa2;
    int v = 0xcc;
    for (int i = 0; i < 80; i++)
    {
        printf("%c%c", h, v);
    };

    gotoxy1(3, 25);
    for (int i = 0; i < 80; i++)
    {
        printf("%c%c", h, v);
    };
    int horse_num, i, number, k, max = 0, count = 0, rank[10] = { 0 }, guess = 0;
    int horse[5] = { 0 }, race;
    char horse_name[10][10];
    int horse_rank[10];
    clock_t start, end;
    double pst;
    srand(time(NULL));

    horse_num = 5;
    gotoxy1(13, 4);

    printf(":: 경주마의 순위를 예측하세요(1~5까지의 숫자를 입력하고 Enter을 눌러주세요) ::\n", horse_num);

    {
        int input;
        int rank = 1;



        while (rank <= 5) {
            gotoxy1(3, 6 + rank);
            printf("%c경주마 순위:", 'A' + rank - 1);

            if (scanf("%d", &input) != 1) {

                gotoxy1(5, 6 + rank);
                printf("               \n");

                while (getchar() != '\n');  // 잘못된 입력 버퍼를 비웁니다.
                continue;
            }

            if (is_valid_input(input, horse_rank)) {
                horse_rank[rank - 1] = input;
                rank++;
                printf("\b");
            }
            else {
                gotoxy1(3, 17);
                printf("> 1에서 5 사이의 정수를 중복되지 않게 입력하세요.\n");
            }
        }
    }

  
    system("cls");
    printf("\n\n");
    printf("(start)  1         10         20        30        40(end) 등수 시간(초)\n");
    printf("----------------------------------------------------------------------\n");
    gotoxy1(52, 1);
    printf("소요시간:");
    for (i = 0; i < horse_num; i++)
    {
        gotoxy1(1, 5 + i * 2);
        printf("%c (%-2d)등:>", 'A' + i, horse_rank[i]);

    }

    _getch();
    start = clock();
    while (count != horse_num)
    {

        number = rand() % horse_num;
        if (rank[number] != 0)
            continue;
        race = rand() % 2 + 1;
        horse[number] = horse[number] + race;
        Sleep(60);
        if (horse[number] > 39)
        {
            horse[number] = 40;
            if (!rank[number])
            {
                count++;
                rank[number] = count;
                gotoxy1(10, 5 + number * 2);
                for (k = 0; k < horse[number]; k++)
                    printf(" ");
                if (horse[number])
                    printf(">");



                gotoxy1(55, 5 + number * 2);
                printf("    %d등   ", count);
                if (number + 1 == count)
                {
                    guess++;
                }
                end = clock();
                pst = (double)(end - start) / CLK_TCK;
                printf("%6.2f", pst);

            }
        }
        else
        {
            gotoxy1(10, 5 + number * 2);
            for (k = 0; k < horse[number]; k++)
                printf(" ");
            if (horse[number])
                printf(">");
        }
        gotoxy1(62, 1);
        end = clock();
        pst = (double)(end - start) / CLK_TCK;
        printf("%6.3f초", pst);

    }
    gotoxy1(1, 20);
    printf("\n\n\n");


    printf("맞춘 개수: %d", guess);
    switch (guess)
    {
    case 5: printf("  오 모두 맞히셨습니다! 배터리가 100 증가합니다!"); break;
    case 4: printf("  거의 다 맞히셨습니다! 배터리가 40 증가합니다!"); break;
    case 3: printf("  많이 맞히셨습니다! 배터리가 30 증가합니다!"); break;
    case 2: printf("  2개 맞히셨습니다! 배터리가 20 증가합니다!"); break;
    default: printf("흠.... 운이 없군요. 배터리가 감소합니다 ㅠㅠ"); break;
    }
    Sleep(4000);

    system("cls");
    drawMap();
    gotoxy1(22, 4);
    for (int i = 0; i < 39; i++)
        printf("* ");
    gotoxy1(22, 22);
    for (int i = 0; i < 39; i++)
        printf("* ");
    draw_portal();

    if (guess==5)
    {
        timek -= 100;
        return 1;
    }
    else if (guess == 4)
    {
       
            timek -= 40;
            return 1;
        
    }
    else if(guess==3) {
        timek -= 30;
        return 1;
    }
    else if (guess == 2) {
        timek -= 20;
        return 1;
    }
    else if(guess==1)
    {
        timek += 20;
        return 0;
    }
    else
    {
        timek += 40;
        return 0;
    }
}