#pragma once


// x: 23~96   y: 5~21

int item1_x, item1_y;

void item1(void) {
    int i;

    int item_crush_on = 0;//item�� �÷��̾��� ��ǥ�� ���� ��� on 
    int r = 0; //���� ������ �絿�Ǵ� ���� 


    while (1) {
        item_crush_on = 0;
        srand((unsigned)time(NULL) + r); //����ǥ���� 
        item1_x = rand()%30+20;      //������ ��ǥ���� ���� 
        item1_y = rand()%15+5;

        
        

        if (item_crush_on == 1) continue; //������ ��� while���� �ٽ� ���� 
        Setcolor(15);
        gotoxy(item1_x,item1_y, "��"); //�Ȱ����� ��� ��ǥ����item�� ��� 
        
        break;

    }
}



