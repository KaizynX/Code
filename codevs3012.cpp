#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1e6 + 7;

int n;
long long f[Maxn];
struct Node
{
	int l, r, w;
	bool operator < (const Node &b) const { return r < b.r; }
}a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
	sort(a, a+n);
	for(int i = 1, cur = 0; cur < n; ++i)
	{
		f[i] = f[i-1];
		while(cur < n && a[cur].r == i)
			f[i] = max(f[i], f[a[cur].l] + a[cur++].w);
	}
	printf("%lld\n", f[a[n-1].r]);
	return 0;
}
