#pragma once
#include<iostream>
using namespace std;
#include"AVLTree"
enum Colour
{
	BLACK,
	RED,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Colour _col;
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<pair<K, V>> Node;
public:
	RBTree()
		:_root(nullptr)
	{}

	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_data.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data.first > kv.first)
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
		cur->_col = RED;
		if (parent->_data.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//
		while (parent && parent->_col == RED)
		{
			// �ؼ�������
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// ���1
				if (uncle && uncle->_col == RED)
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					//�������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���2 + ���3	uncle�����ڻ���Ϊ��
				{
					// ��ת

					if (cur == parent->_left)
					{
						// �ҵ���
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						// ˫��	����˫��
						RotateLR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					//����ѭ��
					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle&&uncle->_col==RED)
				{
					parent->_col =uncle->_col=BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//uncle�����ڻ��ߴ�����Ϊ��ɫ
					//��ת+��ɫ			����
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//����˫��
						RotateRL(grandfather);
						grandfather->_col = RED;
						cur->_col = BLACK;
					}
					break;
				}
			}
		}

		_root->_col = BLACK;

		return make_pair(cur, true);
	}

private:
	Node* _root;
};
