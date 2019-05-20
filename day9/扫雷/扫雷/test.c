#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"
void game()
{
	char show_board[ROW][COL];
	char real_board[ROW][COL];
	srand((unsigned int)time(NULL));
	init_board(show_board,real_board, ROW, COL);
	PrintBoard(show_board, ROW, COL);
	PrintBoard(real_board, ROW, COL);
	mai_lei(real_board, ROW, COL);
	//PrintBoard(show_board, ROW, COL);
	//PrintBoard(real_board, ROWS, COLS);
	int x = 0, y = 0;
	//printf("����������Ҫ�㿪�����꣺");
	//scanf("%d %d", &x, &y);
	CountBoard(real_board, x, y);
	SafeBoard(show_board, real_board,ROW,COL, x, y);
	start = clock();
	CountShowBoard(show_board,ROWS,COLS);
	if (CountShowBoard(show_board, ROWS, COLS) == COUNT)//һ����Ӯ�����
	{
		PrintBoard(show_board, ROW, COL);
		printf("���Ӯ��\n\n");
		return;
	}
	PrintBoard(show_board, ROW, COL);//��ӡ�������
	while (1)//ѭ��ɨ��
	{
		int ret = sweep_mine(show_board,real_board, ROW, COL);//ɨ��,�ȵ��׷���1��û�вȵ��׷���0
		if (CountShowBoard(show_board, ROWS, COLS) == COUNT)//��������̵�'*'����Ϊ����ʱ��ɨ����ɣ���Ϸʤ��
		{
			PrintBoard(real_board, ROW, COL);//��ӡ���������
			printf("���Ӯ��\n\n");
			finish = clock();//ȡ����ʱ��
			printf("��ʱ%d ��\n", (int)(finish - start) / CLOCKS_PER_SEC);
			break;
		}
		if (ret)//�ж��Ƿ�ȵ���
		{
			printf("����ը��\t");
			finish = clock();//ȡ����ʱ��
			printf("��ʱ%d ��\n", (int)(finish - start) / CLOCKS_PER_SEC);
			PrintBoard(real_board, ROW, COL);//��ӡ���������鿴�׵ķֲ�
			break;
		}
		PrintBoard(show_board, ROW, COL);//��ӡ�������
	}
}
 
int main()
{
	int choose = 0;
	do{
		nume();
		printf("������ѡ��>");
		scanf("%d",&choose);
		switch(choose)
		{
		case 0:printf("�˳���Ϸ");break;
		case 1:printf("��Ϸ��ʼ>\n");
			game();break;
		default :printf("����������������룺>");
		}
	}while(choose);
	return 0;
}
