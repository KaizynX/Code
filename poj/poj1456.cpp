#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int Maxn = 1e5 + 7;

int n, ans;
struct Node
{
	int p, d;
	bool operator < (const Node &b) const
	{
		return d == b.d ? p > b.p : d > b.d;
	}
} a[Maxn];

int main()
{
	while(scanf("%d", &n) == 1)
	{
		ans = 0;
		priority_queue<int> q;
		for(int i = 0; i < n; ++i)
			scanf("%d%d", &a[i].p, &a[i].d);
		sort(a, a+n);
		for(int cur = 0, t = a[0].d; t; --t)
		{
			while(cur < n && a[cur].d == t) q.push(a[cur++].p);
			if(!q.empty())
			{
				ans += q.top();
				q.pop();
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
