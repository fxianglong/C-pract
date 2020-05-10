#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


//int calculateMinimumHP(vector<vector<int>>& dungeon) {
//	int n = dungeon.size(), m = dungeon[0].size();
//	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
//	dp[n][m - 1] = dp[n - 1][m] = 1;
//	for (int i = n - 1; i >= 0; --i) {
//		for (int j = m - 1; j >= 0; --j) {
//			int minn = min(dp[i + 1][j], dp[i][j + 1]);
//			dp[i][j] = max(1, minn - dungeon[i][j]);
//		}
//	}
//	return dp[0][0];
//}
//
//int main()
//{
//	vector<vector<int>> ans{ { -2, -3, 5 }, { -5, -10, 1 }, { 10, 30, -5 } };
//	calculateMinimumHP(ans);
//	return 0;
//}



//int numPairsDivisibleBy60(vector<int>& time) {
//	int len = time.size();
//	if (len < 2) {
//		return 0;
//	}
//
//	int cnt = 0;
//	vector<int> remains(60, 0);
//	for (int i = len - 1; i >= 0; --i) {
//		int remain = time[i] % 60; // 计算余数
//		cnt += remains[(60 - remain) % 60]; // 找到它的小伙伴
//		++remains[remain]; // 记录当前余数的个数
//	}
//	return cnt;
//}
//
//
//int main()
//{
//	vector<int> ans={30,40,20,30,150,140};
//	numPairsDivisibleBy60(ans);
//	system("pause");
//	return 0;
//}



//int fact(int n){
//	if (n == 1 || n == 0)  return 1;
//	return n*fact(n - 1);
//}
//int A(int m, int n){
//	return fact(m) / fact(m - n);
//}
//int numDupDigitsAtMostN(int N) {
//	//求N的位数n
//	string strN = to_string(N);
//	int n = strN.size();
//
//	int used[10] = { 0 };
//	int total = 0;
//
//	//位数比n小的
//	for (int i = 1; i<n; i++)
//		total += 9 * A(9, i - 1);
//
//	//位数和n一样的
//	for (int i = 0; i<n; i++){
//		int num = strN[i] - 48;
//		for (int j = (i == 0 ? 1 : 0); j<num; j++){
//			if (used[j] != 0)
//				continue;
//			total += A(10 - 1 - i, n - i - 1);
//		}
//		if (++used[num]>1)
//			break;
//		if (i == n - 1)
//			total += 1;
//	}
//	return N - total;
//}
//
//
//int main()
//{
//	int n = 3456;
//	numDupDigitsAtMostN(n);
//	system("pause");
//	return 0;
//}
//
//class Solution {
//public:
//	int maxScoreSightseeingPair(vector<int>& A) {
//		int left = A[0] + 0;
//		int Max = 0;
//		for (int i = 1; i<A.size(); i++)
//		{
//			Max = max(Max, left + A[i] - i);
//			left = max(left, A[i] + i);
//		}
//		return Max;
//	}
//};


//int smallestRepunitDivByK(int K) {
//	if (K % 2 == 0 || K % 5 == 0)
//		return -1;
//	int len = 1;
//	for (int i = 1; i % K != 0; len++)
//	{
//		i = i % K;
//		i = i * 10 + 1;
//	}
//	return len;
//}
//int main()
//{
//	cout<<smallestRepunitDivByK(7);
//	system("pause");
//	return 0;
//
//}


bool queryString(string S, int N) {

	for (int i = 1; i <= N; i++)
	{
		string s = "";
		int m = i;
		while (m)
		{
			s += to_string(m % 2);
			m /= 2;
		}
		reverse(s.begin(),s.end());
		if (S.find(s)==-1)
			return false;
		int n = S.find(s);
	}
	return true;
}

int main()
{
	string s = "0110";
	queryString(s, 4);
	system("pause");
	return 0;
}