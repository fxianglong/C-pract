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
	//printf("请输入你需要点开的坐标：");
	//scanf("%d %d", &x, &y);
	CountBoard(real_board, x, y);
	SafeBoard(show_board, real_board,ROW,COL, x, y);
	start = clock();
	CountShowBoard(show_board,ROWS,COLS);
	if (CountShowBoard(show_board, ROWS, COLS) == COUNT)//一步就赢的情况
	{
		PrintBoard(show_board, ROW, COL);
		printf("玩家赢！\n\n");
		return;
	}
	PrintBoard(show_board, ROW, COL);//打印玩家棋盘
	while (1)//循环扫雷
	{
		int ret = sweep_mine(show_board,real_board, ROW, COL);//扫雷,踩到雷返回1，没有踩到雷返回0
		if (CountShowBoard(show_board, ROWS, COLS) == COUNT)//若玩家棋盘的'*'个数为雷数时，扫雷完成，游戏胜利
		{
			PrintBoard(real_board, ROW, COL);//打印设计者棋盘
			printf("玩家赢！\n\n");
			finish = clock();//取结束时间
			printf("用时%d 秒\n", (int)(finish - start) / CLOCKS_PER_SEC);
			break;
		}
		if (ret)//判断是否踩到雷
		{
			printf("被雷炸死\t");
			finish = clock();//取结束时间
			printf("用时%d 秒\n", (int)(finish - start) / CLOCKS_PER_SEC);
			PrintBoard(real_board, ROW, COL);//打印设计者雷阵查看雷的分布
			break;
		}
		PrintBoard(show_board, ROW, COL);//打印玩家棋盘
	}
}
 
int main()
{
	int choose = 0;
	do{
		nume();
		printf("请输入选择>");
		scanf("%d",&choose);
		switch(choose)
		{
		case 0:printf("退出游戏");break;
		case 1:printf("游戏开始>\n");
			game();break;
		default :printf("输入错误，请重新输入：>");
		}
	}while(choose);
	return 0;
}
