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
	// ��ϣͰ�е�Ԫ�ز����ظ�
	PNode* Insert(const V& data)
	{
		// ȷ���Ƿ���Ҫ���ݡ�����
		// _CheckCapacity();

		// 1. ����Ԫ�����ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		// 2. ����Ԫ���Ƿ���Ͱ��
		PNode pCur = _ht[bucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;

			pCur = pCur->_pNext;
		}

		// 3. ������Ԫ��
		pCur = new Node(data);
		pCur->_pNext = _ht[bucketNo];
		_ht[bucketNo] = pCur;
		_size++;
		return pCur;
	}
	// ɾ����ϣͰ��Ϊdata��Ԫ��(data�����ظ�)������ɾ��Ԫ�ص���һ���ڵ�
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
					// ���ýڵ��ԭ��ϣ���в����
					_ht[bucketIdx] = pCur->_pNext;

					// ���ýڵ���뵽�¹�ϣ����
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
	size_t _size;      // ��ϣ������ЧԪ�صĸ���
};



//// ��ϣ�������ô�������������ģ��key����ҪΪ���βſ��Դ����˴��ṩ��keyת��Ϊ���εķ���
//// �������ݲ���Ҫת��
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
//// keyΪ�ַ������ͣ���Ҫ����ת��Ϊ����
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
//// Ϊ��ʵ�ּ򵥣��˹�ϣ�������ǽ��Ƚ�ֱ����Ԫ�ذ���һ��
////template<class V, class HF>
////class HashBucket
////{
////	 ����
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
////	 ������
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
////	 Ϊkey��Ԫ����Ͱ�еĸ���
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