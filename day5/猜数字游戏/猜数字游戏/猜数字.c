#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void  menu ()
{
	printf("*******************\n");
	printf("******1��play******\n");
	printf("******0��exit******\n");
	printf("*******************\n");
}
void game()
{
 int ret = rand()%100+1;
 int input = 0;
 while(1)
 {
 printf("������µ�����>:");
 scanf("%d", &input);
 if(input > ret)
 {
 printf("�´���\n");
 }
 else if(input < random_num)
 {
 printf("��С��\n");
 }
 else
 {
 printf("��ϲ�㣬�¶���\n");
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
//	printf("������֣�>");
//	scanf("%d",&i);
//	if(i>ret)
//		printf("�´��ˣ�\n");
//	else if(i<ret)
//		printf("��С�ˣ�\n");
//	else
//		printf("��ϲ�㣬�¶���!\n");break;
//}
int main()
{
	int input=0;
srand((unsigned )time(NULL));
		do{
			menu();
		printf("�����룺");
			scanf("%d",&input);
		switch(input)
		{case 1:game();
		break;
		case 0:printf("�˳���Ϸ\n");
			break;
		default  :printf("�����������������\n");
			break;
		}
	}while(inpu);
	system("pause");
	return 0;
}