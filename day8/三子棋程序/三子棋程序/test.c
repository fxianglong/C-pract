#include<stdio.h>
#include<time.h>
#include"������.h"

void nume()
{
	printf("************************\n");
	printf("*********1��play********\n");
	printf("*********0��exit********\n");
	printf("************************\n");
}
void game()
{
	char board[ROW][COL];
    init_board(board,ROW,COL);
	while(1)
	{
		printf("�����ߣ�\n");
		computer_play(board,ROW,COL);
	    show_board(board,ROW,COL);
	     if (Win(board, ROW, COL) != ' ')
        {
            break;
        }
	    printf("�����\n");
        Player(board, ROW, COL);
        show_board(board, ROW, COL);
        if (Win(board, ROW, COL) != ' ')
        {
            break;
        }	
	}
	if (Win(board,ROW,COL) == '*')
    {
        printf("���Ӯ\n");
    }
	else if (Win(board,ROW,COL) == '#')
    {
        printf("����Ӯ\n");
    }
    else if (Win(board,ROW,COL) == 'P')
    {
        printf("ƽ��\n");
    }

}
int main()
{
	int ch = 0;
	do{
		nume();
		printf("��ѡ��");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:game();break;
		case 0:printf("�˳���Ϸ");break;
		default:printf("�����������������");break;
		}
	}while(ch);
	return 0;
}
