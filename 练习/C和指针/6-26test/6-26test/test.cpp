/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* removeDuplicateNodes(ListNode* head) {
		if (head == nullptr) return head;
		unordered_set<int> s;
		ListNode*p;
		p = head;
		s.insert(p->val);
		while (p->next != nullptr){
			if (s.count(p->next->val)){
				p->next = p->next->next;
			}
			else{
				s.insert(p->next->val);
				p = p->next;
			}
		}
		return head;
	}
};