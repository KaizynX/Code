#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG

using namespace std;

const int Maxn = 1e6 + 7;

int n;
long long f[Maxn<<1];

struct Node
{
	int l, r, w;
	bool operator < (const Node &b) const { return r < b.r; }
} a[Maxn];

struct Hash
{
	long long v;
	int index;
	bool side; // 0 --> left    1 --> right
	bool operator < (const Hash &b) const { return v < b.v; }
} h[Maxn*2];

template <typename T> inline void read(T &);

int main()
{
	// scanf("%d", &n);
	read(n);
	for(int i = 0, cnt = 0; i < n; ++i)
	{
		// scanf("%lld%lld%d", &h[++cnt].v, &h[++cnt].v, &a[i].w);
		read(h[++cnt].v); read(h[++cnt].v); read(a[i].w);
		h[cnt-1].index = i; h[cnt].index = i;
		h[cnt-1].side = false; h[cnt].side = true;
	}

#ifdef DEBUG
	printf("\nh   i     v index  side\n");
	for(int i = 1; i <= n*2; ++i)
		printf("%5d %5lld %5d %5d\n", i, h[i].v, h[i].index, h[i].side);
#endif
	// Descretization
	sort(h+1, h+n*2+1);
#ifdef DEBUG
	printf("\nh   i     v index  side\n");
	for(int i = 1; i <= n*2; ++i)
		printf("%5d %5lld %5d %5d\n", i, h[i].v, h[i].index, h[i].side);
#endif
	h[0].v = -1; // 0 <= ai, bi  so cur start from 1
	for(int i = 1, cur = 0; i <= n*2; ++i)
	{
		if(h[i].v != h[i-1].v) cur++;
		if(h[i].side) a[h[i].index].r = cur;
		else a[h[i].index].l = cur;
	}

#ifdef DEBUG
	printf("\na   i     l     r     w\n");
	for(int i = 0; i < n; ++i)
		printf("%5d %5d %5d %5d\n", i, a[i].l, a[i].r, a[i].w);
#endif
	sort(a, a+n);
	for(int pos = 1, cur = 0; cur < n; ++pos)
	{
		f[pos] = f[pos-1];
		while(cur < n && a[cur].r == pos)
			f[pos] = max(f[pos], f[a[cur].l] + a[cur++].w);
	}
	printf("%lld\n", f[a[n-1].r]);
	return 0;
}

template <typename T> inline void read(T &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}
