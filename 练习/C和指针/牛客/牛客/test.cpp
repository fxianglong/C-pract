//#include<iostream>
//#include<stdlib.h>
//#include<queue>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int con = 0;
//		queue<char> _q;
//		for (int i = 0; i < n; i++)
//		{
//			char ID; cin >> ID;
//			string op; cin>>op;
//			if (op == "connect")
//			{
//				_q.push(ID);
//			}
//			else
//			{
//				con = con>_q.size()? con: _q.size();
//				_q.pop();
//			}
//		}
//		cout << con << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsZi(string s1, string s2)
{
	if (s1[1] == s2[1])
	{
		s2 = s2.substr(0, s1.size());
		if (s1 == s2)
			return true;
	}
	return false;
}
void Mkdir(vector<string> v)
{
	string mk = "mkdir -p ";
	int i = 0;
	while (i<v.size() - 1)
	{
		if (IsZi(v[i], v[i + 1]) && v[i + 1][v[i].size()] == '/')
			v.erase(v.begin() + i);
		else
			i++;
	}
	for (auto &e : v)
		cout << mk << e << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		for (int i = 0; i<n; i++)
		{
			string s1;
			cin >> s1;
			v.push_back(s1);
		}
		sort(v.begin(), v.end());
		Mkdir(v);
		cout << endl;
	}
	return 0;
}