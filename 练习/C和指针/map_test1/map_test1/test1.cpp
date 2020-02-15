////����һ��Ӣ�ľ��ӣ��Ѿ����еĵ���(�����ִ�Сд)�����ִ������Ӷൽ�ٰѵ���
////�ʹ�������Ļ���������Ҫ����ʶ��Ӣ�ľ�źͶ��ţ�����˵�����ɿո񡢾�źͶ��Ÿ�����
//
//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//int main()
//{
//	string s, p;
//	getline(cin, s);
//	map<string, int> a;
//	auto l = s.begin();
//	for (; l < s.end() + 1; l++)
//	{
//		int count = 0;
//		while (*l == ' ' || *l == ',' || *l == '.')
//		{
//			if (s.begin() != l)
//			{
//				p.assign(s.begin(), l);
//				if (p[0] <= 'Z'&&p[0] >= 'A')
//					p[0] += 32;
//				a[p]++;
//				count = 0;
//			}
//			s.erase(s.begin(), l + 1);
//			l = s.begin();
//			if (s.begin() == s.end())
//			{
//				for (auto res = a.begin(); res != a.end(); res++)
//				{
//					cout << res->first << ':' << res->second << endl;
//				}
//				break;
//			}
//		}
//	}
//	return 0;
//}

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res;
		map<string, int> a;
		for (int i = 0; i<words.size(); i++){
			a[words[i]]++;
		}
		vector<pair<string, int>> word_sord(a.begin(), a.end());
		std::sort(word_sord.begin(), word_sord.end(), [](const pair<string, int> &l, const pair<string, int> &r)
		{
			if (l.second == r.second)
			{
				for (size_t i = 0; i<min(l.first.size(), r.first.size()); ++i){
					if (l.first[i] == r.first[i]) continue;
					return l.first[i] < r.first[i];
				}
			}
			return l.second > r.second;
		});
		for (int i = 0; i<k; i++){
			res.push_back(word_sord[i].first);
		}
		return res;
	}
