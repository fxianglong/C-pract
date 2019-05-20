#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[]={12,23,34,64,21,2,24,23};
	int b[]={13,25,75,12,23,5,67,89};
	int i,sz,t;
	sz=sizeof(a)/sizeof(a[0]);
	for(i=0;i<sz;i++)
	{
		t=a[i];
		a[i]=b[i];
		b[i]=t;
	}
	printf("a[]=");
	for(i=0;i<sz;i++)
		printf("%d  ",a[i]);
	printf("b[]=");
	for(i=0;i<sz;i++)
		printf("%d  ",b[i]);
	system("pause");
	return 0;
}