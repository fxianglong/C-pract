#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m = 0;  
	int n = 0;
	for (m=101;m<=200;m++)
		for(n=2;n<m;n++)
			{if (m%n==0)
				break;
             if (m==n+1)
				 printf ("%d ",m);
		}
	system("pause");
	return 0;
}