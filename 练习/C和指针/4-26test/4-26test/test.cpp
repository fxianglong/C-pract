#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


//vector<string> uncommonFromSentences(string A, string B) {
//	unordered_map<string, int> m;
//	vector<string> ans;
//	string s;
//	A = A + ' ' + B;
//	for (int i = 0; i<A.size(); i++)
//	{
//		s.clear();
//		while (A[i] != ' '&&i<A.size())
//		{
//			s += A[i];
//			i++;
//		}
//		m[s]++;
//	}
//	for (auto e : m){
//		if (e.second == 1)
//			ans.push_back(e.first);
//	}
//	return ans;
//}
//
//
//int main()
//{
//	string s1 = "i love my boy";
//	string s2 = "my boy is bad";
//	uncommonFromSentences(s1, s2);
//
//	system("pause");
//	return 0;
//}