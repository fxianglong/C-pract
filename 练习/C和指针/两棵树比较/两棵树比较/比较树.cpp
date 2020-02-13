//实现两个树的比较，相等返回0否则返回其他值
#include<iostream>
#include<stdio.h>
#include<string>
#include<conio.h>
using namespace std;
typedef struct TreeNode{
	char c;
	TreeNode *leftchild;
	TreeNode *rightchild;
}tree1,tree2;
int CompTree(TreeNode *tree1, TreeNode *tree2)
{
	bool isTree1Null = (tree1 == NULL);
	bool isTree2Null = (tree2 == NULL);
	if (isTree1Null != isTree2Null)
		return 1;
	if (isTree1Null&&isTree2Null)
		return 0;
	if (tree1->c != tree2->c)
		return 1;
	return (CompTree(tree1->leftchild, tree2->leftchild))&(CompTree(tree1->rightchild, tree2->rightchild)) |
		(CompTree(tree1->leftchild, tree2->rightchild))&(CompTree(tree1->rightchild, tree2->leftchild));
}