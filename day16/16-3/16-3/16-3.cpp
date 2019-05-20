#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
const char* My_strstr(const char* parr1,const char* parr2)
{
	assert(parr1 && parr2);
	const char* start = parr1;
	while(*parr1 != '\0'&&*parr2 != '\0')
	{
		if(*parr1 == *parr2)
		{
			parr1++; parr2++;
		}
		else 
		{
			parr1++;
			start = parr1;
		}
	}
	if(*parr2 == '\0')
			return start;
	return NULL;

}
int main()
{
	char arr1[]="hello";
	char arr2[]="llo";
	printf("%s\n",My_strstr(arr1,arr2));
	printf("%s\n",arr1);
	printf("%s\n",arr2);
	system("pause");
	return 0;
}