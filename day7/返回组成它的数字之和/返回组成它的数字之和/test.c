#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n)
{
	if(n>9)
	return DigitSum(n/10)+n%10;
	else
		return n;
}
int main()
{
	int n=0;
	printf("请输入非负整数");
	scanf("%d",&n);
	printf("%d\n",DigitSum(n));
	system("pause");
	return 0;
}
