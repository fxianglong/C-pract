#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	float  sum=0;
	for(i=1;i<=100;i++)
	{
		if(i%2==1)
			sum=sum+1.0/i;
		else
			sum=sum-1.0/i;
	}
	printf("%f",sum);
	system("pause");
	return 0;
}