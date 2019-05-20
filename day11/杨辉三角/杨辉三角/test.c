#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
    int a[N][N];                    
    int i = 0, j = 0;                        
    for(i = 0; i < N;i++)
	{
		a[i][0]=a[i][i]=1;
	}
	for(i = 2;i<N;i++)
		for(j=1;j<i;j++)
		{
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
		for(i=0;i<N;i++)
			{for(j=0;j<=i;j++)
				{
					printf("%3d ",a[i][j]);
		}printf("\n");
		}
    system("pause");                 
    return 0;
}
