#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,tmp;
	printf("������Ҫ��������������");
		scanf("%d %d",&i,&j);
	tmp=i;
	i=j;
	j=tmp;
	printf("%d  %d",i,j);
	system("pause");
	return 0;
}