#include "main.h"

// void playMusic(const char* address);


// ȯ�漳�� ���� �Լ�
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
			else if (optionCode == 3) {
				subjectCode = setTheme();
			}
		}
	} while (optionCode != BACK);
}

// ����� �Է� �޴� ��ȯ
int selectOption(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	selectOptionContent();
	selectOptionContent2(2, 7);
	gotoxy1((MAP_X + 14) * 2, y);
	printf("��\b\b");
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
				printf("��\b\b");
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
				printf("��\b\b");
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

int selectOptionContent(void) {
	resetMapInner();
	titleBoxDraw();
	Setcolor(15);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 6, MAP_Y + 5, "!Option Menu!");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 2, MAP_Y + 7, "You can change the game option");
	Setcolor(8);
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "��  Select from the menu  ��");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 18);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

int selectOptionContent2(int c1, int c2) {
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH + 4, MAP_Y + 14);
	printf("��� ���� ����");
	if (c1 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 82) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 82) / 2, MAP_Y + 14);
		printf(" ");
	}
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH + 6, MAP_Y + 16);
	printf("�׸� ����");
	if (c2 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 82) / 2, MAP_Y + 16);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 82) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(7);
}



// ���� ���� ���
int setMusic(void) {
	resetMapInner();
	int keyInput;
	keyInput = selectMusic();
	switch (keyInput) {
	case 1:
		PlaySound(TEXT("c_team_bgm1.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//ù ��° ��� ����
		break;
	case 2:
		PlaySound(TEXT("c_team_bgm2.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//�� ��° ��� ����
		break;
	case 3:
		PlaySound(TEXT("c_team_bgm3.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//�� ��° ��� ����
		break;
	case 4:
		PlaySound(TEXT("c_team_bgm4.wav"), NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);//�� ��° ��� ����
		break;

		// ��� ���� �߰� �� case �߰� �� select Music�� 3�� ���� ��� �߰�
	}
	return BACK;
}

// ����� �Է� �뷡 ��ȯ
int selectMusic(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	selectMusicContent();
	selectMusicContent2(2, 7, 7, 7);
	gotoxy1((MAP_X + 16) * 2, y);
	printf("��\b\b");

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
				printf("��\b\b");
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
				printf("��\b\b");
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
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "��  Select from the menu  ��");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

void selectMusicContent2(int c1, int c2, int c3, int c4) {
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH + 8, MAP_Y + 14);
	printf("1������");
	if (c1 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 14);
		printf(" ");
	}
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH + 8, MAP_Y + 15);
	printf("2������");
	if (c2 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 15);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 15);
		printf(" ");
	}
	Setcolor(c3);
	gotoxy1(MAP_X + MAP_WIDTH + 8, MAP_Y + 16);
	printf("3������");
	if (c3 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 16);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(c4);
	gotoxy1(MAP_X + MAP_WIDTH + 8, MAP_Y + 17);
	printf("4������");
	if (c4 == 2) {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 17);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 74) / 2, MAP_Y + 17);
		printf(" ");
	}
	Setcolor(7);
}

// �׸� ���� ���
int setTheme(void) {
	int keyInput;
	keyInput = selectTheme();
	printf("%d", keyInput);
	switch (keyInput) {
	case 1:
		theme = 1;//�Ķ���
		break;
	case 2:
		theme = 5;//���ֻ�
		break;
	case 3:
		theme = 6;//�����
		break;
	case 4:
		theme = 15;//���� ���
		break;
	case 5:
		theme = 7;//�⺻ ���
		break;
	}
	reset();
	return BACK;
}

// ����� �Է� �׸� ��ȯ
int selectTheme(void) {
	int x = (MAP_X + 2) * 2, y = MAP_Y + 14;
	selectThemeContent();
	selectThemeContent2(1, 7, 7, 7, 7);
	gotoxy1((MAP_X + 13) * 2, y);
	printf("��\b\b");

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
				printf("��\b\b");
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
				printf("��\b\b");
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

void selectThemeContent(void) {
	resetMapInner();
	titleBoxDraw();
	Setcolor(15);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 6, MAP_Y + 5, " !Theme Menu!");
	Setcolor(7);
	gotoxy(MAP_X + (MAP_WIDTH - 19) / 2 + 2, MAP_Y + 7, "You can change the game Theme");
	Setcolor(8);
	gotoxy(MAP_X + (MAP_WIDTH - 13) / 2, MAP_Y + 12, "��  Select from the menu  ��");
	gotoxy1(MAP_X * 2 + 25, MAP_Y + 20);
	printf("**** spacebar to select ****");
	Setcolor(7);
}

void selectThemeContent2(int c1, int c2, int c3, int c4, int c5) {
	Setcolor(c1);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 14);
	printf("�����̾�");
	Setcolor(1);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 14);
	printf("��");
	if (c1 == 1) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 14);
		printf(" ");
	}
	Setcolor(c2);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 15);
	printf("�ڼ��� ");
	Setcolor(5);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 15);
	printf("��");
	if (c2 == 5) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 15);
		printf(" ");
	}
	Setcolor(c3);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 16);
	printf("������ ");
	Setcolor(6);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 16);
	printf("��");
	if (c3 == 6) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 16);
		printf(" ");
	}
	Setcolor(c4);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 17);
	printf("���̾Ƹ��");
	Setcolor(15);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 17);
	printf("��");
	if (c4 == 15) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 17);
		printf(" ");
	}
	Setcolor(c5);
	gotoxy1(MAP_X + MAP_WIDTH + 2, MAP_Y + 18);
	printf("�⺻���");
	Setcolor(7);
	gotoxy1(MAP_X + MAP_WIDTH + 18, MAP_Y + 18);
	printf("��");
	if (c5 == 8) {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 18);
		Setcolor(7);
		printf("��");
	}
	else {
		gotoxy1(MAP_X + (MAP_WIDTH + 84) / 2, MAP_Y + 18);
		printf(" ");
	}
}

/*
// ���� ���Ͽ� �����Ͽ� ����ϴ� �Լ�
void playMusic(const char* address) { // ���� ������ �ּҸ� �μ��� �޴´�.
	char command[256];
	snprintf(command, sizeof(command), "%s", address);
	printf("%s", command);
	PlaySound(command, NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);
	while (1) {
		Sleep(10000);
	}
}
*/