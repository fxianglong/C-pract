//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> a;
//	vector<int> b(6, 10);
//	vector<int> c(b);
//	vector<int> d(c.begin(), c.end());
//
//	for (int i = 0; i < a.size(); i++)
//		cout << a[i] << " ";
//	cout << endl;
//	for (int i = 0; i < b.size(); i++)
//		cout << b[i] << " ";
//	cout << endl;
//	for (int i = 0; i < c.size(); i++)
//		cout << c[i] << " ";
//	cout << endl;
//	for (int i = 0; i < d.size(); i++)
//		cout << d[i] << " ";
//	cout << endl;
//	int e[] = { 3, 43, 2, 3435, 2, 65, 7, 8, 2, 7, 54 };
//	vector<int> f(e, e + sizeof(e) / sizeof(e[0]));
//	for (int i = 0; i < f.size(); i++)
//		cout << f[i] << " ";
//	cout << endl;
//	vector<int>::iterator it = f.begin();
//	while (it!=f.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	system("pause");
//	return 0;
//}



//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> ans;
//	ans.push_back(1);
//	ans.push_back(2);
//	ans.push_back(3);
//	ans.push_back(4);
//	ans.push_back(5);
//
//	//使用迭代器进行遍历
//	vector<int>::iterator it = ans.begin();
//	while (it != ans.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	//使用迭代器进行修改
//	it = ans.begin();
//	while (it != ans.end())
//	{
//		*it=*it * 2;
//		it++;
//	}
//	for (int i = 0; i < ans.size(); i++)
//		cout << ans[i] << " ";
//	cout << endl;
//
//	//使用逆向迭代器进行迭代
//	vector<int>::reverse_iterator rit = ans.rbegin();
//	while (rit != ans.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int> ans;
//	int sz = ans.capacity();
//	for (int i = 0; i < 100; i++)
//	{
//		ans.push_back(i);
//		if (sz != ans.capacity()) {
//			sz = ans.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	vector<int> ans;
//	ans.push_back(1);
//	ans.push_back(2);
//	ans.push_back(3);
//	ans.push_back(4);
//	ans.push_back(5);
//	//删除尾部
//	ans.pop_back();
//	//使用迭代器查找
//	vector<int>::iterator it = find(ans.begin(), ans.end(), 3);
//	//插入
//	ans.insert(it, 50);
//	//使用迭代器遍历
//	it = ans.begin();
//	while (it != ans.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

//class Solution {
//public:
//	vector<vector<int>> generate(int numRows) {
//		vector<vector<int>> ans;
//		for (int i = 0; i<numRows; i++)
//		{
//			ans.push_back(vector<int>());
//			ans[i].push_back(1);
//			for (int j = 0; j<i - 1; j++)
//			{
//				ans[i].push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
//			}
//			if (i > 0) ans[i].push_back(1);
//		}
//		return ans;
//	}
//};

//#include<iostream>
//#include<vector>
//using namespace std;
//
//void DFS(string digits, int pos, string & s, vector<string> &res, vector<string>& m){
//	if (pos == digits.size()){
//		res.push_back(s);
//		return;
//	}
//	//获取对应键盘的字母
//	string tmp = m[digits[pos] - '0'];
//	for (int i = 0; i < tmp.size(); i++){
//		s.push_back(tmp[i]);
//		DFS(digits, pos + 1, s, res, m);
//		s.pop_back();
//	}
//	return;
//}
//vector<string> letterCombinations(string digits) {
//	vector<string> m = { "","", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
//	vector<string> res;
//	if (digits.size() == 0) return res;
//	string s;
//
//	DFS(digits, 0, s, res, m);
//	return res;
//}
//
//
//int main()
//{
//	string s = "34";
//	letterCombinations(s);
//	system("pause");
//	return 0;
//}