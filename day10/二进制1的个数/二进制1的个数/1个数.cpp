#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)
{
	int count = 0;
	while(value)
	{
		if(value%2)
			count++;
		value = value/2;
	}
	return count;
}
int main()
{
	int value = 0;
	printf("请输入要统计的数>");
	scanf("%d",&value);
	printf("count=%d",count_one_bits( value));
	system("pause");
	return 0;
}