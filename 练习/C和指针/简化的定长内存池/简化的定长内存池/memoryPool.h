#pragma once
#include<iostream>
using namespace std;

template<class T,size_t N_MP=20>
class MemoryPool{
public:
	MemoryPool() = default;
	MemoryPool(const MemoryPool<T>&) = delete;
	MemoryPool<T>& operator=(const MemoryPool<T>&) = delete;

	template<class INIT_T>
	T* New(const INIT_T& x=INIT_T())
	{
		T* obj = nullptr;
		if (_freelist != nullptr)
		{
			void* next = *((void**)_freelist);
			obj = (T*)_freelist;
			_freelist = next;
		}
		else
		{
			if (_start == _last)
			{
				_start = (char*)malloc(sizeof(T)* N_MP);
				if (_start == nullptr)
				{
					throw std::bad_alloc();
				}
				_last = _start + sizeof(T)* N_MP;
			}

			obj = (T*)_start;
			_start += sizeof(T);
		}
		new(obj)T(x);
		return obj;
	}
	void Delete(T* ptr)
	{
		ptr->~T();
		*(void**)ptr = _freelist;
		_freelist = ptr;
	}
private:
	char* _start = nullptr;
	char* _last = nullptr;
	void* _freelist = nullptr;
};