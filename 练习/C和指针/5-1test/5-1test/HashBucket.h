#pragma once
#include<iostream>
#include<string>
#include<vector>

template<class V>
struct HashBucketNode
{
	HashBucketNode(const V& data)
	: _pNext(nullptr), _data(data)
	{}
	HashBucketNode<V>* _pNext;
	V _data;
};


template<class V>
class HashBucket
{
	typedef HashBucketNode<V> Node;
	typedef Node* PNode;
public:
	HashBucket(size_t capacity = 3) : _size(0)
	{
		_ht.resize(GetNextPrime(capacity), nullptr);
	}
	// 哈希桶中的元素不能重复
	PNode* Insert(const V& data)
	{
		// 确认是否需要扩容。。。
		// _CheckCapacity();

		// 1. 计算元素所在的桶号
		size_t bucketNo = HashFunc(data);

		// 2. 检测该元素是否在桶中
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;

			pCur = pCur->_pNext;
		}

		// 3. 插入新元素
		pCur = new Node(data);
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;
		return pCur;
	}
	// 删除哈希桶中为data的元素(data不会重复)，返回删除元素的下一个节点
	PNode* Erase(const V& data)
	{
		size_t bucketNo = HashFunc(data);
		PNode pCur = _ht[bucketNo];
		PNode pPrev = nullptr, pRet = nullptr;

		while (pCur)
		{
			if (pCur->_data == data)
			{
				if (pCur == _ht[bucketNo])
					_ht[bucketNo] = pCur->_pNext;
				else
					pPrev->_pNext = pCur->_pNext;


				pRet = pCur->_pNext;
				delete pCur;
				_size--;
				return pRet;
			}
		}

		return nullptr;
	}

	PNode* Find(const V& data);
	size_t Size()const;
	bool Empty()const;
	void Clear();
	bool BucketCount()const;
	void Swap(HashBucket<V, HF>& ht;
	~HashBucket();
	void _CheckCapacity()
	{
		size_t bucketCount = BucketCount();
		if (_size == bucketCount)
		{
			HashBucket<V, HF> newHt(bucketCount);
			for (size_t bucketIdx = 0; bucketIdx < bucketCount; ++bucketIdx)
			{
				PNode pCur = _ht[bucketIdx];
				while (pCur)
				{
					// 将该节点从原哈希表中拆出来
					_ht[bucketIdx] = pCur->_pNext;

					// 将该节点插入到新哈希表中
					size_t bucketNo = newHt.HashFunc(pCur->_data);
					pCur->_pNext = newHt._ht[bucketNo];
					newHt._ht[bucketNo] = pCur;
					pCur = _ht[bucketIdx];
				}
			}

			newHt._size = _size;
			this->Swap(newHt);
		}
	}
private:
	size_t HashFunc(const V& data)
	{
		return data%_ht.capacity();
	}
private:
	vector<PNode*> _ht;
	size_t _size;      // 哈希表中有效元素的个数
};



//// 哈希函数采用处理余数法，被模的key必须要为整形才可以处理，此处提供将key转化为整形的方法
//// 整形数据不需要转化
////template<class T>
////class DefHashF
////{
////public:
////	size_t operator()(const T& val)
////	{
////		return val;
////	}
////};
////
//// key为字符串类型，需要将其转化为整形
////class Str2Int
////{
////public:
////	size_t operator()(const string& s)
////	{
////		const char* str = s.c_str();
////		unsigned int seed = 131; // 31 131 1313 13131 131313
////		unsigned int hash = 0;
////		while (*str)
////		{
////			hash = hash * seed + (*str++);
////		}
////
////		return (hash & 0x7FFFFFFF);
////	}
////};
////
//// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
////template<class V, class HF>
////class HashBucket
////{
////	 ……
////private:
////	size_t HashFunc(const V& data)
////	{
////		return HF()(data.first) % _ht.capacity();
////	}
////};
////
////
////template<class K, class V, class KeyOfValue, class HF = DefHashF<T> >
////class HashBucket
////{
////	friend HBIterator<K, V, KeyOfValue, HF>;
////	 ......
////public:
////	typedef HBIterator<K, V, KeyOfValue, HF> Iterator;
////	////////////////////////////////////////////////////////
////	 ...
////	 迭代器
////	Iterator Begin()
////	{
////		size_t bucketNo = 0;
////		for (; bucketNo < _ht.capacity(); ++bucketNo)
////		{
////			if (_ht[bucketNo])
////				break;
////		}
////
////		if (bucketNo < _ht.capacity())
////			return Iterator(_ht[bucketNo], this);
////		else
////			return Iterator(nullptr, this);
////	}
////
////	Iterator End(){ return Iterator(nullptr, this); }
////	Iterator Find(const K& key);
////	Iterator Insert(const V& data);
////	Iterator Erase(const K& key);
////
////	 为key的元素在桶中的个数
////	size_t Count(const K& key)
////	{
////		if (Find(key) != End())
////			return 1;
////
////		return 0;
////	}
////
////	size_t BucketCount()const{ return _ht.capacity(); }
////	size_t BucketSize(size_t bucketNo)
////	{
////		size_t count = 0;
////		PNode pCur = _ht[bucketNo];
////		while (pCur)
////		{
////			count++;
////			pCur = pCur->_pNext;
////		}
////
////		return count;
////	}
////
////	 ......
////};