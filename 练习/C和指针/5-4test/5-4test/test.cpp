#include<iostream>
#include<vector>
using namespace std;

//bool Isleap(int x)
//{
//	return x & 1;
//}
//vector<int> exchange(vector<int>& nums) {
//	int i = 0, j = nums.size() - 1;
//	while (i <= j)
//	{
//		if (!Isleap(nums[i]) && Isleap(nums[j]))
//			swap(nums[i], nums[j]);
//		if (Isleap(nums[i])) i++;
//		if (!Isleap(nums[j])) j--;
//	}
//	return nums;
//}
//
//int main()
//{
//	vector<int> ans{ 1, 2, 3, 4};
//	exchange(ans);
//	system("pause");
//	return 0;
//}


//class Solution {
//	bool Isleap(int x)
//	{
//		return x & 1;
//	}
//public:
//	vector<int> exchange(vector<int>& nums) {
//		int i = 0, j = nums.size() - 1;
//		while (i <= j)
//		{
//			if (!Isleap(nums[i]) && Isleap(nums[j]))
//				swap(nums[i], nums[j]);
//			if (Isleap(nums[i])) i++;
//			if (!Isleap(nums[j])) j--;
//		}
//		return nums;
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
//	ListNode* getKthFromEnd(ListNode* head, int k) {
//		ListNode* fast = head;
//		ListNode* slow = head;
//		while (k--)
//		{
//			fast = fast->next;
//		}
//		while (fast != nullptr)
//		{
//			fast = fast->next;
//			slow = slow->next;
//		}
//		return slow;
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
//	ListNode* reverseList(ListNode* head) {
//		if (head == nullptr || head->next == nullptr)
//			return head;
//		ListNode* p = head; ListNode* q = head->next;
//		p->next = nullptr;
//		ListNode* temp = nullptr;
//		while (q != nullptr)
//		{
//			temp = q->next;
//			q->next = p;
//			p = q;
//			q = temp;
//		}
//		return p;
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
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		if (l1 == nullptr)return l2;
//		if (l2 == nullptr)return l1;
//		ListNode* p = new ListNode(1); ListNode* q = p;
//		while (l1 != nullptr&&l2 != nullptr)
//		{
//			if (l1->val<l2->val)
//			{
//				p->next = l1;
//				l1 = l1->next;
//				p = p->next;
//			}
//			else{
//				p->next = l2;
//				l2 = l2->next;
//				p = p->next;
//			}
//		}
//		if (l1 == nullptr)p->next = l2;
//		else{
//			p->next = l1;
//		}
//		return q->next;
//
//		// ListNode* head = new ListNode(1);
//		// ListNode* ret = head;
//		// while (l1 != NULL && l2 != NULL) {
//		//     if (l1->val < l2->val) {
//		//         head->next = l1;
//		//         l1 = l1->next;
//		//     } else {
//		//         head->next = l2;
//		//         l2 = l2->next;
//		//     }
//		//     head = head->next;
//		// }
//		// head->next = l1 == NULL ? l2 : l1;
//		// return ret->next;
//
//	}
//};


//#include"Shared_ptr.h"
//int main()
//{
//	Shared_Ptr<int> sp1(new int(10));
//	Shared_Ptr<int> sp2(sp1);
//	*sp2 = 20;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	Shared_Ptr<int> sp3(new int(10));
//	sp2 = sp3;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	cout << sp3.UseCount() << endl;
//	sp1 = sp3;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	cout << sp3.UseCount() << endl;
//
//	system("pause");
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	char a[100];
//	int i, count = 0, b = 0;
//	char c;
//	gets(a);//获取字符串
//
//	for (i = 0; a[i] != '\0'; i++)
//	{
//		c = a[i];
//		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//			continue;
//		else if (c == ' ')
//		{
//			count++;
//		}
//		else
//		{
//			count++;
//			b++;
//		}
//	}
//	if ((a[i - 1] >= 'a' && a[i - 1] <= 'z') || (a[i - 1] >= 'A' && a[i - 1] <= 'Z'))
//		count++;
//
//	printf("单词个数=%d\n", count);
//	printf("标点个数=%d\n", b);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	char a[100];
//	int count = 0, op = 0;
//	gets(a);
//	char* c = a;
//	char* pre;
//	while (*c != '\0')
//	{
//		pre = c;
//		if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
//			c++;
//		else if (*c == ' ')
//		{
//			count++;
//			c++;
//		}
//		else
//		{
//			count++;
//			op++;
//			c++;
//		}
//	}
//	if ((*pre >= 'a' && *pre <= 'z') || (*pre >= 'A' && *pre <= 'Z'))
//		count++;
//	printf("%d %d", count, op);
//	return 0;
//}

