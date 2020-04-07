//#include<iostream>
//#include<deque>
//using namespace std;
//void PrintDeque(const std::deque<int>& d){
//	for (auto n : d){
//		cout << n << " ";
//	}
//	cout << endl;
//}
////测试deque的构造函数
//void TestDeque1(){
//	std::deque<int> d1;
//	PrintDeque(d1);
//	std::deque<int> d2(5, 10);
//	PrintDeque(d2);
//	std::deque<int> d3(d2.begin(), d2.end());
//	PrintDeque(d3);
//	int array[] = { 3, 24, 35, 46, 3, 7, 54, 32, 23, 345, 6, 7, 6554, 23 };
//	std::deque<int> d5(array, array+sizeof(array) / sizeof(array[0]));
//	PrintDeque(d5);
//	std::deque<int> d4(d5);
//	PrintDeque(d4);
//}
//
////测试deque的迭代器
//void TestDeque2(){
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	std::deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
//
//	// 利用正向迭代器打印deque中的元素
//	for (auto it = d.cbegin(); it != d.cend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//
//	auto cit = d.cbegin();
//	//*it = 100;   该条语句编译失败，it为const迭代器，其指向空间元素值不能修改
//
//
//	// 利用反向迭代器逆向打印deque中的元素
//	for (auto it = d.crbegin(); it != d.crend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//}
//
//void TestDeque3()
//{
//	// 列表方式初始化，C++11语法
//	deque<int> d1{ 3, 4, 5 };
//
//	// 在deque的尾部插入5，头部插入1，并打印
//	d1.push_back(6);
//	d1.push_front(2);
//	PrintDeque(d1);
//	cout << d1.size() << endl;
//	cout << d1.front() << endl;
//	cout << d1.back() << endl;
//
//	// 在deque的尾部构造6，头部构造0
//	// 注意：如果是内置类型元素，
//	//      emplace_back与push_back emplace_front与push_front的效率形同
//	//      如果是自定义类型元素
//	//      emplace_back/emplace_front的效率更高，这两个操作直接在尾部或者头部构造元素
//	//      push_back/push_front的效率低，该操作时先将元素构造好，然后拷贝到尾部或头部
//	d1.emplace_back(7);
//	d1.emplace_front(1);
//	PrintDeque(d1);
//
//	// 在deque的begin位置插入元素0
//	d1.insert(d1.begin(), 0);
//	PrintDeque(d1);
//
//	// 删除deque首部与尾部元素
//	d1.pop_front();
//	d1.pop_back();
//	d1.erase(d1.begin());
//	PrintDeque(d1);
//
//	// 将deque中的元素清空
//	d1.clear();
//	cout << d1.size() << endl;
//}
//int main()
//{
//	//TestDeque1();
//	//TestDeque2();
//	TestDeque3();
//	system("pause");
//	return 0;
//}
//
//// 问题：如果要对deque中的元素进行排序，以下的效率高吗？
//#include <algorithm>
//#include <deque>
//void TestDequeSort()
//{
//	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
//	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
//	PrintDeque(d);
//
//	// 利用标准库中的算法对deque中的元素进行升序排序
//	sort(d.begin(), d.end());
//	PrintDeque(d);
//}
//
///*
//上述对deque中排序操作的效率是非常低的，当对deque排序时，需要多次对deque中的元素进行整体遍历，而
//deque中的元素整体遍历时效率比较低，这是因为deque底层的空间不连续，如果要进行整体遍历，在某段空间的
//默认或首部时，必须要计算下一段或者前一段空间的位置，导致deque的效率比较底下。
//*/


//#include<iostream>
//#include<deque>
//using namespace std;
//template<class T,class Con=deque<T>>
//class Stack
//{
//public:
//	Stack(){}
//	void Push(const T& x){ _c.push_back(x); }
//	void Pop(){ _c.pop_back(); }
//	T& Top(){ return _c.back(); }
//	const T& Top()const{ return _c.back(); }
//	size_t Size()const{ return _c.size(); }
//	bool Empty()const{ return _c.empty(); }
//private:
//	Con _c;
//};
//void TestStack()
//{
//	Stack<int> s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	cout << s.Size() << endl;
//	cout << s.Top() << endl;
//	s.Pop();
//	s.Pop();
//	cout << s.Size() << endl;
//	cout << s.Top() << endl;
//	system("pause");
//}
//int main()
//{
//	TestStack();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<deque>
//using namespace std;
//template<class T, class Con = deque<T>>
//class Queue
//{
//public:
//	Queue(){}
//	void Push(const T& x){ _c.push_back(x); }
//	void Pop(){ _c.pop_front(); }
//	T& Back(){ return _c.back(); }
//	const T& Back()const{ return _c.back(); }
//	T& Front(){ return _c.front(); }
//	const T& Front()const{ return _c.front(); }
//	size_t Size()const{ return _c.size(); }
//	bool Empty()const{ return _c.empty(); }
//private:
//	Con _c;
//};
//void TestQueue()
//{
//	// 适配体现在第二个模板参数可以使用不同的容器，然后适配生成的queue效果是一样的。
//	//Queue<int, deque<int>> q;
//	//Queue<int, list<int>> q;
//
//	Queue<int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	cout << q.Size() << endl;
//	cout << q.Front() << endl;
//	cout << q.Back() << endl;
//
//	q.Pop();
//	q.Pop();
//	cout << q.Size() << endl;
//	cout << q.Front() << endl;
//	cout << q.Back() << endl;
//}
//int main()
//{
//	TestQueue();
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//
//void Test()
//{
//	char* p1 = "hello";
//	char* p2 = "hello1";
//
//	if (IsEqual(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}


template<class T>
void Copy(T dst, const T src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

int main()
{
	// 试试下面的代码
	string strarr1[3] = { "11", "22", "33" };
	string strarr2[3];
	Copy(strarr2, strarr1, 3);
	system("pause");
	return 0;
}
//int main(){
//	Test();
//	system("pause");
//	return 0;
//}