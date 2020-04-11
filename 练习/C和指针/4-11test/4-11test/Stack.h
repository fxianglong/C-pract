#pragma once
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
namespace fxl{
	template<class T, class Con = deque<T>>
	class Stack{
	public:
		Stack() {}
		void Push(const T& val){
			_con.push_back(x);
		}
		void Pop(){
			_con.pop_back();
		}
		T& Top() { return _c.back(); }
		const T& Top()const { return _c.back(); }
		bool Empty(){
			return _con.empty();
		}
		size_t Size(){
			return _con.size();
		}
	private:
		Con _con;
	};
}
