#include<stdio.h>
#include<time.h>
#include"三子棋.h"

void nume()
{
	printf("************************\n");
	printf("*********1、play********\n");
	printf("*********0、exit********\n");
	printf("************************\n");
}
void game()
{
	char board[ROW][COL];
    init_board(board,ROW,COL);
	while(1)
	{
		printf("电脑走：\n");
		computer_play(board,ROW,COL);
	    show_board(board,ROW,COL);
	     if (Win(board, ROW, COL) != ' ')
        {
            break;
        }
	    printf("玩家走\n");
        Player(board, ROW, COL);
        show_board(board, ROW, COL);
        if (Win(board, ROW, COL) != ' ')
        {
            break;
        }	
	}
	if (Win(board,ROW,COL) == '*')
    {
        printf("玩家赢\n");
    }
	else if (Win(board,ROW,COL) == '#')
    {
        printf("电脑赢\n");
    }
    else if (Win(board,ROW,COL) == 'P')
    {
        printf("平局\n");
    }

}
int main()
{
	int ch = 0;
	do{
		nume();
		printf("请选择：");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:game();break;
		case 0:printf("退出游戏");break;
		default:printf("输入错误，请重新输入");break;
		}
	}while(ch);
	return 0;
}
