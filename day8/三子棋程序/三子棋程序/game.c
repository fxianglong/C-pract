#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"三子棋.h"
void init_board(char board[ROW][COL], int row, int col)
{
	int x = 0,y = 0;
	for(x=0;x<row;x++)
		{for(y=0;y<col;y++)
		{
			board[x][y] = ' ';
		}
	}
}
void show_board(char board[ROW][COL], int row, int col)
{
    int i;
    for (i=0; i<row;i++)
    {
        printf("  %c | %c | %c  \n",board[i][0],board[i][1],board[i][2]);
        if (i != row - 1)
            printf(" ---|---|--- \n");
    } 
}
void computer_play(char board[ROW][COL],int row,int col)
{
	srand((unsigned int)time(NULL));
	while(1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if(board[x][y]==' ')
		{
			board[x][y] = '#';break;
		}
	}
}
void Player(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    while (1)
    {
        scanf("%d,%d", &x, &y);
        x--;
        y--;
        if((0 <= x && x <= row - 1) && (0 <= y && y <= col - 1))
        {
            if (board[x][y] == ' ')
            {
                board[x][y] = '*';
                break;
            }
            else {
                printf("请不要把棋放到人家的棋上\n");
            }
        }
    else {
        printf("请在棋盘里面下棋\n");
    }
    }
}
int Checkfull(char board[ROW][COL], int row, int col)
{
	int x = 0,y = 0;
	for(x=0;x<row;x++)
		for(y=0;y<col;y++)
		{
			if(board[x][y]==' ')
				return 1;
		}
		return 0;
}
char Win(char board[ROW][COL],int row,int col)
{
	int i = 0;
	{if(Checkfull(board,ROW,COL) == 0)
		{
			return 'p';
	    }
	}
	for (i = 0; i < row; i++)
    {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] != ' '))
        {
            return board[i][0];
        }
    }
    for (i = 0; i < col; i++)
    {
        if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[2][i] != ' '))
        {
            return board[0][i];
        }
    }
    if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] != ' '))
    {
        return board[0][0];
    }
    if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[2][0] != ' '))
    {
        return board[0][2];
    }
    return ' ';
}
