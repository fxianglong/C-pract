//#include<iostream>
//#include<string> 
//using namespace std;
//
//int main()
//{
//	string s, t;
//	while (cin >> s >> t)
//	{
//		int count = 0; size_t i = 0;
//		while (i < s.size()){
//			size_t it = 0;
//			it = s.find(t,i);
//			if (it != -1)
//			{
//				count++;
//				i = it + t.size();
//			}
//			else break;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}


//#include <iostream>
//#include <string>
//
//using namespace  std;
//
//int Number(string s1, string s2)
//{
//	int number = 0;
//	size_t i = 0;
//	while (i<s1.size())
//	{
//		size_t pos = 0;
//		pos = s1.find(s2, i);
//		if (pos != -1)
//		{
//			number++;
//			i = pos + s2.size();
//		}
//		else
//			break;
//	}
//	return number;
//}
//int main()
//{
//	string s, t;
//	while (cin >> s >> t)
//	{
//		int n = Number(s, t);
//		cout << n << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	long long ans[90] = { 0 };
//	ans[1] = 1; ans[2] = 1;
//	for (int i = 3; i <= 80; i++)
//	{
//		ans[i] = ans[i - 1] + ans[i - 2];
//	}
//	int start = 0, end = 0;
//	while (cin >> start >> end)
//	{
//		long long sum = 0;
//		while (start <= end)
//		{
//			sum += ans[start];
//			start++;
//		}
//		cout << sum<<endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//bool hasfh(string s)
//{
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ' ' || s[i] == ',')
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		cin.get();
//		vector<string> str;
//		while (n--)
//		{
//			string s;
//			getline(cin, s);
//			str.push_back(s);
//		}
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (hasfh(str[i]))
//			{
//				cout << '\"' << str[i] << '\"';
//			}
//			else
//			{
//				cout << str[i];
//			}
//			if (i < str.size() - 1)
//				cout << ','<<' ';
//			else cout << endl;
//		}
//	}
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cin.get();
//		string name;
//		for (int i = 0; i<n; i++)
//		{
//			getline(cin, name);
//			if (i != n - 1)
//			{
//				if (name.find(',') != -1 || name.find(' ') != -1)
//					cout << '\"' << name << '\"' << ',' << ' ';
//				else
//					cout << name << ',' << ' ';
//			}
//			else
//			{
//				if (name.find(',') != -1 || name.find(' ') != -1)
//					cout << '\"' << name << '\"' << endl;
//				else
//					cout << name << endl;
//			}
//		}
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//long long JC(int n)
//{
//	if (n == 1)
//		return 1;
//	else
//		return n*JC(n - 1);
//}
//long long PC(int n)
//{
//	if (n == 1)
//		return 0;
//	if (n == 2)
//		return 1;
//	else return (n-1)*(PC(n - 1) + PC(n - 2));
//}
//int main()
//{
//	int n = 0;
//	while (cin>>n)
//	{
//		long long max = JC(n);
//		long long min = PC(n);
//		double gailv = (min*100.00)/ max;
//		printf("%.2f%%\n", gailv);
//	}
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	long long der[21] = { 0, 0, 1 }, fun[21] = { 0, 1, 2 };
//	int i, n;
//	for (i = 3; i < 21; i++)
//	{
//		der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
//		fun[i] = i*fun[i - 1];
//	}
//	while (~scanf("%d", &n))
//	{
//		printf("%.2f%c\n", 1.0*der[n] / fun[n] * 100, '%');
//	}
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string s;
//	string str;
//	vector<string> k;
//	int sta = -1;
//	while (getline(cin, s))
//	{
//		getline(cin, str);
//		int flag = 1;
//		for (int i = 0; i < s.size(); i++)
//		{
//			int Flag = 1;
//			string ans = "";
//			if (s[i] == '"')
//			{
//				Flag = Flag*(-1); i++;
//			}
//			if (Flag == 1 && (s[i] == ' ' || s[i] == ','))
//				i++;
//			if (Flag == 1)
//			{
//				while (i<s.length() && s[i] != ' '&&s[i] != ',')
//				{
//					ans += s[i];
//					i++;
//				}
//				if (ans == str)
//					sta = 1;
//					k.push_back(ans);
//					ans = "";
//			}
//			else
//			{
//				while (i<s.length() && s[i] != '"')
//				{
//					ans += s[i];
//					i++;
//				}
//				if (s[i] == '"')
//				{
//					if (ans == str)
//						sta == 1;
//					k.push_back(ans);
//					ans = "";
//					i++;
//				}
//			}
//		}
//		if (sta == 1)
//			cout << "Ignore" << endl;
//		else
//			cout << "Important!" << endl;
//	}
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string s, res;
//	while (getline(cin, s))
//	{
//		getline(cin, res);
//		bool sta = false;
//		for (int i = 0; i < s.length(); i++)
//		{
//			string t;
//			if (s[i] == '"')
//			{
//				i++;
//				while (i<s.length() && s[i] != '"')
//				{
//					t += s[i];
//					i++;
//				}
//				if (t == res)
//				{
//					sta = true;
//					break;
//				}
//			}
//			else if (s[i] != ',')
//			{
//				while (i<s.length() && s[i] != ',')
//				{
//					t += s[i];
//					i++;
//				}
//				if (t == res)
//				{
//					sta = true;
//					break;
//				}
//			}
//		}
		//if (sta == true)
		//	cout << "Ignore" << endl;
		//else
		//	cout << "Important!" << endl;
//	}
//	return 0;
//}

