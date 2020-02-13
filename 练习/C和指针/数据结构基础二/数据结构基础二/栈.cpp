#include<iostream>
#include<string>
#include<stdlib.h>
#include<conio.h>
using namespace std;
typedef struct student{
	int data;
	struct student *next;
}node;

typedef struct stackqueue{
	node* zhandi, *top;
}queue;

//ÈëÕ»
queue *push(queue *HQ, int x)
{
	node *s, *p;
	s = (node*)malloc(sizeof(node));
	s->data = x;
	s->next = NULL;
	if (HQ->zhandi == NULL)
	{
		HQ->zhandi = s;
		HQ->top = s;
	}
	else
	{
		HQ->top->next = s;
		HQ->top = s;
	}
	return HQ;
}

//³öÕ»
queue *pop(queue *HQ)
{
	node *p; int x;
	if (HQ->zhandi == NULL)
	{
		printf("\nÒç³ö");
	}
	else{
		p = HQ->zhandi;
		if (HQ->zhandi == HQ->top)
		{
			HQ->top = NULL;
			HQ->zhandi = NULL;
		}
		else
		{
			while (p->next != HQ->top)
			{
				p = p->next;
			}
			HQ->top = p;
			HQ->top->next = NULL;
		}
		return HQ;
	}
}