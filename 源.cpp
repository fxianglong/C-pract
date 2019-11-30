//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	string s;
//	cin >> s;
//	reverse(s.begin(),s.end());
//	cout << s << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//int getcommentlength(string s1, string s2)
//{
//	if (s1 > s2)
//		swap(s1, s2);
//	int count = 0;
//	for (int i = 0; i < s1.size(); i++)
//	{
//		int ret = 0;
//		int j = 0;
//		while (j<s2.size())
//		{
//			int m = i;
//			j = s2.find(s1[m], j);   //在s2中找s1的字母
//			while (s1[m] == s2[j] && m<s1.size())   //如果找到，ret计数++，并继续查找
//			{
//				ret++;
//				m++; j++;
//			}
//			if (ret>count)   //比较ret 与count，取较大的值
//				count = ret;
//			ret = 0;
//		}
//	}
//	return count;
//
//}
//int main()
//{
//	string s1, s2;
//	cin >> s1;
//	cin >> s2;
//
//	cout << getcommentlength(s1, s2) << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//const int Tabsize = 256;
//int hashtab[Tabsize];
//int main(){
//	string str;
//	while (cin >> str){
//		bool flg = false;
//		for (int i = 0; i<Tabsize; ++i) {
//			hashtab[i] = 0;
//		}
//		for (int i = 0; i<str.size(); ++i){
//			hashtab[str[i]]++;
//		}
//		for (int i = 0; !flg && i<str.size(); ++i){
//			if (hashtab[str[i]] == 1){
//				cout << str[i] << endl;
//				flg = true;
//				break;
//			}
//		}
//		if (!flg)
//			cout << '-1' << endl;
//	}
//	return 0;
//}


#include <iostream>
#include "stdio.h"
#include <vector>
using namespace std;
int gcd(int m, int n)
{
	if (n == 0)
		return m;

	int temp = m%n;
	m = n;
	n = temp;
	return gcd(m, n);
}
int main()
{
	int n, ans;
	while (cin >> n >> ans)
	{
		while (n>0)
		{
			int cur;
			cin >> cur;
			ans = ans + ((ans<cur) ? gcd(cur, ans) : cur);
			n--;
		}
		cout << ans << endl;
	}
	return 0;
}