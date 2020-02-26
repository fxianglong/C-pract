//#include<iostream>
//#include<string>
//using namespace std;
//typedef struct ListNode
//{
//	int val;
//	ListNode* next;
//	ListNode(int x) 
//		: val(x)
//		, next(NULL)
//	{}
//}ListNode;
//
////ListNode* partition(ListNode* head, int x) {
////	ListNode* nhead = new ListNode(-1);	//记录要插入位置的前一个位置
////	nhead->next = head;
////	ListNode* cur = head;	//扫描指针
////	ListNode* prev = nhead;	//紧跟着cur的指针，用来删除cur指向的元素
////	while (cur) {
////		if (cur->val < x && cur != head) {
////			prev->next = cur->next;
////			cur->next = head;
////			nhead->next = cur;
////			head = cur;
////			cur = prev->next;
////
////		}
////		else {
////			cur = cur->next;
////			prev = prev->next;
////		}
////	}
////	return nhead->next;
////}
//
//ListNode* deleteDuplicates(ListNode* head) {
//	if (!head) return head;
//	ListNode* slow = head;
//	ListNode* fast = slow->next;
//	while (fast != NULL)
//	{
//		if (slow->val == fast->val)
//			fast = fast->next;
//		else
//		{
//			slow->next = fast;
//			slow = slow->next;
//			fast = fast->next;
//		}
//	}
//	slow->next = NULL;
//	return head;
//}
//
//int main()
//{
//	/*ListNode* head =new ListNode(1);
//	ListNode*cur = new ListNode(2);
//	ListNode* pre = new ListNode(3);
//	ListNode* q = new ListNode(4);
//	ListNode *w = new ListNode(5);
//	ListNode *r = new ListNode(2);
//	ListNode *t = new ListNode(6);
//	r->next = t;
//	w->next = r;
//	q->next =w;
//	pre->next = q;
//	cur->next = pre;
//	head->next = cur;
//	partition(head, 3);*/
//
//	ListNode* head = new ListNode(1);
//	ListNode* pre = new ListNode(1);
//	ListNode* q = new ListNode(2);
//	pre->next = q;
//	head->next = pre;
//	deleteDuplicates(head);
//	system("pause");
//	return 0;
//
//}


//class Solution {
//public:
//	ListNode *detectCycle(ListNode *head) {
//		if (head == NULL)  return NULL;
//		ListNode* slow = head;
//		ListNode* fast = head;
//		while (fast != NULL&&fast->next != NULL)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//			if (slow == fast)
//			{
//				fast = head;
//				while (fast != slow)
//				{
//					fast = fast->next;
//					slow = slow->next;
//				}
//				return fast;
//				break;
//			}
//		}
//		return NULL;
//	}
//};

