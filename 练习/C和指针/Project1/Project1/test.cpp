#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//vector<vector<int>> threeSum(vector<int>& nums) {
//	set<vector<int>> ans;
//	set<int> res;
//	for (int i = 0; i<nums.size(); i++)
//		res.insert(nums[i]);
//	for (int i = 0; i<nums.size() - 2; i++)
//	for (int j = i + 1; j<nums.size(); j++){
//		int add = (-1)*(nums[i] + nums[j]);
//		set<int>::iterator it = res.find(add);
//		if (it!=res.end()){
//			vector<int> ak;
//			ak.push_back(nums[i]);
//			ak.push_back(nums[j]);
//			ak.push_back(add);
//			sort(ak.begin(), ak.end());
//			ans.insert(ak);
//		}
//	}
//	vector<vector<int>>	q;
//	auto it = ans.begin();
//	while (it != ans.end()){
//		q.push_back(*it);
//		it++;
//	}
//	
//	return q;
//}


//vector<vector<int>> threeSum(vector<int> &nums)
//{
//	vector<vector<int>> result;
//	int vecSize = int(nums.size());
//	if (vecSize <= 2)
//	{
//		return result;
//	}
//	int possibleSize = vecSize - 2;
//	sort(nums.begin(), nums.end());
//
//	for (int index = 0; index < possibleSize; index++)
//	{
//		int intNow = nums[index];
//		if (intNow > 0){
//			break;
//		}
//		int negativeNow = 0 - intNow;
//		int lo = index + 1;
//		int hi = vecSize - 1;
//		while (lo < hi)
//		{
//			int intLo = nums[lo];
//			int intHi = nums[hi];
//
//			if (intLo + intHi == negativeNow)
//			{
//				vector<int> tmpVec{ intNow, intLo, intHi };
//				result.push_back(tmpVec);
//				//去重
//				while (lo < hi && nums[lo] == intLo)
//				{
//					lo++;
//				}
//				while (lo < hi && nums[hi] == intHi)
//				{
//					hi--;
//				}
//			}
//			else if (intLo + intHi < negativeNow)
//			{
//				lo++;
//			}
//			else if (intLo + intHi > negativeNow)
//			{
//				hi--;
//			}
//		}
//		//去重
//		while (index + 1 < possibleSize && nums[index] == nums[index + 1])
//		{
//			index++;
//		}
//	}
//
//	return result;
//}
//
//
//int main(){
//	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
//	threeSum(nums);
//	system("pause");
//	return 0;
//}

void test()

{
	int *p1 = new int[10];
	int *p2 = new int[20];
	int *p3 = new int[30];
	
	delete
}
int main()
{

	return 0;
}