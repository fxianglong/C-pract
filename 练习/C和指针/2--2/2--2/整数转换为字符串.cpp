////将一个整数转换为字符串并打印出来
//方法1：
//#include<string>
//#include<iostream>
//using namespace std;
//string s = "";
//void Printf(int i)
//{
//	if (i % 10)
//	{
//		Printf(i / 10);
//		s += (i % 10+'0');
//	}
//}
//int main()
//{
//	int i = 0;
//	cin >> i;
//	Printf(i);
//	cout << s << endl;
//	system("pause");
//}

//方法2

//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
//using namespace std;
//int main()
//{
//	int s = 234567;
//	char str[100];
//	_itoa(s, str, 10);
//	printf("%d,%s", s, str);
//	system("pause");
//	return 0;
//}