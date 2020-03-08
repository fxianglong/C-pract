//#include<iostream>
//#include<vector>
//#include<set>
//using namespace std;
//template<class _Ty = void>
//struct more
//	: public binary_function<_Ty, _Ty, bool>
//{
//	bool operator()(const _Ty& _Left, const _Ty& _Right) const
//	{
//		return (_Left > _Right);
//	}
//};
//
//int findPeakElement(vector<int>& nums) {
//	set<int,more<int>> ans;
//	for (auto num : nums)
//		ans.insert(num);
//	auto it = ans.begin();
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (nums[i] == *it)
//			return i;
//	}
//}
//int main()
//{
//	vector<int> nums = { 1, 2, 3, 4, 32, 34, 54, 546, 53, 2, 32 };
//	cout << findPeakElement(nums);
//	system("pause");
//	return 0;
//}

//
//class Solution {
//public:
//	int findPeakElement(vector<int>& nums) {
//		for (int i = 0; i<nums.size() - 1; i++)
//		{
//			if (nums[i]>nums[i + 1])
//				return i;
//		}
//		return nums.size() - 1;
//	}
//};


#include<iostream>
#include<hash_map>
#include<unordered_map>
using namespace std;

unordered_map<int, int> ans;