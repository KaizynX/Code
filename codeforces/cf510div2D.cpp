#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e5+7;

int n, a[Maxn], tr[Maxn], tot;
long long t, ans, sum[Maxn], dis[Maxn];

inline void update(int x)
{
	for( ; x <= n; x += x&-x) tr[x]++;
}

inline int query(int x)
{
	int res = 0;
	for( ; x; x -= x&-x) res += tr[x];
	return res;
}

int main()
{
	scanf("%d%I64d", &n, &t);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		dis[i] = sum[i] = sum[i-1]+a[i];
	}
	dis[n] = 0;
	sort(dis+1, dis+n+1);
	tot = unique(dis+1, dis+n+1)-(dis+1);
	for(int i = 1, cur; i <= n; ++i)
	{
		cur = lower_bound(dis+1, dis+tot+1, sum[i-1])-dis;
		update(cur);
		cur = upper_bound(dis+1, dis+tot+1, sum[i]-t)-(dis+1);
		ans += query(cur);
	}
	printf("%I64d\n", ((n+1ll)*n)/2-ans);
	return 0;
}
