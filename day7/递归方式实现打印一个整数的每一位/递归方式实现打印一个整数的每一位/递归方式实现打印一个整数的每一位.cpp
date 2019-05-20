#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int getweishu(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return count;
} 
int main()
{
	int a = 0;int arr[100]={0};int i;
	printf("请输入一个整数：");
	scanf("%d", &a); int n=getweishu(a);
	for (i =0; i<n; i++)
	{
    arr[i]=a%10;
	a=a/10;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//#include<stdio.h>
//#include<stdlib.h>
//#include <math.h>
//void print(int n)
//{
//    if (n < 10)
//    {
//        printf("%d ", n);
//    }
//    else
//    {
//        print(n / 10);
//        printf("%d ", n % 10);
//    }
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    print(n);
//    system("pause");
//    return 0;
//}

