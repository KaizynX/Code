#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, m, a[Maxn];

struct Tree
{
	int l, r;
	long long sum, add;
	Tree(){ sum = add = 0; }
} tr[Maxn<<2];

template <typename T> inline void read(T &);
template <typename T> void write(T);
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1|1; }
inline void push_up(int);
inline void push_down(int);
inline void build_tree(int, int, int);
inline void update_tree(int, int, int, long long);
inline long long query_tree(int, int, int);

int main()
{
	read(n); read(m);
	for(int i = 1; i <= n; ++i) read(a[i]);
	build_tree(1, 1, n);
	for(int i = 1, op, x, y; i <= m; ++i)
	{
		read(op); read(x); read(y);
		if(op == 1)
		{
			long long k;
			read(k);
			update_tree(1, x, y, k);
		}
		else write(query_tree(1, x, y)), putchar('\n');
	}
	return 0;
}

inline void push_up(int i)
{
	tr[i].sum = tr[ls(i)].sum+tr[rs(i)].sum;
}

inline void push_down(int i)
{
	if(!tr[i].add) return;
	int len = tr[i].r-tr[i].l+1;
	tr[ls(i)].add += tr[i].add;
	tr[rs(i)].add += tr[i].add;
	tr[ls(i)].sum += tr[i].add*(len-len/2);
	tr[rs(i)].sum += tr[i].add*(len/2);
	tr[i].add = 0;
}

inline void build_tree(int i, int l, int r)
{
	tr[i].l = l; tr[i].r = r;
	if(l == r) { tr[i].sum = a[l]; return; }
	int mid = (l+r)>>1;
	build_tree(ls(i), l, mid);
	build_tree(rs(i), mid+1, r);
	push_up(i);
}

inline void update_tree(int i, int l, int r, long long k)
{
	if(tr[i].l >= l && tr[i].r <= r)
	{
		tr[i].sum += k*(tr[i].r-tr[i].l+1);
		tr[i].add += k;
		return;
	}
	push_down(i);
	int mid = (tr[i].l+tr[i].r)>>1;
	if(l <= mid) update_tree(ls(i), l, r, k);
	if(r > mid)  update_tree(rs(i), l, r, k);
	push_up(i);
}

inline long long query_tree(int i, int l, int r)
{
	if(tr[i].l >= l && tr[i].r <= r) return tr[i].sum;
	push_down(i);
	int mid = (tr[i].l+tr[i].r)>>1;
	long long res = 0;
	if(l <= mid) res += query_tree(ls(i), l, r);
	if(r > mid)  res += query_tree(rs(i), l, r);
	return res;
}

template <typename T> inline void read(T &x)
{
	char c; T tag = 1;
	while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
	x = c-'0';
	while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}

template <typename T> void write(T x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x/10);
	putchar(x%10+'0');
}
