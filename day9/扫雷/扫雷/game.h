#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
 
#define ROW 10
#define COL 10
 
#define ROWS 12
#define COLS 12
#define COUNT 10
 
extern char show_board[ROWS][COLS];//չʾ����
extern char real_board[ROWS][COLS];//��������
 
void init_Board(char show_board[ROWS][COLS], char real_board[ROWS][COLS], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void SetBoard(char real_board[ROW][COL], int row, int col);
int CountBoard(char real_board[ROW][COL], int x, int y);
void SafeBoard(char show_board[ROW][COL],char real_board[ROW][COL],int row, int col, int x, int y);
int sweep_mine(char show_board[ROW][COL], char real_board[ROW][COL], int row, int col);
int CountShowBoard(char show_board[ROWS][COLS], int row, int col);
 
#endif

--------------------- 
���ߣ�Jochebed666 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/Jochebed666/article/details/80150504 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