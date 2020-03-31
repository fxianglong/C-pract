//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int mat = nums[0];
//		int sum = 0;
//		for (auto num : nums){
//			if (sum>0){
//				sum += num;
//			}
//			else
//				sum = num;
//			mat = max(mat, sum);
//		}
//		return mat;
//	}
//};


class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> kRows(rowIndex + 1);
		for (int i = 0; i <= rowIndex; i++)
		{
			kRows[i] = 1;//行末尾为1
			for (int j = i; j > 1; j--)//每一行的更新过程
			{
				kRows[j - 1] = kRows[j - 2] + kRows[j - 1];
			}
		}
		return kRows;
	}
};