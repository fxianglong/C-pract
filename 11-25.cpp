//#include<iostream>
//using namespace std;
//int Fun(int N, int i)
//{
//	if (i == 1 || i == 2 * N - 1)
//		return 1;
//	if (i<1 || i>2 * N - 1)
//		return 0;
//	else
//		return Fun(N - 1, i - 1) + Fun(N - 1, i) + Fun(N - 1, i + 1);
//}
//int main()
//{
//	int N; cin >> N;
//	for (int i = 0; i <= 2 * N - 1; i++)
//	{
//		if (Fun(N, i) % 2 == 0)
//		{
//			cout << i << endl; break;
//		}
//		else if (i = 2 * N - 1)
//			cout << "-1" << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	char ss[512];
//	string s;
//	string s1, s2;
//	int i, j, len1, len2, lmax;
//	while (cin >> s1 >> s2)
//	{
//		len1 = s1.length();
//		len2 = s2.length();
//		reverse(s1.begin(), s1.end());
//		reverse(s2.begin(), s2.end());
//		lmax = len1>len2 ? len1 : len2;
//		int temp = 0;
//		int sum[512];
//		int k = 0, j;
//		for (i = 0; i<lmax; i++)
//		{
//			int a = 0, b = 0;
//			if (i<len1)
//				a = s1[i] - '0';
//			else
//				a = 0;
//			if (i<len2)
//				b = s2[i] - '0';
//			else
//				b = 0;
//			int result = a + b + temp;
//			temp = result>9 ? 1 : 0;
//			sum[k++] = result % 10;
//		}
//		if (temp>0)
//		{
//			sum[k] = 1;
//			for (j = k; j >= 0; j--)
//				cout << sum[j];
//		}
//		else
//		{
//			for (j = k - 1; j >= 0; j--)
//				cout << sum[j];
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int Sum(int x)
//{
//	int oneCount = 1;
//	int twoCount = 0;
//	int threeCount = 0;
//
//	int start = 1;
//	while (start < x)
//	{
//		int tmp = oneCount;
//		oneCount = twoCount + threeCount;
//		twoCount = tmp;
//		threeCount = oneCount;
//	start++;
//	}
//	return oneCount + twoCount + threeCount;
//}
//int main()
//{
//	int m;
//	while (cin >> m)
//	{
//		cout << Sum(m) << endl;
//	}
//	return 0;
//}


#include<iostream>
#include<string>
using namespace std;
bool IsTpf(const char* p, const char* q)
{
	if (*p == '\0' && *q == '\0')
		return true;
	else if (*p == '\0' || *q == '\0')
		return false;
	if (*p == '?')
	{
		return IsTpf(p + 1, q + 1);
	}
	else if (*p == '*')
	{
		return IsTpf(p + 1, q) || IsTpf(p + 1, q + 1) || IsTpf(p + 1, q + 1);
	}
	else if (*p == *q)
	{
		return IsTpf(p + 1, q + 1);
	}
	return false;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (IsTpf(s1.c_str(), s2.c_str()))
			cout << "true" << endl;
		else
		{
			cout << "false" << endl;
		}
	}
	return 0;
}