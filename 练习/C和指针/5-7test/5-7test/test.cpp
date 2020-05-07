#include<iostream>
#include<vector>
#include<string>
using namespace std;


//572
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
//	bool isSubtree(TreeNode* s, TreeNode* t) {
//		if (!s)
//			return false;
//		return isSubtree(s->left, t) || Sametree(s, t) || isSubtree(s->right, t);
//	}
//	bool Sametree(TreeNode* s, TreeNode* t)
//	{
//		if (!s&&!t)return true;
//		if (!s || !t)return false;
//		return s->val == t->val&&Sametree(s->left, t->left) && Sametree(s->right, t->right);
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
//	int kthToLast(ListNode* head, int k) {
//		int i = 0;
//		struct ListNode *fast = head;
//		struct ListNode *slow = head;
//		while (fast->next != NULL)
//		{
//			fast = fast->next;
//			i++;
//			if (i >= k)
//				slow = slow->next;
//		}
//		return slow->val;
//	}
//};



//class Solution {
//public:
//	void deleteNode(ListNode* node) {
//		node->val = node->next->val;
//
//		//¸Éµônext½áµã
//		ListNode* tmp = node->next;
//		node->next = node->next->next;
//
//		delete tmp;
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
//	ListNode* partition(ListNode* head, int x) {
//		ListNode* res = new ListNode(0, nullptr);
//		ListNode *node = res;
//		vector<int> vec;
//		while (head != NULL)
//		{
//			if (head->val >= x)
//			{
//				vec.push_back(head->val);
//			}
//			else
//			{
//				node->next = new ListNode(head->val, nullptr);
//				node = node->next;
//			}
//			head = head->next;
//		}
//		vector<int>::iterator iter;
//		for (iter = vec.begin(); iter != vec.end(); iter++)
//		{
//			node->next = new ListNode(*iter, nullptr);
//			node = node->next;
//		}
//		return res->next;
//	}
//};

#include<stack>


//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		stack<int> st1, st2;
//		while (l1!=nullptr)
//		{
//			st1.push(l1->val);
//			l1 = l1->next;
//		}
//		while (l2!=nullptr)
//		{
//			st2.push(l2->val);
//			l2 = l2->next;
//		}
//		unsigned long long n1 = 0, n2 = 0;
//		while (!st1.empty())
//		{
//			n1 = n1 * 10 + st1.top(); st1.pop();
//		}
//		while (!st2.empty())
//		{
//			n2 = n2 * 10 + st2.top(); st2.pop();
//		}
//		unsigned long long n = n1 + (n2-n1)/2; ListNode* cur = new ListNode(0); ListNode* head = cur;
//		while (n != 0)
//		{
//			if (n%10)
//			cur->next = new ListNode(n % 10);
//			cur = cur->next;
//			n /= 10;
//		}
//		return head->next;
//	}
//
//int main()
//{
//	vector<int> ans = { 9 };
//	vector<int> ret = { 1,9,9,9,9,9,9,9,9,9,9 };
//	ListNode* l1 = new ListNode(0); ListNode* l11 = l1;
//	for (auto e : ans)
//	{
//		l1->next = new ListNode(e);
//		l1 = l1->next;
//	}
//	ListNode* l2 = new ListNode(0); ListNode* l22 = l2;
//	for (auto e : ret)
//	{
//		l2->next = new ListNode(e);
//		l2 = l2->next;
//	}
//	addTwoNumbers(l11->next,l22->next);
//	system("pause");
//	return 0;
//}

//#include<deque>
//
//int main()
//{
//	deque<int> ans{ 1, 2, 3, 4, 5, 6, 7, 8, 2 };
//	cout<<ans.back();
//	return 0;
//}


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
//	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//		ListNode* l1 = headA; ListNode* l2 = headB;
//		while (l1 != l2)
//		{
//			if (l1 != NULL)
//				l1 = l1->next;
//			else
//				l1 = headB;
//			if (l2 != NULL)
//				l2 = l2->next;
//			else
//				l2 = headA;
//		}
//		return l1;
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
//	ListNode *detectCycle(ListNode *head) {
//		ListNode* slow = head;
//		ListNode* fast = head;
//
//		while (fast && fast->next)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//
//			if (slow == fast)
//				break;
//		}
//
//		if (fast == nullptr || fast->next == nullptr)
//			return nullptr;
//
//		ListNode* p1 = head;
//		ListNode* p2 = fast;
//
//		while (p1 != p2)
//		{
//			p1 = p1->next;
//			p2 = p2->next;
//		}
//
//		return p1;
//	}
//};



//class TripleInOne {
//public:
//	int size;
//	vector<int> vec;
//public:
//	TripleInOne(int stackSize) {
//		size = stackSize;
//		vec.assign(3 * (size + 1), 0);
//	}
//
//	void push(int stackNum, int value) {
//		int start = stackNum * (size + 1);
//		if (vec[start] < size)
//		{
//			int i = vec[start];
//			vec[start] = i + 1;
//			vec[start + i + 1] = value;
//		}
//	}
//
//	int pop(int stackNum) {
//		int start = stackNum * (size + 1);
//		if (vec[start] > 0)
//		{
//			int i = vec[start];
//			vec[start] = i - 1;
//			return vec[start + i];
//		}
//		return -1;
//	}
//
//	int peek(int stackNum) {
//		int start = stackNum * (size + 1);
//		if (vec[start] == 0)
//		{
//			return -1;
//		}
//		int i = vec[start];
//		return vec[start + i];
//	}
//
//	bool isEmpty(int stackNum) {
//		int start = stackNum * (size + 1);
//		if (vec[start] == 0)
//		{
//			return true;
//		}
//		return false;
//	}
//};



//class MinStack {
//	stack<int> st1;
//	stack<int> st2;
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//
//	}
//
//	void push(int x) {
//		st1.push(x);
//		if (st2.empty() || st2.top() >= x)
//			st2.push(x);
//	}
//
//	void pop() {
//		if (st2.top() == st1.top())
//			st2.pop();
//		st1.pop();
//	}
//
//	int top() {
//		return st1.top();
//	}
//
//	int getMin() {
//		return st2.top();
//	}
//};



//class Solution {
//public:
//	int distributeCandies(vector<int>& candies) {
//		unordered_set<int> s;
//		for (auto e : candies)
//			s.insert(e);
//		if (s.size()>candies.size() / 2)
//			return candies.size() / 2;
//		else
//			return s.size();
//	}
//};



