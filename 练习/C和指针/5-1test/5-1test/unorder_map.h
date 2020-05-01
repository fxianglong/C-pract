// unordered_map�д洢����pair<K, V>�ļ�ֵ�ԣ�KΪkey�����ͣ�VΪvalue�����ͣ�HF��ϣ��������
// unordered_map��ʵ��ʱ��ֻ�轫hashbucket�еĽӿ����·�װ����
template<class K, class V, class HF = DefHashF<K>>
class unordered_map
{
	typedef pair<K, V> ValueType;
	typedef HashBucket<K, ValueType, KeyOfValue, HF> HT;
	// ͨ��key��ȡvalue�Ĳ���
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