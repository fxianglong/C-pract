#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//vector<vector<int>> levelOrderBottom(TreeNode* root) {
//	queue<TreeNode*> nodeq;
//	queue<int> levelq;
//	vector<vector<int>> vv;
//	if (root)
//	{
//		nodeq.push(root);
//		levelq.push(0);
//	}
//
//	while (!nodeq.empty())
//	{
//		TreeNode* node = nodeq.front();
//		nodeq.pop();
//
//		int level = levelq.front();
//		levelq.pop();
//		//将出来的数据，进到相应的vector分层
//		//检查vector层的vector是否存在，不存在则创建一个
//		if (level >= vv.size())
//		{
//			vv.push_back(vector<int>());
//		}
//		vv[level].push_back(node->val);
//
//
//		//将下一层的节点带进队列
//		if (node->left)
//		{
//			nodeq.push(node->left);
//			levelq.push(level + 1);
//		}
//		if (node->right)
//		{
//			nodeq.push(node->right);
//			levelq.push(level + 1);
//		}
//	}
//	reverse(vv.begin(), vv.end());
//	return vv;
//}
//
//
///**
//* Definition for a binary tree node.
//* struct TreeNode {
//*     int val;
//*     TreeNode *left;
//*     TreeNode *right;
//*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//* };
//*/
//class Solution {
//public:
//	vector<vector<int>> levelOrderBottom(TreeNode* root) {
//		// queue<TreeNode*> Myqueue;
//		// vector<vector<int>> ans;
//		// if(root==nullptr) return ans;
//		// Myqueue.push(root);
//		// while(!Myqueue.empty())
//		// {
//		//     vector<int> ret;
//		//     for(int i =Myqueue.size()-1;i>=0;i--)
//		//     {
//		//         TreeNode* cur=Myqueue.front();
//		//         Myqueue.pop();
//		//         ret.push_back(cur->val);
//		//         if(cur->left) Myqueue.push(cur->left);
//		//         if(cur->right) Myqueue.push(cur->right);
//		//     }
//		//     ans.push_back(ret);
//		// }
//		// reverse(ans.begin(),ans.end());
//		// return ans;
//		vector<vector<int>> ans;
//		helper(ans, root, 0);
//		reverse(ans.begin(), ans.end());
//		return ans;
//	}
//	void helper(vector<vector<int>>& ans, TreeNode* node, int level)
//	{
//		if (node == nullptr)return;
//		if (level >= ans.size())
//		{
//			vector<int> level_ret;
//			ans.emplace_back(level_ret);
//		}
//		ans[level].emplace_back(node->val);
//		helper(ans, node->left, level + 1);
//		helper(ans, node->right, level + 1);
//	}
//};


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
//	TreeNode* sortedArrayToBST(vector<int>& nums) {
//		//     return helper(0,nums.size()-1,nums);
//		// }
//		// TreeNode* helper(int l,int r,vector<int>& nums)
//		// {
//		//     if(l>r) return nullptr;
//		//     int mid=(r-l)/2+l;
//		//     TreeNode* root=new TreeNode(nums[mid]);
//		//     root->left=helper(l,mid-1,nums);
//		//     root->right=helper(mid+1,r,nums);
//		//     return root;
//
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
//	TreeNode* sortedListToBST(ListNode* head) {
//		return helper(head, nullptr);
//	}
//	TreeNode* helper(ListNode* head, ListNode* tail)
//	{
//		if (head == tail)return nullptr;
//		ListNode* slow = head, *fast = head;
//		while (fast != tail && fast->next != tail){
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		TreeNode* root = new TreeNode(slow->val);
//		root->left = helper(head, slow);
//		root->right = helper(slow->next, tail);
//		return root;
//	}
//};


