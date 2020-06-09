class Solution {
public:
	int translateNum(int num) {
		// if(num<=9)return 1;
		// int ans=num%100;
		// if(ans<=9||ans>=26)return translateNum(num/10);
		// else{
		//     return translateNum(num/10)+translateNum(num/100);
		// }
		if (num <= 9)return 1;
		vector<int> ans;
		while (num)
		{
			ans.push_back(num % 10);
			num /= 10;
		}
		reverse(ans.begin(), ans.end());
		int add = 0; int num1 = 1, num2 = 1;
		for (int i = 1; i<ans.size(); i++)
		{
			if (ans[i - 1] == 0 || ans[i - 1] * 10 + ans[i]>25)
				add = num1;
			else add = num1 + num2;
			num2 = num1;
			num1 = add;
		}
		return add;
	}
};