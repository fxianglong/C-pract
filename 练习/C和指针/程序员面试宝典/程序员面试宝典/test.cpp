#include<iostream>
using namespace std;
//int main()
//{
//	printf("%f", 5);
//	printf("%d", 5.01);
//	system("pause");
//}
union{
	unsigned char a;
	unsigned int i;
}u;
int main()
{
	u.i = 0xf0f1f2f3;
	cout << hex << u.i << endl;
	cout << hex << int(u.a) << endl;
	system("pause");
	return 0;
}