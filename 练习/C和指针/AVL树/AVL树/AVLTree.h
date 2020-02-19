#include<iostream>
#include<vector>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	int _bf;//平衡因子
	AVLTree(const pair<K, V> &kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{

	}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTree<K, V> Node;
public:
	V& operator[](const K&key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second;
	}
	
	pair<Node*,bool> Insert(const pair<K,V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root, true);
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first>kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else return make_pair(cur, false);
		}
		cur = new Node(kv);
		if (parent->kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		return make_pair(cur, true);
	}

private:
	Node* _root = nullptr;//缺省值
};
void TestAVLTree()
{
	AVLTree<int, int> t;
	t.Insert(make_pair(1, 1));
}