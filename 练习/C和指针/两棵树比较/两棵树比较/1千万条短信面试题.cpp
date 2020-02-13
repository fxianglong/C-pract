//有1千万条短信，有重复，以文本文件的形式保存，一行一条，有重复，请用5分钟时间，找出重复出现最多的前10条。
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<Windows.h>
using namespace std;
struct TNode
{
	BYTE *PText;
	//直接指向内存映射的内存地址
	DWORD dwCount;
	//计算器，记录此节点的相同短信数
	TNode *ChildNode[256] ;
	TNode()
	{
			//初始化成员
	}
	~TNode()
	{
		//释放资源
	}
};
void CreateChildNode(TNode*pNode, BYTE* pText, int nIndex)
{
	if (pNode->ChildNode[pText[nIndex]] == NULL)
	{
		pNode->ChildNode[pText[nIndex]] = new TNode;
	}
	if (pText[nIndex] == '\0')
	{
		pNode->ChildNode[pText[nIndex]]->dwCount++;
		pNode->ChildNode[pText[nIndex]]->PText = pText;
	}
	else
	{
		CreateNode(pNode->ChildNode[pText[nIndex]], pText, nIndex + 1);
	}
}
void CreateRootNode(const BYTE**pTexts, DWORD dwCount)
{
	TNode RootNode;
	for (DWORD dwIndex = 0; dwIndex < dwCount; dwCount++)
	{
		CreateNode(&RootNode, pTexts[dwIndex], 0);
	}
}