//leet-code 每日一题 6-12
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> result;
		int vecSize = int(nums.size());
		if (vecSize <= 2)
		{
			return result;
		}
		int possibleSize = vecSize - 2;
		sort(nums.begin(), nums.end());

		for (int index = 0; index < possibleSize; index++)
		{
			int intNow = nums[index];
			if (intNow > 0){
				break;
			}
			int negativeNow = 0 - intNow;
			int lo = index + 1;
			int hi = vecSize - 1;
			while (lo < hi)
			{
				int intLo = nums[lo];
				int intHi = nums[hi];

				if (intLo + intHi == negativeNow)
				{
					vector<int> tmpVec{ intNow, intLo, intHi };
					result.push_back(tmpVec);

					while (lo < hi && nums[lo] == intLo)
					{
						lo++;
					}
					while (lo < hi && nums[hi] == intHi)
					{
						hi--;
					}
				}
				else if (intLo + intHi < negativeNow)
				{
					lo++;
				}
				else if (intLo + intHi > negativeNow)
				{
					hi--;
				}
			}
			while (index + 1 < possibleSize && nums[index] == nums[index + 1])
			{
				index++;
			}
		}

		return result;
	}
};