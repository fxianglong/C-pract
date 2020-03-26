#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int massage(vector<int>& nums) {
	int a = 0, b = 0;
	for (int i = 0; i<nums.size(); i++){
		int c = max(b, a + nums[i]);
		a = b;
		b = c;
	}
	return b;
}

int main(){
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(2);
	ans.push_back(3);
	ans.push_back(1);
	massage(ans);
	return 0;
}