#include<iostream>
#include<malloc.h>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;

//template<class T>
//class SmartPtr {
//public:
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private:
//	T* _ptr;
//};
//
//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	SmartPtr<int> sp1(new int);
//	*sp1 = 10;
//	cout << *sp1 << endl;
//
//	SmartPtr<Date> sparray(new Date);
//	// 需要注意的是这里应该是sparray.operator->()->_year = 2018;
//	// 本来应该是sparray->->_year这里语法上为了可读性，省略了一个->
//	sparray->_year = 2018;
//	sparray->_month = 1;
//	sparray->_day = 1;
//	return 0;
//}


//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr = NULL)
//		: _ptr(ptr)
//	{}
//
//	~AutoPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	// 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系，
//	// 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
//	AutoPtr(AutoPtr<T>& ap)
//		: _ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// 检测是否为自己给自己赋值
//		if (this != &ap)
//		{
//			// 释放当前对象中资源
//			if (_ptr)
//				delete _ptr;
//
//			// 转移ap中资源到当前对象中
//			_ptr = ap._ptr;
//
//			ap._ptr = NULL;
//		}
//
//		return *this;
//	}
//
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private:
//	T* _ptr;
//};
//
//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	AutoPtr<Date> ap(new Date);
//
//	// 现在再从实现原理层来分析会发现，这里拷贝后把ap对象的指针赋空了，导致ap对象悬空
//	// 通过ap对象访问资源时就会出现问题。
//	AutoPtr<Date> copy(ap);
//	ap->_year = 2018;
//
//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T * ptr = nullptr)
//		: _ptr(ptr)
//	{}
//
//	~UniquePtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//
//private:
//	// C++98防拷贝的方式：只声明不实现+声明成私有
//	UniquePtr(UniquePtr<T> const &);
//	UniquePtr & operator=(UniquePtr<T> const &);
//
//	// C++11防拷贝的方式：delete
//	UniquePtr(UniquePtr<T> const &) = delete;
//	UniquePtr & operator=(UniquePtr<T> const &) = delete;
//
//private:
//	T * _ptr;
//};


#include<thread>
#include<mutex>
template<class T>
class SharedPtr{
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pRefCount(new int(0))
		, _pMutex(new mutex)
	{}
	~SharedPtr(){ Release(); }
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			Release();
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;
			AddRefCount();
		}
		return *this;
	}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }

	int UseCount() { return *_pRefCount; }
	T* Get() { return _ptr; }

	void AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;

		// 引用计数减1，如果减到0，则释放资源
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();
		if (deleteflag == true)
			delete _pMutex;
	}
private:
	int* _pRefCount; // 引用计数
	T*   _ptr;       // 指向管理资源的指针   
	mutex* _pMutex;      // 互斥锁
};


//int main()
//{
//	SharedPtr<int> sp1(new int(10));
//	SharedPtr<int> sp2(sp1);
//	*sp2 = 20;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//
//	SharedPtr<int> sp3(new int(10));
//	sp1 = sp3;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	cout << sp3.UseCount() << endl;
//
//	sp2 = sp1;
//	cout << sp1.UseCount() << endl;
//	cout << sp2.UseCount() << endl;
//	cout << sp3.UseCount() << endl;
//	system("pause");
//	return 0;
//}


//void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
//{
//	cout << sp.Get() << endl;
//	for (size_t i = 0; i < n; ++i)
//	{
//		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
//		SharedPtr<Date> copy(sp);
//
//		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最终看到的结果，并一定是加了2n
//		copy->_year++;
//		copy->_month++;
//		copy->_day++;
//	}
//}
//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	SharedPtr<Date> p(new Date);
//	cout << p.Get() << endl;
//	const size_t n = 100;
//	thread t1(SharePtrFunc, p, n);
//	thread t2(SharePtrFunc, p, n);
//
//	t1.join();
//	t2.join();
//
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//
//	return 0;
//}

#include <memory>

//struct ListNode
//{
//
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//
//	~ListNode(){ cout << "~ListNode()" << endl; }
//};
//
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	node1->_next = node2;
//	node2->_prev = node1;
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	system("pause");
//	return 0;
//}


template<class Mutex>
class LockGuard
{
public:
	LockGuard(Mutex& mtx)
		:_mutex(mtx)
	{
		_mutex.lock();
	}

	~LockGuard()
	{
		_mutex.unlock();
	}

	LockGuard(const LockGuard<Mutex>&) = delete;

private:
	// 注意这里必须使用引用，否则锁的就不是一个互斥量对象
	Mutex& _mutex;
};

mutex mtx;
static int n = 0;
void Func()
{
	for (size_t i = 0; i < 1000000; ++i)
	{
		LockGuard<mutex> lock(mtx);
		++n;
	}
}
//
//int main()
//{
//	int begin = clock();
//	thread  t1(Func);
//	thread  t2(Func);
//
//	t1.join();
//	t2.join();
//
//	int end = clock();
//
//	cout << n << endl;
//	cout << "cost time:" << end - begin << endl;
//	system("pause");
//	return 0;
//}


#include<array>
#include<tuple>

/*
array 是一个类似vector的容器，但是是保存在栈区的，因此性能更好，不能够隐式转换为指针
编译时创建固定大小数组，只需要指定类型和大小即可

*/
void Tarray()
{
	array<int, 5>  arr={ 1, 2, 3, 4, 5 };//长度必须是常量或者常量表达式
	int * parr = &arr[0];
	parr = arr.data();
	parr = nullptr;//转换为指针的操作
	//forward_list<int> flist;
	//区别于list双向链表的单向链表，空间利用率和速率都更高
	/*
	新增两组无序容器：
	unordered_map
	unordered_multimap
	unordered_set
	unordered_multiset
	不同于set和map内部通过红黑树实现，而是hash表实现
	*/
}
void Ttuple()
{
	//就像一个可以容纳不同类型的结构体
	tuple<int, double, string> tps(12, 17.58, "pixel");
	auto tp = make_tuple(5, 12.125, "hello");//构造元组，类型推断为tuple<int,double,string>
	cout << get<2>(tp) << endl;//获取元素，无法使用变量下标
	int id;
	double bim;
	string item;
	tie(id, bim, item) = tp;//元组拆包
	cout << id << " " << bim << " " << item << endl;
	auto ntp = tuple_cat(tps, tp);//元组的连接
	/*
	pair，一个两个成员的结构体
	*/
	auto p1 = make_pair(12, 'c');
	pair<double, int> p2(12.125, 17);
	cout << p2.first << " " << p2.second << endl;
	p2 = make_pair(1, 1.2);
	p2 = p1;//一个含有成员函数的结构体
	//pair可以使用typedef进行简化声明
}
int main()
{
	Tarray();
	Ttuple();
	system("pause");
	return 0;
}

