#include<stdio.h>
#include<stdlib.h>
int judge_prime_number( int i)
{
	int j;
	for(j=2;i>j;j++)
	{
		if(i%j==0)
			break;
		if(i=j+1)
		return 1;
	}
	return 0;
}
void judge_prime_number_printf(int i,int ret)
{
	if(i>2)
    {
	ret = judge_prime_number(i);
	}
	if(ret)
		printf("%d������",i);
	else
		printf("%d��������",i);
	}
int main()
{
	int i,ret=1;
	printf("������Ҫ�жϵ���ֵ");
	scanf("%d",&i);
    judge_prime_number_printf(i, ret);
	system("pause");
	return 0;
}