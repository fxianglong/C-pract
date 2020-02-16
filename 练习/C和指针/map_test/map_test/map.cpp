//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//
//void test_map2()
//{
//	string strs[] = { "Æ»¹û", "Ïã½¶", "Æ»¹û", "Æ»¹û", "Ïã½¶", "Àæ" };
//	map<string, int> countMap;
//	for (auto str : strs){
//		int ret = strs.find(str);
//		if (ret!=end())
//		{
//			ret.second++:
//		}
//		else 
//
//	}
//}
//int main()
//{
//
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
void GetFavoriteFruit(const vector<string>& fruits, size_t k){
	map<string, int> a;
	for (auto e : fruits){
		a[e]++;
	}
	vector<pair<string, int>> strs(a.begin(),a.end());
	std::sort(strs.begin(), strs.end(), [](const pair<string,int> &l, const pair<string,int> &r)
	{
		if (l.second == r.second){
			for (int i = 0; i < min(l.first.size(), r.first.size()); i++)
			{
				if (l.first[i] == r.first[i])
					continue;
				return l.first[i] < r.first[i];
			}
		}
		return l.second>r.second;
	});
	for (int i = 0; i < k; i++){
		cout << strs[i].first<<":"<<strs[i].second << endl;
	}
}