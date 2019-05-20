#include<stdio.h>
#include<stdlib.h>
void Printf_multiplication(int i,int j,int a)
	{
		for(i=1;i<=a;i++)
	{for(j=1;j<=i;j++)
	printf("%d*%d=%2d  ",i,j,i*j);
			printf("\n");
	}
	}
int main()
{
	int i=0,j=0,a=0;
	printf("请输入乘法口诀的行列数：");
	scanf("%d",&a);
	Printf_multiplication(i,j,a);
    system("pause");
	return 0;
}