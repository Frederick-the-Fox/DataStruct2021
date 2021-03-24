#include<iostream>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* pnext;
}Node, * LinkList;

LinkList InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(Node));
	if (L)
	{
		L->data = 'a';
		L->pnext = NULL;
	}
	return L;
}

void CreateList(LinkList L, int number)
{
	Node* s;
	Node* ite;
	ite = L;
	int c;
	while (number)
	{
		cin >> c;
		s = (Node*)malloc(sizeof(Node));
		if (s)
		{	
			ite->pnext = s;
			s->pnext = NULL;
			s->data = c;
		}
		ite = ite->pnext;
		number -= 1;
	}
}

void InsertNum(int ele, LinkList L)
{
	Node* ne = NULL;
	ne = (Node*)malloc(sizeof(Node));
	Node* ite;
	ite = L->pnext;
	if (ne)
	{
		while (1)
		{
			if (ele <= ite->data) break;
			if (ite->pnext == NULL) break;
			ite = ite->pnext;
		}
		ne->data = ele;
		ne->pnext = ite->pnext;
		ite->pnext = ne;
	}
}

void OutPut(LinkList L, int number)
{
	Node* s;
	s = L->pnext;
	while (s->pnext != NULL)
	{
		cout << s->data << " ";
		s = s->pnext;
	}
	cout << s->data << endl;
}

void FreeAll(LinkList L)
{
	Node* s = L;	
	while (s != NULL)
	{
		Node* s1 = s->pnext;
		free(s);
		s = s1;
	}
}

int main()
{
	int num = 0;
	int x = 0;
	cin >> num;
	LinkList L = NULL;
	L = InitList(L);
	CreateList(L, num);
	cin >> x;
	InsertNum(x, L);
	OutPut(L, num);
	FreeAll(L);
	return 0;
}