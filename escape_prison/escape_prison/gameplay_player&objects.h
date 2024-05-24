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


// 게임 시스템

int speed; //게임 속도 
int score; //점수 저장  --reset함수에 의해 초기화됨
int best_score = 0; //최고 점수 저장 --reset함수에 의해 초기화 되지 않음 
int last_score = 0; //마지막 점수 저장  --reset함수에 의해 초기화 되지 않음
int dir; //이동방향 저장 
int key; //입력받은 키 저장 
int status_on = 0; // 개발자용 status 표시활성화 변수.. 게임중에 S키를 누르면 활성 
int length; //
int length1=4; //
int length2 =4;


// 체력
int HP = 3;
int* pHP = &HP;

// 플레이어의 좌표
int x[100], y[100]; 

// 아이템A의 좌표
int x1[100], y1[100];
int x2[100], y2[100];



int item_x, item_y;
int item0_x, item0_y; // speed +
int item0a_x, item0a_y; 

int item1_x, item1_y; // speed -
int item1a_x, item1a_y;
