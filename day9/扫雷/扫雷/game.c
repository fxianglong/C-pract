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
		printf("%d ", i);//��ӡ��꣨0--10��
	}
	printf("\n");
	for (i=1;i<row-1;i++)//��ӡ���꣨1--10��
	{
		printf("%d ", i);
		for (j=1;j<col-1;j++)
		{
			printf("%c ", board[i][j]);//�����������
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

int CountBoard(char board[ROW][COL],int x, int y)//�����Χ8�������׵ĸ���
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

int CountBoard(char real_board[ROW][COL],int x, int y)//�����Χ8�������׵ĸ���
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
 
void open_mine(char show_board[ROW][COL], char real_board[ROW][COL], int x, int y)//������Χչ������
{
	if (real_board[x - 1][y - 1] == '0')
	{
		show_board[x - 1][y - 1] = CountBoard(show_board,x - 1, y - 1) + '0';//��ʾ��������Χ����
	}
	if (real_board[x - 1][y] == '0')
	{
		show_board[x - 1][y] = CountBoard(show_board,x - 1, y) + '0';//��ʾ��������Χ����
	}
	if (real_board[x - 1][y + 1] == '0')
	{
		show_board[x - 1][y + 1] = CountBoard(show_board,x - 1, y + 1) + '0';//��ʾ��������Χ����
	}
	if (real_board[x][y - 1] == '0')
	{
		show_board[x][y - 1] = CountBoard(show_board,x, y - 1) + '0';//��ʾ��������Χ����
	}
	if (real_board[x][y + 1] == '0')
	{
		show_board[x][y + 1] = CountBoard(show_board,x, y + 1) + '0';//��ʾ��������Χ����
	}
	if (real_board[x + 1][y - 1] == '0')
	{
		show_board[x + 1][y - 1] = CountBoard(show_board,x + 1, y - 1) + '0';//��ʾ��������Χ����
	}
	if (real_board[x + 1][y] == '0')
	{
		show_board[x + 1][y] = CountBoard(show_board,x + 1, y) + '0';//��ʾ��������Χ����
	}
	if (real_board[x + 1][y + 1] == '0')
	{
		show_board[x + 1][y + 1] = CountBoard(show_board,x + 1, y + 1) + '0';//��ʾ��������Χ����
	}
}
 
void SafeBoard(char show_board[ROW][COL],char real_board[ROW][COL],int row,int col,int x, int y)//�����һ��ը��
{
	char ch = 0;
	int count = 0;
	int ret = 1;
	printf("��������ɨ��\n");
	while (1)
	{
		scanf("%d%d", &x, &y);//ֻ������1��10�����������������
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//�ж����������Ƿ�����
		{
			if (real_board[x][y] == '1')//��һ�βȵ��׺󲹾�
			{
				real_board[x][y] = '0';
				char ch = CountBoard(real_board, x, y);
				show_board[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
				open_mine(show_board,real_board, x, y);
				while (ret)//�������пյĵط�����һ����
				{
					int x = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
					int y = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
					if (real_board[x][y] == '0')//�Ҳ����׵ĵط�����
					{
						real_board[x][y] = '1';
						ret--;
						break;
					}
				}break;//�����˺���  
			}
			if (real_board[x][y] == '0')
			{
				char ch = CountBoard(real_board,x, y);
				show_board[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
				open_mine(show_board, real_board, x, y);
				break;
			}
		}
		else//�������
		{
			printf("���������������\n");
		}
	}
}
 
int CountShowBoard(char show_board[ROWS][COLS], int row, int col)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
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

int sweep_mine(char show_board[ROW][COL], char real_board[ROW][COL], int row, int col)//ɨ�׺������ȵ��׷���1��û�вȵ��׷���0
{
	int x = 0;
	int y = 0;
	int count = 0;
	printf("��������ɨ��\n");
	scanf("%d%d", &x, &y);//ֻ������1��10
	if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//�ж����������Ƿ��������������������
	{
		if (real_board[x][y] == '0')//û�ȵ���
		{
			char ch = CountBoard(real_board,x, y);
			show_board[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
			if ((CountShowBoard(show_board, ROW, COL)) == Count)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
			{
				PrintBoard(show_board, ROW, COL);//��ӡ�������
				printf("���Ӯ��\n\n");
				return 0;
			}
		}
		else if (real_board[x][y] == '1')//�ȵ���
		{
			return 1;
		}
 
	}
	else
	{
		printf("���������������\n");
	}
	return 0;//û�ȵ���
}
