#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


//class Solution {
//public:
//	int findRepeatNumber(vector<int>& nums) {
//		unordered_map<int, int> m;
//		for (auto e : nums)
//		{
//			m[e]++;
//			if (m[e] == 2)
//				return e;
//		}
//		return 0;
//	}
//};

//class Solution {
//public:
//	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//		if (matrix.size() == 0 || matrix[0].size() == 0)
//			return false;
//		int i = 0;
//		int j = matrix[0].size() - 1;
//		while (j >= 0 && i<matrix.size())
//		{
//			if (matrix[i][j] == target)
//				return true;
//			else if (matrix[i][j]>target)
//				j--;
//			else if (matrix[i][j]<target)
//				i++;
//		}
//		return false;
//	}
//};
//
//
//class Solution {
//public:
//	string replaceSpace(string s) {
		// string ans;
		// auto it = s.rbegin();
		// while (it != s.rend())
		// {
		// 	if (*it != ' ')
		// 	{
		// 		ans.push_back(*it);
		// 		it++;
		// 	}
		// 	else
		// 	{
		// 		ans.append("02%");
		// 		it++;
		// 	}
		// }
		// reverse(ans.begin(),ans.end());
		// return ans;

//		string ans = "";
//		for (int i = 0; i<s.size(); i++)
//		{
//			if (s[i] == ' ')
//			{
//				ans += "%20";
//			}
//			else
//				ans += s[i];
//		}
//		return ans;
//
//
//	}
//};
//int main(){
//	string str = "We are happy.";
//	replaceSpace(str);
//	system("pause");
//	return 0;
//}



//class Solution {
//public:
//	vector<int> ans;
//	vector<int> reversePrint(ListNode* head) {
//		bt(head);
//		return ans;
//	}
//
//	void bt(ListNode* node) {
//		if (node == nullptr) return;
//		bt(node->next);
//		ans.push_back(node->val);
//		return;
//	}
//};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0 || inorder.size() == 0) {
		return NULL;
	}
	TreeNode* treeNode = new TreeNode(preorder[0]);
	int mid = distance(begin(inorder), find(inorder.begin(), inorder.end(), preorder[0]));
	vector<int> left_pre(preorder.begin() + 1, preorder.begin() + mid + 1);
	vector<int> right_pre(preorder.begin() + mid + 1, preorder.end());
	vector<int> left_in(inorder.begin(), inorder.begin() + mid);
	vector<int> right_in(inorder.begin() + mid + 1, inorder.end());

	treeNode->left = buildTree(left_pre, left_in);
	treeNode->right = buildTree(right_pre, right_in);
	return treeNode;
}