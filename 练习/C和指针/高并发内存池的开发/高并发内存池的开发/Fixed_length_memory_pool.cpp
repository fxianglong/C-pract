//#pragma once
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//template<class T, size_t N_OBJ = 20>
//class ObjectPool{
//public:
//	ObjectPool() = default;
//	ObjectPool(const ObjectPool<T>&) = delete;
//	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;
//public:
//	template<class INIT_T>
//	T* New(const INIT_T& x = INIT_T()){
//		T* Obj = nullptr;
//		if (_freelist != nullptr)
//		{
//			void* next = *((void**)_freelist);
//			Obj = (T*)_freelist;
//			_freelist = next;
//		}
//		else{
//			if (_start == _last)
//			{
//				_start = (char*)malloc(sizeof(T)*N_OBJ);
//				if (_start == nullptr)
//					throw::std::bad_alloc();
//				_last = _start + sizeof(T)*N_OBJ;
//			}
//			Obj = (T*)_start;
//			_start += sizeof(T);
//		}
//		new(Obj)T(x);
//		return Obj;
//	}
//	void Delete(T *ptr)
//	{
//		ptr->~T();
//		*(void**)ptr = _freelist;
//		_freelist = ptr;
//	}
//private:
//	char* _start = nullptr;
//	char* _last = nullptr;
//	void* _freelist = nullptr;
//};
//
//
//void TestObjectPool()
//{
//	ObjectPool<std::string> pool;
//	std::string* p1 = pool.New("1111");
//	std::string* p2 = pool.New("2222");
//
//	cout << p1 << endl;
//	cout << p2 << endl;
//
//	pool.Delete(p1);
//	pool.Delete(p2);
//
//	std::string* p3 = pool.New("3333");
//	std::string* p4 = pool.New("4444");
//	std::string* p5 = pool.New("5555");
//
//	cout << p3 << endl;
//	cout << p4 << endl;
//	cout << p5 << endl;
//}
//
//
//#include <vector>
//#include <time.h>
//
//void BenchMark()
//{
//	size_t n = 100000;
//
//	std::vector<std::string*> v1;
//	v1.reserve(n);
//	size_t begin1 = clock();
//	for (size_t i = 0; i < n; ++i)
//	{
//		v1.push_back(new std::string);
//	}
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		delete v1[i];
//	}
//
//	v1.clear();
//	for (size_t i = 0; i < n; ++i)
//	{
//		v1.push_back(new std::string);
//	}
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		delete v1[i];
//	}
//
//	size_t end1 = clock();
//
//	std::vector<std::string*> v2;
//	v2.reserve(n);
//	size_t begin2 = clock();
//	ObjectPool<std::string> pool;
//	for (size_t i = 0; i < n; ++i)
//	{
//		v2.push_back(pool.New(""));
//	}
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		pool.Delete(v2[i]);
//	}
//	v2.clear();
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		v2.push_back(pool.New(""));
//	}
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		pool.Delete(v2[i]);
//	}
//	size_t end2 = clock();
//
//	cout << end1 - begin1 << endl;
//	cout << end2 - begin2 << endl;
//}
//
//int main()
//{
//	BenchMark();
//	system("Pause");
//	return 0;
//}