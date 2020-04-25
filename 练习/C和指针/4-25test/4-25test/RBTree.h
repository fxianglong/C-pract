#include<iostream>
using namespace std;

enum Color{
	RED,
	BLACK
};
template<class ValueType>
struct RBTreeNode
{
	RBTreeNode<ValueType>* _pLeft;
	RBTreeNode<ValueType>* _pRight;
	RBTreeNode<ValueType>* _pParent;
	ValueType _data;
	Color _color;
	RBTreeNode(const ValueType& data = ValueType(),Color color = RED)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(color)
	{}
};

template<class T,class Ptr,class Ref>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T, Ptr, Ref> Self;
	Node* _node;
	RBTreeIterator(Node* node)
		:_node(node)
	{}
	Ref operator*(){
		return _node->_data;
	}
	Ref operator->(){
		return &_node->_data;
	}
	Self& operator++()
	{
		if (_node->_pRight != nullptr)
		{
			_node = _node->_pRight;
			while (_node->_pLeft != nullptr)
			{
				_node = _node->_pLeft;
			}
		}
		else
		{
			Node* parent = _node->_pParent;
			while (parent != nullptr && _node == parent->_pRight){
				_node = parent;
				parent = _node->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self operator++(int){
		Self tmp(*this);
		++(*this);
		return tmp;
	}
	Self& operator--(){
		if (_node->_pLeft != nullptr)
		{
			_node = _node->_pLeft;
			while (_node->_pLeft != nullptr)
			{
				_node = _node->_pRight;
			}
		}
		else
		{
			Node* parent = _node->_pParent;
			while (parent != nullptr && _node == parent->_pLeft){
				_node = parent;
				parent = _node->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Self operator--(int){
		Self tmp(*this);
		--(*this);
		return tmp;
	}

	bool operator != (const Self& s) const{
		return _node != s._node;
	}

	bool operator == (const Self& s) const{
		return _node == s._node;
	}
};

template<class K, class T, class KeyOfValue>
class RBTree{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T, T*, T&> iterator;
	typedef RBTreeIterator<T, const T*, const T&> const_iterator;

	RBTree() = default;
	// 拷贝构造 + operator=
	// 析构函数

	iterator begin(){
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	iterator end(){
		return iterator(nullptr);
	}

	const_iterator begin() const{
		Node* cur = _root;
		while (cur && cur->_left){
			cur = cur->_left;
		}

		return const_iterator(cur);
	}

	const_iterator end() const{
		return const_iterator(nullptr);
	}
	
	pair<iterator, bool> Insert(const T& val){
		//插入节点
		if (_root == nullptr)
		{
			_root = new Node(val);
			_root->_color = BLACK;
			return make_pair(iterator(_root), true);
		}
		//寻找位置
		KeyOfValue kov;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kov(cur->_data) < kov(val)){
				parent = cur;
				cur = cur->_pRight;
			}
			else if (kov(cur->_data) > kov(val)){
				parent = cur;
				cur = cur->_pLeft;
			}
			else{
				return make_pair(iterator(cur), false);
			}
		}
		
		cur = new Node(val);
		Node* newnode = cur;
		cur->_color = RED;
		//插入适当位置
		if (kov(parent->_data) < kov(val)){
			parent->_pRight = cur;
			cur->_pParent = parent;
		}
		else{
			parent->_pLeft = cur;
			cur->_pParent = parent;
		}
		//变色处理
		//父节点为红色节点
		while (parent && parent->_pParent == RED){
			Node* grandfather = parent->_pParent;
			//父亲是祖父节点左孩子
			if (parent == grandfather->_pLeft){
				Node* uncle = grandfather->_pRight;
				// 1.叔叔节点存在且为红
				if (uncle && uncle->_color == RED){
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_pParent;
				}
				//叔叔节点不存在或者叔叔节点为黑
				else{
					if (cur == parent->_pRight){
						RotateL(parent);
						swap(parent, cur);
					}

					RotateR(grandfather);
					parent->_color = BLACK;
					grandfather->_color = RED;

					break;
				}
			}
			//父亲节点是祖父节点右孩子
			else{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_color == RED){
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandfather->_color = RED;

					cur = grandfather;
					parent = cur->_pParent;
				}
				else{
					if (cur == parent->_pLeft){
						RotateR(parent);
						swap(parent, cur);
					}

					RotateL(grandfather);
					parent->_color = BLACK;
					grandfather->_color = RED;
					break;
				}
			}
		}

		_root->_color = BLACK;

		return make_pair(iterator(newnode), true);
	}

	void RotateL(Node* parent){
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;

		parent->_pRight = subRL;
		if (subRL)
			subRL->_pParent = parent;

		subR->_pLeft = parent;
		Node* pNode = parent->_pParent;
		parent->_pParent = subR;

		if (parent == _root){
			_root = subR;
			_root->_pParent = nullptr;
		}
		else{
			if (pNode->_pLeft == parent)
				pNode->_pLeft = subR;
			else
				pNode->_pRight = subR;

			subR->_pParent = pNode;
		}

	}

	void RotateR(Node* parent){
		Node* subL = parent->_pLeft;
		Node* subLR = subL->_pRight;

		parent->_pLeft = subLR;
		if (subLR)
			subLR->_pParent = parent;

		subL->_pRight = parent;

		Node* pNode = parent->_pParent;
		parent->_pParent = subL;

		if (pNode == nullptr){
			_root = subL;
			_root->_pParent = nullptr;
		}
		else{
			if (pNode->_pLeft == parent){
				pNode->_pLeft = subL;
			}
			else{
				pNode->_pRight = subL;
			}

			subL->_pParent = pNode;
		}
	}



	iterator Find(const K& k){
		Node* cur = _root;
		while (cur){
			KeyOfValue kov;
			if (kov(cur->_data) < k){
				cur = cur->_pRight;
			}
			else if (kov(cur->_data) > k){
				cur = cur->_pLeft;
			}
			else{
				return iterator(cur);
			}
		}

		return end();
	}

	bool IsValidRBTree(){
		Node* pRoot = _root;
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;

		// 检测根节点是否满足情况
		if (BLACK != pRoot->_color){
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur){
			if (BLACK == pCur->_color)
				blackCount++;

			pCur = pCur->_pLeft;
		}

		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount){
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot){
			if (k != blackCount){
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色节点的个数
		if (BLACK == pRoot->_color)
			k++;

		// 检测当前节点与其双亲是否都为红色
		Node* pParent = pRoot->_pParent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color){
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}

		return _IsValidRBTree(pRoot->_pLeft, k, blackCount) &&
			_IsValidRBTree(pRoot->_pRight, k, blackCount);
	}

	void InOrder(){
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root){
		if (root == nullptr)
			return;

		_InOrder(root->_pLeft);
		cout << root->_data.first << " ";
		_InOrder(root->_pRight);
	}

private:
	Node* _root = nullptr;
};

void TestRBtree(){
	RBTree<int, int> t;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, };
 
	for (auto e : a){
		t.Insert(make_pair(e, e));
	}
 
	t.InOrder();
	cout << t.IsValidRBTree() << endl;
}