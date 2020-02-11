#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	static int firstMissingPositive(vector<int>& nums) {
		vector<int> res;
		for (auto n : nums)
		{
			if (n>0)
				res.push_back(n);
		}
		sort(res.begin(), res.end());
		if (res[0]>1)
			return (res[0] - 1);
		else
		{
			for (int i = 0; i<res.size(); i++)
			{
				if (res[i] != res[i+1] - 1)
					return res[i] + 1;
			}
			return res[res.size() - 1] + 1;
		}
	}
};
int main()
{
	vector<int> res = { 0, 1, 2 };
	cout << Solution::firstMissingPositive(res) << endl;
	system("pause");
	return 0;
}