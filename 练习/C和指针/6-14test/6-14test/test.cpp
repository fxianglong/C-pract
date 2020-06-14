#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ans[4][4];
	for (int i = 0; i < 4; i++)
	{	for (int j = 0; j < 4; j++)
	{
		scanf("%d", &ans[i][j]);
	}
}
	
	for (int i = 0; i < 4; i++)
	{
		int temp;
		temp = ans[0][i];
		ans[0][i] = ans[2][i];
		ans[2][i] = temp;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%5d", ans[i][j]);
		}
		printf("\n");
	}
	system("pause"); 
	return 0;
}
