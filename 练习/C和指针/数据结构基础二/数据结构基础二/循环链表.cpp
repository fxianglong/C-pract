#include<iostream>
#include<stdlib.h>
#include<stdio.h>
typedef struct Lnode{
	int data;
	struct Lnode *link;
}Lnode,*LinkList;
void JOSEPHUS(int n, int k, int m)
{
	LinkList p, r, list, curr;
	//建立循环列表
	p = (LinkList)malloc(sizeof(Lnode));
	p->data = 0;
	p->link = p;
	curr = p;
	for (int i = 0; i < n; i++)
	{
		LinkList t = (LinkList)malloc(sizeof(Lnode));
		t->data = i;
		t->link = curr->link;
		curr->link = t;
		curr = t;
	}
	r = curr;
	while (k--)
	{
		r = p; p = p->link;
	}
	while (n--)
	{
		for (int s = m - 1; s--; r = p, p = p->link);
		r->link = p->link;
		printf("%d->", p->data);
		free(p);
		p = r->link;
	}
}
//int main()
//{
//	JOSEPHUS(13, 4, 1);
//	system("pause");
//	return 0;
//}