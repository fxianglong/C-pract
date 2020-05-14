#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;

//class Node {
//public:
//	int val;
//	Node* next;
//	Node* random;
//
//	Node(int _val) {
//		val = _val;
//		next = NULL;
//		random = NULL;
//	}
//};
//
//Node* copyRandomList(Node* head) {
//	if (head == NULL)return NULL;
//	Node*p = head, *q;
//	while (p){
//		q = p->next;
//		p->next = new Node(p->val);
//		p->next->next = q;
//		p = q;
//	}
//	p = head;
//	while (1){
//		if (p->random)
//			p->next->random = p->random->next;
//		if (p->next->next) p = p->next->next;
//		else break;
//	}
//	p = head; q = head->next;
//	Node *ret = head->next;
//	while (p&&q){
//		p->next = q->next;
//		p = p->next;
//		if (p)q->next = p->next;
//		else break;
//		q = q->next;
//	}
//	return ret;
//}
//
//int main()
//{
//
//}
//
///*
//// Definition for a Node.
//class Node {
//public:
//int val;
//Node* next;
//Node* random;
//
//Node(int _val) {
//val = _val;
//next = NULL;
//random = NULL;
//}
//};
//*/
//class Solution {
//public:
//	Node* copyRandomList(Node* head) {
//		if (head == nullptr){
//			return nullptr;
//		}
//		copy(head);
//		randomDirect(head);
//		return reList(head);
//	}
//
//	void copy(Node* head){
//		while (head != nullptr){
//			Node* cloneNode = new Node(head->val);
//			Node* nextNode = head->next;
//			head->next = cloneNode;
//			cloneNode->next = nextNode;
//			head = cloneNode->next;
//		}
//	}
//	//指定随机指针
//	void randomDirect(Node* head){
//		while (head != nullptr){
//			Node* cloneNode = head->next;
//			if (head->random != nullptr){
//				Node* direct = head->random;
//				cloneNode->random = direct->next;
//			}
//			head = cloneNode->next;
//		}
//	}
//	Node* reList(Node* head){
//		Node* cloneNode = head->next;
//		Node* cloneHead = cloneNode;
//		head->next = cloneNode->next;
//		head = head->next;
//		while (head != nullptr){
//			cloneNode->next = head->next;
//			head->next = head->next->next;
//			head = head->next;
//			cloneNode = cloneNode->next;
//		}
//		return cloneHead;
//	}
//
//};


//class Solution {
//public:
//	Node* treeToDoublyList(Node* root) {
//		if (!root) return nullptr;
//		Node* head = nullptr, *pre = nullptr;
//		helper(root, head, pre);
//		head->left = pre;
//		pre->right = head;
//		return head;
//	}
//	void helper(Node* root, Node*& head, Node*& pre) {
//		if (!root)  return;
//		helper(root->left, head, pre);
//		if (!head) {
//			head = root;   // 找到head
//			pre = root;    // 对pre进行初始化
//		}
//		else {
//			pre->right = root;
//			root->left = pre;
//			pre = root;
//		}
//		helper(root->right, head, pre);
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
//class Codec {
//public:
//
//	// Encodes a tree to a single string.
//	string serialize(TreeNode* root) {
//		string res;
//		queue<TreeNode*> que;  //队列
//		que.push(root);
//		while (!que.empty()){
//			TreeNode* p = que.front();
//			que.pop();
//			if (p == NULL){
//				res += "null,";  //string型
//			}
//			else{
//				res += to_string(p->val) + ",";
//				que.push(p->left);
//				que.push(p->right);
//			}
//		}
//		return res;
//	}
//
//	// Decodes your encoded data to tree.
//	TreeNode* deserialize(string data) {
//		TreeNode* r = NULL;
//		vector<string> arr;
//		string tmp;
//		for (int i = 0; i<data.size(); i++){
//			if (data[i] == ','){   //用”#”表示一个字符串的首地址！！所以要用单引号！！
//				arr.push_back(tmp);
//				tmp = "";
//			}
//			else{
//				tmp += data[i];
//			}
//		}
//		if (arr[0] == "null"){
//			return r;
//		}
//		queue<TreeNode*> que;
//		TreeNode* root = new TreeNode(stoi(arr[0]));
//		que.push(root);
//		int i = 1;
//		TreeNode *q;
//		while (!que.empty() && i<arr.size()){
//			q = que.front();
//			que.pop();
//			if (arr[i] != "null"){
//				q->left = new TreeNode(stoi(arr[i]));
//				que.push(q->left);
//			}
//			i++;
//			if (i>data.size()){
//				break;
//			}
//			if (arr[i] != "null"){
//				q->right = new TreeNode(stoi(arr[i]));
//				que.push(q->right);
//			}
//			i++;
//		}
//		return root;
//	}
//};


//vector<string> result;
//bool judge(string& s, int start, int end) {
//	for (int i = start; i < end; ++i) {
//		if (s[i] == s[end]) return true;
//	}
//	return false;
//}
//void dfs(string& s, int pos) {
//	if (pos >= s.size()) {
//		result.push_back(s);
//		return;
//	}
//	for (int i = pos; i < s.size(); ++i) {
//
//		if (judge(s, pos, i)) continue;   // 如果pos和i之间有字符等于s[i]，则跳过。
//		swap(s[pos], s[i]);
//		dfs(s, pos + 1);
//		swap(s[pos], s[i]);
//	}
//}
//
//vector<string> permutation(string s) {
//	dfs(s, 0);
//	return result;
//}
//
//
//
//
//int main()
//{
//	string s = "abc";
//	dfs(s, 0);
//	system("pause");
//	return 0;
//}



//class Solution {
//public:
//	int majorityElement(vector<int>& nums) {
//		map<int, int> ans;
//		for (auto e : nums)
//		{
//			ans[e]++;
//			if (ans[e]>nums.size() / 2)
//				return e;
//		}
//		return -1;
//	}
//};


