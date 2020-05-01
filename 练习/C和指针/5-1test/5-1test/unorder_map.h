// unordered_map中存储的是pair<K, V>的键值对，K为key的类型，V为value的类型，HF哈希函数类型
// unordered_map在实现时，只需将hashbucket中的接口重新封装即可
template<class K, class V, class HF = DefHashF<K>>
class unordered_map
{
	typedef pair<K, V> ValueType;
	typedef HashBucket<K, ValueType, KeyOfValue, HF> HT;
	// 通过key获取value的操作
	struct KeyOfValue
	{
		const K& operator()(const ValueType& data)
		{
			return data.first;
		}
	};
public:
	typename typedef HT::Iterator iterator;
public:
	unordered_map() : _ht()
	{}
	////////////////////////////////////////////////////
	iterator begin(){ return _ht.Begin(); }
	iterator end(){ return _ht.End(); }
	////////////////////////////////////////////////////////////
	// capacity
	size_t size()const{ return _ht.Size(); }
	bool empty()const{ return _ht.Empty(); }
	///////////////////////////////////////////////////////////
	// Acess
	V& operator[](const K& key)
	{
		return (*(_ht.InsertUnique(ValueType(key, V())).first)).second;
	}
	const V& operator[](const K& key)const;
	//////////////////////////////////////////////////////////
	// lookup
	iterator find(const K& key){ return _ht.Find(key); }
	size_t count(const K& key){ return _ht.Count(key); }
	/////////////////////////////////////////////////
	// modify
	pair<iterator, bool> insert(const ValueType& valye)
	{
		return _ht.Insert(valye);
	}

	iterator erase(iterator position)
	{
		return _ht.Erase(position);
	}
	////////////////////////////////////////////////////////////
	// bucket
	size_t bucket_count(){ return _ht.BucketCount(); }
	size_t bucket_size(const K& key){ return _ht.BucketSize(key); }
private:
	HT _ht;
};