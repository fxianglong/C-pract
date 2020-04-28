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
//	// ��Ҫע���������Ӧ����sparray.operator->()->_year = 2018;
//	// ����Ӧ����sparray->->_year�����﷨��Ϊ�˿ɶ��ԣ�ʡ����һ��->
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
//	// һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ��
//	// �����ͽ����һ��ռ䱻�������ʹ�ö���ɳ���������
//	AutoPtr(AutoPtr<T>& ap)
//		: _ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// ����Ƿ�Ϊ�Լ����Լ���ֵ
//		if (this != &ap)
//		{
//			// �ͷŵ�ǰ��������Դ
//			if (_ptr)
//				delete _ptr;
//
//			// ת��ap����Դ����ǰ������
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
//	// �����ٴ�ʵ��ԭ����������ᷢ�֣����������ap�����ָ�븳���ˣ�����ap��������
//	// ͨ��ap���������Դʱ�ͻ�������⡣
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
//	// C++98�������ķ�ʽ��ֻ������ʵ��+������˽��
//	UniquePtr(UniquePtr<T> const &);
//	UniquePtr & operator=(UniquePtr<T> const &);
//
//	// C++11�������ķ�ʽ��delete
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

		// ���ü�����1���������0�����ͷ���Դ
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
	int* _pRefCount; // ���ü���
	T*   _ptr;       // ָ�������Դ��ָ��   
	mutex* _pMutex;      // ������
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
//		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
//		SharedPtr<Date> copy(sp);
//
//		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ��������տ����Ľ������һ���Ǽ���2n
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
	// ע���������ʹ�����ã��������ľͲ���һ������������
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
array ��һ������vector�������������Ǳ�����ջ���ģ�������ܸ��ã����ܹ���ʽת��Ϊָ��
����ʱ�����̶���С���飬ֻ��Ҫָ�����ͺʹ�С����

*/
void Tarray()
{
	array<int, 5>  arr={ 1, 2, 3, 4, 5 };//���ȱ����ǳ������߳������ʽ
	int * parr = &arr[0];
	parr = arr.data();
	parr = nullptr;//ת��Ϊָ��Ĳ���
	//forward_list<int> flist;
	//������list˫������ĵ��������ռ������ʺ����ʶ�����
	/*
	������������������
	unordered_map
	unordered_multimap
	unordered_set
	unordered_multiset
	��ͬ��set��map�ڲ�ͨ�������ʵ�֣�����hash��ʵ��
	*/
}
void Ttuple()
{
	//����һ���������ɲ�ͬ���͵Ľṹ��
	tuple<int, double, string> tps(12, 17.58, "pixel");
	auto tp = make_tuple(5, 12.125, "hello");//����Ԫ�飬�����ƶ�Ϊtuple<int,double,string>
	cout << get<2>(tp) << endl;//��ȡԪ�أ��޷�ʹ�ñ����±�
	int id;
	double bim;
	string item;
	tie(id, bim, item) = tp;//Ԫ����
	cout << id << " " << bim << " " << item << endl;
	auto ntp = tuple_cat(tps, tp);//Ԫ�������
	/*
	pair��һ��������Ա�Ľṹ��
	*/
	auto p1 = make_pair(12, 'c');
	pair<double, int> p2(12.125, 17);
	cout << p2.first << " " << p2.second << endl;
	p2 = make_pair(1, 1.2);
	p2 = p1;//һ�����г�Ա�����Ľṹ��
	//pair����ʹ��typedef���м�����
}
int main()
{
	Tarray();
	Ttuple();
	system("pause");
	return 0;
}

