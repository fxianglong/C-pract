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

void InitTree(TreeNode** root)//�������ĳ�ʼ��
{
	assert(root);
	if (*root == NULL)
		return;
	*root = NULL;
	return;
}

//������ǰ������ݹ�汾
void PreOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->elem);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
	return;
}
//������ǰ������ǵݹ�汾
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

////��������ݹ�汾
void InOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->lchild);
	printf("%c ", root->elem);
	InOrder(root->rchild);
	return;
}
/////��������ǵݹ�ʵ��
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

////��������ݹ�汾
void PostOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%c ", root->elem);
	return;
}
////��������ǵݹ�ʵ��
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

////�������Ĵ���
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


///�������Ŀ���
TreeNode* TreeClone(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	TreeNode* new_node = _CreateTree(root->elem);
	new_node->lchild = TreeClone(root->lchild);
	new_node->rchild = TreeClone(root->rchild);
	return new_node;
}

/////������������
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

///////��������ĸ߶�
size_t TreeHeight(TreeNode* root)
{
	if (root == NULL)
		return 0;
	size_t lheight = TreeHeight(root->lchild) + 1;
	size_t rheight = TreeHeight(root->rchild) + 1;
	return rheight > lheight ? rheight : lheight;
}


/////��Ҷ�ӽ�����
size_t TreeLeafSize(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->lchild == NULL && root->rchild == NULL)
		return 1;
	return TreeLeafSize(root->lchild) + TreeLeafSize(root->rchild);
}

////��K��ڵ�ĸ���
size_t TreeKLevelSize(TreeNode* root, int K)
{
	if (root == NULL)
		return 0;
	if (K == 1)
		return 1;
	return TreeKLevelSize(root->lchild, K - 1) + TreeKLevelSize(root->rchild, K - 1);
}


////��������ľ���
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

/////��������ľ��񣨷ǵݹ飩

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

/////�ж�һ�����Ƿ�Ϊ��ȫ������
bool isCBT(TreeNode* head)//�ж���headΪͷ�ڵ�Ķ������Ƿ�Ϊ��ȫ������
{
	if (head == NULL)
		return true;
	bool leaf = false;//leaf�����������һ��״̬�Ƿ�����ֻҪ��ǰ�ڵ�����Ӻ��Һ��Ӷ�Ϊ�ջ������Ӳ�Ϊ�գ��Һ���Ϊ��ʱ�����״̬�ͷ�����ֻҪ���������״̬���Ժ���ʵ��Ľڵ���붼��Ҷ�ڵ㣩
	queue < DataType >q;//ͨ������qʵ�ֶ������Ĳ�α�����ͨ����α������ж��Ƿ�Ϊ��ȫ������
	q.push(head);//����ͷ�ڵ�
	while (!!q.empty())
	{
		DataType p = q.front();
		q.pop();
		if ((leaf && (p.left != null || p.right != null)) || (p.left == null&&p.right != null))//��Щ�ж����������еĲ���������ȫ������������������һ���ڶ���||ǰ�����������������״̬�Ѿ����������ǵ�ǰ���ʵ��Ľڵ㲻��Ҷ�ڵ㣨�����ӻ����Һ��ӣ�������������ǰ�ڵ����Һ��ӣ�û������
			return false;
		if (p.left != null)//���Ӳ�Ϊ�գ����뵽������ȥ
			q.push(p.left);
		if (p.right != null)//�Һ��Ӳ�Ϊ�գ����뵽������ȥ
			q.push(p.right);
		if ((p.left != null&&p.right == null) || (p.left == null&&p.right == null))//���if�������ж�״̬�Ƿ�Ҫ����
			leaf = true;
	}
	return true;
}