#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int fun(int a, int b)
//{
//	if (a > b)
//		return (a + b);
//	else return (a - b);
//}
//#define MOD(x,y) x%y
int fun(char* s)
{
	char* p = s;
	while (*p != '\0')
	{
		p++;
	}
	return p - s;
}
int main()
{
	printf("%d", fun("goodbey!"));
	//int a[5] = { 1, 2, 3, 4, 5 };
	//int* p1 = (int*)(&a + 1);
	//int* p2 = (int*)((int)a + 1);
	//int* p3 = (int*)(a + 1);
	//printf("%d,%x,%d\n", p1[-1], p2[0], p3[1]);
	//union X{
	//	int x; char y[4];
	//}a;
	//a.x = 0x11223344;
	//printf("%x %x %x %x", a.y[1], a.y[2], a.y[3], a.y[0]);
	//printf("%d", 1 << 3 + 2);
	//unsigned long u = 0x11000000;
	//printf("%x\n", *(unsigned char*)&u);
	//char* p = "blue1";
	//char a[] = "blue1";
	//printf("%d %d %d %d", strlen(p), strlen(a), sizeof(p), sizeof(a));
	//system("pause");
	//int s = 0, n;
	//for (n = 0; n < 4; n++)
	//{
	//	switch (n)
	//	{
	//	default:s += 4;
	//	case 1:s += 1; case 2:s += 2; case 3:s += 3;
	//	}
	//}
	//printf("%d\n", s);
	//system("pause");
	//char s[] = "\\123456\123456\t";
	//printf("%d", strlen(s));
	//int a = 13, b = 94;
	//printf("%d", MOD(b, a + 4));
	//int n, m;
	//for (m = 0, n = -1; n = 0; m++, n++)
	//	n++;
	//int x = 3, y = 8, z = 6, r;
	//r = fun(fun(x, y), 2 * z);
	//printf("%d", r);
	system("pause");
}