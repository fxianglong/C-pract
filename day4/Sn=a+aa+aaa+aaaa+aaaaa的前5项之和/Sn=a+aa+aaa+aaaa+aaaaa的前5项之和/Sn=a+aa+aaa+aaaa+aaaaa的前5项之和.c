#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0,i=0,t=0,sum=0;
	printf("«Î ‰»Îa: ");
	scanf("%d",&a);
	for(i=1;i<=5;i++)
		{t=t*10+a;
	sum=sum+t;
	}
	printf("%d\n",sum);
	system("pause");
	return 0;
}