//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//
//char* Mystrcat(char* dest, const char* src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest)
//	{
//		dest++;
//	}
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char s[12] = "gtfcvg";
//	char ans[] = "hy";
//	Mystrcat(s, ans);
//	system("pause");
//	return 0; 
//}

//#include <stdio.h>
//#include <string.h>
//#include<stdlib.h>
//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "To be ");
//	strcpy(str2, "or not to be");
//	strncat(str1, str2, 6);
//	puts(str1);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include<stdlib.h>
//
//int main()
//{
//	char str[][5] = { "R2D2", "C3PO", "R2A6" };
//	int n;
//	puts("Looking for R2 astromech droids...");
//	for (n = 0; n<3; n++)
//	if (strncmp(str[n], "R2xx", 2) == 0)
//	{
//		printf("found %s\n", str[n]);
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include<stdlib.h>
//int main()
//{
//	char str[] = "This is a simple string";
//	char * pch;
//	pch = strstr(str, "simple");
//	strncpy(pch, "sample", 6);
//	puts(str);
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include<stdlib.h>
//
//int main()
//{
//	char str[] = "- This, a sample string.";
//	char * pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok(NULL, " ,.-");
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <ctype.h>
//#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	char str[] = "Test String.\n";
//	char c;
//	while (str[i])
//	{
//		c = str[i];
//		if (isupper(c))
//			c = tolower(c);
//		putchar(c);
//		i++;
//	}
//	system("pause");
//	return 0;
//}

//#include<stdlib.h>
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char str[] = "memmove can be very useful......";
//	memmove(str + 20, str + 15, 11);
//	puts(str);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";
	int n;
	n = memcmp(buffer1, buffer2, sizeof(buffer1));
	if (n>0) printf("'%s' is greater than 	'%s'.\n", buffer1, buffer2);
	else if (n<0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
	system("pause");
	return 0;
}