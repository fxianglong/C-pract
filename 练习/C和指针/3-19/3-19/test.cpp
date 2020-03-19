//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s;
//	while (cin>>s){
//			for (int i = 0; i < s.size(); ++i)
//			{
//				if (s[i] == '_') continue;
//				if (i > 0 && s[i - 1] == '_') cout << (char)toupper(s[i]);
//				else cout << s[i];
//			}
//			cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	stack<string> str;
//	string res="";
//	for (int i = 0; i < s.size(); i++){
//		if (s[i] != ' ')	res += s[i];
//		else
//		{
//			str.push(res);
//			res = "";
//		}
//	}
//	str.push(res);
//	res = "";
//	for (int i = 0; i < str.size(); i++){
//		if (i != str.size() - 1)
//		{
//			cout << str.top() << " ";
//		}
//		else
//		{
//			cout << str.top() << endl;
//		}
//		str.pop();
//	}
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2){
//		if (s2.size() > s1.size()||s2=="")	{ cout << "No" << endl; continue; }
//		int hash1[26] = { 0 }, hash2[26] = { 0 };
//		for (int i = 0; i < s1.size(); i++){
//			hash1[s1[i] - 'A']++;
//		}
//		for (int i = 0; i < s1.size(); i++){
//			hash2[s1[i] - 'A']++;
//		}
//		for (auto i:s2){
//			if (hash1[i-'A'] >= hash2[i-'A'])
//				continue;
//			else
//			{
//				cout << "No" << endl;
//				break;
//			}
//		}
//		cout << "Yes" << endl;
//	}
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		map<char, int>A, B;
//		int i = 0;
//		for (i = 0; i<s1.size(); i++)
//		{
//			A[s1[i]]++;
//		}
//		for (i = 0; i<s2.size(); i++)
//		{
//			B[s2[i]]++;
//		}
//		for (i = 'A'; i <= 'Z'; i++)
//		{
//			if (B[i]>A[i])
//			{
//				cout << "No" << endl;
//				break;
//			}
//			if (i == 'Z')
//				cout << "Yes" << endl;
//		}
//
//	}
//	return 0;
//}


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isBrother(string str, string s){
	if (str.size() == s.size()){
		if (str == s)
			return false;
		sort(str.begin(), str.end());
		sort(s.begin(), s.end());
		if (str == s)
			return true;
	}
	return false;
}
int main(){
	int num;
	while (cin >> num){
		string str;
		string word, s;
		int index;
		vector<string> vs;
		for (int i = 0; i < num; ++i){
			cin >> str;
			vs.push_back(str);
		}
		sort(vs.begin(), vs.end());  // 因为是字典，一定要排序！！
		cin >> word;
		cin >> index;
		int counts = 0;

		for (int i = 0; i < num; ++i){
			if (isBrother(word, vs[i])){
				counts++;
				if (counts == index)
					s = vs[i];
			}
		}
		if (!vs.empty())
			cout << counts << endl;
		if (counts >= index)
			cout << s << endl;

	}
	return 0;
}