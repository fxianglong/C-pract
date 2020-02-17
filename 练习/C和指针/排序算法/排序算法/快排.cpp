//#include<iostream>
//#include<vector>
//#include<stack>
//using namespace std;
////void Qsort(vector<int>& arr, int low, int high){
////	if (high <= low) return;
////	int i = low;
////	int j = high + 1;
////	int key = arr[low];
////	while (true)
////	{
////		/*从左向右找比key大的值*/
////		while (arr[++i] < key)
////		{
////			if (i == high){
////				break;
////			}
////		}
////		/*从右向左找比key小的值*/
////		while (arr[--j] > key)
////		{
////			if (j == low){
////				break;
////			}
////		}
////		if (i >= j) break;
////		/*交换i,j对应的值*/
////		int temp = arr[i];
////		arr[i] = arr[j];
////		arr[j] = temp;
////	}
////	/*中枢值与j对应值交换*/
////	int temp = arr[low];
////	arr[low] = arr[j];
////	arr[j] = temp;
////	Qsort(arr, low, j - 1);
////	Qsort(arr, j + 1, high);
////}
//void QuickSortNonR(int* a, int left, int right)
//{
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, left);
//	StackPush(&st, right);
//	while (StackEmpty(&st) != 0)
//	{
//		int end = StackTop(&st);
//		StackPop(&st);
//		int begin = StackTop(&st);
//		StackPop(&st);
//		int div = PartSort1(a, begin, end);
//		if (begin < div - 1)
//		{
//			StackPush(&st, begin);
//			StackPush(&st, div - 1);
//		}
//		if (div + 1 < end)
//		{
//			StackPush(&st, div + 1);
//			StackPush(&st, end);
//		}
//	}
//}
//int main()
//{
//	vector<int> res;
//	int tmp = 0;
//	cout << "请输入要排序的数字并以任意字符作为结尾" << endl;
//	while (cin >> tmp)
//	{
//		res.push_back(tmp);
//	}
//	Qsort(res,0, res.size()-1);
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << endl;
//	system("pause");
//	return 0;
//}
