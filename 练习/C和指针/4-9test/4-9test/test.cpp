#include<iostream>
#include<string>

#include<algorithm>
using namespace std;

//new malloc 
//申请基本内存一样
//申请自定义内存不一样。new申请内存并且调用构造函数

//int main()
//{
////	int *p = (int*)malloc(sizeof(int));
////	int *p2 = new int;
////	free(p);
////	delete p2;
////
////	int *p3 = (int*)malloc(sizeof(int)*10);
////	int *p4 = new int[10];
////	free(p3);
////	delete[] p4;
//////delete释放内存并且调用一次析构函数
//
//	char *pool = (char*)malloc(1024);
//
//	return 0;
//}
//template<typename T>
//void Swap(T& x1,T& x2){
//	T x3;
//	x3 = x1;
//	x1 = x2;
//	x2 = x3;
//}
//int main()
//{
//	int a = 2, b = 1;
//	Swap(a, b);
//	double c = 0.22, d = 2.3232;
//	Swap(c, d);
//	return 0;
//}

//
//void TestString()
//{
//	string s1;
//	string s2("hello fxl");
//	string s3(s2.begin(), s2.end());
//	string s4(s3);
//}
//int main()
//{
//	
//	return 0;
//}
//string 管理字符串数组的数据结构
//int main()
//{
//	//string s1("hello");
//	//for (size_t i = 0; i > s1.size(); i++)
//	//	cout << s1[i] << endl;
//	//string::iterator it = s1.begin();
//	//while (it != s1.end()){
//	//	cout << *it;
//	//	it++;
//	//}
//	//string::reverse_iterator rit = s1.rbegin();
//	//while (rit != s1.rend()){
//	//	cout << *rit;
//	//	rit++;
//	//}
//	string file1("string.cpp.zip.gz");
//	//size_t pos = file1.find(".");
//	//string suffix(file1, pos, file1.size() - pos);
//	//cout << suffix << endl;
//	//suffix = file1.substr(pos, file1.size() - pos);
//	//cout << suffix << endl;
//	size_t first = file1.find('.');
//	while (first != string::npos)
//	{
//		size_t second = file1.find('.', first+1);
//		if (second != string::npos){
//			cout << file1.substr(first, second - first) << endl;
//		}
//		else
//		{
//			cout << file1.substr(first, file1.size() - first) << endl;
//			break;
//		}
//		first = second;
//	} 
//	system("pause");
//	return 0;
//}



//void test_list(){
//	list<int> l;
//	l.push_back(1);
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(3);
//	//l.unique();
//	l.sort();
//	list<int>::iterator it = l.begin();
//	while (it != l.end()){
//		cout << *it << endl;
//		it++;
//	}
//	for (auto e : l){
//		cout << e << " ";
//	}
//}
//int main()
//{
//	test_list();
//	system("pause");
//	return 0;
//}

namespace fxl{
	template<class T>
	struct __list_node
	{
		__list_node(const T&val=T())
		:next(nullptr)
		,prev(nullptr)
		,_data(val){
		}
		__list_node<T>* next;
		__list_node<T>* prev;
		T _data;
	};
	template<class T>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		node* node;
		operartor*()
		{
			return node->Data;
		}
		__list_iterator<T> operator++(){
			node = node->next;
			return *this;
		}
		__list_iterator<T> operator(int){
			__list_iterator<T> tmp(*this);
			node = node->next;
			return *this;
		}
		bool operator!=(node )
	};
	template<class T>
	class list{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T> iterator;
		list()
		{
			_head = new node;
			_head->next = _head;
			_head->prev = _head;
		}
		void Push_Back(const T& x){
			node* tail = _head->prev;
			node* newnode = new node(x);

			tail->next = newnode;
			newnode->prev = tail;
			newnode->next = _head;
			_head->prev = newnode;
		}
	private:
		node* _head;

	};
}