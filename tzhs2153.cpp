#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5+7;
const int Maxm = 2e5+7;

int n, m, cnt, ans;
struct Node
{
	int u, v;
	bool operator < (const Node &b) const
	{
		return v < b.v;
	}
}a[Maxm];

int main()
{
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		if(v == u+1) continue;
		a[++cnt].u = u; a[cnt].v = v;
	}
	ans = n-1;
	sort(a+1, a+cnt+1);
	for(int i = 1, last = -1; i <= cnt; ++i)
	{
		if(a[i].u >= last)
		{
			++ans;
			last = a[i].v;
		}
	}
	printf("%d\n", ans);
	return 0;
}
