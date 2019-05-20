#include<stdio.h>
#include<stdlib.h>
int fbnqs(int n)
{
	int a=1,b=1,c=0,i=0;
	if(n<=2)
	{
		c=1;
	}
	else
		for(i=3;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
		return c;
}
int main()
{
	int n,ret;
	printf("第几个斐波那契数：");
		scanf("%d",&n);
	ret=fbnqs(n);
	printf("%d\n",ret);
	system("pause");
	return 0;
}

//int fbnqs(int n)
//{	if(n<=2)
//		return 1;
//	else
//		return (fbnqs(n-1)+fbnqs(n-2));
//}