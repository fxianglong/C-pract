#include<stdio.h>
#include<stdlib.h>
int main()
{ int i=0,a=0,b=0,c=0;
	for(i=100;i<=999;i++)
	{
		a=i/100;
		c=i%10;
		b=i/10-a*10;
		
		if(i==a*a*a+b*b*b+c*c*c)
			printf("%d  ",i);
	}
	system("pause");
	return 0;
}