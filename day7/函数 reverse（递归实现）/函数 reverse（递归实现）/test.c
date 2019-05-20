#include <stdio.h>
#include "stdlib.h"
#include<stdio.h>
void reverse_string(char *string)
{
	if ('\0' != *(++string))
		reverse_string(string);
	printf("%c", *(string -1));
}

int main()
{
	char *a = "abcd";
	reverse_string(a);
	printf("\n");
	system("pause");
	return 0;
}
