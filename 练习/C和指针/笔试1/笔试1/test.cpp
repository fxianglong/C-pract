//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string str1, str2; string ans;
//	getline(cin, str1);
//	getline(cin, str2);
//	if (str1 == "")
//		return 0;
//	if (str2 == "")
//	{
//		cout << str1 << endl;
//		return 0;
//	}
//	for (int i = 0; i < str1.size(); i++)
//	{
//		for (int j = 0; i<str1.size()&&j < str2.size(); j++)
//		{
//			if (str1[i] == str2[j])
//				i++;
//		}
//		ans.push_back(str1[i]);
//	}
//	cout << ans << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str1;
//	string str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int hash[256];
//	for (int i = 0; i < str2.size(); i++)
//	{
//		hash[str2[i]]++;
//	}
//  string res;
//	for (string::iterator it = str1.begin(); it != str1.end();it++)
//	{
//		if (hash[str1[i]==0)
//			res = res+str[i];
//	}
//	cout << str1 << endl;;
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	vector<int> ans;
//	int T = 0;
//	cin >> T;
//	if (T <= 0)
//		return 0;
//	int i = 0;
//	while (T--)
//	{
//		cin >> i;
//		ans.push_back(i);
//	}
//	int sum = 0;
//	int maxs = 0;
//	for (int i = 0; i < ans.size(); i++)
//	{
//		if (ans[i]>0)
//		{
//			sum += ans[i];
//			continue;
//		}
//		maxs = max(maxs, sum);
//	}
//	cout << maxs << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//bool Is24(vector<int> ans,int res)
//{
//
//}
//int main()
//{
//	vector<int> ans;
//	for (int i = 0; i < 4; i++)
//	{
//		int x = 0;
//		cin >> x;
//		ans.push_back(x);
//	}
//	if (Is24(ans, 24))
//		cout << "true"<<endl;
//	else cout << "false" << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	for (int i = 0; i < str2.size(); i++)
//	{
//		int index;
//		while ((index = (str1.find(str2))) != -1)
//			str1.erase(index, 1);
//	}
//	cout << str1 << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string str1;
//	string str2;
//	string res;
//	getline(cin, str1);
//	getline(cin, str2);
//	int hashtable[256] = { 0 };
//	for (int i = 0; i < str2.size(); i++)
//	{
//		hashtable[str2[i]]++;
//	}
//	for (int i = 0; i < str1.size(); i++)
//	{
//		if (hashtable[str1[i] == 0])
//			res += str1[i];
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int a[1000000];
//	int sum = 0;
//	int max = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//		sum += a[i];
//		if (sum>max)
//			max = sum;
//		if (sum < 0)
//			sum = 0;
//	}
//	cout << max << endl;
//	return 0;
//}

#include<iostream>
using namespace std;
bool Istrue(int a[4],int index)
{
	
	return true;
}
int main()
{
	int a[4] = { 0 };
	for (int i = 0; i < 4; i++)
		cin >> a[i];
	if (Istrue(a, 24))
		cout << "true";
	else cout << "false" << endl;
	system("pause");
	return 0;
}