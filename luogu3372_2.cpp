#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

struct Tree
{
	long long sum, add;
	int l, r;
	Tree():sum(0),add(0),l(0),r(0){}
} tr[Maxn << 2];

int n, m;
int a[Maxn];

template <typename T> inline void read(T &);
void build_tree(int, int, int);
inline void push_down(int);
void update_tree(int, int, int, int);
long long query_tree(int, int, int);
inline int ls(int p) { return p << 1; }     // left son
inline int rs(int p) { return p << 1 | 1; } // right son

int main()
{
	read(n); read(m);
	for(int i = 1; i <= n; ++i) read(a[i]);
	build_tree(1,n,1);
	for(int i = 0, op, x, y, k; i < m; ++i)
	{
		read(op); read(x); read(y);
		if(op == 1)
		{
			read(k);
			update_tree(x, y, k, 1);
		}
		else printf("%lld\n",query_tree(x, y, 1));
	}
	return 0;
}

long long query_tree(int l, int r, int i)
{
	if(l <= tr[i].l && r >= tr[i].r) return tr[i].sum;
	push_down(i);
	int mid = (tr[i].l + tr[i].r) >> 1;
	long long res = 0;
	if(l <= mid) res += query_tree(l, r, ls(i));
	if(r > mid) res += query_tree(l, r, rs(i));
	return res;
}

void update_tree(int l, int r, int k, int i)
{
	if(l <= tr[i].l && r >= tr[i].r)
	{
		tr[i].add += k;
		tr[i].sum += (tr[i].r - tr[i].l + 1) * k;
		return;
	}
	push_down(i);
	int mid = (tr[i].l + tr[i].r) >> 1;
	if(l <= mid) update_tree(l, r, k, ls(i)); 
	if(r > mid) update_tree(l ,r, k, rs(i));
	tr[i].sum = tr[ls(i)].sum + tr[rs(i)].sum;
}

inline void push_down(int i)
{
	if(!tr[i].add) return;
	int len = tr[i].r - tr[i].l + 1;
	tr[ls(i)].add += tr[i].add;
	tr[rs(i)].add += tr[i].add;
	tr[ls(i)].sum += tr[i].add * ((len+1) >> 1);
	tr[rs(i)].sum += tr[i].add * (len >> 1);
	tr[i].add = 0;
}

void build_tree(int l, int r, int i)
{
	tr[i].l = l; tr[i].r = r;
	if(l == r) { tr[i].sum = a[l]; return; }
	int mid = (l + r) >> 1;
	build_tree(l, mid, ls(i));
	build_tree(mid+1, r, rs(i));
	tr[i].sum = tr[ls(i)].sum + tr[rs(i)].sum;
}

template <typename T> inline void read(T &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}
