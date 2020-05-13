//#include<iostream>
//#include<vector>
//#include<string>
//#include<map>
//#include<set>
//#include<deque>
//#include<stack>
//#include<algorithm>
//using namespace std;

//28
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
//	bool isSymmetric(TreeNode* root) {
//		if (root == nullptr)
//			return true;
//		return helper(root->left, root->right);
//	}
//	bool helper(TreeNode* l, TreeNode* r)
//	{
//		if (l == nullptr&&r == nullptr)
//			return true;
//		else if (l == nullptr || r == nullptr)
//			return false;
//		else if (l->val != r->val)
//			return false;
//		return helper(l->left, r->right) && helper(l->right, r->left);
//	}
//};


//vector<int> spiralOrder(vector<vector<int>>& matrix) {
//	int cd = 0, rd = 0;
//	int cu = matrix.size() - 1, ru = matrix[0].size() - 1;
//	vector<int> ans;
//	while (1)
//	{
//		for (int j = rd; j <= ru; j++)
//			ans.push_back(matrix[cd][j]);
//		if (cd++ > cu) break;
//		for (int i = cd; i <= cu; i++)
//			ans.push_back(matrix[i][ru]);
//		if (ru-- < rd)break;
//		for (int j = ru; j >= rd; j--)
//			ans.push_back(matrix[cu][j]);
//		if (cu-- < cd)break;
//		for (int i = cu; i >= cd; i--)
//			ans.push_back(matrix[i][rd]);
//		if (rd++ > ru)
//			break;
//	}
//	return ans;
//}
//
//
//int main()
//{
//	vector<vector<int>> ret = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
//	spiralOrder(ret);
//	system("pause");
//	return 0;
//}
//30
//class MinStack {
//	stack<int> stk;
//	stack<int> smin;
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//	}
//
//	void push(int x) {
//		stk.push(x);
//		if (smin.empty() || smin.top() >= x)
//			smin.push(x);
//	}
//
//	void pop() {
//		if (stk.top() == smin.top())
//			smin.pop();
//		stk.pop();
//	}
//
//	int top() {
//		return stk.top();
//	}
//
//	int min() {
//		return smin.top();
//	}
//};
//
////31
//class Solution {
//public:
//	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//		int n = pushed.size();
//		int m = popped.size();
//		if (n != m)return false;
//		stack<int> stk;
//		int j = 0;
//		for (int i = 0; i<n; i++)
//		{
//			stk.push(pushed[i]);
//			while (!stk.empty() && j<m&&popped[j] == stk.top())
//			{
//				stk.pop();
//				j++;
//			}
//		}
//		return stk.empty();
//
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
//	vector<int> levelOrder(TreeNode* root) {
//		vector<int> ans;
//		if (root == nullptr)
//			return ans;
//		queue<TreeNode*> que;
//		que.push(root);
//		TreeNode* temp = nullptr;
//		while (!que.empty())
//		{
//			temp = que.front();
//			que.pop();
//			ans.push_back(temp->val);
//			if (temp->left != nullptr)
//				que.push(temp->left);
//			if (temp->right != nullptr)
//				que.push(temp->right);
//		}
//		return ans;
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
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> ans;
//		if (root == nullptr)
//			return ans;
//		queue<TreeNode*> que;
//		que.push(root);
//		while (!que.empty())
//		{
//			vector<int> ret;
//			int l = que.size();
//			for (int i = 0; i<l; i++)
//			{
//				TreeNode* temp = que.front();
//				ret.push_back(temp->val);
//				if (temp->left != nullptr)
//					que.push(temp->left);
//				if (temp->right != nullptr)
//					que.push(temp->right);
//				que.pop();
//			}
//			ans.push_back(ret);
//		}
//		return ans;
//	}
//};


//static bool myfun(vector<int> &a, vector<int> &b)
//{
//	if (a[0] == b[0]) {
//		return a[1] > b[1];
//	}
//
//	return a[0] < b[0];
//}
//
//
//int bestSeqAtIndex(vector<int> &height, vector<int> &weight)
//{
//	vector<vector<int>> persons = vector<vector<int>>(height.size(), vector<int>(2, 0));
//	int maxvalue = 0;
//
//	for (int i = 0; i < height.size(); i++) {
//		persons[i] = { height[i], weight[i] };
//	}
//
//	sort(persons.begin(), persons.end(), myfun);
//	vector<int>  result;
//
//	for (int i = 0; i < persons.size(); i++) {
//		int index = lower_bound(result.begin(), result.end(), persons[i][1]) - result.begin();
//		if (index == result.size()){
//			result.push_back(persons[i][1]);
//		}
//		else{
//			result[index] = persons[i][1];
//		}
//	}
//
//	return result.size();
//}
//
//
//int main()
//{
//	vector<int> ans = { 65, 70, 56, 75, 60, 68 };
//	vector<int> ret = { 100, 150, 90, 190, 95, 110 };
//	bestSeqAtIndex(ans, ret);
//	system("pause");
//	return 0;
//}



