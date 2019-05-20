#include <stdio.h>
#include <string.h>
#include<assert.h>
void* My_memmove(void* dst,void const* src,size_t length)
{
	void* ret = dst;
	char* str1 = (char*)dst;
	char* str2 = (char*)src;
	assert(dst);
	assert(src);
	if (str1 > str2) 
	{
		while (length--)
		{
			*(str1 + length) = *(str2 + length);
		}
	}
	else
	{
		while (length--)
		{
			*str1++ = *str2++;
		}
	}
	return ret;
}
int main(void)
{
char s[]="ABCDEFGAIJK";
//memmove(s,s+7,strlen(s)+1-7);
My_memmove(s,s+7,strlen(s)+1-7);
printf("%s",s);
getchar();
return 0;
}