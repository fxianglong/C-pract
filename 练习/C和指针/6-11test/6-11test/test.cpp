//leet-code每日一题 6-11
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int len = T.size();
		vector<int> ans(len, 0);
		stack<int> stk;
		for (int i = 0; i<len; i++)
		{
			while (stk.size() && T[i]>T[stk.top()])
			{
				ans[stk.top()] = i - stk.top();
				stk.pop();
			}
			stk.push(i);
		}
		return ans;
	}
};


