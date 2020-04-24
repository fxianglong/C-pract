#include<iostream>
#include<map>
#include<set>
using namespace std;

namespace fxl
{
	template<class K,class V>
	struct BSTreeNode
	{
		pair<K, V> _kv;
		BSTreeNode<K, V>* _pLeft;
		BSTreeNode<K, V>*_pRight;

		BSTreeNode(const pair<K,V>& kv)
			:_kv(kv)
			, _pLeft(nullptr)
			, _pRight(nullptr)
		{}
	};
	template<class K,class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		BSTree()
			:_root(nullptr)
		{}
		//二叉搜索树的插入
		bool Insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_pLeft;
				}
				else if (cur->_kv.first<kv.first)
				{
					parent = cur;
					cur = cur->_pRight;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(kv);
			if (parent->_kv.first > cur->_kv.first)
				parent->_pLeft=cur;
			else
			{
				parent->_pRight=cur;
			}
			return true;
		}
		//二叉排序树的查找
		Node* Find(const K& Key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first < Key){
					cur = cur->_pRight;
				}
				else if (cur->_kv.first>Key)
				{
					cur = cur->_pLeft;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		bool Remove(const K& Key)
		{
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_kv.first < Key)
				{
					parent = cur;
					cur = cur->_pRight;
				}
				else if (cur->_kv.first>Key)
				{
					parent = cur;
					cur = cur->_pLeft;
				}
				else
				{
					//1.只有0-1个孩子
					//2.有2个孩子
					Node* del = cur;
					if (cur->_pLeft == nullptr){
						if (parent == nullptr)
							_root = cur->_pRight;
						else
						{
							if (cur == parent->_pLeft)
								parent->_pLeft = cur->_pRight;
							else
							{
								parent->_pRight = cur->_pRight;
							}
						}
					}
					else if (cur->_pRight == nullptr)
					{
						if (parent == nullptr)
							_root = cur->_pLeft;
						else
						{
							if (cur == parent->_pLeft)
								parent->_pLeft = cur->_pLeft;
							else
							{
								parent->_pRight = cur->_pRight;
							}
						}
					}
					else{
						Node* rpParent = cur;
						Node* replace = cur->_pRight;
						while (replace->_pLeft){
							rpParent = replace;
							replace = replace->_pLeft;
						}

						cur->_kv = replace->_kv;
						del = replace;
						if (rpParent->_pLeft == replace){
							rpParent->_pLeft = replace->_pRight;
						}
						else{
							rpParent->_pRight = replace->_pRight;
						}
					}
					delete del;
					return true;
				}
			}
			return false;
		}
		void InOrder(){
			_InOrder(_root);
			cout << endl;
		}

		void _InOrder(Node* root){
			if (root == nullptr)
				return;

			_InOrder(root->_pLeft);
			cout << root->_kv.first << " " << root->_kv.second << endl;;
			_InOrder(root->_pRight);
		}
	private:
		Node* _root;
	};
}
void BSTreeTest()
{
	fxl::BSTree<int, int> tree;
	tree.Insert(make_pair(1, 1));
	tree.Insert(make_pair(3, 1));
	tree.Insert(make_pair(4, 1));
	tree.Insert(make_pair(6, 1));
	tree.Insert(make_pair(1, 1));
	tree.Insert(make_pair(2, 1));
	tree.InOrder();

	tree.Remove(1);
	tree.Remove(3);
	tree.Remove(2);
	tree.Remove(6);
	tree.Remove(4);
	tree.Remove(1);
	tree.Remove(10);
	tree.InOrder();
}