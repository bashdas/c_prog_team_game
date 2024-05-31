#pragma once


// x: 23~96   y: 5~21

int item1_x, item1_y;

void item1(void) {
    int i;

    int item_crush_on = 0;//item이 플레이어의 좌표에 생길 경우 on 
    int r = 0; //난수 생성에 사동되는 변수 


    while (1) {
        item_crush_on = 0;
        srand((unsigned)time(NULL) + r); //난수표생성 
        item1_x = rand()%30+20;      //난수를 좌표값에 넣음 
        item1_y = rand()%15+5;

        
        

        if (item_crush_on == 1) continue; //겹쳤을 경우 while문을 다시 시작 
        Setcolor(15);
        gotoxy(item1_x,item1_y, "♪"); //안겹쳤을 경우 좌표값에item를 찍고 
        
        break;

    }
}



