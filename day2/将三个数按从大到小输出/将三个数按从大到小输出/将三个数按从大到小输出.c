
#include<stdio.h>
#include<stdlib.h>

	int main()
{
	int a=0,b=0,c=0;int t;
	printf("请输入比较的三个数：");
		scanf("%d%d%d",&a,&b,&c);
	if(a<b)
		{
			t=a;
			a=b;
			b=t;
	}
    if(a<c)
	{
		t=a;
		a=c;
		c=t;
	}
	if(b<c)
	{
		t=b;
		b=c;
		c=t;
	}
	printf("%d  %d  %d",a,b,c);
	system("pause");
	return 0;
}