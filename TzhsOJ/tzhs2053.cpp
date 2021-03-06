#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

string str;
size_t pos = 0;

struct tree
{
	char c;
	tree *l,*r;
	tree()
	{
		l = nullptr;
		r = nullptr;
	}
} ;

void build_tree(tree *cur)
{
	if(pos >= str.length()) return;
	cur->c = str[pos++];
	if(str[pos-1] == '.') return;
	cur->l = new(tree);
	build_tree(cur->l);
	cur->r = new(tree);
	build_tree(cur->r);
}

void LDR_print(tree *cur)
{
	if(cur->c == '.') return;
	LDR_print(cur->l);
	putchar(cur->c);
	LDR_print(cur->r);
}

void LRD_print(tree *cur)
{
	if(cur->c == '.') return;
	LRD_print(cur->l);
	LRD_print(cur->r);
	putchar(cur->c);
}

int main()
{
	cin >> str;
	tree *root = new(tree);
	build_tree(root);
	LDR_print(root);
	putchar('\n');
	LRD_print(root);
	return 0;
}
