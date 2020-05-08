//#include<stdio.h>
//class A
//{
//public:
//	virtual void f(){}
//public:
//	A()
//	{
//		f();
//	}
//};
//class B1 :public A
//{
//private:
//	char *_s;
//public:
//	B1()
//	{
//		_s = new char[1024];
//	}
//private:
//	void f()
//	{
//		delete _s;
//		_s = NULL;
//	}
//};
//class B2 :public A
//{
//private:
//	int * _m;
//public:
//	B2()
//	{
//		_m = new int(2016);
//	}
//private:
//	virtual void f()
//	{
//		delete _m;
//		_m = NULL;
//	}
//};
//int main()
//{
//	A*a1 = new B1;
//	A*a2 = new B2;
//	delete a1;
//	delete a2;
//	return 0;
//}



//#include <iostream>
//#include <math.h>
//#include <string.h>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int key[14] = { 77, 28, 38, 41, 45, 1, 9, 31, 99, 51, 23, 47, 68, 61 };
//	int remain[14];
//	int remain_conts = 0;
//	int temp;
//	int p = 0;
//	while (++p)
//	{
//		remain_conts = 0;
//		for (int i = 0; i < 14; i++)
//		{
//			temp = key[i] % p;
//			int j = 0;
//			for (; j < remain_conts; j++)
//			{
//				if (remain[j] == temp) break;
//			}
//			if (j == remain_conts)
//			{
//				remain[remain_conts++] = temp;
//			}
//		}
//		if (abs((float)remain_conts / p - 0.8) < 0.1)
//		{
//			break;
//		}
//	}
//	cout << p << endl;
//	cout << "对应的余数:" << endl;
//	for (int i = 0; i< 14; i++)
//	{
//		cout << key[i] % p << endl;
//	}
//	system("pause");
//	return 0;
//}


//class Solution {
//public:
//	int maximalSquare(vector<vector<char>>& matrix) {
//		if (matrix.size() == 0 || matrix[0].size() == 0)
//			return 0;
//		int maxS = 0;
//		int row = matrix[0].size();
//		int col = matrix.size();
//		vector<vector<int>> dp(col, vector<int>(row, 0));
//		for (int i = 0; i<col; i++)
//		{
//			for (int j = 0; j<row; j++)
//			{
//				if (matrix[i][j] == '1')
//				{
//					if (i == 0 || j == 0)
//						dp[i][j] = 1;
//					else{
//						dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
//					}
//					if (maxS<dp[i][j]) maxS = dp[i][j];
//				}
//			}
//		}
//		return maxS*maxS;
//	}
//};


