//1.��ɸѡ����100���ڵ�������
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int main()
//{
//	int i ,j ,a[101];
//	for(i = 1;i<101;i++)
//		a[i] = i;
//	    a[1] = 0;
//	for(i = 2;i <= sqrt(100.0);i++)
//		for(j = i+1;j<101;j++)
//		{
//			if(a[i] != 0&&a[j] != 0)
//			if(a[j] % a[i] == 0)
//				a[j] = 0;
//		}
//	for(j = 2;j < 101;j++)
//	{
//		if(a[j] != 0)
//			printf("%d ",a[j]);
//		if(n%10 == 0)
//			printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//2.��ѡ�񷨶�ʮ����������
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int a[11] = {0};int i = 0,j = 0;
//	for(i = 1;i < 11;i++)
//		scanf("%d",&a[i]);
//	for(i = 1;i < 11;i++)
//		for(j = i+1;j <= 10;j++)
//		if(a[i]>=a[j])
//		{
//			a[i] = a[i]^a[j];
//			a[j] = a[i]^a[j];
//			a[i] = a[i]^a[j];
//		}
//		for(i = 1;i<11;i++)
//			printf("%d ",a[i]);
//	system("pause");
//	return 0;
//}
//3.��һ��3x3�����;���Խ���Ԫ��֮��
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i = 0,j = 0,a[3][3] = {0},sum = 0;
//	for(i = 0;i < 3;i++)
//		for(j = 0;j < 3;j++)
//			scanf("%d",&a[i][j]);
//	for(i = 0;i < 3;i++)
//		sum = sum + a[i][i];
//	printf("%d",sum);
//	system("pause");
//	return 0;
//}
//4.��һ�����ź�������飬Ҫ������һ�����󣬰�ԭ������Ĺ��ɽ�������������
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a[11] = {1,2,3,4,6,8,9,21,22,56};int New = 0,i = 0,j = 0,tmp = 0,ret = 0,end = 0;
//	for(i = 0;i < 11;i++)
//		printf("%d  ",a[i]);
//		scanf("%d",&New);
//		end = a[9];
//	if(a[9] <= New)
//		a[10] = New;
//	else 
//	{
//		for(i = 0;i<10;i++)
//		{
//			if(a[i] > New)
//			{
//				tmp = a[i];
//				a[i] = New;
//				for(j = i+1;j < 11;j++)
//				{
//					ret = a[j];
//					a[j] = tmp;
//					tmp = ret;
//				}
//			}break;
//		}
//	}
//	for(i = 0;i<11;i++)
//		printf("%d ",a[i]);
//	system("pause");
//	return 0;
//}
//5.��һ�������е�ֵ���������´�š����磺ԭ��˳��Ϊ8,6,5,4,1��Ҫ���Ϊ1,4,5,6,8.
#include<stdio.h>
#include<stdlib.h>
#define N 5
int main()
{
	int i = 0,a[N] = {0};
	for(i = 0;i < N;i++)
		scanf("%d",&a[i]);
	for(i = 0;i < (N/2);++i)
	{
		a[i] = a[i]^a[N-i-1];
		a[N-i-1] = a[i]^a[N-i-1];
		a[i] = a[i]^a[N-i-1];
	}
	for(i = 0;i < N;i++)
		printf("%d ",a[i]);
	system("pause");
	return 0;
}