#include <bits/stdc++.h>

using namespace std;

const int Maxn = (1<<10)+7;

int n;
char a[Maxn];

struct Tree
{
	char v;
	Tree *l, *r;
	Tree(){ l = NULL; r = NULL; }
} root;

void build_tree(Tree *tr, int l, int r)
{
	if(l == r)
	{
		tr->v = a[l] == '0' ? 'B' : 'I';
		return;
	}
	int mid = (l+r)>>1;
	build_tree((tr->l = new Tree), l, mid);
	build_tree((tr->r = new Tree), mid+1, r);
	tr->v = tr->l->v == tr->r->v ? tr->l->v : 'F';
}

void print_tree(Tree *tr)
{
	if(tr->l) print_tree(tr->l);
	if(tr->r) print_tree(tr->r);
	putchar(tr->v);
}

int main()
{
	scanf("%d%s", &n, a+1);
	build_tree(&root, 1, 1<<n);
	print_tree(&root);
	return 0;
}