#include<memory>
//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode(){ cout << "~ListNode()" << endl; }
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	system("pause");
//	return 0;
//}



// 解决方案：在引用计数的场景下，把节点中的_prev和_next改成weak_ptr就可以了
// 原理就是，node1->_next = node2;和node2->_prev = node1;时weak_ptr的_next和_prev不会增加node1和node2的引用计数。
//struct ListNode
//{
//	int _data;
//	weak_ptr<ListNode> _prev;
//	weak_ptr<ListNode> _next;
//	~ListNode(){ cout << "~ListNode()" << endl; }
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	system("pause");
//	return 0;
//}


//template<class T>
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(T& x) : val(x), left(NULL), right(NULL) {}
//};
//
//bool flag = true;
//template<class T>
//bool isValidBST(TreeNode<T>* root) {
//	isValidDFS(root);
//	return flag;
//}
//template<class T>
//void isValidDFS(TreeNode<T>* root){
//	if (flag = false || root == nullptr) return;
//	if (root->left&&root->val<root->left->val)
//		flag = false;
//	if (root->right&&root->val>root->right->val)
//		flag = false;
//	isValidDFS(root->left);
//	isValidDFS(root->right);
//}
//
//
//int main()
//{
//	TreeNode<int>* ans;
//
//}


//class Solution {
//public:
//	bool isSameTree(TreeNode* p, TreeNode* q) {
//		if (!p && !q) return true;
//		if (!p || !q) return false;
//		return (p->val == q->val)
//			&& (isSameTree(p->left, q->left)
//			&& isSameTree(p->right, q->right));
//		// stack<TreeNode*> s1;
//		// TreeNode* ptemp;
//		// TreeNode* qtemp;
//		// s1.push(p);
//		// s1.push(q);
//		// while(!s1.empty())
//		// {
//		//     ptemp=s1.top();
//		//     s1.pop();           
//		//     qtemp=s1.top();
//		//     s1.pop();
//		//     if(!ptemp&&!qtemp)  continue;
//		//     else if(!ptemp||!qtemp)return false;
//		//     else if(ptemp->val != qtemp->val)return false;
//		//     else{
//		//         s1.push(ptemp->left);
//		//         s1.push(qtemp->left);
//		//         s1.push(ptemp->right);
//		//         s1.push(qtemp->right);
//		//     }
//		// }
//		// return true;
//	}
//};

#include<queue>
class Solution {
public:
	int maxDepth(TreeNode* root) {
		// if(!root) return 0;
		// return max(maxDepth(root->left),maxDepth(root->right))+1;



		// queue<TreeNode*> q;
		// int ans = 0;
		// if (root != nullptr) q.push(root);
		// while (!q.empty()) {
		//     for (int i = q.size() - 1; i >= 0; --i) {
		//         TreeNode* cur = q.front();
		//         q.pop();
		//         if (cur->left) q.push(cur->left);
		//         if (cur->right) q.push(cur->right);
		//     }
		//     ++ans;
		// }
		// return ans;

		queue<TreeNode*> q;
		int ans = 0;
		if (root) q.push(root);
		while (!q.empty())
		{
			for (int i = q.size() - 1; i >= 0; i--)
			{
				TreeNode* cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			ans++;
		}
		return ans;
	}
};