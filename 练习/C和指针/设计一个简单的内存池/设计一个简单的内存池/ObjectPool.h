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
	size_t _countIn;      //��ǰ�������õļ���
	BlockNode* _frist;    //ָ�������ͷ
	BlockNode* _last;     //ָ�������β
	size_t _maxNum;        //��¼�ڴ����������
	static size_t _itemSize;   //��������Ĵ�С
	T* _lastDelete;        //ָ�������ͷŵ��Ǹ�����Ŀռ�
public:
	ObjectPool(size_t initNum = 32, size_t Max_Num = 100000)//Ĭ���ʼ�ڴ����32������һ���ڴ�������maxNum������
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

	T* New()//�����ڴ�
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
		//�����Ѿ�����õ�δ��ʹ�õ��ڴ�
		T* object = (T*)��(char*)_last->_memory + _countIn*_itemSize��;
		_countIn++;
		return new(object)T();        //�����ռ����ض�λnew��ʼ��һ��
	}

	void Destory()
	{
		BlockNode *cur = _frist;
		while (cur)
		{
			BlockNode* del = cur;
			cur = cur->_next;
			delete del;            //���Զ�����~BlockNode()
		}
		_frist = _last = NULL;
	}
	void Delete(T* object)          //�ͷ��ڴ�
	{
		if (object)
		{
			object->~T();
			*((T**)object) = _lastDelete;      //��_lastDelete���汣��ĵ�ַ�浽tmpָ��ռ��ǰT*��С�Ŀռ�����
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