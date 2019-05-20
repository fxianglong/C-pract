#include<stdio.h>
#include<stdlib.h>
void Judge_leap_year(int i)
{
	if((i%4==0&&i%100!=0)||(i%400==0))
		printf("%d是闰年",i);
	else
		printf("%d不是闰年\n",i);
}
int main()
{
	int i;
	printf("请输入你要判断的年份：");
		scanf("%d",&i);
	Judge_leap_year(i);
	system("pause");
	return 0;
}