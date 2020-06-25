#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
bool wordBreak(string s, vector<string>& wordDict) {
	auto wordDictSet = unordered_set <string>();
	for (auto word : wordDict) {
		wordDictSet.insert(word);
	}

	auto dp = vector <bool>(s.size() + 1);
	dp[0] = true;
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
				dp[i] = true;
				break;
			}
		}
	}

	return dp[s.size()];
}

int main()
{
	string s = "leetcode";
	vector<string> ans = { "leet", "code" };
	bool ret = wordBreak(s, ans);
	if (ret == false)
		cout << "false";
	else
	{
		cout << "true";
	}
	system("pause");
	return 0;
}