#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;


//int fun(int x, int y)
//{
//	int sum = 0;
//	int N = 0;
//	for (int i = 1; i <= y;i++)
//	{
//		N = N * 10 + 1;
//		sum += N;
//	}
//	return sum;
//}


//long fun(int a, int n)
//{
//	int j = 0; long s = 0, t = 0;
//	while (j <= n)
//	{
//		j++;
//		if (j > n)break;
//		t = t*10 + a;
//		s = s + t;
//	}
//	return s;
//}
//int main()
//{
//	int x, m;
//	scanf("%d%d", &x, &m);
//	fun(x, m);
//	return 0;
//}


//class Solution {
//public:
//	string baseNeg2(int N) {
//		if (N == 0)
//			return "0";
//		int n = N;
//		string result = "";
//		while (n)
//		{
//			if (n % 2 == 0)
//			{
//				result = "0" + result;
//				n = n / (-2);
//			}
//			else{
//				result = "1" + result;
//				n = (n - 1) / (-2);
//			}
//		}
//		return result;
//	}
//};


//class Solution {
//public:
//	vector<bool> prefixesDivBy5(vector<int>& A) {
//		vector<bool> vec;
//
//		int sum = 0;
//		for (int i = 0; i < A.size(); i++)
//		{
//			sum = sum * 2 + A[i];
//			sum = sum % 5;
//			if (sum == 0)
//				vec.push_back(true);
//			else
//				vec.push_back(false);
//		}
//		return vec;
//	}
//};


//class Solution {
//public:
//	int shipWithinDays(vector<int>& weights, int D) {
//		int l = 0, r = 500 * 50000 + 1, m;
//		while (r - l > 1) {
//			m = (l + r) / 2;
//			if (cannot_achieve(weights, D, m)) {
//				l = m;
//			}
//			else {
//				r = m;
//			}
//		}
//		return r;
//	}
//	bool cannot_achieve(vector<int> &weights, int D, int m) {
//		int cnt = 0, rem = 0;
//		for (auto w : weights) {
//			if (rem >= w) {
//				rem -= w;
//			}
//			else {
//				rem = m - w;
//				++cnt;
//			}
//			if (cnt > D || m < w) return true;
//		}
//		return false;
//	}
//};
bool cannot_achieve(vector<int> &weights, int D, int m) {
	int cnt = 0, rem = 0;
	for (auto w : weights) {
		if (rem >= w) {
			rem -= w;
		}
		else {
			rem = m - w;
			++cnt;
		}
		if (cnt > D || m < w) return true;
	}
	return false;
}

int shipWithinDays(vector<int>& weights, int D) {
	int l = 0, r = 500 * 50000 + 1, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (cannot_achieve(weights, D, m)) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return r;
}


int main()
{
	vector<int> ans = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	shipWithinDays(ans, 5);
	system("pause");
	return 0;
}