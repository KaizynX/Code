#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e6+7;
const long long INF = 1e15;

int n, ans;

struct Node
{
	long long l, r;
	bool operator < (const Node &b) const
	{
		return l < b.l;
	}
} a[Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld%lld", &a[i].l, &a[i].r);
	sort(a+1, a+n+1);
	long long last = -INF;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i].l > last)
		{
			++ans;
			last = a[i].r;
		}
		else last = min(last, a[i].r);
	}
	printf("%d\n", ans);
	return 0;
}