//int getKthMagicNumber(int k) {
//	if (k <= 0) return 0;
//
//	vector<long long int> nums(k + 1, 1);
//	int p3 = 0, p5 = 0, p7 = 0;
//	for (int i = 1; i < k; ++i)
//	{
//		nums[i] = min(min(3 * nums[p3], 5 * nums[p5]), 7 * nums[p7]);
//		if (nums[i] == 3 * nums[p3]) p3++;
//		if (nums[i] == 5 * nums[p5]) p5++;
//		if (nums[i] == 7 * nums[p7]) p7++;
//	}
//	return nums[k - 1];
//}
//
//
//int main()
//{
//	getKthMagicNumber(10);
//	system("pause");
//	return 0;
//}


//class Solution {
//	bool helper(vector<int>& ans, int ld, int ru)
//	{
//		if (ld >= ru) return true;
//		int root = ans[ru];
//		int l = ld;
//		while (l<ru&&ans[l]<root)
//			l++;
//		int r = l;
//		while (r<ru&&ans[r]>root)
//			r++;
//		if (r != ru)return false;
//		return helper(ans, ld, l - 1) && helper(ans, l, ru - 1);
//	}
//public:
//	bool verifyPostorder(vector<int>& postorder) {
//		return helper(postorder, 0, postorder.size() - 1);
//	}
//};


//int trap(vector<int>& height) {
	// int ans=0;
	// int size=height.size()-1;
	// for(int i=1;i<=size;i++)
	// {
	//     int max_left=0,max_right=0;
	//     for(int j=i;j>=0;j--)
	//     {
	//         max_left=max(max_left,height[j]);
	//     }
	//     for(int j=i;j<=size;j++)
	//     {
	//         max_right=max(max_right,height[j]);
	//     }
	//     ans+=min(max_left,max_right)-height[i];
	// }
	// return ans;

	//int ans = 0;
	//int size = height.size();
	//vector<int> max_left(size, 0), max_right(size, 0);
	//max_left[0] = height[0];
	//for (int i = 1; i<size; i++)
	//{
	//	max_left[i] = max(max_left[i - 1], height[i]);
	//}
	//max_right[size - 1] = height[size - 1];
	//for (int i = size - 2; i >= 0; i--)
	//{
	//	max_right[i] = max(max_right[i + 1], height[i]);
	//}
	//for (int i = 1; i<size - 1; i++)
	//{
	//	ans += min(max_left[i], max_right[i]) - height[i];
	//}
	//return ans;


//	int ans = 0, current = 0;
//	stack<int> st;
//	while (current < height.size()) {
//		while (!st.empty() && height[current] > height[st.top()]) {
//			int top = st.top();
//			st.pop();
//			if (st.empty())
//				break;
//			int distance = current - st.top() - 1;
//			int bounded_height = min(height[current], height[st.top()]) - height[top];
//			ans += distance * bounded_height;
//		}
//		st.push(current++);
//	}
//	return ans;
//}
//
//int main()
//{
//	vector<int> ans = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
//	trap(ans);
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<algorithm>
//using namespace std;
//int p[1005], t[1005];
//int main()
//{
//	int n=0;
//	cin >> n;
//	int m = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> m;
//		p[i] = min(p[i - 1], t[i - 1]) + m;
//		if (i == 1)
//			continue;
//		t[i] = min(p[i - 1], p[i - 2]);
//	}
//	cout << min(p[n], t[n]) << endl;
//	system("pause");
//	return 0;
//}


#include<iostream>
using namespace std;
long long x[8], y[8];
int main()
{

}



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
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ans;
		if (root == nullptr)return ans;
		if (sum == root->val&&!root->left&&!root->right)
		{
			vector<int> ret;
			ret.push_back(root->val);
			ans.push_back(ret);
		}
		else{
			vector<vector<int>> mid;
			mid = pathSum(root->left, sum - root->val);
			for (auto s : mid){
				s.insert(s.begin(), root->val);
				ans.push_back(s);
			}
			mid = pathSum(root->right, sum - root->val);
			for (auto s : mid){
				s.insert(s.begin(), root->val);
				ans.push_back(s);
			}
		}
		return ans;
	}
};