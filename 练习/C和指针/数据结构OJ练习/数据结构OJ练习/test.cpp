//#include<iostream>
//#include<stack>
//using namespace std;
//
//bool isValid(string s) {
//	int len = s.size();
//	if (len == 0) return 1;
//
//	if (len % 2 == 1) return 0;
//
//	stack<char> st;
//	st.push('0');
//	st.push(s[0]);
//	for (int i = 1; i <= len - 1; i++)
//	{
//		if ((st.top() == '('&&s[i] == ')') || (st.top() == '['&&s[i] == ']') || (st.top() == '{'&&s[i] == '}'))
//		{
//			st.pop();
//		}
//		else{
//			st.push(s[i]);
//		}
//	}
//	if (st.top() == '0') return 1;
//	else return 0;
//}
//int main()
//{
//	string s="){";
//	cout << isValid(s) << endl;
//	system("pause");
//	return 0;
//}

