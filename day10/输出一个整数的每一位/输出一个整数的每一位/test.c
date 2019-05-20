#include<stdio.h>
#include<stdlib.h>
void Printf(int x)
{
	if (x != 0)
	{
		printf("%d ", x % 10);
		Printf(x / 10);
	}
}
 
int main()
{
	int x = 0;
	scanf("%d", &x);
	Printf(x);
	system("pause");
	return 0;
 
}
