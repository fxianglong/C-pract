#pragma once
#ifndef _SANZIQI_H_
#define _SANZIQI_H_
#define ROW 3
#define COL 3
void init_board(char arr[ROW][COL], int row, int col);//初始化
void show_board(char arr[ROW][COL], int row, int col);//打印棋盘
void computer_play(char arr[ROW][COL], int row, int col);//电脑走
void Player(char arr[ROW][COL], int row, int col);//玩家走
int Checkfull(char arr[ROW][COL], int row, int col);//判断棋盘是否有空格
char Win(char arr[ROW][COL], int row, int col);//判断输赢
#endif