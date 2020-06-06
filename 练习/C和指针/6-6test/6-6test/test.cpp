#include<iostream>
#include<vector>
#include<stack>
#include<set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	set<int> s;
	stack<int>  skt;
	for (auto e : nums)
		s.insert(e);
	int max = 1;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		skt.push(*it);
		it++;
		while (it != s.end() && (*it == skt.top() + 1))
		{
			skt.push(*it);
			if (skt.size()>max)
				max = skt.size();
			it++;
		}
		while (skt.size())
			skt.pop();
	}
	return max;
}
int main()
{
	vector<int> ans{100,200,1,3,2,4};
	cout << longestConsecutive(ans) << endl;
	system("pause");
	return 0;
}


class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> a;
		for (auto i : nums)
			a[i] = i;
		int ans = 0;
		for (int i = nums.size() - 1; i >= 0; --i){
			if (!a.count(nums[i] - 1)){
				int cur = nums[i];
				while (a.count(cur + 1)){
					++cur;
				}
				ans = max(ans, cur - nums[i] + 1);
			}
		}
		return ans;
	}
};