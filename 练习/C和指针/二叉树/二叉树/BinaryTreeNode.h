#include<stdio.h>
#include<assert.h>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

typedef char DataType;
typedef struct TreeNode
{
	DataType elem;
	struct TreeNode* rchild;
	struct TreeNode* lchild;
}TreeNode;

void InitTree(TreeNode** root)//二叉树的初始化
{
	assert(root);
	if (*root == NULL)
		return;
	*root = NULL;
	return;
}

//二叉树前序遍历递归版本
void PreOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->elem);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
	return;
}
//二叉树前序遍历非递归版本
vector<int> preorderTraversal(TreeNode* root) {
	stack<TreeNode*> _stk;
	vector<int> ans;
	TreeNode* temp = root;
	while (temp != NULL || !_stk.empty()){
		while (temp != NULL){
			ans.push_back(temp->elem);
			_stk.push(temp);
			temp = temp->lchild;
		}
		temp = _stk.top();
		_stk.pop();
		temp = temp->rchild;
	}
	return ans;
}

////中序遍历递归版本
void InOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->lchild);
	printf("%c ", root->elem);
	InOrder(root->rchild);
	return;
}
/////中序遍历非递归实现
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	stack<TreeNode*> s;
	while (root || s.size() > 0){
		while (root){
			s.push(root);
			root = root->lchild;
		}
		root = s.top();
		s.pop();
		res.push_back(root->elem);
		root = root->rchild;
	}
	return res;
}

////后序遍历递归版本
void PostOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%c ", root->elem);
	return;
}
////后序遍历非递归实现
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;
	stack<TreeNode*> stk;
	TreeNode* cur = root;
	TreeNode* rightchild = NULL;
	while (cur || !stk.empty()){
		while (cur != NULL){
			stk.push(cur);
			cur = cur->lchild;
		}
		cur = stk.top();
		if (!cur->rchild || rightchild == cur->rchild){
			ans.push_back(cur->elem);
			stk.pop();
			rightchild = cur;
			cur = NULL;
		}
		else{
			rightchild = NULL;
			cur = cur->rchild;
		}
	}
	return ans;
}

////二叉树的创建
TreeNode* _CreateTree(DataType array[], size_t size, DataType null_node, size_t* index)
{
	assert(index);
	if (*index >= size)
		return NULL;
	if (array[*index] == null_node)
	{
		++*index;
		return NULL;
	}
	TreeNode* new_node = _CreateTree(array[(*index)++]);
	new_node->lchild = _CreateTree(array, size, null_node, index);
	new_node->rchild = _CreateTree(array, size, null_node, index);
	return new_node;
}
TreeNode* CreateTree(DataType array[], size_t size, DataType null_node)
{
	assert(array);
	size_t index = 0;
	return _CreateTree(array, size, null_node, &index);
}


///二叉树的拷贝
TreeNode* TreeClone(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	TreeNode* new_node = _CreateTree(root->elem);
	new_node->lchild = TreeClone(root->lchild);
	new_node->rchild = TreeClone(root->rchild);
	return new_node;
}

/////二叉树的销毁
void DestroyNode(TreeNode* node)
{
	free(node);
	return;
}
void TreeDestroy(TreeNode** root)
{
	assert(root);
	if (*root == NULL)
		return;
	TreeDestroy(&((*root)->lchild));
	TreeDestroy(&((*root)->rchild));
	DestroyNode(*root);
	*root = NULL;
	return;
}

///////求二叉树的高度
size_t TreeHeight(TreeNode* root)
{
	if (root == NULL)
		return 0;
	size_t lheight = TreeHeight(root->lchild) + 1;
	size_t rheight = TreeHeight(root->rchild) + 1;
	return rheight > lheight ? rheight : lheight;
}


/////求叶子结点个数
size_t TreeLeafSize(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->lchild == NULL && root->rchild == NULL)
		return 1;
	return TreeLeafSize(root->lchild) + TreeLeafSize(root->rchild);
}

////求K层节点的个数
size_t TreeKLevelSize(TreeNode* root, int K)
{
	if (root == NULL)
		return 0;
	if (K == 1)
		return 1;
	return TreeKLevelSize(root->lchild, K - 1) + TreeKLevelSize(root->rchild, K - 1);
}


////求二叉树的镜像
void TreeMirror(TreeNode* root)
{
	if (root == NULL)
		return;
	TreeNode* tmp = root->lchild;
	root->lchild = root->rchild;
	root->rchild = tmp;
	TreeMirror(root->lchild);
	TreeMirror(root->rchild);
	return;
}

/////求二叉树的镜像（非递归）

void TreeMirrorByLoop(TreeNode* root)
{
	if (root == NULL)
		return;
	SeqQueue q;
	InitSeqQueue(&q);
	PushSeqQueue(&q, root);
	TreeNode* tmp;
	while (SizeSeqQueue(&q) > 0)
	{
		FrontSeqQueue(&q, &tmp);
		TreeNode* tp = tmp->lchild;
		tmp->lchild = tmp->rchild;
		tmp->rchild = tp;
		if (tmp->lchild != NULL)
			PushSeqQueue(&q, tmp->lchild);
		if (tmp->rchild != NULL)
			PushSeqQueue(&q, tmp->rchild);
		PopSeqQueue(&q);
	}
	return;
}

/////判断一个数是否为完全二叉树
bool isCBT(TreeNode* head)//判断以head为头节点的二叉树是否为完全二叉树
{
	if (head == NULL)
		return true;
	bool leaf = false;//leaf变量用来标记一个状态是否发生（只要当前节点的左孩子和右孩子都为空或者左孩子不为空，右孩子为空时，这个状态就发生，只要发生了这个状态，以后访问到的节点必须都是叶节点）
	queue < DataType >q;//通过队列q实现二叉树的层次遍历，通过层次遍历来判断是否为完全二叉树
	q.push(head);//加入头节点
	while (!!q.empty())
	{
		DataType p = q.front();
		q.pop();
		if ((leaf && (p.left != null || p.right != null)) || (p.left == null&&p.right != null))//这些判断条件是所有的不满足是完全二叉树的条件。条件一（第二个||前面的条件）：上述的状态已经发生，但是当前访问到的节点不是叶节点（有左孩子或者右孩子）。条件二：当前节点有右孩子，没有左孩子
			return false;
		if (p.left != null)//左孩子不为空，加入到队列中去
			q.push(p.left);
		if (p.right != null)//右孩子不为空，加入到队列中去
			q.push(p.right);
		if ((p.left != null&&p.right == null) || (p.left == null&&p.right == null))//这个if语句就是判断状态是否要发生
			leaf = true;
	}
	return true;
}