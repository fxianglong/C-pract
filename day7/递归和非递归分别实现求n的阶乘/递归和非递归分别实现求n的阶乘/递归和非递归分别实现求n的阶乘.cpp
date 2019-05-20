#include<stdio.h>
#include<stdlib.h>
int Factorial(int i)
{
	if(i>1)
		return i*Factorial(i-1);
	else if(i==1)
		return 1;

}
int main()
{
	int i = 0;
	printf("请输入求阶乘的值：");
	scanf("%d",&i);
	printf("%d\n",Factorial(i));
	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int Factorial(int i)
//{
//	int j = 0,mul = 1;
//	for(j=1;j<=i;j++)
//	{
//		mul=mul*j;
//	}
//	return mul;
//}
//int main()
//{
//	int i = 0;
//	printf("请输入求阶乘的值：");
//	scanf("%d",&i);
//	printf("%d",Factorial(i));
//	system("pause");
//	return 0;
//}