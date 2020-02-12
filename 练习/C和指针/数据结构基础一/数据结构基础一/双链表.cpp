#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
using namespace std;
typedef struct student{
	int data;
	struct student *next;
	struct student *pre;
}dnode;
dnode *create()
{
	dnode*head, *p, *s;
	int x, cycle = 1;
	head = (dnode*)malloc(sizeof(dnode));
	p = head;
	while (cycle)
	{
		printf("请输入双链表数值");
		scanf("%d", &x);
		if (x != 0)
		{
			s = (dnode*)malloc(sizeof(dnode));
			s->data = x;
			printf("\n   %d", s->data);
			p->next = s;
			s->pre = p;
			p = s;
		}
		else
		{
			cycle = 1;
		}
	}
	head = head->next;
	head->pre = NULL;
	p->next = NULL;
	return head;
}


//双链表删除节点
dnode *del(dnode *head, int num)
{
	dnode *p1, *p2;
	p1 = head;
	while (p1->data != num || p1->next != NULL)
	{
		p1 = p1->next;
	}
	if (num = p1->data)
	{
		if (p1 = head)
		{
			head = head->next;
			head->pre = NULL;
			free(p1);
		}
		else if (p1->next == NULL)
		{
			p1->pre->next = NULL;
			free(p1);
		}
		else
		{
			p1->next->pre = p1->pre;
			p1->pre->next = p1->next;
		}
	}
	else
	{
		printf("%d  不在双链表中");
	}
	return head;
}


//双链表插入节点

dnode *insert(dnode *head, int num)
{
	dnode *p1, *p2;
	p2 = head;
	p1 = (dnode *)malloc(sizeof(dnode));
	p1->data = num;
	while (p1->data > p2->data&&p2->next != NULL)
	{
		p2 = p2->next;
	}
	if (p1->data < p2->data)
	{
		if (head == p2)
		{
			p1->next = p2;
			p2->pre = p1;
			head = p1;
		}
		else
		{
			p2->pre->next = p1;
			p1->next = p2;
			p1->pre = p2->pre;
			p2->pre = p1;
		}
	}
	else
	{
		p2->next = p1;
		p1->pre = p2;
		p1->next = NULL;
	}
	return head;
}