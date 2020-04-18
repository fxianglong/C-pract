#pragma once
#include<iostream>
#include<assert.h>
#include<Windows.h>
using namespace std;

const size_t MAX_SIZE = 64 * 1024;
const size_t NFREE_LIST = MAX_SIZE / 8;
const size_t MAX_PAGES = 129;
const size_t PAGE_SHIFT = 12;//4K为页移位

inline void*& NextObj(void* obj)
{
	return *(void**)obj;
}

class FreeList{
public:
	void Push(void* obj)
	{
		//头插
		NextObj(obj) = _freelist;
		_freelist = obj;
	}
	void PushRange(void* head,void* tail)
	{
		NextObj(tail) = _freelist;
		_freelist = head;
	}
	void* Pop()
	{
		//头删
		void* obj = _freelist;
		_freelist = NextObj(obj);
		return obj;
	}
	size_t PopRange(void* start, void* end,size_t num)
	{
		size_t actualNum = 0;
		void* prev = nullptr;
		void* cur = _freelist;
		for (; actualNum < num&&cur!=nullptr; ++actualNum)
		{
			prev = cur;
			cur = NextObj(cur);
		}

		start = _freelist;
		end = prev;
		_freelist = cur;
		return actualNum;
	}
	bool Empty()
	{
		return _freelist == nullptr;
	}


private:
	void* _freelist=nullptr;
};

class SizeClass{
public:
	static inline size_t _ListIndex(size_t bytes)
	{
		assert(bytes <= MAX_SIZE);
		// 每个区间有多少个链
		static int group_array[4] = { 16, 56, 56, 56 };
		if (bytes <= 128){
			return _ListIndex(bytes, 3);
		}
		else if (bytes <= 1024){
			return _ListIndex(bytes - 128, 4) + group_array[0];
		}
		else if (bytes <= 8192){
			return _ListIndex(bytes - 1024, 7) + group_array[1] + group_array[0];
		}
		else if (bytes <= 65536){
			return _ListIndex(bytes - 8192, 9) + group_array[2] + group_array[1] +
				group_array[0];
		}
		assert(false);
		return -1;
	}
	static size_t _ListIndex(size_t size, int align_shift)
	{
		return (size + (1 << align_shift) - 1) >> align_shift - 1;
	}
	//向上对其
	static size_t _RoundUp(size_t size, int alignment){
		return (size + alignment - 1)&(~(alignment - 1));
		//if (size % 8 != 0)
		//{
		//	return (size / 8 + 1) * 8;
		//}
		//else
		//{
		//	return size;
		//}
	}

	static size_t RoundUp(size_t size, int alignment){
		return (size + alignment - 1)&(~(alignment - 1));
	}
	//[2,512]个之间
	// 对齐大小计算
	// 控制在12%左右的内碎片浪费
	// [1,128] 8byte对齐 freelist[0,16)
	// [129,1024] 16byte对齐 freelist[16,72)
	// [1025,8*1024] 128byte对齐 freelist[72,128)
	// [8*1024+1,64*1024] 512byte对齐 freelist[128,240)
	static inline size_t RoundUp(size_t size)
	{
		assert(size <= MAX_SIZE);
		if (size <= 128){
			return _RoundUp(size, 8);
		}
		else if (size <= 1024){
			return _RoundUp(size, 16);
		}
		else if (size <= 8192){
			return _RoundUp(size, 128);
		}
		else if (size <= 65536){
			return _RoundUp(size, 1024);
		}
		return -1;
	}



	static size_t NumMovePage(size_t size)
	{
		size_t num = NumMoveSize(size);
		size_t npage = num*size;
		
		npage >>= 12;//除以4K
		if (npage == 0)
			npage = 1;
		
		return npage;
	}

	static size_t NumMoveSize(size_t size)//单个对象的大小
	{
		if (size == 0)
			return 0;
		int num = MAX_SIZE / size;
		if (num < 2)
			num = 2;
		if (num>512)
			num = 512;
		return num;
	}
	//static size_t NumMoveSize(size_t size){
	//	if (size == 0)
	//		return 0;
	//	int num = static_cast<int>(MAX_SIZE / size);//强转
	//	if (num < 2)
	//		num = 2;
	//	if (num>512)
	//		num = 512;
	//	return num;
	//}
};


//////////////span  跨度  管理页为单位的内存对象，本质是方便合并，解决内存碎片
#ifdef _WIN32
typedef unsigned int PAGE_ID;
#else
typedef unsigned long long PAGE_ID;
#endif////WIN32

#ifdef _X86
typedef unsigned int PAGE_ID;
#else
typedef unsigned long long PAGE_ID;
#endif////Linux

struct Span
{
	PAGE_ID _pageid;//页号
	int _pagesize;///页的数量

	void* _freelist;////对象的自由链表
	int _usecount;/////内存块对象使用计数

	//size_t objsize;///对象大小
	Span* _next;
	Span* _prev;

};

class SpanList{
public:
	SpanList()
	{
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushFront(Span* newspan)
	{
		Insert(_head->_next, newspan);
	}
	void PopFront()
	{
		Erase(_head->_next);
	}
	Span* Begin()
	{
		return _head->_next;
	}
	Span* End()
	{
		return _head;
	}
	void PushBack(Span* newspan)
	{
		Insert(_head->_prev, newspan);
	}
	void PopBack(Span* newspan)
	{
		Erase(_head->_prev);
	}

	void Insert(Span* pos, Span* newspan)
	{
		Span* prev = pos->_prev;

		prev->_next = newspan;
		newspan->_next = pos;
		pos->_prev = newspan;
		newspan = prev = prev;
	}

	void Erase(Span* pos)
	{
		assert(pos != _head);
		Span* prev = pos->_prev;
		Span* next = pos->_next;

		prev->_next = next;
		next->_prev = prev;
	}
	bool Empty(){ return _head->_next == _head; }
private:
	Span* _head;
};

inline static void* SystemAlloc(size_t num_page)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, num_page*(1 << PAGE_SHIFT),
		MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	if (ptr == nullptr)
		throw std::bad_alloc();
	return ptr;
#endif
}