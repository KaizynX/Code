#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1 << 13;

int n;
int tree[Maxn * 2];
int point[Maxn];

inline int cul(int l,int r)
{
	return l == r ? l : 2;
}

int build_tree(int cur)
{
	if(cur < n)
		tree[cur] = cul(build_tree(cur*2),build_tree(cur*2+1));
	return tree[cur];
}

void print_tree(int cur)
{
	if(cur >= n*2) return ;
	print_tree(cur*2);
	print_tree(cur*2+1);
	if(tree[cur] == 0) putchar('B');
	else if(tree[cur] == 1) putchar('I');
	else putchar('F');
}

int main()
{
	char c;
	int tmp;
	scanf("%d",&tmp);
	n = 1 << tmp;
	for(int i = 0; i < n; ++ i)
	{
		cin >> c;
		if(c == '0') tree[n + i] = 0;
		else tree[n + i] = 1;
	}
	build_tree(1);
	print_tree(1);
	return 0;
} 
