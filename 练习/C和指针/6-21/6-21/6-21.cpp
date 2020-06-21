/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
	int maxPath(TreeNode* root, int& val)
	{
		if (root == nullptr)return 0;
		int li = maxPath(root->left, val);
		int ri = maxPath(root->right, val);
		int rlr = root->val + max(0, li) + max(0, ri);
		int ret = root->val + max(0, max(ri, li));
		val = max(val, max(rlr, ret));
		return ret;
	}
public:
	int maxPathSum(TreeNode* root) {
		int val = INT_MIN;
		maxPath(root, val);
		return val;
	}
};