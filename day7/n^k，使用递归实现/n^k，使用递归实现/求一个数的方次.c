#include<stdio.h>
#include<stdlib.h>
int Power_number(int i,int j)
{
		if (j == 0)
	{
		return 0;
	}
	else if (j == 1)
	{
		return i;
	}
	else
	{
		return i * Power_number(i, j - 1);
	}
}
int main()
{
	int i=0,j=0,ret=0;
	printf("���������");
	scanf("%d",&i);
		printf("����������");
	scanf("%d",&j);
	
	printf("%d",Power_number(i,j));
	system("pause");
	return 0;
}