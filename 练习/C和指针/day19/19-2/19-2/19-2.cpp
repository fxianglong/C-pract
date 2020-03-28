#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
char* My_strncat(char* dst,char* scr,size_t sz)
{
	char* ret = dst;
	assert(NULL != *dst);
	assert(NULL != *scr);
	while (*dst)
	{
		dst++;
	}
	while(sz && (*dst++ = *scr++))
		sz--;
	dst = '\0';
	return ret;
}
int main()
{
	char arr1[20] = "qwert";
	char arr2[20] = "asdfgh";
	/*printf("%s",strncat(arr1,arr2,5));*/
	printf("%s",My_strncat(arr1,arr2,5));
	system("pause");
	return 0;
}