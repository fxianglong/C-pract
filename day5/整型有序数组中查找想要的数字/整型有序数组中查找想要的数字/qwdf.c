#include<stdio.h>
#include<stdlib.h>
int  BinarySearch(int arr[],int i,int x,int y)
{
	int mid;
	while(x<=y)
	{
		mid=x+(y-x)/2;
			if(arr[mid]>i)
				y=mid-1;
		if(arr[mid]<i)
			x=mid+1;
		if(arr[mid]==i)
			return mid;
	}
	return 0;
}
int main()
{
	int l=0; int arr[9]={1,2,3,4,5,6,7,8,9};
	int r=sizeof(arr)/sizeof(arr[0]);
	int i;int ret;
	printf("请输入你要查找的值：");
	scanf("%d",&i);
	 ret=BinarySearch(arr,i,l,r);
	if(ret)
		printf("%d",ret);
	else
		printf("-1");
	system("pause");
	return 0;
}