#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;
const int Maxt = 25;
const int Maxd = 2e3+7;

int n, D, cnt;
int dp[Maxd], rk[Maxn], res[Maxn];
bitset<Maxn> choose[Maxd];

struct Portal
{
	int t, d, c, id;
	bool operator < (const Portal &b) const
	{
		return d < b.d;
	}
} a[Maxn];

bool cmp(int x, int y)
{
	return rk[x] < rk[y];
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].c);
		a[i].id = i;
		D = max(D, a[i].d);
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i)
	{
		rk[a[i].id] = i;
		// the time finish it
		for(int j = a[i].d-1; j >= a[i].t; --j)
		{
			// dp[j] = max(dp[j], dp[j-a[i].t]+a[i].c);
			int tmp = dp[j-a[i].t]+a[i].c;
			if(tmp > dp[j])
			{
				dp[j] = tmp;
				choose[j] = choose[j-a[i].t];
				choose[j][a[i].id] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < D; ++i)
		if(dp[ans] < dp[i])
			ans = i;
	printf("%d\n%d\n", dp[ans], choose[ans].count());
	if(choose[ans].count() == 0) return 0;
	for(int i = 1; i <= n; ++i)
		if(choose[ans][i])
			res[++cnt] = i;
	sort(res+1, res+cnt+1, cmp);
	for(int i = 1; i < cnt; ++i)
		printf("%d ", res[i]);
	printf("%d\n", res[cnt]);
	return 0;
}
