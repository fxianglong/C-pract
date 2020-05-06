#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;


//120
//int minimumTotal(vector<vector<int>>& triangle) {
//	int len = triangle.size();
//	vector<int> ans(len, 0);
//	for (int i = 0; i<triangle.size(); i++)
//	for (int j = i; j>=0; j--)
//	{
//		if (j == 0)
//			ans[j] = ans[j] + triangle[i][j];
//		else if (i == j)
//			ans[i] = ans[i-1] + triangle[i][j];
//		else
//			ans[j] = min(ans[j] + triangle[i][j], ans[j-1] + triangle[i][j]);
//	}
//	sort(ans.begin(), ans.end());
//	return ans[0];
//}
//int main()
//{
//	vector<vector<int>> ret = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
//	int Min = minimumTotal(ret);
//	cout << Min << endl;
//	system("pause");
//	return 0;
//}


////121
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		// if(prices.size()==0)return 0;
//		// int min=0;
//		// for(int i=0;i<prices.size()-1;i++)
//		// for(int j=i+1;j<prices.size();j++)
//		// {
//		//     if((prices[j]-prices[i])>min)
//		//         min=(prices[j]-prices[i]);
//		// }
//		// return min;
//
//		int maxpro = 0;
//		int minp = INT_MAX;
//		for (auto e : prices)
//		{
//			maxpro = max(maxpro, e - minp);
//			minp = min(e, minp);
//		}
//		return maxpro;
//	}
//};


//122
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int maxp = 0;
//		for (int i = 1; i<prices.size(); i++)
//		{
//			if (prices[i]>prices[i - 1])
//				maxp += prices[i] - prices[i - 1];
//		}
//		return maxp;
//	}
//};


//int maxProfit(vector<int>& prices) {
//	if (prices.empty()) return 0;
//	int n = prices.size();
//	vector<int> f(n);
//	vector<int> b(n);
//	int min_price = prices[0];
//	for (int i = 1; i<n; i++){
//		f[i] = max(f[i - 1], prices[i] - min_price);
//		min_price = min(prices[i], min_price);
//	}
//	int max_price = prices[n - 1];
//	for (int i = n - 2; i >= 0; i--){
//		b[i] = max(b[i + 1], max_price - prices[i]);
//		max_price = max(max_price, prices[i]);
//	}
//	int res = 0;
//	for (int i = 0; i<n - 1; i++){
//		res = max(res, max(f[i] + b[i + 1], f[i]));
//	}
//	res = max(res, f[n - 1]);
//	return res;
//}
//
//int main()
//
//{
//	vector<int> ans = { 3, 3, 5, 0, 0, 3, 1, 4 };
//	maxProfit(ans);
//	system("pause");
//	return 0;
//}


//123
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//class Solution {
//	int maxPath(TreeNode* root, int& val)
//	{
//		if (root == nullptr)return 0;
//		int li = maxPath(root->left, val);
//		int ri = maxPath(root->right, val);
//		int rlr = root->val + max(0, li) + max(0, ri);
//		int ret = root->val + max(0, max(ri, li));
//		val = max(val, max(rlr, ret));
//		return ret;
//	}
//public:
//	int maxPathSum(TreeNode* root) {
//		int val = INT_MIN;
//		maxPath(root, val);
//		return val;
//	}
//};


//class Solution {
//public:
//	bool isUnique(string astr) {
//		unordered_map<char, int> ans;
//		for (auto e : astr)
//		{
//			ans[e]++;
//			if (ans[e]>1)
//				return false;
//		}
//		return true;
//
//		// vector<int> ans(256,0);
//		// for(auto e:astr)
//		// {
//		//     ans[e]++;
//		//     if(ans[e]>1)
//		//         return false;
//		// }
//		// return true;
//	}
//};


//class Solution {
//public:
//	bool isNumber(string s) {
//		int n = s.size();
//		// 去除收尾空格
//		int bg = 0, ed = n - 1;
//		while (bg<n && s[bg] == ' ') bg++;
//		while (ed >= 0 && s[ed] == ' ') ed--;
//		if (ed<bg) return false;
//
//		string ss = s.substr(bg, ed - bg + 1);
//		int i = 0;
//		n = ed - bg + 1;
//		// 跳过符号
//		if (ss[i] == '+' || ss[i] == '-') i++;
//
//		bool ef = false, df = false, nf = false;
//		while (i<n){
//			if (ss[i] - '0' >= 0 && ss[i] - '0' <= 9){
//				nf = true;
//			}
//			else if (ss[i] == '.'){
//				if (ef) return false;    // 出现在e的后面
//				if (!df){                // 出现多次
//					df = true;
//				}
//				else{
//					return false;
//				}
//			}
//			else if (ss[i] == 'e' || ss[i] == 'E'){
//				if (!ef){                // 出现多次
//					if (!nf)             // 判断e前是否存在数字
//						return false;
//					else
//						ef = true;
//				}
//				else{
//					return false;
//				}
//				nf = false;              // 用于之后判断e后是否存在数字
//				if (i + 1<n && (ss[i + 1] == '+' || ss[i + 1] == '-')) // 跳过符号
//					i++;
//			}
//			else{                     //其他字符
//				return false;
//			}
//
//			i++;
//		}
//
//		if (nf)
//			return true;
//		else
//			return false;
//	}
//};


