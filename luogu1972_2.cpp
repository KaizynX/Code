#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 5e5+7;
const int Maxa = 1e6+7;

int n, m;
int a[Maxn], vis[Maxa], tr[Maxn], res[Maxn];

struct Query
{
	int l, r, id;
	bool operator < (const Query &b) const
	{
		return r < b.r;
	}
} q[Maxn];

inline void read(int &);
void put(int);
inline void add(int, int);
inline int query(int, int);

int main()
{
	read(n);
	for(int i = 1; i <= n; ++i)
		read(a[i]), a[i]++;
	read(m);
	for(int i = 1; i <= m; ++i)
		read(q[i].l), read(q[i].r), q[i].id = i;
	sort(q+1, q+m+1);
	for(int i = 1, cur = 0; i <= m; ++i)
	{
		while(cur < q[i].r)
		{
			cur++;
			if(vis[a[cur]]) add(vis[a[cur]], -1);
			add(cur, 1);
			vis[a[cur]] = cur;
		}
		res[q[i].id] = query(q[i].l, q[i].r);
	}
	for(int i = 1; i <= m; ++i)
		put(res[i]), putchar('\n');
	return 0;
}

inline void add(int p, int v)
{
	for(; p <= n; p += p&-p) tr[p] += v;
}

inline int query(int l, int r)
{
	int vl = 0, vr = 0;
	for(int i = l-1; i; i -= i&-i) vl += tr[i];
	for(int i = r; i; i -= i&-i) vr += tr[i];
	return vr-vl;
}

inline void read(int &x)
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	x = c-'0';
	while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
}

void put(int x)
{
	if(x/10) put(x/10);
	putchar(x%10+'0');
}
