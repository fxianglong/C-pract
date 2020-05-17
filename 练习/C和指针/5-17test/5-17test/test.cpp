#include<iostream>
#include<vector>
#include<string>
using namespace std;


//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		string s = "";
//		int minLen = 0;
//		for (int i = 0; i<strs.size(); i++){
//			if (strs[i].size()>minLen){
//				minLen = strs[i].size();
//			}
//		}
//		for (int i = 0; i<minLen; i++){
//			char ch = strs[0][i];
//			int flag = 1;
//			for (int j = 1; j<strs.size(); j++){
//				if (ch != strs[j][i]){
//					flag = 0;
//					break;
//				}
//			}
//			if (flag == 0){
//				return s;
//			}
//			else{
//				s += ch;
//			}
//		}
//		return s;
//	}
//};
//
//
//
//class Solution {
//public:
//	int numTimesAllBlue(vector<int>& light) {
//		int m = 1; int count = 0;
//		for (int i = 0; i<light.size(); i++)
//		{
//			m = max(light[i], m);
//			if (m == i + 1)
//				count++;
//		}
//		return count;
//	}
//};


