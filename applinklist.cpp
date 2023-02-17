#include<iostream>
#include<malloc.h>

using namespace std;

typedef struct polynode
{
	int coef;
	int expn;
	struct polynode *next;
}*pnode;

pnode createpoly()
{
	int a, n, i = 1;
	pnode head, s, p;
	cout << "输入一元多项式（以0,0标志结束）：" << endl;
	cout << "要求：1.按幂从大到小顺序输入各节点" << endl;
	cout << "      2.没有两个结点具有相同的幂：" << endl;
	head = (pnode)malloc(sizeof(struct polynode));
	head->next = NULL;
	p = head;
	do
	{
		cout << "第" << i++ << "次->系数，幂：";
		cin >> a;
		cin >> n;
		if (a != 0 || n != 0)
		{
			s = (pnode)malloc(sizeof(struct polynode));
			s->coef = a;
			s->expn = n;
			s->next = NULL;
			p->next = s;
			p = s;
		}
	} while (a != 0 || n != 0);
	cout << endl;
	return (head);
}
void printpoly(pnode head)
{
	int first = 1;
	head = head->next;
	while (head != NULL)
	{
		if (first)
		{
			if (head->expn == 1)
				cout << head->coef;
			else if (head->expn == 0)
				cout << head->coef;
			else
				cout << head->coef << "x^" << head->expn;
			first = 0;
		}
		else
		{
			if (head->expn == 1)
			{
				cout << "+" << head->coef << "x";
			}
			else if (head->expn == 0)
			{
				cout << "+" << head->coef;
			}
			else
				cout << "+" << head->coef << "x^" << head->expn;
		}
		head = head->next;
	}
	cout << endl;
}


pnode addpoly(pnode pa, pnode pb)
{
	int n;
	pnode pc, s, p;
	pa = pa->next;
	pb = pb->next;
	pc = (pnode)malloc(sizeof(struct polynode));
	pc->next = NULL;
	p = pc;
	while (pa != NULL && pb != NULL)
	{
		if (pa->expn > pb->expn)
		{
			s = (pnode)malloc(sizeof(struct polynode));
			s->coef = pa->coef;
			s->expn = pa->expn;
			s->next = NULL;
			p->next = s;
			p = s;
			pa = pa->next;
		}
		else if (pa->expn < pb->expn)
		{
			s = (pnode)malloc(sizeof(struct polynode));
			s->coef = pb->coef;
			s->expn = pb->expn;
			s->next = NULL;
			p->next = s;
			p = s;
			pb = pb->next;
		}
		else
		{
			n = pa->coef + pb->coef;
			if (n != 0)
			{
				s = (pnode)malloc(sizeof(struct polynode));
				s->coef = n;
				s->expn = pb->expn;
				s->next = NULL;
				p->next = s;
				p = s;
			}
			pa = pa->next;
			pb = pb->next;
		}
	}
	while (pa != NULL)
	{
		s = (pnode)malloc(sizeof(struct polynode));
		s->coef = pa->coef;
		s->expn = pa->expn;
		s->next = NULL;
		p->next = s;
		p = s;
		pa = pa->next;
	}
	while (pb != NULL)
	{
		s = (pnode)malloc(sizeof(struct polynode));
		s->coef = pb->coef;
		s->expn = pb->expn;
		s->next = NULL;
		p->next = s;
		p = s;
		pb = pb->next;
	}
	return (pc);
}



void main()
{
	pnode poly1, poly2, poly3;
	cout << "建立第一个一元多项式=>" << endl;
	poly1 = createpoly();
	cout << "建立第二个一元多项式=>" << endl;
	poly2 = createpoly();
	poly3 = addpoly(poly1, poly2);
	cout << "第一个一元多项式为：";
	printpoly(poly1);
	cout << "第二个一元多项式为：";
	printpoly(poly2);
	cout << "相加后一元多项式为：";
	printpoly(poly3);
	system("pause");
}