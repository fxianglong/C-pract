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
//高效->去重、排序	
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

//map  key/value -> 字典/统计次数
//void test_map()
//{
//	map<string, string> dict;
//	dict.insert(pair<string, string>("insert", "插入"));
//	dict.insert(pair<string, string>("sort", "排序"));
//	dict.insert(pair<string, string>("string", "字符串"));
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
//		else cout << "没有这个单词，请重新输入" << endl;
//	}
//}
//template<class K,class V>
//mapped_type& operator[](const& key_type&k)
//{
//	return (*((this->insert(make_pair(k, key_type()))).first.second);
//}
//operator[]作用：1、返回容器中key对应的value值的引用  两层意义：a,找key映射value   b,修改key映射的value
//2.key不在容器中-》插入make_pair(key,V())

//void map_test2()
//{
//	string strs[] = { "苹果", "香蕉", "猕猴桃", "苹果", "香蕉", "猕猴桃", "香蕉", "猕猴桃" };
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
//		//插入+修改
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
//	vector<string> strs = { "苹果", "香蕉", "猕猴桃", "苹果", "香蕉", "猕猴桃", "香蕉", "猕猴桃","核桃" };
//	GetFavoriteFruit3(strs, 4);
//}
