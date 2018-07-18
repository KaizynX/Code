#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 107;

int n, ans;

struct Node
{
	int l, r;
	bool operator < (const Node &b) const
	{
		return l == b.l ? r < b.r : l < b.l;
	}
} a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a[i].l, &a[i].r);
		if(a[i].l > a[i].r) swap(a[i].l, a[i].r);
	}
	sort(a, a+n);
	for(int i = 0, last = -1000; i < n; ++i)
	{
		if(a[i].l >= last)
		{
			ans++;
			last = a[i].r;
		}
		else last = min(last, a[i].r);
	}
	printf("%d\n", ans);
	return 0;
}
