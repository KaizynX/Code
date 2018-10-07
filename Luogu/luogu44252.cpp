#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, m;
int fa[Maxn], sz[Maxn];

struct Color
{
	int c, t;
} a[Maxn];

struct Tree
{
	int l, r, c, t;
} tr[Maxn<<2];

inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1|1; }
int getf(int s) { return s == fa[s] ? s : fa[s] = getf(fa[s]); }

void connect(int l, int r, int x, int t)
{
	int fl = getf(l), fr = getf(r);
	if(fl != fr)
	{
		fa[fl] = fr;
		sz[fr] += sz[fl];
	}
	a[fr].c = x;
	a[fr].t = t;
}

void push_down(int i)
{
	int l = ls(i), r = rs(i);
	if(tr[l].t < tr[i].t)
	{
		tr[l].t = tr[i].t;
		tr[l].c = tr[i].c;
	}
	if(tr[r].t < tr[i].t)
	{
		tr[r].t = tr[i].t;
		tr[r].c = tr[i].c;
	}
}

void build_tree(int i, int l, int r)
{
	tr[i].l = l; tr[i].r = r;
	if(l == r) return;
	int mid = (l+r)>>1;
	build_tree(ls(i), l, mid);
	build_tree(rs(i), mid+1, r);
}

void update_tree(int i, int l, int r, int x, int t)
{
	if(l <= tr[i].l && r >= tr[i].r)
	{
		tr[i].c = x;
		tr[i].t = t;
		return;
	}
	push_down(i);
	int mid = (tr[i].l+tr[i].r)>>1;
	if(l <= mid) update_tree(ls(i), l, r, x, t);
	if(r > mid)  update_tree(rs(i), l, r, x, t);
}

void push_tree(int i)
{
	if(tr[i].l == tr[i].r)
	{
		int f = getf(tr[i].l);
		if(tr[i].t > a[f].t)
		{
			a[f].t = tr[i].t;
			a[f].c = tr[i].c;
		}
		return;
	}
	push_down(i);
	push_tree(ls(i));
	push_tree(rs(i));
}

int main()
{
	scanf("%d%d", &n, &m);
	// init
	build_tree(1, 1, n);
	for(int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;

	for(int i = 1; i <= n; ++i) scanf("%d", &a[i].c);
	for(int i = 1, op, l, r, x; i <= m; ++i)
	{
		scanf("%d%d%d%d", &op, &l, &r, &x);
		if(op == 1) update_tree(1, l, r, x, i);
		else connect(l, r, x, i);
	}
	// calc the ans
	push_tree(1);
	for(int i = 1; i < n; ++i) printf("%d ", a[getf(i)].c);
	printf("%d\n", a[getf(n)].c);
	for(int i = 1; i < n; ++i) printf("%d ", sz[getf(i)]-1);
	printf("%d\n", sz[getf(n)]-1);
	return 0;
}
