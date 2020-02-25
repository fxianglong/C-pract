#include<iostream>
int main()
{
	/*union Un
	{
		char c;
		int i;
	};
	union Un un;
	printf("%d\n", sizeof(un));*/

	//union Un
	//{
	//	int i;
	//	char c;
	//};
	//union Un un;
	//printf("%d\n", &(un.i));
	//printf("%d\n", &(un.c));
	//un.i = 0x11223344;
	//un.c = 0x55;
	//printf("%x\n", un.i);

	union Un1
	{
		char c[5];
		int i;
	};
	union Un2
	{
		short c[7];
		int i;
	};
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
	system("pause");
	return 0;
}
