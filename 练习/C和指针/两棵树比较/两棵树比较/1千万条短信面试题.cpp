//��1ǧ�������ţ����ظ������ı��ļ�����ʽ���棬һ��һ�������ظ�������5����ʱ�䣬�ҳ��ظ���������ǰ10����
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
	//ֱ��ָ���ڴ�ӳ����ڴ��ַ
	DWORD dwCount;
	//����������¼�˽ڵ����ͬ������
	TNode *ChildNode[256] ;
	TNode()
	{
			//��ʼ����Ա
	}
	~TNode()
	{
		//�ͷ���Դ
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