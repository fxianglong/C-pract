#include<stdio.h>
#include<stdlib.h>
void Judge_leap_year(int i)
{
	if((i%4==0&&i%100!=0)||(i%400==0))
		printf("%d������",i);
	else
		printf("%d��������\n",i);
}
int main()
{
	int i;
	printf("��������Ҫ�жϵ���ݣ�");
		scanf("%d",&i);
	Judge_leap_year(i);
	system("pause");
	return 0;
}