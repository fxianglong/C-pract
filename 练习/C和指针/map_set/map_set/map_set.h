#include<map>
//#include<set>
//#include<iostream>
//#include<vector>
//#include<list>
//#include<algorithm>
//#include<string>
//#include<queue>
//#include<forward_list>
//#include <functional>
//using namespace std;
//��Ч->ȥ�ء�����	
//void test_set1()
//{
//	set<int> s;
//	s.insert(3);
//	s.insert(5);
//	s.insert(3);
//	s.insert(1);
//	set<int>::iterator it = s.begin();
//	for (; it != s.end(); it++)
//		cout << *it << endl;
//	s.erase(3);
//	for (it=s.begin(); it != s.end(); it++)
//		cout << *it << endl;
//}

//map  key/value -> �ֵ�/ͳ�ƴ���
//void test_map()
//{
//	map<string, string> dict;
//	dict.insert(pair<string, string>("insert", "����"));
//	dict.insert(pair<string, string>("sort", "����"));
//	dict.insert(pair<string, string>("string", "�ַ���"));
//	auto it = dict.begin();
//	while (it != dict.end())
//	{
//		cout << (*it).first << ":" << (*it).second << endl;
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//	cout << endl;
//
//	string str;
//	while (cin >> str)
//	{
//		auto ret = dict.find(str);
//		if (ret != dict.end())
//			cout << ret->second << endl;
//		else cout << "û��������ʣ�����������" << endl;
//	}
//}
//template<class K,class V>
//mapped_type& operator[](const& key_type&k)
//{
//	return (*((this->insert(make_pair(k, key_type()))).first.second);
//}
//operator[]���ã�1������������key��Ӧ��valueֵ������  �������壺a,��keyӳ��value   b,�޸�keyӳ���value
//2.key����������-������make_pair(key,V())

//void map_test2()
//{
//	string strs[] = { "ƻ��", "�㽶", "⨺���", "ƻ��", "�㽶", "⨺���", "�㽶", "⨺���" };
//	map<string, int> countMap;
//	//for (auto str : strs)
//	//{
//	//	map<string, int>::iterator ret = countMap.find(str);
//	//	if (ret != countMap.end())
//	//	{
//	//		/*ret->second++;*/
//	//		(countMap[str])++;
//	//	}
//	//	else {
//	//		countMap.insert(pair<string, int>(str, 1));
//	//	}
//	//}
//	for (auto str : strs)
//	{
//		//pair<map<string,int>::iterator,bool> ret = countMap.insert(pair<string, int>(str, 1));
//		//auto ret = countMap.insert(pair<string, int>(str, 1));
//		//if (ret.second == false)
//		//{
//		//	ret.first->second++;
//		//}
//
//		//����+�޸�
//		countMap[str]++;
//	}
//
//	cout << string() << endl;
//	cout << int() << endl;
//
//}
//void GetFavoriteFruit(const vector<string>&fruits, size_t k)
//{
//	map<string, int> ans;
//	for (auto& str : fruits)
//	{
//		ans[str]++;
//	}
//	vector<pair<string, int>> res(ans.begin(), ans.end());
//	/*sort(res.begin(), res.end(), [](const pair<string,int>&k,const pair<string,int>&v){
//		if (k.second == v.second)
//		{
//			for (size_t i = 0; i<min(k.first.size(), v.first.size()); ++i){
//				if (k.first[i] == v.first[i]) continue;
//				return k.first[i] < v.first[i];
//			}
//		}
//		return k.second > v.second;
//	});*/
//	for (int i=0; i<k; i++)
//	{
//		cout << res[i].first << ":" << res[i].second << endl;
//	}
//}
//bool CountCompare[](const pair<string, int>&k, const pair<string, int>&v){
//	if (k.second == v.second)
//	{
//		for (size_t i = 0; i<min(k.first.size(), v.first.size()); ++i){
//			if (k.first[i] == v.first[i]) continue;
//			return k.first[i] < v.first[i];
//		}
//	}
//	return k.second > v.second;
//}
//struct CountCompare
//{
//	bool operator()(const pair<string, int>& l, const pair<string, int>& r)
//	{
//		return l.second > r.second;
//	}
//};
//void GetFavoriteFruit2(const vector<string>&fruits, size_t k)
//{
//	map<string, int> ans;
//	for (auto& str : fruits)
//	{
//		ans[str]++;
//	}
//	size_t i = 0;
//	priority_queue<pair<string, int>, vector<string, int>, CountCompare> pq;
//	for (auto&e : ans)
//	{
//		if (i < k)
//		{
//			pq.push(e);
//		}
//		else if (e.second>pq.top().second)
//		{
//			pq.pop();
//			pq.push(e);
//		}
//	}
//}
//
//void GetFavoriteFruit3(const vector<string>&fruits, size_t k)
//{
//	map<string, int> res;
//	for (const auto& e : fruits){
//		res[e]++;
//	}
//	multimap<string, int> ans;
//	for (const auto& n : res)
//	{
//		ans.insert(make_pair(n.first, n.second));
//	}
//	auto it = ans.end();
//	for (int i = 0; i < k; i++)
//	{
//		it--;
//		cout << (*it).first << ":" << (*it).second << endl;
//	}
//}
//void test3()
//{
//	vector<string> strs = { "ƻ��", "�㽶", "⨺���", "ƻ��", "�㽶", "⨺���", "�㽶", "⨺���","����" };
//	GetFavoriteFruit3(strs, 4);
//}
