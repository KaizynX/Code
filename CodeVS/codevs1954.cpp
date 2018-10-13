#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const long long INF = 9e18;

int n, m, a[Maxn];

struct Tree
{
	int l, r;
	long long maxv, minv, sum, add;
	Tree(){ l = r = 0; maxv = -INF; minv = INF; sum = add = 0; }
} tr[Maxn<<2];

template <typename T> inline void read(T &);
template <typename T> void write(T);
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1|1; }
inline void push_up(int);
inline void push_down(int);
inline void build_tree(int, int, int);

int main()
{
	read(n); read(m);
	for(int i = 1; i <= n; ++i) read(a[i]);
	build_tree(1, 1, n);
	return 0;
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

inline void push_up(int i)
{
	tr[i].sum = tr[ls(i)].sum+tr[rs(i)].sum;
}

template <typename T> inline void read(T &x)
{
	char c; T tag = -1;
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
