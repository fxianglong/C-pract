#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int count=0,i=0;
	for(i=1;i<=100;i++)
	{
		if(i%9==0)
			{
				count ++;
		if(i/9==0)
			count++;
	}
	}
	printf("%d",count);
	system("pause");
	return 0;
}