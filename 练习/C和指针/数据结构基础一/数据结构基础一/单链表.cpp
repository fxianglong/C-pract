#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}node;
node *create()
{
	node *head, *p, *s;
	int x, cycle = 1;
	head = (node*)malloc(sizeof(node));
	p = head;
	while (cycle)
	{
		cout << "����������" << endl;
		cin >> x;
		if (x != 0)
		{
			s = (node*)malloc(sizeof(node));
			s->data = x;
			printf("%d", s->data);
			p->next = x;
			p = s;
		}
		else cycle = 0;
	}
	head = head->next;
	p->next = NULL;
	printf("\n   yyy  %d", head->data);
	return(head);
}

//������ⳤ
int length(node *head)
{
	int n = 0;
	node *p;
	p = head;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

//��ӡ������
void print(node *head)
{
	node* p; int n;
	p = head;
	n = length(head);
	if (head!=NULL)
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
}

//�������ɾ��
node *del(node* head,int num)
{
	node*p, *q;
	p = head;
	while (p->data != num&&p->next != NULL)
	{
		q = p;
		p = p->next;
	}
	if (num == p->data)
	{
		if (p == head)
		{
			head = head->next;
			free(p);
		}
		else q->next = p->next;
	}
	else
	{
		printf("%d����������", num);
	}
	return head;
}


//������Ĳ���
node *insert(node *head, int num)
{
	node* p0, *p1, *p2;
	p1 = head;
	p0 = (node*)malloc(sizeof(node));
	p0->data = num;
	while (p0->data > p1->data&&p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p0->data <= p1->data)
	{
		if (head == p1)
		{
			p0->next = p1;
			head = p0;
		}
		else
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	else
	{
		p1->next = p0;
		p0->next = NULL;
	}
	return head;
}

//ʵ�ֵ����������
node *sort(node *head)
{
	node*p;
	int tmp;
	int n = length(head);
	if (head == NULL || head->next == NULL)
		return head;
	for (int i = 1; i < n; i++)
	{
		p = head;
		for (int j = 0; j < n - i; j++)
		{
			if (p->data>p->next->data)
			{
				tmp = p->data;
				p->data = p->next->data;
				p->next->data = tmp;
			}
			p = p->next;
		}
	}
	return head;
}

//���õ�����
node *reverse(node* head)
{
	node* p1, *p2, *p3;
	if (head == NULL || head->next == NULL)
		return head;
	p1 = head; p2 = p1->next;
	while (p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	head->next = NULL;
	head = p1;
	return head;
}

//ɾ���������ͷԪ��
node *delfirst(node *head)
{
	node *p;
	p = head->next;
	head = p;
	free(p);
}

//���ص������м�ֵ
int returnmid(node* head)
{
	node*mid, *tmp;
	mid = head;
	while (head->next->next != NULL)
	{
		head = head->next->next;
		tmp = tmp->next;
		mid = tmp;
	}
	return mid->data;
}