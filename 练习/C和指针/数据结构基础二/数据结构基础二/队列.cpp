#include<iostream>
#include<stdio.h>
#include<string>
#include<conio.h>
using namespace std;
typedef struct student
{
	int data;
	struct student *next;
}node;
typedef struct linkqueue{
	node *first, *rear;
}queue;

//队列入队
queue *insert(queue *HQ, int x)
{
	node*s;
	s = (node*)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;
	if (HQ->rear == NULL)
	{
		HQ->first = s;
		HQ->rear = s;
	}
	else
	{
		HQ->rear->next = s;
		HQ->rear = s;
	}
	return HQ;
}

//队列出列
queue *del(queue *HQ)
{
	node*p;
	int x;
	if (HQ->first == NULL)
		printf("\n   溢出");
	else
	{
		x = HQ->first->data;
		p = HQ->first;
		if (HQ->first == HQ->rear)
		{
			HQ->first = NULL;
			HQ->rear = NULL;
		}
		else
		{
			HQ->first = HQ->first->next;
			free(p);
		}
		return HQ;
	}
}