//class Solution {
//	int flag = 1;
//public:
//	bool isBalanced(TreeNode* root) {
//		if (root == nullptr) return true;
//		int l = DNS(root->left);
//		int r = DNS(root->right);
//		if (abs(l - r)<2 && isBalanced(root->left) && isBalanced(root->right))
//			return true;
//		return false;
//	}
//	int DNS(TreeNode* root)
//	{
//		if (root == nullptr)return 0;
//		int l = DNS(root->left);
//		int r = DNS(root->right);
//		return max(l, r) + 1;
//	}
//};


//class Solution {
//public:
//	int minDepth(TreeNode* root) {
//		if (root == nullptr) return 0;
//		int l = minDepth(root->left);
//		int r = minDepth(root->right);
//		if (root->left == nullptr || root->right == nullptr){
//			return l == 0 ? r + 1 : l + 1;
//		}
//		else{
//			return min(l, r) + 1;
//		}
//	}
//};


//class Solution {
//public:
//	bool hasPathSum(TreeNode* root, int sum) {
//		if (root == nullptr)return false;
//		sum -= root->val;
//		if ((root->left == nullptr) && (root->right == nullptr))return sum == 0;
//		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
//	}
//};

//class Solution {
//public:
//	vector<vector<int>> pathSum(TreeNode* root, int sum) {
//		// vector<vector<int>> ans;
//		// if(root==nullptr) return ans;
//		// vector<int> ret;
//		// stack<TreeNode*> stk;TreeNode* prev=nullptr;
//		// while(root||!stk.empty())
//		// {
//		//     while(root){
//		//         stk.push(root);
//		//         sum-=root->val;
//		//         ret.push_back(root->val);
//		//         root=root->left;
//		//     }
//		//     root=stk.top();
//		//     if(!root->left&&!root->right&&(sum==0))
//		//     {
//		//         ans.push_back(ret);
//		//     }
//		//     if(!root->right||root->right==prev)
//		//     {
//		//         stk.pop();
//		//         sum+=root->val;
//		//         ret.pop_back();
//		//         prev=root;
//		//         root=nullptr;
//		//     }
//		//     else
//		//         root=root->right;
//		// }
//		// return ans;
//
//
//		path.clear();
//		res.clear();
//
//		if (root == nullptr){
//			return res;
//		}
//
//		path.push_back(root->val);
//		dfs(root, sum - root->val);
//		path.pop_back();
//		return res;
//	}
//
//private:
//	vector<int> path;
//	vector<vector<int>> res;
//
//	void dfs(TreeNode* root, int sum)
//	{
//		if (root->left == nullptr && root->right == nullptr){
//			if (sum == 0){
//				res.push_back(path);
//			}
//			return;
//		}
//
//		if (root->left != nullptr){
//			path.push_back(root->left->val);
//			dfs(root->left, sum - root->left->val);
//			path.pop_back();
//		}
//		if (root->right != nullptr){
//			path.push_back(root->right->val);
//			dfs(root->right, sum - root->right->val);
//			path.pop_back();
//		}
//	}
//};

////114
//class Solution {
//public:
//	void flatten(TreeNode* root) {
//		// while(root!=nullptr)
//		// {
//		//     if(root->left!=nullptr)
//		//     {
//		//         auto most_right=root->left;
//		//         while(most_right->right!=nullptr)most_right=most_right->right;
//		//         most_right->right=root->right;
//		//         root->right=root->left;
//		//         root->left=nullptr;
//		//     }
//		//     root=root->right;
//		// }
//		// return;
//
//
//		if (root == nullptr)return;
//		flatten(root->left);
//		flatten(root->right);
//		if (root->left != nullptr) {
//			auto pre = root->left;
//			while (pre->right != nullptr) pre = pre->right;
//			pre->right = root->right;
//			root->right = root->left;
//			root->left = nullptr;
//		}
//		root = root->right;
//		return;
//	}
//};


