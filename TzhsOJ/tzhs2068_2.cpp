#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG

using namespace std;

const int Maxn = 2e5 + 7;
const int INF = 2e9;

int n, ans;

struct Node
{
	int l, r;
	bool operator < (const Node &b) const
	{
		return l == b.r ? r < b.r : l < b.l;
	}
} a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0, x, w; i < n; ++i)
	{
		// abs(x1 - x2) >= w1 + w2
		// x1 > x2 ==> x1 - w1 >= x2 + w2
		// x1 < x2 ==> x1 + w1 <= x2 - w2
		scanf("%d%d", &x, &w);
		a[i].l = x - w;
		a[i].r = x + w;
	}
#ifdef DEBUG
	for(int i = 0; i < n; ++i) printf("%d %d\n", a[i].l, a[i].r);
#endif
	sort(a, a+n);
	for(int i = 0, last = -INF; i < n; ++i)
	{
		if(a[i].l >= last) { last = a[i].r; ++ans; }
		else last = min(last, a[i].r);
	}
	printf("%d\n", ans);
	return 0;
}