//class Solution {
//public:
//	bool CheckPermutation(string s1, string s2) {
//		// sort(s1.begin(),s1.end());
//		// sort(s2.begin(),s2.end());
//		// return s1==s2;
//		unordered_map<char, int>mp;
//		for (auto i : s1){
//			mp[i]++;
//		}
//		for (auto i : s2){
//			mp[i]--;
//			if (mp[i]<0)return false;
//		}
//		return true;
//	}
//};



//class Solution {
//public:
//	bool oneEditAway(string first, string second) {
//		int len = 0;
//		if (first.size()>second.size())
//			len = first.size() - second.size();
//		else
//			len = second.size() - first.size();
//		if (len > 1)
//			return false;
//		int i = 0, j = 0; int count = 0;
//		while (i<first.size() || j<second.size())
//		{
//			if (first[i] == second[j]){ i++; j++; }
//			else{
//				count++;
//				if (count>1)
//					return false;
//				if (first.size()<second.size()){
//					j++;
//				}
//				if (first.size() == second.size()){
//					i++; j++;
//				}
//				if (first.size()>second.size()){
//					i++;
//				}
//			}
//		}
//		return true;
//	}
//};


//class Solution {
//	string Trans(int count)
//	{
//		string res;
//		while (count)
//		{
//			res += (count % 10 + '0');
//			count = count / 10;
//		}
//		reverse(res.begin(), res.end());
//		return res;
//	}
//public:
//	string compressString(string S) {
//		if (S.size() == 0)  return S;
//		string ret;
//		int count = 1;
//		for (int i = 1; i <= S.size(); i++)
//		{
//			if (S[i] == S[i - 1])
//				count++;
//			else{
//				ret.push_back(S[i - 1]);
//				ret.append(to_string(count));
//				count = 1;
//			}
//		}
//		return S.size()>ret.size() ? ret : S;
//	}
//};


//class Solution {
//public:
//	void rotate(vector<vector<int>>& matrix) {
//		// int n=matrix.size();
//		// vector<vector<int>> ans(n,vector<int>(n,0));
//		// for(int i =0;i<n;i++)
//		// for(int j=0;j<n;j++)
//		// {
//		//     ans[j][n-i-1]=matrix[i][j];
//		// }
//		// matrix=ans;
//		// return ;
//
//		int n = matrix.size();
//
//		for (int i = 0; i < n / 2; ++i) {
//			swap(matrix[i], matrix[n - i - 1]);
//		}
//
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < i; ++j) {
//				swap(matrix[i][j], matrix[j][i]);
//			}
//		}
//	}
//};


//class Solution {
//public:
//	void setZeroes(vector<vector<int>>& matrix) {
//		set<int> col;
//		set<int> row;
//		for (int i = 0; i<matrix.size(); i++)
//		for (int j = 0; j<matrix[0].size(); j++)
//		{
//			if (matrix[i][j] == 0)
//			{
//				col.insert(i);
//				row.insert(j);
//			}
//		}
//		for (auto e : col)
//		{
//			for (int j = 0; j<matrix[0].size(); j++)
//				matrix[e][j] = 0;
//		}
//		for (auto e : row)
//		{
//			for (int i = 0; i<matrix.size(); i++)
//				matrix[i][e] = 0;
//		}
//		return;
//	}
//};


//class Solution {
//public:
//	bool isFlipedString(string s1, string s2) {
//		// return s1.size()==s2.size()&&(s1+=s1).find(s2)!=-1;
//
//		if (s1.size() != s2.size()) return false;
//		int len = s1.size();
//		if (len == 0) return true;
//		s1 = s1 + s1;
//		for (int i = 0; i<len; i++){
//			if (s1.substr(i, len) == s2) return true;
//		}
//		return false;
//	}
//};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//class Solution {
//public:
//	ListNode* removeDuplicateNodes(ListNode* head) {
//		if (head == nullptr) return head;
//		unordered_set<int> s;
//		ListNode*p;
//		p = head;
//		s.insert(p->val);
//		while (p->next != nullptr){
//			if (s.count(p->next->val)){
//				p->next = p->next->next;
//			}
//			else{
//				s.insert(p->next->val);
//				p = p->next;
//			}
//		}
//		return head;
//	}
//};