#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void InitArry(int arr[], int sz)
{
	int i=0;
	for ( i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
}
 
void EmptyArry(int arr[], int sz)
{
	memset(arr, 0, sizeof(arr[0]) *sz);
}
 
void ReverseArry(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
 
void PrintArry(int arr[], int sz)
{
	int i=0;
	for ( i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
 
int main()
{
	int a[5];
	int sz = sizeof(a) / sizeof(a[0]);
	InitArry(a,sz);
	PrintArry(a, sz);
	ReverseArry(a, sz);
	PrintArry(a, sz);
	system("pause");
	return 0;
}