//#include<iostream>
//#include<vector>
//using namespace std;
//void selectsort(vector<int> &res, int len)
//{
//	int i=0, j=0, m = 0;
//	for (int i = 0; i < len - 1; i++)
//	{
//		m = i;
//		for (j = i + 1; j < len;j++)
//		if (res[j]<res[m]) m = j;
//		if (m != i){
//			int tmp = res[i];
//			res[i] = res[m];
//			res[m] = tmp;
//		}
//	}
//}
//int main()
//{
//	vector<int> res;
//	int tmp = 0;
//	cout << "������Ҫ��������ֲ��������ַ���Ϊ��β" << endl;
//	while (cin >> tmp)
//	{
//		res.push_back(tmp);
//	}
//	selectsort(res, res.size());
//	for (int i = 0; i < res.size(); i++)
//		cout << res[i] << endl;
//	system("pause");
//	return 0;
//}