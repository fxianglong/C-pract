//#include<stdio.h>
//
////typedef struct student{
////	int sid;
////	char name[20];
////	int age;
////	char tel[15];
////}student;
//
//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { { 1, 2, 3, 4 }, 1000 };
////�ṹ�崫��
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////�ṹ���ַ����
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s); //���ṹ��
//	print2(&s); //����ַ
//	return 0;
//}
#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;//�������ս��
//	int n = 0;
//	int ret = 1;//����n�Ľ׳�
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		ret = 1;
//		for (j = 1; j <= i; j++)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}
//
//#include <stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	system("pause");
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a = 10;
//	int b = -5;
//
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int system_duan()
//{
//	int i = 1;
//	return (*(char*)&i);
//}
//int main()
//{
//	int ret = system_duan();
//	if (ret == 1)
//		printf("С�˻�");
//	else
//	{
//		printf("��˻�");
//	}
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//
//	int n = 9;
//	float *pFloat = (float *)&n;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("n��ֵΪ��%d\n", n);
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	return 0;
//}

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned char i = 0;
int main()
{
	/*int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);*/

	/*unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
	}*/

/*
	char a[1000];
	int i;
	for (i = 0; i<1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));*/




		for (i = 0; i <= 255; i++)
		{
			printf("hello world\n");
		}
		return 0;

	system("pause");
	return 0;
}