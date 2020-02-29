//class Solution {
//public:
//	vector<string> fizzBuzz(int n) {
//		vector<string> s;
//		for (int i = 1; i <= n; i++)
//		{
//			if (i % 3 == 0)
//			{
//				if (i % 5 == 0)
//					s.push_back("FizzBuzz");
//				else
//					s.push_back("Fizz");
//			}
//			else if (i % 5 == 0)
//			{
//				s.push_back("Buzz");
//			}
//			else
//				s.push_back(to_string(i));
//		}
//		return s;
//	}
//};

//
//class Solution {
//public:
//	int fib(int n) {
//		// if(n==0)
//		//     return 0;
//		// if(n==1)
//		//     return 1;
//		// return fib(n-1)+fib(n-2);
//		vector<int> ans(n + 1 + 1, 0);
//		ans[1] = 1;
//		for (int i = 2; i <= n; i++)
//		{
//			ans[i] = (ans[i - 1] + ans[i - 2]) % 1000000007;
//		}
//		return ans[n];
//	}
//};


//class Solution {
//public:
//	int minArray(vector<int>& numbers) {
//		int len = numbers.size();
//		int left = 0, right = len - 1;
//		while (left <= right)
//		{
//			if (left == right)
//				return numbers[left];
//			int mid = (left + right) / 2;
//			if (numbers[right] == numbers[mid])
//			{
//				right--;
//			}
//			else if (numbers[mid]>numbers[right])
//			{
//				left = mid + 1;
//			}
//			else right = mid;
//		}
//		return -1;
//	}
//};


//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//	unordered_map<string, int> m;
//	int res = 0;
//	for (auto& r : matrix) {
//		string s;
//		int d = 1 ^ r[0];
//		for (auto x : r) {
//			s += (d ^ x) + '0';
//		}
//		++m[s];
//		res = max(res, m[s]);
//	}
//	return res;
//}
//
//int main()
//{
//	vector<vector<int>> ans = { { 0, 0, 0 }, { 0, 0, 1 }, { 1, 1, 0}};
//	cout<<maxEqualRowsAfterFlips(ans);
//	system("pause");
//	return 0;
//
//}


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
	void reorderList(ListNode* head) {
		stack<ListNode*> ans;
		ListNode* p = head;
		while (p)
		{
			ans.push(p);
			p = p->next;
		}
		if (ans.size() <= 2)
			return;
		p = head;
		int size = ans.size();
		for (int i = 0; i< size / 2; i++)
		{
			ListNode* next = p->next;
			p->next = ans.top();
			ans.pop();
			p->next->next = next;
			p = next;
		}
		p->next = NULL;
		return;

	}
};