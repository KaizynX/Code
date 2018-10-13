#include <bits/stdc++.h>

using namespace std;

string a, b;

struct Tree
{
	char v;
	Tree *l, *r;
	Tree(){ l = NULL; r = NULL; }
} root;

void build_tree(string MLR, string LMR, Tree *tr)
{
	tr->v = MLR[0];
	int pos = LMR.find(MLR[0]);
	if(pos > 0)
		build_tree(MLR.substr(1, pos), LMR.substr(0, pos), (tr->l = new Tree));
	if(pos < (int)LMR.length()-1)
		build_tree(MLR.substr(pos+1), LMR.substr(pos+1), (tr->r = new Tree));
}

void print_tree(Tree *tr)
{
	if(tr->l) print_tree(tr->l);
	if(tr->r) print_tree(tr->r);
	putchar(tr->v);
}

int main()
{
	cin >> a >> b;
	build_tree(a, b, &root);
	print_tree(&root);
	return 0;
}
