#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int len = preorder.size();
		if (len == 0) return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		vector<int> preorder_left, inorder_left, preorder_right, inorder_right;
		int i;
		for (i = 0; i<len; i++)
		{
			if (inorder[i] == preorder[0])break;
			inorder_left.push_back(inorder[i]);
		}
		for (i = i + 1; i<len; i++)
		{
			inorder_right.push_back(inorder[i]);
		}
		for (i = 1; i<len; i++)
		{
			if (i <= inorder_left.size()) preorder_left.push_back(preorder[i]);
			else
				preorder_right.push_back(preorder[i]);
		}
		root->left = buildTree(preorder_left, inorder_left);
		root->right = buildTree(preorder_right, inorder_right);
		return root;
	}
};