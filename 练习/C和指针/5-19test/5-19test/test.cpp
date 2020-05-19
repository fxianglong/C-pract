#include<iostream>
using namespace std;
#include<string>




//int main()
//{
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	int hash[256] = { 0 };
//	for (int i = 0; i < str2.size(); i++)
//	{
//		hash[str2[i]]++;
//	}
//	string str;
//	for (int i = 0; i < str1.size(); i++)
//	{
//		if (hash[str1[i]] != 0)
//			str += str1[i];
//	}
//	cout << str << endl;
//	return 0;
//}


//class Solution {
//public:
//	bool checkPalindrome(const string& s, int low, int high) {
//		for (int i = low, j = high; i < j; ++i, --j) {
//			if (s[i] != s[j]) {
//				return false;
//			}
//		}
//		return true;
//	}
//	bool validPalindrome(string s) {
//		int low = 0, high = s.size() - 1;
//		while (low < high) {
//			char c1 = s[low], c2 = s[high];
//			if (c1 == c2) {
//				++low;
//				--high;
//			}
//			else {
//				return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
//			}
//		}
//		return true;
//	}
//};


