#include<iostream>
using namespace std;

template<class T>
struct BSTNode
{
	BSTNode(const T& val=T())
	:_left(nullptr)
	, _right(nullptr)
	, _data(val)
	{}
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _data;
};

template<class T>
class BSTree{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	~BSTree()
	{
		_pRoot = nullptr;
	}

	////修改
	PNode Find(const T& data){
		if (_pRoot == data)
			return _pRoot;
		else if (_pRoot == nullptr)
			return nullptr;
		else
		{
			if (_pRoot->_data > data)
				Find(_pRoot->_left);
			else
			{
				Find(_pRoot->_data>_right);
			}
		}
		return nullptr;
	}


	bool Insert(const T& data)
	{
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}
		PNode cur = _pRoot;
		PNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data > data)
				cur = cur->_left;
			else if (cur->_data < data)
				cur = cur->_right;
			else
			{
				return false;
			}
		}
		//插入元素
		cur = new Node(data); 
		if (parent->_data>cur->_data)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	bool Erase(const T& data)
	{
		if (_pRoot == nullptr)
			return false;
		PNode cur = _pRoot;
		PNode parent = nullptr;
		while (cur)
		{
			if (cur->_data == data)
				break;
			else if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}

		//不在树中
		if (cur == nullptr)
			return false;

		if (!_pRoot->_right|| !_pRoot->_left) {
			_pRoot = _pRoot->_left ? _pRoot->_left : _pRoot->_right;
		}
		else {
			PNode cur = _pRoot->_right;
			while (cur->_left) {
				cur = cur->_left;
			}
			_pRoot->val = cur->val;//值替换，很巧妙
			_pRoot = _pRoot->_right;
			_pRoot->_right = deleteNode(cur->val);
		}
		return true;
	}
private:
	PNode _pRoot;
};