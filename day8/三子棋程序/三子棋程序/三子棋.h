#pragma once
#ifndef _SANZIQI_H_
#define _SANZIQI_H_
#define ROW 3
#define COL 3
void init_board(char arr[ROW][COL], int row, int col);//��ʼ��
void show_board(char arr[ROW][COL], int row, int col);//��ӡ����
void computer_play(char arr[ROW][COL], int row, int col);//������
void Player(char arr[ROW][COL], int row, int col);//�����
int Checkfull(char arr[ROW][COL], int row, int col);//�ж������Ƿ��пո�
char Win(char arr[ROW][COL], int row, int col);//�ж���Ӯ
#endif