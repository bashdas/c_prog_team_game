#pragma once
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_X 3
#define MAP_Y 2
#define MAP_WIDTH 39
#define MAP_HEIGHT 26


// ���� �ý���

int speed; //���� �ӵ� 
int score; //���� ����  --reset�Լ��� ���� �ʱ�ȭ��
int best_score = 0; //�ְ� ���� ���� --reset�Լ��� ���� �ʱ�ȭ ���� ���� 
int last_score = 0; //������ ���� ����  --reset�Լ��� ���� �ʱ�ȭ ���� ����
int dir; //�̵����� ���� 
int key; //�Է¹��� Ű ���� 
int status_on = 0; // �����ڿ� status ǥ��Ȱ��ȭ ����.. �����߿� SŰ�� ������ Ȱ�� 
int length; //
int length1=4; //
int length2 =4;


// ü��
int HP = 3;
int* pHP = &HP;

// �÷��̾��� ��ǥ
int x[100], y[100]; 

// ������A�� ��ǥ
int x1[100], y1[100];
int x2[100], y2[100];



int item_x, item_y;
int item0_x, item0_y; // speed +
int item0a_x, item0a_y; 

int item1_x, item1_y; // speed -
int item1a_x, item1a_y;


void gotoxy(int x, int y, const char* s) { //x���� 2x�� ����, ��ǥ���� �ٷ� ���ڿ��� �Է��� �� �ֵ��� printf�Լ� ����  
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);
};
