#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int my_strcmp(const char *string1,const char *string2)
{
    const char *p = string1;
    const char *q = string2; 
	assert(NULL != string1);
    assert(NULL != string2);
    while(*p == *q)
    {
        if(*p == '\0')
        {
            return 0;
        }
        p++;
        q++;
    }
    return *(unsigned char*)p - *(unsigned char*)q; 
}
int main()
{
	char arr1[]="ABCDEF";
	char arr2[]="ABCDEF";
	int ret = my_strcmp(arr1,arr2);
	if(ret > 0) ret = 1;
	if(ret < 0) ret = -1;
	printf("%d",ret);

	system("pause");
	return 0;
}