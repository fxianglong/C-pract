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
 
extern char show_board[ROWS][COLS];//展示数组
extern char real_board[ROWS][COLS];//布雷数组
 
void init_Board(char show_board[ROWS][COLS], char real_board[ROWS][COLS], int row, int col);
void PrintBoard(char board[ROW][COL], int row, int col);
void SetBoard(char real_board[ROW][COL], int row, int col);
int CountBoard(char real_board[ROW][COL], int x, int y);
void SafeBoard(char show_board[ROW][COL],char real_board[ROW][COL],int row, int col, int x, int y);
int sweep_mine(char show_board[ROW][COL], char real_board[ROW][COL], int row, int col);
int CountShowBoard(char show_board[ROWS][COLS], int row, int col);
 
#endif

--------------------- 
作者：Jochebed666 
来源：CSDN 
原文：https://blog.csdn.net/Jochebed666/article/details/80150504 
版权声明：本文为博主原创文章，转载请附上博文链接！