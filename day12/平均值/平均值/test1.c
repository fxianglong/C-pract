#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x = 0,y = 0;
	scanf("%d%d",&x,&y);
	printf("%d",(((x^y)+((x&y) << 1))>>1));
	system("pause");
	return 0;
}
