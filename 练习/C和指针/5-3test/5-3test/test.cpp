#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;



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
//public:
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		// if (preorder.size() == 0 || inorder.size() == 0) {
		//     return NULL;
		// }
		// TreeNode* treeNode = new TreeNode(preorder[0]);
		// int mid = distance(begin(inorder), find(inorder.begin(), inorder.end(), preorder[0]));
		// vector<int> left_pre(preorder.begin() + 1, preorder.begin() + mid + 1);
		// vector<int> right_pre(preorder.begin() + mid + 1, preorder.end());
		// vector<int> left_in(inorder.begin(), inorder.begin() + mid);
		// vector<int> right_in(inorder.begin() + mid + 1, inorder.end());

		// treeNode->left = buildTree(left_pre, left_in);
		// treeNode->right = buildTree(right_pre, right_in);
		// return treeNode;

		//递归分治
//		return recursionBuild(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
//	}
//
//	//递归分治
//	TreeNode* recursionBuild(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd)
//	{
//		if (inEnd == inBegin) return NULL;
//		TreeNode* cur = new TreeNode(*preBegin);
//		auto root = find(inBegin, inEnd, *preBegin);
//		cur->left = recursionBuild(preBegin + 1, preBegin + 1 + (root - inBegin), inBegin, root);
//		cur->right = recursionBuild(preBegin + 1 + (root - inBegin), preEnd, root + 1, inEnd);
//		return cur;
//	}
//};
//
//
//class CQueue {
//public:
//	stack<int> s1;
//	stack<int> s2;
//	CQueue() {
//	}
//
//	void appendTail(int value) {
//		s1.push(value);
//	}
//
//	int deleteHead() {
//		if (s1.empty()){
//			return -1;
//		}
//		while (!s1.empty())
//		{
//			s2.push(s1.top());
//			s1.pop();
//		}
//		int temp = s2.top();
//		s2.pop();
//		while (!s2.empty())
//		{
//			s1.push(s2.top());
//			s2.pop();
//		}
//		return temp;
//	}
//};
//
//class Solution {
//public:
//	int numWays(int n) {
//		if (n == 0) return 1;
//		if (n == 1) return 1;
//		vector<int> ans(n + 1);
//		ans[0] = 1;
//		ans[1] = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			ans[i] = (ans[i - 1] + ans[i - 2]) % 1000000007;
//		}
//		return ans[n];
//	}
//};


//class Solution {
//public:
//	int minArray(vector<int>& numbers) {
//		for (int i = 1; i<numbers.size(); i++)
//		{
//			if (numbers[i - 1]>numbers[i])
//				return numbers[i];
//		}
//		return numbers[0];
//	}
//};

//
//class Solution {
//public:
//	static bool exist(vector<vector<char>>& board, string word) {
//		if (board.empty() || board[0].empty())
//			return word.empty();
//		for (int row = 0; row < board.size(); ++row) {
//			for (int col = 0; col < board[0].size(); ++col) {
//				if (backtrack(board, row, col, word, 0)) return true;
//			}
//		}
//		return false;
//	}
//private:
//	static bool backtrack(vector<vector<char>> &board, int row, int col,
//		const string &word, int idx) {
//		if (idx == word.size()) return true;
//		if (row < 0 || row >= board.size() ||
//			col < 0 || col >= board[0].size()) return false;
//		if (word[idx] != board[row][col]) return false;
//
//		board[row][col] = '*';
//		if (backtrack(board, row - 1, col, word, idx + 1) ||
//			backtrack(board, row + 1, col, word, idx + 1) ||
//			backtrack(board, row, col - 1, word, idx + 1) ||
//			backtrack(board, row, col + 1, word, idx + 1))
//			return true;
//
//		board[row][col] = word[idx];
//		return false;
//	}
//};
//
//
//int main()
//{
//	vector<vector<char>> res = { { 1, 2, 3, 4, 5, 6 }, { 2, 3, 4, 5, 6, 7 }, { 3, 4, 5, 6, 7, 8 } };
//	Solution::exist(res, "2374");
//	system("pause");
//	return 0;
//}
//
//
//class Solution {
//public:
//	int cuttingRope(int n) {
//		vector<int> dp(60, 0);
//		dp[1] = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			for (int j = 1; j<i; j++)
//			{
//				dp[i] = max(dp[i], dp[j] * dp[i - j]);
//			}
//			if (i != n) dp[i] = max(dp[i], i);
//		}
//		return dp[n];
//	}
//};


//class solution {
//public:
//	int cuttingrope(int n) {
//		if (n <= 3) return n - 1;
//		long rs = 1;
//		while (n > 4) {
//			rs *= 3;
//			rs %= 1000000007;
//			n -= 3;
//		}
//		return (rs * n) % 1000000007;
//	}
//};


//int hammingWeight(int n) {
//	int count = 0;
//	while (n)
//	{
//		if (n & 1)
//		{
//			count++;
//		}
//		n=n>>1;
//	}
//	return count;
//}
//int main()
//{
//	int a = 9;
//	cout<< hammingWeight(a) << endl;
//	system("pause");
//	return 0;
//}
//
//class Solution {
//public:
//	int hammingWeight(uint32_t n) {
//		int count = 0;
//		while (n)
//		{
//			n &= (n - 1);
//			count++;
//		}
//		return count;
//	}
//};



//class Solution {
//public:
//	double myPow(double x, int n) {
//		double res = 1.0;
//		int i = n;
//		while (i)
//		{
//			if (i & 1)res *= x;
//			x *= x;
//			i /= 2;
//		}
//		return n>0 ? res : 1 / res;
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
//	ListNode* deleteNode(ListNode* head, int val) {
//		if (head == nullptr) return head;
//		if (head->val == val)return head->next;
//		ListNode* cur = head->next;
//		ListNode* pre = head;
//		while (cur != nullptr)
//		{
//			if (cur->val == val)
//			{
//				pre->next = cur->next;
//				delete cur;
//				cur = nullptr;
//			}
//			else
//			{
//				pre = cur;
//				cur = cur->next;
//			}
//		}
//		return head;
//	}
//};


