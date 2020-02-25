//#include <stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int arr[10] = { 0 };
//	printf("arr = %p\n", arr);
//	printf("&arr= %p\n", &arr);
//	printf("arr+1 = %p\n", arr + 1);
//	printf("&arr+1= %p\n", &arr + 1);
//	system("pause");
//	return 0;
//}

//#include<stdlib.h>
//#include <stdio.h>
//#include<functional>
//void print_arr1(int arr[3][5], int row, int col)
//{
//	int i = 0, j = 0;
//	for (i = 0; i<row; i++)
//	{
//		for (j = 0; j<col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print_arr2(int(*arr)[5], int row, int col)
//{
//	int i = 0,j = 0;
//	for (i = 0; i<row; i++)
//	{
//		for (j = 0; j<col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	print_arr1(arr, 3, 5);
//	//数组名arr，表示首元素的地址
//	//但是二维数组的首元素是二维数组的第一行
//	//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
//	//可以数组指针来接收
//	print_arr2(arr, 3, 5);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	system("pause");
//	return 0;
//}

//#include<stdlib.h>
//#include <stdio.h>
//#include<functional>
//int int_cmp(const void * p1, const void * p2)
//{
//	return (*(int *)p1 > *(int *)p2);
//}
//void _swap(void *p1, void * p2, int size)
//{
//	int i = 0;
//	for (i = 0; i< size; i++)
//	{
//		char tmp = *((char *)p1 + i);
//		*((char *)p1 + i) = *((char *)p2 + i);
//		*((char *)p2 + i) = tmp;
//	}
//}
//void bubble(void *base, int count, int size, int(*cmp)(const void *,const void *))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i< count - 1; i++)
//	{
//		for (j = 0; j<count - i - 1; j++)
//		{
//			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
//			{
//				_swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);
//	for (i = 0; i< sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}


//#include <stdio.h>
//#include<functional>
////qosrt函数的使用者得实现一个比较函数
//int int_cmp(const void * p1, const void * p2)
//{
//	return (*(int *)p1 > *(int *)p2);
//}
//int main()
//{5
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//int main()
//{
//
//	system("pause");
//	return 0;
//}