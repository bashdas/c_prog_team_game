#pragma once
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define MAP_X 3  // ?? main.h와 한번 더 비교해서 확인해보기 ?? 뭔가 예상했던 값과 다르다.


// 게임 시스템

int speed; //게임 속도 
int score; //점수 저장  --reset함수에 의해 초기화됨
int best_score = 0; //최고 점수 저장 --reset함수에 의해 초기화 되지 않음 
int last_score = 0; //마지막 점수 저장  --reset함수에 의해 초기화 되지 않음
int dir; //이동방향 저장 
int key; //입력받은 키 저장 
int status_on = 0; // 개발자용 status 표시활성화 변수.. 게임중에 S키를 누르면 활성 

// 길이
int length; // 플레이어의 꼬리
int length1=4;   // strider의 길이
int length2 =4;  // strider1의 길이


// 체력 [전역변수]
int HP = 3;
int* pHP = &HP;

// 플레이어의 좌표
int x[100], y[100]; 

// strider의 좌표
int x1[100], y1[100];   // strider 의 좌표를 저장
int x2[100], y2[100];   // strider2 의 좌표를 저장








int item_x, item_y;     // 속도 증가 함수 

int item0_x, item0_y;   // item0 게임속도 증가 + 
int item0a_x, item0a_y; // item0a 게임속도 증가 +

int item1_x, item1_y; // item1. 게임속도 감소 -
int item1a_x, item1a_y; // item1a. 게임속도 감소 -
