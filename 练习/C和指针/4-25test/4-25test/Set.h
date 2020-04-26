#include"RBTree.h"

namespace fxl
{
	template<class K>
	class set
	{
		typedef K ValueType;

		struct KeyOfValue
		{
			const K& operator()(const ValueType& key)
			{
				return key;
			}
		};

		// 红黑树类型重命名
		typedef RBTree<K, ValueType, KeyOfValue> RBTree;
	public:
		typedef typename RBTree::Iterator iterator;
	public:
		Set(){}

		iterator begin(){ return _t.Begin(); }
		iterator end(){ return _t.End(); }


		size_t size()const{ return _t.Size(); }
		bool empty()const{ return _t.Empty(); }

		pair<iterator, bool> insert(const ValueType& data)
		{
			return _t.Insert(data);
		}
		void clear(){ _t.Clear(); }
		iterator find(const K& key){ return _t.Find(key); }

	private:
		RBTree _t;
	};
}