#pragma once
#include<deque>
#include<iostream>
#include<vector>
using namespace std;
namespace fxl{
	template<class T,class Container=deque<T>>
	class Queue{
	public:
		void Push(const T& x) { _c.push_back(x); }

		void Pop() { _c.pop_front(); }

		T& Back() { return _c.back(); }

		const T& Back()const { return _c.back(); }

		T& Front() { return _c.front(); }

		const T& Front()const { return _c.front(); }

		size_t Size()const { return _c.size(); }

		bool Empty()const { return _c.empty(); }
	private:
		Container _c;
	};
	void test_queue()
	{
		fxl::Queue<int> q;
		q.Push(8);
		q.Push(4);
		q.Push(3);
		q.Push(2);
		while (!q.Empty())
		{
			cout << q.Front() << endl;
			q.Pop();
		}
		
	}
}