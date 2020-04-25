#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _val;
	AVLTreeNode<K, V>* _pLeft;
	AVLTreeNode<K, V>* _pRight;
	AVLTreeNode<K, V>* _pParent;
	int _bf;
	AVLTreeNode(const pair<K,V>& val)
		:_val(val)
		, _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree{
	typedef AVLTreeNode<K,V> Node;
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
				cur = cur->_pRight;
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
			else if (abs(Parent->_bf) == 1)
			{
				cur = Parent;
				Parent = Parent->_pParent;
			}
			else if (abs(Parent->_bf) == 2)
			{
				if (Parent->_bf == 2){
					if (cur->_bf == 1){
						RotateL(Parent);
					}
					else if (cur->_bf == -1){
						RotateRL(Parent);
					}
				}
				else if (Parent->_bf == -2){
					if (cur->_bf == -1){
						RotateR(Parent);
					}
					else if (cur->_bf == 1){
						RotateLR(Parent);
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
		Node* subL = parent->_pLeft;		//左孩子
		Node* subLR = subL->_pRight;		//左孩子的右孩子

		parent->_pLeft = subLR;
		if (subLR)
			subLR->_pParent = parent;

		subL->_pRight = parent;

		Node* ppNode = parent->_pParent;		//parent结点还有祖先结点
		parent->_pParent = subL;

		if (ppNode == nullptr){		//parent就是原树的根
			_root = subL;
			_root->_pParent = nullptr;
		}
		else{
			if (ppNode->_pLeft == parent){
				ppNode->_pLeft = subL;
			}
			else{
				ppNode->_pRight = subL;
			}

			subL->_pParent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}

	//右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_pRight;
		Node* subRL = subR->_pLeft;
		int bf = subRL->_bf;	//保存subRL的平衡因子，因为在下面两行会置 0

		RotateR(parent->_pRight);
		RotateL(parent);

		if (bf == 0){
			parent->_bf = subRL->_bf = subR->_bf = 0;
		}
		else if (bf == 1){		//在c插入的新结点
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == -1){		//在b插入的新结点
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
	}
	//左右双选
	void RotateLR(Node* parent)
	{
		RotateL(parent->_pLeft);
		RotateR(parent);
	}

	void InOrder(){
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root){
		if (root == nullptr)
			return;

		_InOrder(root->_pLeft);
		cout << root->_val.first << " ";
		_InOrder(root->_pRight);
	}


	int _Height(Node* root){
		if (root == nullptr){
			return 0;
		}

		int leftheight = _Height(root->_pLeft);
		int rightheight = _Height(root->_pRight);

		return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
	}

	bool IsBalance(){		//this指针是隐含的，所以需要封装
		return _IsBalance(_root);
	}

	bool _IsBalance(Node* root){
		if (root == nullptr)
			return true;

		int leftheight = _Height(root->_pLeft);
		int rightheight = _Height(root->_pRight);
		if (rightheight - leftheight != root->_bf){
			cout << root->_val.first << "平衡因子异常" << endl;
			return false;
		}

		return abs(leftheight - rightheight) < 2
			&& _IsBalance(root->_pLeft)
			&& _IsBalance(root->_pRight);
	}

private:
	Node* _root = nullptr;
};

void TestAVLTree(){
	AVLTree<int, int> t;
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };	//说明是搜索树
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a){
		t.Insert(make_pair(e, e));
	}

	t.InOrder();
	cout << t.IsBalance() << endl;
}