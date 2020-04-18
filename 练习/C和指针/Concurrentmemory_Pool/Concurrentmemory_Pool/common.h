#pragma once
#include<iostream>
#include<assert.h>
#include<Windows.h>
using namespace std;

const size_t MAX_SIZE = 64 * 1024;
const size_t NFREE_LIST = MAX_SIZE / 8;
const size_t MAX_PAGES = 129;
const size_t PAGE_SHIFT = 12;//4KΪҳ��λ

inline void*& NextObj(void* obj)
{
	return *(void**)obj;
}

class FreeList{
public:
	void Push(void* obj)
	{
		//ͷ��
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
		//ͷɾ
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
		// ÿ�������ж��ٸ���
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
	//���϶���
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
	//[2,512]��֮��
	// �����С����
	// ������12%���ҵ�����Ƭ�˷�
	// [1,128] 8byte���� freelist[0,16)
	// [129,1024] 16byte���� freelist[16,72)
	// [1025,8*1024] 128byte���� freelist[72,128)
	// [8*1024+1,64*1024] 512byte���� freelist[128,240)
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
		
		npage >>= 12;//����4K
		if (npage == 0)
			npage = 1;
		
		return npage;
	}

	static size_t NumMoveSize(size_t size)//��������Ĵ�С
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
	//	int num = static_cast<int>(MAX_SIZE / size);//ǿת
	//	if (num < 2)
	//		num = 2;
	//	if (num>512)
	//		num = 512;
	//	return num;
	//}
};


//////////////span  ���  ����ҳΪ��λ���ڴ���󣬱����Ƿ���ϲ�������ڴ���Ƭ
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
	PAGE_ID _pageid;//ҳ��
	int _pagesize;///ҳ������

	void* _freelist;////�������������
	int _usecount;/////�ڴ�����ʹ�ü���

	//size_t objsize;///�����С
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