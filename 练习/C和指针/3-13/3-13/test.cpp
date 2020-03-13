//#include<iostream>
//#include<string>
//using namespace std;
//int Fun(string s)
//{
//	int ret = 0;
//	for (int i = 0; i<s.size(); i++)
//	{
//		ret = ret * 26 + s[i] - 'a';
//	}
//	return ret;
//}
//int main()
//{
//	string str1, str2;
//	int l1, l2;
//	while (cin >> str1 >> str2 >> l1 >> l2)
//	{
//		cout << (Fun(str2) - Fun(str1) - 1) % 1000007 << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string m, n;
//	while (cin >> m >> n){
//		int a[256] = { 0 }; int count = 0;
//		for (int i = 0; i < m.size(); i++)
//		{
//			a[m[i]] = 1;
//		}
//		for (int i = 0; i < n.size(); i++)
//		{
//			if (a[n[i]] == 1)
//			{
//				a[n[i]]++;
//				count++;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}



#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
		for (int i = 1; i <= s1.size(); i++)
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
		}
		cout << dp[s1.size()][s2.size()] << endl;
	}
	return 0;
}