#pragma once
#include<iostream>
using namespace std;
template<typename T>
class ObjectPool
{
	struct BlockNode
	{
		void* _memory;
		BlockNode* _next;
		size_t _objNum;
		BlockNode(size_t objNum)
			:_objNum(objNum)
			, _next(NULL)
		{
			_memory = malloc(_objNum*_itemSize);
		}
		~BlockNode()
		{
			free(_memory);
			_memory = NULL;
			_next = NULL;
			_objNum = 0;
		}
	};
protected:
	size_t _countIn;	//当前节点在用的计数
	BlockNode* _first;
	BlockNode* _last;
	size_t _maxNum;
	static size_t _itemSize;	//单个对象的大小
	T* _lastDelete;	//指向最新释放的那个对象的大小
public:
	ObjectPool(size_t initNum = 32, size_t maxNum = 100000)
		:_countIn(0)
		, _maxNum(maxNum)
		, _lastDelete(NULL)
	{
		_first = _last = new BlockNode(initNum);
	}
	~ObjectPool()
	{
		Destroy()
	}
	T* new()
	{
		if (_lastDelete)
		{
			T* object = _lastDelete;
			_lastDelete = *((T**)_lastDelete);
			return new(object)T();
		}
		if (_countIn >= _last->objNum)
		{
			size_t size = 2 * _countIn;
			if (size > _maxNum)
				size = _maxNum;
			_last->next = new BlockNode(size);
			_last = _last->next;
			_countIn = 0;
		}
		T* object = (T*)((char*)_last->_memory + _countIn*_itemSize);
		_countIn++;
		return new(object) T();
	}
	void Destory()
	{
		BlockNode *cur = _first;
		while (cur)
		{
			BlockNode* del = cur;
			cur = cur->_next;
			delete del;
		}
		_first = _last = NULL;
	}
	void Delete(T* object)
	{
		if (object)
		{
			object->~T();
			*((T**)object) = _lastDelete;
			_lastDelete = object;
		}
	}
protected:
	static size_t GetItemSize()
	{
		if (sizeof(T) > sizeof(T*))
		{
			return sizeof(T);
		}
		else
		{
			return sizeof(T*);
		}
	}
};
template<typename T>
size_t ObjectPool<T>::_itemSize = ObjectPool<T>::GetItemSize();