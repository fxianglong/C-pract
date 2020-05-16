#include<iostream>
#include<vector>
using namespace std;


//int pos[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//class Solution {
//public:
//	void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited, int curx, int cury)
//	{
//		//���
//		visited[curx][cury] = 1;
//		for (int i = 0; i<4; i++)
//		{
//			int nx = curx + pos[i][0];
//			int ny = cury + pos[i][1];
//			//�жϷ�Χ
//			if (nx<0 || nx >= row
//				|| ny<0 || ny >= col)
//				continue;
//			//�ж��Ƿ�Ϊ½�أ����Ƿ���ʹ�
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
//		while (p) {  //��������ĳ���
//			n++;
//			p = p->next;
//		}
//		cnt = n / k;//���㷴ת�Ĵ���
//		p = head;
//		for (int i = 0; i < cnt; i++) {
//			ListNode *temp;
//			for (int j = 0; j < k; j++) {
//				if (j == 0) r = p; //�õ�ͷ�巨����¼β��㣬��һ����ת��pre���
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
		long i = 1;//ָ�������λ������i=1����λ��i=10��ʮλ��...����Ϊn������31λ������10^31��long�洢
		while (n / i != 0){
			//n/i���Ʊ����Ĵ����������е�λ�����������
			long high = n / (10 * i);//����ǰλ֮ǰ�����и�λ������high��
			long cur = (n / i) % 10;//����ǰλ��¼��cur�У�������ÿ�ζ���Ҫͳ�Ƶ�ǰλ��1���ֵĴ���
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
			i = i * 10;//׼��������һλ
		}
		return count;
	}
};