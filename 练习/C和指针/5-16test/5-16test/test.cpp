#include<iostream>
#include<vector>
using namespace std;


//int pos[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//class Solution {
//public:
//	void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited, int curx, int cury)
//	{
//		//标记
//		visited[curx][cury] = 1;
//		for (int i = 0; i<4; i++)
//		{
//			int nx = curx + pos[i][0];
//			int ny = cury + pos[i][1];
//			//判断范围
//			if (nx<0 || nx >= row
//				|| ny<0 || ny >= col)
//				continue;
//			//判断是否为陆地，且是否访问过
//			if (grid[nx][ny] == '1'&&visited[nx][ny] == 0)
//				dfs(grid, row, col, visited, nx, ny);
//		}
//	}
//	int numIslands(vector<vector<char>>& grid) {
//		if (grid.empty())
//			return 0;
//		int row = grid.size();
//		int col = grid[0].size();
//		vector<vector<int>> visited(row, vector<int>(col, 0));
//
//		int number = 0;
//		for (int i = 0; i<row; i++)
//		{
//			for (int j = 0; j<col; j++)
//			{
//				if (grid[i][j] == '1'&&visited[i][j] == 0)
//				{
//					++number;
//					dfs(grid, row, col, visited, i, j);
//				}
//			}
//		}
//		return number;
//	}
//};


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//class Solution {
//public:
//	ListNode* reverseKGroup(ListNode* head, int k) {
//		ListNode *dummy = new ListNode(0);
//		ListNode *p = head, *pre = dummy, *r;
//		int cnt = 0;
//		int n = 0;
//		while (p) {  //计算链表的长度
//			n++;
//			p = p->next;
//		}
//		cnt = n / k;//计算反转的次数
//		p = head;
//		for (int i = 0; i < cnt; i++) {
//			ListNode *temp;
//			for (int j = 0; j < k; j++) {
//				if (j == 0) r = p; //用的头插法，记录尾结点，下一波反转的pre结点
//				temp = p;
//				p = p->next;
//				temp->next = pre->next;
//				pre->next = temp;
//			}
//			pre = r;
//		}
//		r->next = p;
//		return  dummy->next;
//	}
//};


//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		int dp = nums[0];
//		int ans = dp;
//		for (int i = 1; i < nums.size(); i++){
//			dp = max(dp + nums[i], nums[i]);
//			ans = max(ans, dp);
//		}
//		return ans;
//	}
//};


class Solution {
public:
	int countDigitOne(int n) {
		int count = 0;
		long i = 1;//指向遍历的位数，如i=1即个位，i=10即十位，...，因为n可以有31位，所以10^31用long存储
		while (n / i != 0){
			//n/i控制遍历的次数，将所有的位数都遍历完毕
			long high = n / (10 * i);//将当前位之前的所有高位都存在high中
			long cur = (n / i) % 10;//将当前位记录在cur中，即我们每次都需要统计当前位上1出现的次数
			long low = n - (n / i)*i;
			if (cur == 0){
				count += high * i;
			}
			else if (cur == 1){
				count += high * i + low + 1;
			}
			else {
				count += high * i + i;
			}
			i = i * 10;//准备遍历下一位
		}
		return count;
	}
};