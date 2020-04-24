#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	pair<K,V> _val;
	AVLTreeNode<K, V>* _pLeft;
	AVLTreeNode<K, V>* _pRight;
	AVLTreeNode<K, V>* _pParent;
	int _bf;
	AVLTree(const T& val)
		:_val(val)
		, _Left(nullptr)
		, _Right(nullptr)
		, _pParent(nullptr)
		, _bf(0)
	{}
};

template<class K,class V>
class AVLTree{
	typedef AVLTreeNode Node;
public:
	bool Insert(const pair<K, V> kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}
		Node* Parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_val.first > kv.first)
			{
				Parent = cur;
				cur = cur->_pLeft;
			}
			else if (cur->_val.first < kv.first)
			{
				Parent = cur;
				cur=cur->_pRight
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (Parent->_val > cur->_val)
		{
			Parent->_pLeft = cur;
			cur->_pParent = Parent;
		}
		else
		{
			Parent->_pRight = cur;
			cur->_pParent = Parent;
		}
		while (Parent)
		{
			if (cur == Parent->_pLeft)
				Parent->_bf--;
			else
			{
				Parent->_bf++;
			}
			if (Parent->_bf == 0)
				break;
			else if (abs(Parent->_bf)==1)
			{
				cur = Parent;
				Parent = Parent->_pParent;
			}
			else if (abs(Parent->_bf) == 2)
			{
				if (parent->_bf == 2){
					if (cur->_bf == 1){
						RotateL(parent);
					}
					else if (cur->_bf == -1){
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2){
					if (cur->_bf == -1){
						RotateR(parent);
					}
					else if (cur->_bf == 1){
						RotateLR(parent);
					}
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;
		parent->_pRight = subRL;
		if (subRL)
			subRL->_pParent = parent;

		subR->_pLeft = parent;
		Node* ppNode = parent->_pParent;
		parent->_pParent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_pParent = nullptr;
		}
		else
		{
			if (ppNode->_pLeft == subR)
				ppNode->_pLeft = subR;
			else
			{
				ppNode->_pRight = subR;
			}
			subR->_pParent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
	}

	//右单选
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;		//左孩子
		Node* subLR = subL->_right;		//左孩子的右孩子

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* ppNode = parent->_parent;		//parent结点还有祖先结点
		parent->_parent = subL;

		if (ppNode == nullptr){		//parent就是原树的根
			_root = subL;
			_root->_parent = nullptr;
		}
		else{
			if (ppNode->_left == parent){
				ppNode->_left = subL;
			}
			else{
				ppNode->_right = subL;
			}

			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}
private:
	Node* _root = nullptr;
};