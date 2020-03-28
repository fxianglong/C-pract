#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void* My_memcpy(void* dst,void* src,size_t length)
{
	if((dst == NULL) ||(src == NULL))
	{
		printf("parameter error!\n");
		return 0;
	}
	char *pdst = (char*)dst;
	char *psrc = (char*)src;
	while(length --)
	{
		*pdst = *psrc;
		*pdst ++;
		*psrc++;
	}
	return dst;
}
int main()
{
	char arr1[] = "QWERT";
	char arr2[20] = {0};
	printf("%s",My_memcpy(arr2, arr1, sizeof(arr1)));
	system("pause");
	return 0;
}