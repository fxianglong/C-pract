//#include<iostream>
//#include<vector>
//using namespace std;
//void shellsort(vector<int> &res,int len)
//{
//	int d = len;
//	while (d > 1)
//	{
//		d = (d + 1) / 2;
//		for (int i = 0; i < len - d; i++)
//		{
//			if (res[i + d] < res[i])
//			{
//				int tmp = res[i];
//				res[i] = res[i + d];
//				res[i + d] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	vector<int> res;
//	int tmp = 0;
//	cout << "请输入要排序的数字并以任意字符作为结尾" << endl;
//	while (cin>>tmp)
//	{
//		res.push_back(tmp);
//	}
//	shellsort(res, res.size());
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << endl;
//	system("pause");
//	return 0;
//}