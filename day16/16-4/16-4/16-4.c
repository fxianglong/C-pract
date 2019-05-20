#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char const* My_strchr(char const* parr,char ch)
{
	assert(parr);
	while(*parr != '\0')
	{
		if(*parr == ch)
			return parr;
		else parr++;
	}
		return 0;
}
int main()
{
	char arr[] = "ABCDEFG";
	char a = 'B';
	printf("%s\n",My_strchr(arr,a));
	printf("%s\n",arr);
	printf("%c\n",a);
	system("pause");
	return 0;
}