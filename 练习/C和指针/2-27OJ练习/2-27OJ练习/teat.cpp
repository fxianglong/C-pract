//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//	for (int i = 0; i<nums2.size(); i++)
//		nums1.push_back(nums2[i]);
//	sort(nums1.begin(), nums1.end());
//	if (((nums1.size() % 2) & 1) == 0)
//		return ((nums1[(nums1.size()) / 2-1] + nums1[(nums1.size()) / 2]) / 2.0);
//	else
//		return (nums1[(nums1.size() / 2)-1]);
//}
//
//int main()
//{
//	vector<int> num1 = { 1, 2 };
//	vector<int> num2 = { 3, 4 };
//	cout<<findMedianSortedArrays(num1, num2);
//	system("pause");
//	return 0;
//}
