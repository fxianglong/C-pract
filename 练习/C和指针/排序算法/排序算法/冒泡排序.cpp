//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//void bubble_sort(vector<int>& arr, int len)
//{
//	int i, j;  int temp;
//	for (i = 0; i < len - 1; i++)
//	for (j = 0; j < len - 1 - i; j++)
//	if (arr[j] > arr[j + 1])
//	{
//		temp = arr[j];
//		arr[j] = arr[j + 1];
//		arr[j + 1] = temp;
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
//	bubble_sort(res, res.size());
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << endl;
//	system("pause");
//	return 0;
//}