#include"RBTree.h"

namespace fxl
{
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;
		// 作用：将value中的key提取出来
		struct KeyOfValue
		{
			const K& operator()(const ValueType& v)
			{
				return v.first;
			}
		};
		typedef RBTree<K, ValueType, KeyOfValue> RBTree;
	public:
		typedef typename RBTree::Iterator iterator;
	public:
		map(){}

		iterator begin(){ return _t.Begin(); }
		iterator end(){ return _t.End(); }


		size_t size()const{ return _t.Size(); }
		bool empty()const{ return _t.Empty(); }

		V& operator[](const K& key)
		{
			return (*(_t.Insert(ValueType(key, V()))).first).second;
		}
		const V& operator[](const K& key)const;

		pair<iterator, bool> insert(const ValueType& data) { return _t.Insert(data); }
		void clear(){ _t.Clear(); }
		iterator find(const K& key){ return _t.Find(key); }
	private:
		RBTree _t;
	};
}