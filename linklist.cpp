#include<cstdio>
#include<algorithm>
#include<stack>
#include<stdio.h>
#include<iostream>
using namespace std;
#include<malloc.h>
typedef struct LNode
{
	int expn;
	int coef;
	struct LNode *next;
} LinkList;


void InitList(LinkList *&head)
{
	head = (LinkList*)malloc(sizeof(LinkList));
	head->next = NULL;
}
void CreateListA(LinkList *&head, int a[],int b[], int n)
{
	LinkList *r, *s;
	r = head;
	for (int i = 0; i < n; i++)
	{
		s = (LinkList*)malloc(sizeof(LinkList));
		s->coef = a[i];
		s->expn = b[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
bool ListEmpty(LinkList *&head)
{
	return (head->next == NULL);
}

int ListLength(LinkList *head)
{
	int n = 0;
	LinkList *p = head;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

int Zeros(LinkList *&head)
{
	int n = 0;
	LinkList *p = head;
	while (p->next != NULL) {
		if (p->next->coef == 0) {
			n++;
		}
		p = p->next;
	}
	return n;
}

void DisplayList(LinkList *&head,int n)
{
	LinkList *p = head->next;
	//cout << Zeros(*&head)<< endl;
	int y = Zeros(*&head);
	for (int i = 0; i < n; i++) {
		if (p == NULL) {
			return;
		}
		else if(y==n){
			cout << "0";
			break;
		}
		else if (p == head->next) {
			if (p->coef == 1||p->coef == -1) {
				if (p->coef == 0) {
					cout << "";
				}
				else if (p->expn == 0) {
					cout << p->coef;
				}
				else if (p->expn == 1) {
					if (p->coef > 0) {
						cout << "x";
					}
					else if (p->coef < 0) {
						cout << "-x";
					}
					
				}
				else {
					cout  << "x^" << p->expn;
				}

			}
			else {
				if (p->coef == 0) {
					cout << "";
				}
				else if (p->expn == 0) {
					cout << p->coef;
				}
				else if (p->expn == 1) {
					cout << p->coef << "x";
				}
				else {
					cout << p->coef << "x^" << p->expn;
				}

			}
		}
		else {
			if (p->coef == 1||p->coef == -1) {
				if (p->coef == 0) {
					cout << "";
				}
				else if (p->expn == 0) {
					if (p->coef < 0) {
						cout << p->coef;
					}
					else if(p->coef > 0){
						cout << "+" << p->coef;
					}					
				}
				else if (p->expn == 1) {
					if (p->coef < 0) {
						cout  << "x";
					}
					else {
						cout << "+" << "x";
					}			
				}
				else {
					if (p->coef < 0) {
						cout  <<  "x^" << p->expn;
					}
					else {
						cout << "+"  << "x^" << p->expn;
					}				
				}
			}
			else {
				if (p->coef == 0) {
					cout << "";
				}
				else if (p->expn == 0) {
					if (p->coef < 0) {
						cout  << p->coef;
					}
					else {
						cout << "+" << p->coef;
					}
					
				}
				else if (p->expn == 1) {
					if (p->coef < 0) {
						cout << p->coef << "x";
					}
					else {
						cout << "+" << p->coef << "x";
					}				
				}
				else {
					if (p->coef < 0) {
						cout << p->coef << "x^" << p->expn;
					}
					else {
						cout << "+" << p->coef << "x^" << p->expn;
					}
					
				}
			}
			
		}
		p = p->next;
	}
	cout << endl;
}
void Sort(LinkList *&l) { 
	LinkList *p = l->next, *pre;
	LinkList *r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL) {
		r = p->next;
		pre = l;
		while (pre->next != NULL && pre->next->expn < p->expn) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}

void *simplify(LinkList *&L) {
	LinkList *p, *q;
	p = L->next;
	while (p)
	{
		q = p->next;
		if (q != NULL && p->expn == q->expn)
		{
			p->coef += q->coef;
			p->next = q->next;
			free(q);
		}
		else p = p->next;
	}
	return L;
}

void Add(LinkList *ha, LinkList *hb, LinkList *&hc)  
{
	LinkList *pa = ha->next, *pb = hb->next, *s, *tc;
	double c;
	hc = (LinkList *)malloc(sizeof(LinkList));       
	tc = hc;
	while (pa != NULL && pb != NULL)
	{
		if (pa->expn < pb->expn)
		{
			s = (LinkList *)malloc(sizeof(LinkList)); 
			s->expn = pa->expn;
			s->coef = pa->coef;
			tc->next = s;
			tc = s;
			pa = pa->next;
		}
		else if(pa->expn > pb->expn)
		{
			s = (LinkList *)malloc(sizeof(LinkList)); 
			s->expn = pb->expn;
			s->coef = pb->coef;
			tc->next = s;
			tc = s;
			pb = pb->next;
		}
		else                
		{
			c = pa->coef + pb->coef;
			if (c != 0)       
			{
				s = (LinkList *)malloc(sizeof(LinkList)); 
				s->expn = pa->expn;
				s->coef = c;
				tc->next = s;
				tc = s;
			}
			pa = pa->next;
			pb = pb->next;
		}
	}
	if (pb != NULL) pa = pb;    
	while (pa != NULL)
	{
		s = (LinkList *)malloc(sizeof(LinkList)); 
		s->expn = pa->expn;
		s->coef = pa->coef;
		tc->next = s;
		tc = s;
		pa = pa->next;
	}
	tc->next = NULL;
}


int main()
{
	LinkList *head1, *head2, *head3;
	InitList(*&head1);
	InitList(*&head2);
	InitList(*&head3);
	if (ListEmpty(*&head1) == 1) {
		cout << "初始化，此时链表1为空" << endl;
	}
	else if (ListEmpty(*&head2) == 1) {
		cout << "初始化，此时链表2为空" << endl;
	}
	else if (ListEmpty(*&head3) == 1) {
		cout << "初始化，此时链表3为空" << endl;
	}
	cout << "输入的格式为  {{ X1(空格或回车)X2 }} " << endl;
	//第一个链表
	int n;
	int a[100];
	int b[100];
	cout << "请输入第1个多项式的项数n" << endl;
	cin >> n;
	cout << "请依次输入元素" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	CreateListA(*&head1, a, b, n);
	Sort(head1);
	simplify(head1);
	cout << "多项式1为:" << endl;
	//cout << ListLength(head1) << Zeros(*&head1) << endl;//测试用
	DisplayList(*&head1, ListLength(head1));
	
	cout << endl << endl << endl;
	//第二个链表
	cout << "请输入第2个多项式的项数n" << endl;
	cin >> n;
	cout << "请依次输入元素" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cin >> b[i];
	}
	CreateListA(*&head2, a, b, n);
	Sort(head2);
	simplify(head2);
	cout << "多项式2为:" << endl;
	//cout << ListLength(head2) << Zeros(*&head2) << endl;//测试用
	DisplayList(*&head2, ListLength(head2));
	
	cout << endl << endl;
	Add(head1,head2,head3);
	cout << "合并后的多项式为:" << endl;
	//cout << ListLength(head3) << Zeros(*&head2) << endl;//测试用
	DisplayList(*&head3, ListLength(head3));
	
	system("pause");
	return 0;
}