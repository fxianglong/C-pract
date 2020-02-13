//#include<iostream>
//#include<stdio.h>
//#include<string>
//#include<stack>
//#include<conio.h>
//using namespace std;
//template < class T>
//struct Myqueue
//{
//public:
//	void push(T &t)
//	{
//		s1.push(t);
//	}
//	T front()
//	{
//		if (s2.empty())
//		{
//			if (s1.size() == 0)
//				throw;
//			while (!s1.empty())
//			{
//				s2.push(s1.top());
//				s1.pop();
//			}
//		}
//		return s2.top();
//	}
//	void pop()
//	{
//		if (s2.empty())
//		{
//			while (!s1.empty())
//			{
//				s2.push(s1.top());
//				s1.pop();
//			}
//		}
//		if (!s2.empty())
//			s2.pop();
//	}
//private:
//	stack<T> s1;
//	stack<T> s2;
//};
//
//int main()
//{
//	Myqueue<int> mq;
//	int i;
//	for (int i = 0; i < 10; i++)
//		mq.push(i);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d", mq.front());
//		mq.pop();
//	}
//	system("pause");
//	return 0;
//}