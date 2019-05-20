#include<stdio.h>
#include<stdlib.h>
void 	Number_Exchange(int i,int j,int tmp)
{
	tmp=i;
	i=j;
	j=tmp;
	printf("i=%d,j=%d",i,j);
}
int main()
{
	int i=0,j=0,tmp=0;
	printf("请输入要交换的两个数：");
	scanf("%d%d",&i,&j);
	printf("i=%d,j=%d\n",i,j);
	Number_Exchange(i,j,tmp);
	system("pause");
	return 0;
}