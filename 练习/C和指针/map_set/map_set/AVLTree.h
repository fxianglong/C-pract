#include<set>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
#include<queue>
#include<forward_list>
#include <functional>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	int _bf;//Æ½ºâÒò×Ó
	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	//AVLTree()
	//	:_root(nullptr)
	//{}
	V& operator[](const K& key)
	{
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		return ret.first->_kv.second;
	}
	pair<Node*, bool> Insert(const pair<K,V>& kv)
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
			else
			{
				return make_pair(cur, false);
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
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
	Node* _root=nullptr;
};




void TestAVLTree()
{
	AVLTree<int, int> t;
	t.Insert(make_pair(1, 2));
	t.Insert(make_pair(3, 3));
	t.Insert(make_pair(4, 4));
	t.Insert(make_pair(6, 5));
	t[3];
	t[4] = 3;
	t[10] = 9;
}