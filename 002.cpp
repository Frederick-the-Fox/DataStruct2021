#include<iostream>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* pnext;
}Node, * LinkList;

int ar[1000] = {0};

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

void CreateListTail(LinkList L, int number)
{
	Node* s;
	Node* ite;
	ite = L;
	int c;
	int i = 0;
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
		ar[i] = c;
		ite = ite->pnext;
		number -= 1;
		i += 1;
	}
}

void CreateListHead(LinkList L, int number)
{
	Node* s;
	int va;
	int i = 0;
	while (number)
	{
		s = (Node*)malloc(sizeof(Node));
		if (s)
		{
			cin >> va;
			s->pnext = L->pnext;
			L->pnext = s;
			s->data = va;
		}
		ar[i] = va;
		i += 1;
		number -= 1;
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
	while (number)
	{
		cout << ar[number - 1] << " ";
		number -= 1;
	}
	cout << endl;
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
	CreateListHead(L, num);
	OutPut(L, num);
	FreeAll(L);
	return 0;
}