#include<stdio.h>
#include<stdlib.h>
void huoqu_number(int x)
{
	int i = 0,count = 0;
	int a[32]={0};
	while(x)
	{
		a[i++]=x%2;
		x/=2;
		count++;
	}
	printf("�������У�> ");
	for(i=count-2;i>=0;i-=2)
	{
		printf("%d ",a[i]);
	}
	printf("\nż�����У�> ");
	for(i=count-1;i>=0;i-=2)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int x = 0;
	printf("������Ҫ��ȡ���������������е�ż��λ������λ����>");
	scanf("%d",&x);
	huoqu_number(x);
	system("pause");
	return 0;
}