
#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int i=0; int arr[10]={0};	int max=0;
	printf("������Ҫ�Ƚϵ�ʮ������");
	for(i=0;i<10;i++)
		{
			scanf("%d",&arr[i]);
	    }
	for(i=0;i<10;i++)
	{
		if(arr[i]>max)
			max = arr[i];
	}
	printf("%d",max);
	system("pause");
	return 0;
}