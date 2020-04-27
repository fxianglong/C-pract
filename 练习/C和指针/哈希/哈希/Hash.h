#include<iostream>
using namespace std;


enum State{ EMPTY, EXIST, DELETE };

template<class K,class V>
class HashTable{
	struct Elem
	{
		pair<K, V> _val;
		State _state;
	};
public:
	HashTable(size_t capacity = 3)
		: _ht(capacity), _size(0)
	{
		for (size_t i = 0; i < capacity; i++)
		{
			_ht[i]._state = EMPTY;
		}
	}

	bool Insert(const pair<K, V>& val){
		// ¼ì²â¹þÏ£±íµ×²ã¿Õ¼äÊÇ·ñ³ä×ã
		// _CheckCapacity();

	}

private:
	size_t HashFunc(const K& key)
	{
		return key % _ht.capacity();
	}
private:
	vector<Elem> _ht;
	size_t _size;
};
