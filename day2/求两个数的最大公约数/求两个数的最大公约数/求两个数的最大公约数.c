#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=0,b=0,c=0;
	printf("������Ҫ�����Լ������������");
	scanf("%d%d",&a,&b);
	while(a%b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	printf("%d",c);
	system("pause");
	return 0;
}