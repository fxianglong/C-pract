//#include<iostream>
//using namespace std;
//#include<vector>
//
//int main()
//{
//	int w, h;
//	cin >> w >> h; int count = 0;
//	vector<vector<int>> ans(w, vector<int>(h, 1));
//	for (int i = 0; i < w; i++)
//	{
//		for (int j = 0; j < h; j++)
//		{
//			if (ans[i][j] == 1)
//			{
//				count++;
//				if (i + 2 < w)
//				{
//					ans[i + 2][j] = 0;
//				}
//				if (j + 2 < h){
//					ans[i][j + 2] = 0;
//				}
//			}
//		}
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}



#include<iostream>
using namespace std;
#include<string>

//int StrToInt(string str)
//{
//	if (str.size() == 0)
//		return 0;
//	int flag = 1;
//	if (str[0] == '-')
//	{		
//		flag = -1;
//		str[0] = '0';
//	}
//	else if (str[0] == '+')
//		str[0] = '0';
//	int sum = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] >= '0'&&str[i] <= '9')
//		{
//			sum = sum * 10 + (str[i] - '0');
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	return sum*flag;
//}
//int main()
//{
//	string s;
//	cin >> s;
//	cout << StrToInt(s);
//	system("pause");
//	return 0;
//}



//void main()
//{
//	int a = 1, b = 0, c = -1, d = 0;
//	d = ++a || ++b&&++c;
//	cout << d << endl;
//	system("pause");
//	return;
//}


//#include<algorithm>
//#include<vector>
//#include<iostream>
//using namespace std;
//int main()
//{
//	int N;
//	cin >> N;
//	vector<int> ans(3,0);
//	ans[0] = 0;
//	ans[1] = 1;
//	int res = 0;
//	while (ans[0] < N)
//	{
//		ans[2] = ans[0] + ans[1];
//		if (ans[2] >= N&&ans[1] <= N)
//		{
//			res = min(ans[2] - N, N - ans[1]);
//			break;
//		}
//		ans[0] = ans[1];
//		ans[1] = ans[2];
//	}
//	cout << res<<endl;
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//#include<stack>
//using namespace std;
//bool IsKuohao(string A, int n)
//{
//	stack<char> sc;
//	for (auto ele : A) {
//		switch (ele) {
//		case '(':
//			sc.push(ele);
//			break;
//		case ')':
//		{
//			if (sc.empty() || sc.top() != '(')
//				return false;
//			else
//				sc.pop();
//		} break;
//		default:
//			return false;
//		}
//	} 
//	return true;
//}
//int main()
//{
//	string str;
//	cin >> str;
//	IsKuohao(str, str.size());
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int N;
//	cin >> N;
//	vector<string> ans;
//	ans.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> ans[i];
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (ans[i - 1]<ans[i] && ans[i].size()>ans[i - 1].size());
//		else
//		{
//			cout << "both" << endl;
//		}
//	}
//	cout << "none" << endl;
//	system("pause");
//	return 0;
//}


////	求最小公倍数
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int Gbs(int a, int b)
//{
//	int r;
//	while (r = a%b){
//		a = b;
//		b = r;
//	} 
//	return b;
//}
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	int maxGbs = 0;
//	maxGbs=Gbs(n, m);
//	cout << (m*n / maxGbs) << endl;
//	system("pause");
//	return 0;
//}


//// cpp_premain.cpp : Defines the entry point for the console application.
////
//
//#include <iostream>
//using namespace std;
//using std::cout;
//
//int func()
//{
//	cout << "func() called before main()" << endl;
//	return 100;
//}
//class A
//{
//public:
//	A()
//	{
//		cout << "A() constructor called" << endl;
//	}
//	~A()
//	{
//		cout << "~A() destructor called" << endl;
//	}
//};
//
//A a;
//
//int g_iValue = func();
//
//
//int main(int argc, char* argv[])
//{
//	cout << "main() called" << endl;
//	system("pause");
//	return 0;
//}



//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 21;
//	int b = 21;
//	a ^= (1 << 5) - 1;
//	b ^= (1 << 5);
//	b -= 1;
//
//	cout << a <<" "<<b<<" "<<(21^31)<< endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Test{
//public:
//	int a;
//	int b;
//	virtual void fun() {}
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	} 
//	int getA()
//	{
//		return a;
//	} 
//	int getB()
//	{
//		return b;
//	}
//};
//int main()
//{
//	Test obj(5, 10);
//	// Changing a and b
//	int* pInt = (int*)&obj;
//	auto n = *(pInt + 0) = 100;
//	auto m = *(pInt + 1) = 200;
//	cout << "a = " << obj.getA() << endl;
//	cout << "b = " << obj.getB() << endl;
//
//	system("pause");
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	vector<vector<int>> ans(m+1, vector<int>(n+1, 1));
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
//		}
//	}
//	cout << ans[m][n] << endl;
//	system("pause");
//	return 0;
//}


#include<iostream>
using namespace std;
//struct A{
//	void foo(){ printf("foo"); }
//	virtual void bar(){ printf("bar"); }
//	A(){ bar(); }
//};
//struct B :A{
//	void foo(){ printf("b_foo"); }
//	void bar(){ printf("b_bar"); }
//};
//int main()
//{
//	A *p = new B;
//	p->foo();
//	p->bar();
//	system("pause");
//	return 0;
//}


//class Printer{
//public:
//	Printer(std::string name) { std::cout << name; }
//};
//class Container{
//public:
//	Container() : b("b"), a("a") {}
//	Printer a;
//	Printer b;
//};
//int main(){
//	Container c;
//	system("pause");
//	return 0;
//}


class A
{
public :
	virtual void func(int val = 1)
	{
		std::cout << "A->" << val << std::endl;
	}
	virtual void test()
	{
		func();
	}
};
class B : public A
{
	public :
	void func(int val = 0)
	{
		std::cout << "B->" << val << std::endl;
	}
};
int main(int argc, char* argv[])
{
	B*p = new B;
	p->test();
	return 0;
}