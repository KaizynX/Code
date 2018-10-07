#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1e3 + 7;

int n, ans;
int f[Maxn];

struct Node
{
	int l, r, w;
	bool operator < (const Node &b) const
	{
		return l == b.l ? r < b.r : l < b.l;
	}
}a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].w);
	sort(a, a+n);
	for(int i = 0; i < n; ++i)
	{
		f[i] = a[i].w;
		for(int j = 0; j < i; ++j)
			if(a[j].r <= a[i].l)
				f[i] = max(f[i], f[j] + a[i].w);
	}
	for(int i = 0; i < n; ++i)
		if(f[i] > ans) ans = f[i];
	printf("%d\n", ans);
	return 0;
}
