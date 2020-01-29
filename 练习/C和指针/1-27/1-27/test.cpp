#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	/*int i, j, k;
	i = 10; j = 10; k = 3;
	k *= i + j;*/
	//int n = 2;
	//n += n -= n*n;
	//cout << n << endl;
	/*		char *p = "abcdefgh", *r;
			long *q;5
			q = (long*)p;
			q++;
			r = (char*)q;
			printf("%s\n", r);*/
		//char str[] = "ABCD", *p = str;
		//printf("%d\n", *(p + 4));
	/*char s[] = "abcdefgh", *p = s;
	p += 3;
	printf("%d\n", strlen(strcpy(p, "ABCD")));*/

	int a[] = { 2, 4, 6, 8 }, *p = a, i;
	for (i = 0; i<4; i++)
		a[i] = *p++;
	printf("%d\n", a[2]);
	system("pause");
	return 0;
}