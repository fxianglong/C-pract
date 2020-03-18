////1.Å£¿Í-µç»°ºÅÂë
//#include<iostream>
//#include<string>
//#include<vector>
//#include<set>
//using namespace std;
//int main()
//{
//	int n = 0;
//	string res = "22233344455566677778889999";
//	while (cin >> n){
//		string s = "";
//		set<string> ans;
//		for (int j = 0; j < n; j++){
//			cin >> s;
//			string str;
//			int cnt = 0;
//			for (int i = 0; i < s.size(); i++){
//				if (s[i] >= 'A'&&s[i] <= 'Z'){
//					str += res[s[i] - 'A'];
//					cnt++;
//					if (cnt == 3)
//						str += '-';
//				}
//				else if (s[i] >= '0'&&s[i] <= '9')
//				{
//					str += s[i];
//					cnt++;
//					if (cnt == 3)
//						str += '-';
//				}
//			}
//			ans.insert(str);
//		}
//		for (auto it = ans.begin(); it != ans.end(); it++){
//			cout << *it << endl;
//		}
//		cout << endl;
//	}
//	return 0;
//}



//#include<iostream>
//#include<vector>
//#include<map>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	map<int, int> dict;
//	vector<int> ans;
//	for (int i = 0; i < n; i++)
//		ans.push_back(i + 1);
//	if (m < n)
//		n = m;
//	for (int i = 1; i < n / 2; i++){
//		dict.insert(make_pair(n - i, i));
//	}
//	for (auto it = dict.begin(); it != dict.end(); it++)
//	{
//		cout << it.first << " " << it.second << endl;
//	}
//}



#include<iostream>
#include<vector>
using namespace std;
void GetFunc(int start, int n, int m, vector<int> v)
{
	if (m == 0)
	{
		for (int i = 0; i<v.size(); ++i)
			i == 0 ? cout << v[i] : cout << " " << v[i];
		cout << endl;
		return;
	}

	if (m < 0 || start>n)
		return;

	v.push_back(start);
	GetFunc(start + 1, n, m - start, v);

	v.pop_back();
	GetFunc(start + 1, n, m, v);
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v;
		int start = 1;
		GetFunc(start, n, m, v);
	}
	return 0;
}