//115
//class Solution {
//public:
//	int numDistinct(string s, string t) {
//		// int s_size = s.size(), t_size = t.size();
//		// vector<vector<long>> dp(t_size + 1, vector<long>(s_size + 1, 0));
//		// fill(dp[0].begin(), dp[0].end(), 1);
//		// for (int i = 0; i < t_size; ++i) {
//		//     for (int j = 0; j < s_size; ++j) {
//		//         if (t[i] == s[j]) dp[i+1][j+1] = dp[i+1][j] + dp[i][j];
//		//         else dp[i+1][j+1] = dp[i+1][j]; 
//		//     }
//		// }
//		// return dp[t_size][s_size];
//
//
//
//		int s_size = s.size(), t_size = t.size();
//		vector<long> dp(s_size + 1, 1);
//		for (auto c : t) {
//			auto last = dp[0]; // 记录上一个值
//			dp[0] = 0;
//			for (int j = 0; j < s_size; ++j) {
//				auto record = dp[j + 1];
//				if (s[j] == c) dp[j + 1] = last + dp[j];
//				else dp[j + 1] = dp[j];
//				last = record;
//			}
//		}
//		return dp.back();
//
//	}
//};


//116
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/

//class Solution {
//public:
//	Node* connect(Node* root) {
//		if (root == nullptr) return nullptr;
//		queue<Node*> q1;
//		q1.push(root);
//		while (!q1.empty())
//		{
//			queue<Node*> q2;
//			while (!q1.empty()){
//				Node* cur = q1.front();
//				q1.pop();
//				if (cur->left)
//					q2.push(cur->left);
//				if (cur->right)
//					q2.push(cur->right);
//				if (!q1.empty())
//				{
//					cur->next = q1.front();
//				}
//				else{
//					cur->next = nullptr;
//				}
//			}
//			q1 = q2;
//		}
//		return root;
//	}
//};


//117
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;

Node() : val(0), left(NULL), right(NULL), next(NULL) {}

Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/

//class Solution {
//public:
//	Node* connect(Node* root) {
//		if (root == nullptr) return nullptr;
//		queue<Node*> q1;
//		q1.push(root);
//		while (!q1.empty())
//		{
//			queue<Node*> q2;
//			while (!q1.empty()){
//				Node* cur = q1.front();
//				q1.pop();
//				if (cur->left)
//					q2.push(cur->left);
//				if (cur->right)
//					q2.push(cur->right);
//				if (!q1.empty())
//				{
//					cur->next = q1.front();
//				}
//				else{
//					cur->next = nullptr;
//				}
//			}
//			q1 = q2;
//		}
//		return root;
//	}
//};


////118
//class Solution {
//public:
	//vector<vector<int>> generate(int numRows) {
	//	vector<vector<int>> ans(numRows);
	//	for (int i = 0; i<numRows; i++)
	//	{
	//		ans[i] = vector<int>(i + 1, 0);
	//		ans[i][0] = 1;
	//		ans[i][i] = 1;
	//	}
	//	if (numRows <= 2) return ans;
	//	for (int i = 2; i < numRows; ++i)
	//	for (int j = 1; j < ans[i].size() - 1; ++j) ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
	//	return ans;
	//}
//};

//119
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		// vector<int> kRows(rowIndex+1);
		// for(int i = 0; i <= rowIndex; i++)
		//     {
		//         kRows[i] = 1;//行末尾为1
		//         for(int j = i; j > 1; j--)//每一行的更新过程
		//         {
		//             kRows[j-1] = kRows[j-2] + kRows[j-1];
		//         }
		//     }
		// return kRows;
		vector<vector<int>> ans(rowIndex + 1);
		for (int i = 0; i<rowIndex + 1; i++)
		{
			ans[i] = vector<int>(i + 1, 0);
			ans[i][0] = 1;
			ans[i][i] = 1;
		}
		if ((rowIndex) <= 1) return ans[rowIndex];
		for (int i = 2; i < rowIndex + 1; ++i)
		for (int j = 1; j < ans[i].size() - 1; ++j) ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		return ans[rowIndex];
	}
};
