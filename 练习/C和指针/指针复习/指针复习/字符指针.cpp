#include<iostream>
using namespace std;
//int main()
//{
//	char a = '0';
//	char *b;
//	b = &a;
//	cout << a << "\n" << *b << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char* pstr = "hello bit.";//这里是把一个字符串放到pstr指针变量里了吗？
//	printf("%s\n", pstr);
//	system("pause");
//	return 0;
//}

int main()
{
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char *str3 = "hello bit.";
	char *str4 = "hello bit.";
	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	system("pause");
	return 0;
}
