#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,1,2,3,4,5,6,0};
    int i = 0;
    //int ret = arr[0];
	for(i=1;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{
		arr[0]=arr[i]^arr[0];
	}
	printf("%d",arr[0]);
	system("pause");
	return 0;
}