#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int sum = 0;;
	for (int i = 0; i<s.size(); i++)
	{
		int count = 0;
		int hash[256] = { 0 };
		for (int j = i; j<s.size(); j++)
		{
			if (hash[s[j]] == 0)
			{
				count++;
				hash[s[j]]++;
			}
			else
			{
				break;
			}
		}
		if (sum<count)
			sum = count;
	}
	return sum;
}
int main()
{
	string s = "abcabcabc";
	cout << lengthOfLongestSubstring(s) << endl;
	system("pause");
	return 0;
}