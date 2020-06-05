
//力扣顺时针打印链表
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty())
			return ans;
		int cd = 0, rd = 0;
		int cu = matrix.size() - 1, ru = matrix[0].size() - 1;
		while (1)
		{
			for (int j = rd; j <= ru; j++)
				ans.push_back(matrix[cd][j]);
			if (++cd > cu) break;
			for (int i = cd; i <= cu; i++)
				ans.push_back(matrix[i][ru]);
			if (--ru < rd)break;
			for (int j = ru; j >= rd; j--)
				ans.push_back(matrix[cu][j]);
			if (--cu < cd)break;
			for (int i = cu; i >= cd; i--)
				ans.push_back(matrix[i][rd]);
			if (++rd > ru)
				break;
		}
		return ans;
	}
};