#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"
void nume()
{
	printf("**********************\n");
	printf("*********1,game*******\n");
	printf("*********2,exit*******\n");
	printf("**********************\n");
}
void init_board(char board[ROW][COL],char show[ROW][COL],int row,int col)
{
	int x = 0,y = 0;
	for(x=0;x<row-1;x++)
		for(y=0;y<col-1;y++)
		{
			board[x][y] = '0';
			show[x][y] = '*';
		}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0; i<row-1;i++)
	{
		printf("%d ", i);//打印横标（0--10）
	}
	printf("\n");
	for (i=1;i<row-1;i++)//打印竖标（1--10）
	{
		printf("%d ", i);
		for (j=1;j<col-1;j++)
		{
			printf("%c ", board[i][j]);//玩家棋盘数组
		}
		printf("\n");
	}
	printf("\n");
}

void mai_lei(char board[ROW][COL],int row,int col)
{
	int x = 0,y = 0;int count = Count;
	while(count)
	{
	    x = rand()%(row-2)+1;//a[1][1]-a[9][9]
		y = rand()%(col-2)+1;
		if(board[x][y]=='0')
		{
			board[x][y]='1';
			count--;
		}
}
}

int CountBoard(char board[ROW][COL],int x, int y)//检测周围8个区域雷的个数
{
	int count = 0;
	if (board[x - 1][y - 1] == '1')
		count++;
	if (board[x - 1][y] == '1')
		count++;
	if (board[x - 1][y + 1] == '1')
		count++;
	if (board[x][y - 1] == '1')
		count++;
	if (board[x][y + 1] == '1')
		count++;
	if (board[x + 1][y - 1] == '1')
		count++;
	if (board[x + 1][y] == '1')
		count++;
	if (board[x + 1][y + 1] == '1')
		count++;
	return count;
}

int CountBoard(char real_board[ROW][COL],int x, int y)//检测周围8个区域雷的个数
{
	int count = 0;
	if (real_board[x - 1][y - 1] == '1')
		count++;
	if (real_board[x - 1][y] == '1')
		count++;
	if (real_board[x - 1][y + 1] == '1')
		count++;
	if (real_board[x][y - 1] == '1')
		count++;
	if (real_board[x][y + 1] == '1')
		count++;
	if (real_board[x + 1][y - 1] == '1')
		count++;
	if (real_board[x + 1][y] == '1')
		count++;
	if (real_board[x + 1][y + 1] == '1')
		count++;
	return count;
}
 
void open_mine(char show_board[ROW][COL], char real_board[ROW][COL], int x, int y)//坐标周围展开函数
{
	if (real_board[x - 1][y - 1] == '0')
	{
		show_board[x - 1][y - 1] = CountBoard(show_board,x - 1, y - 1) + '0';//显示该坐标周围雷数
	}
	if (real_board[x - 1][y] == '0')
	{
		show_board[x - 1][y] = CountBoard(show_board,x - 1, y) + '0';//显示该坐标周围雷数
	}
	if (real_board[x - 1][y + 1] == '0')
	{
		show_board[x - 1][y + 1] = CountBoard(show_board,x - 1, y + 1) + '0';//显示该坐标周围雷数
	}
	if (real_board[x][y - 1] == '0')
	{
		show_board[x][y - 1] = CountBoard(show_board,x, y - 1) + '0';//显示该坐标周围雷数
	}
	if (real_board[x][y + 1] == '0')
	{
		show_board[x][y + 1] = CountBoard(show_board,x, y + 1) + '0';//显示该坐标周围雷数
	}
	if (real_board[x + 1][y - 1] == '0')
	{
		show_board[x + 1][y - 1] = CountBoard(show_board,x + 1, y - 1) + '0';//显示该坐标周围雷数
	}
	if (real_board[x + 1][y] == '0')
	{
		show_board[x + 1][y] = CountBoard(show_board,x + 1, y) + '0';//显示该坐标周围雷数
	}
	if (real_board[x + 1][y + 1] == '0')
	{
		show_board[x + 1][y + 1] = CountBoard(show_board,x + 1, y + 1) + '0';//显示该坐标周围雷数
	}
}
 
void SafeBoard(char show_board[ROW][COL],char real_board[ROW][COL],int row,int col,int x, int y)//避免第一次炸死
{
	char ch = 0;
	int count = 0;
	int ret = 1;
	printf("输入坐标扫雷\n");
	while (1)
	{
		scanf("%d%d", &x, &y);//只能输入1到10，输入错误重新输入
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//判断输入坐标是否有误
		{
			if (real_board[x][y] == '1')//第一次踩到雷后补救
			{
				real_board[x][y] = '0';
				char ch = CountBoard(real_board, x, y);
				show_board[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
				open_mine(show_board,real_board, x, y);
				while (ret)//在其余有空的地方设置一个雷
				{
					int x = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
					int y = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
					if (real_board[x][y] == '0')//找不是雷的地方布雷
					{
						real_board[x][y] = '1';
						ret--;
						break;
					}
				}break;//跳出此函数  
			}
			if (real_board[x][y] == '0')
			{
				char ch = CountBoard(real_board,x, y);
				show_board[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
				open_mine(show_board, real_board, x, y);
				break;
			}
		}
		else//坐标错误
		{
			printf("输入错误重新输入\n");
		}
	}
}
 
int CountShowBoard(char show_board[ROWS][COLS], int row, int col)//判断剩余未知区域的个数，个数为雷数时玩家赢
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row - 2; i++)
	{
		for (j = 1; j <= col - 2; j++)
		{
			if (show_board[i][j] == '*')
			{
				count++;
			}
		}
 
	}
	return count;
}

int sweep_mine(char show_board[ROW][COL], char real_board[ROW][COL], int row, int col)//扫雷函数，踩到雷返回1，没有踩到雷返回0
{
	int x = 0;
	int y = 0;
	int count = 0;
	printf("输入坐标扫雷\n");
	scanf("%d%d", &x, &y);//只能输入1到10
	if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//判断输入坐标是否有误，输入错误重新输入
	{
		if (real_board[x][y] == '0')//没踩到雷
		{
			char ch = CountBoard(real_board,x, y);
			show_board[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
			if ((CountShowBoard(show_board, ROW, COL)) == Count)//判断剩余未知区域的个数，个数为雷数时玩家赢
			{
				PrintBoard(show_board, ROW, COL);//打印玩家棋盘
				printf("玩家赢！\n\n");
				return 0;
			}
		}
		else if (real_board[x][y] == '1')//踩到雷
		{
			return 1;
		}
 
	}
	else
	{
		printf("输入错误重新输入\n");
	}
	return 0;//没踩到雷
}
