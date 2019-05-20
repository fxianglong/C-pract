#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void  menu ()
{
	printf("*******************\n");
	printf("******1、play******\n");
	printf("******0、exit******\n");
	printf("*******************\n");
}
void game()
{
 int ret = rand()%100+1;
 int input = 0;
 while(1)
 {
 printf("请输入猜的数字>:");
 scanf("%d", &input);
 if(input > ret)
 {
 printf("猜大了\n");
 }
 else if(input < random_num)
 {
 printf("猜小了\n");
 }
 else
 {
 printf("恭喜你，猜对了\n");
 break;
 }
 }
}
//void game()
//{int i;int ret=0;
//	ret=rand()%100+1;
//	
//	while(1)
//	{		
//	printf("请猜数字：>");
//	scanf("%d",&i);
//	if(i>ret)
//		printf("猜大了！\n");
//	else if(i<ret)
//		printf("猜小了！\n");
//	else
//		printf("恭喜你，猜对了!\n");break;
//}
int main()
{
	int input=0;
srand((unsigned )time(NULL));
		do{
			menu();
		printf("请输入：");
			scanf("%d",&input);
		switch(input)
		{case 1:game();
		break;
		case 0:printf("退出游戏\n");
			break;
		default  :printf("输入错误请重新输入\n");
			break;
		}
	}while(inpu);
	system("pause");
	return 0;
}