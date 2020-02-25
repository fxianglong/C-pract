#include <stdio.h>
#include<stdlib.h>
int main()
{
	int num = 20;
	int arr[20] = { 0 };
	int* ptr = NULL;
	ptr = (int*)malloc(num*sizeof(int));
	if (NULL != ptr)//ÅĞ¶ÏptrÖ¸ÕëÊÇ·ñÎª¿Õ
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			*(ptr + i) = 0;
		}
	}
	free(ptr);
	system("pause");
	return 0;
}