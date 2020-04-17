#pragma once
#include<iostream>
using namespace std;

template<class T>
class ObjectPool
{
	struct BlockNode
	{
		void *_memory;
		BlockNode* _next;
		size_t _objectNum;
		BlockNode(size_t objectNum)
			:_objectNum(objectNum)
			, _next(nullptr)
		{
			_memory = malloc(objectNum*_itemSize())
		}
		~BlockNode()
		{
			free(_memory);
			_memory = nullptr;
			_next = nullptr;
			_objectNum = 0;
		}
	};
protected:
	size_t _countIn;      //当前结点的在用的计数
	BlockNode* _frist;    //指向链表的头
	BlockNode* _last;     //指向链表的尾
	size_t _maxNum;        //记录内存块最大的容量
	static size_t _itemSize;   //单个对象的大小
	T* _lastDelete;        //指向最新释放的那个对象的空间
public:
	ObjectPool(size_t initNum = 32, size_t Max_Num = 100000)//默认最开始内存块有32个对象，一个内存块最大有maxNum个对象
		:_countIn(initNum)
		, _maxNum(Max_Num)
		, _lastDelete(nullptr)
	{
		_frist = _last = new BlockNode(initNum);
	}
	~ObjectPool()
	{
		Destory();
	}

	T* New()//分配内存
	{
		if (_lastDelete)
		{
			T* Object = _lastDelete;
			_lastDelete = *((T**)_lastDelete);
			return new(Object)T();
		}
		if (_countIn >= _last->_objectNum)
		{
			size_t size = 2 * _countIn;
			if (size > _maxNum)
				size = _maxNum;
			_last->_next = BlockNode(size);
			_last = _last->_next;
			_countIn = 0;
		}
		//还有已经分配好的未被使用的内存
		T* object = (T*)（(char*)_last->_memory + _countIn*_itemSize）;
		_countIn++;
		return new(object)T();        //将这块空间用重定位new初始化一下
	}

	void Destory()
	{
		BlockNode *cur = _frist;
		while (cur)
		{
			BlockNode* del = cur;
			cur = cur->_next;
			delete del;            //会自动调用~BlockNode()
		}
		_frist = _last = NULL;
	}
	void Delete(T* object)          //释放内存
	{
		if (object)
		{
			object->~T();
			*((T**)object) = _lastDelete;      //将_lastDelete里面保存的地址存到tmp指向空间的前T*大小的空间里面
			_lastDelete = object;
		}
	}
protected:
	static size_t GetItemSize()
	{
		if (sizeof(T) > sizeof(T*))
			return sizeof(T);
		else
		{
			return sizeof(T*);
		}
	}
};
template<typename T>
size_t ObjectPool<T>::_itemSize = ObjectPool<T>::GetItemSize();