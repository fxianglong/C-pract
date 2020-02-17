//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[] = { 43, 2, 3, 5, 76, 87, 45, 345, 5 };
//	int k = sizeof(a) / sizeof(a[0]);
//	int i = 0, j = 0;
//	for (i = 1; i < k; i++)
//	{
//		if (a[i] < a[i - 1])
//		{
//			int tmp = a[i];
//			for (j = i - 1; j>=0 && a[j] > tmp; j--){
//				a[j+1] = a[j];
//			}
//			a[j + 1] = tmp;
//		}
//	}
//	for (int i = 0; i < k; i++)
//		cout << a[i] << endl;
//	system("pause");
//	return 0;
//}