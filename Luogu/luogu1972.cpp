#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

const int Maxn = 5e5 + 7;
const int Maxm = 2e5 + 7;
const int SIZE = 1e6 + 1;

struct Tree
{
	int l, r;
	size_t v;
	Tree(): l(0), r(0), v(0) {}
} tr[Maxn<<2];

int n, m;
int a[Maxn];
typedef bitset<SIZE> Bit;

Bit build_tree(int, int, int);
int query_tree(int, int, int);
inline int ls(int s) { return s<<1; }
inline int rs(int s) { return s<<1|1; }

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) scanf("%d",a+i);
	scanf("%d",&m);
	build_tree(1, n, 1);
	for(int i = 1, x, y; i <= m; ++i)
	{
		scanf("%d%d",&x, &y);
		printf("%d\n",query_tree(x, y, 1));
	}
	return 0;
}

Bit build_tree(int l, int r, int i)
{
	tr[i].l = l; tr[i].r = r;
	if(l == r)
	{
		tr[i].v = 1;
		Bit tmp;
		tmp[a[l]] = 1;
		return tmp;
	}

	int mid = (l + r) >> 1;
	Bit tree_l = build_tree(l, mid, ls(i));
	Bit tree_r = build_tree(mid+1, r, rs(i));
	Bit tree_i = tree_l | tree_r;
	tr[i].v = tree_i.count();
	printf("%d %d %d\n",l, r, tr[i].v); /////
	return tree_i;
}
int query_tree(int l, int r, int i)
{
	if(l <= tr[i].l && r >= tr[i].r) return tr[i].v;
	int mid = (l + r) >> 1;
	if(r <= mid) return query_tree(l, r, ls(i));
	else if(l > mid) return query_tree(l, r, rs(i));
	else return build_tree(l,r,i).count();
}
