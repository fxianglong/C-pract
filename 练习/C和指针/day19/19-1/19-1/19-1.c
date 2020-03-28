#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
char *my_strncpy(char *dest, const char *src,int count)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	
	while (count && (*dest++ = *src++))
	{
		count--;
	}
	if (count > 0)
	{
		while (count--)
		{
			dest = NULL;
		}
	}
	return ret;
}
int main()
{
	char str1[20] = "asdfg";
	char str2[20] = "abcdef";
	printf("%s\n", my_strncpy(str1, str2, 3));
	system("pause");
	return 0;
}
