#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int len = nums.size();
		int left = 1;
		int right = len - 1;

		while (left < right) {
			int mid = left + (right - left + 1) / 2;

			int cnt = 0;
			for (int num : nums) {
				if (num < mid) {
					cnt++;
				}
			}

			// ���ݳ���ԭ���ϸ�С�� 4 �����ĸ���������ڵ��� 4 ����
			// ��ʱ�ظ�Ԫ��һ�������� [1, 3] ������

			if (cnt >= mid) {
				// �ظ���Ԫ��һ�������� [left, mid - 1] ������
				right = mid - 1;
			}
			else {
				// if ������ȷ���Ժ�else ������������� if �ķ���
				// [mid, right]
				// ע�⣺��ʱ��Ҫ������λ����ȡ��Ϊ��ȡ��
				left = mid;
			}
		}
		return left;
	}
};