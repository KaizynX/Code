#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e3+7;

int n, ans, maxd, fa[Maxn], dp[Maxn], is_ok[Maxn];
int ver[Maxn<<1], fir[Maxn], nex[Maxn<<1], tot;
int po[Maxn], pf[Maxn], pn[Maxn], pt;

inline void add_edge(int u, int v)
{
	ver[++tot] = v; nex[tot] = fir[u]; fir[u] = tot;
}

inline void add_dep(int p, int d)
{
	po[++tot] = p; pn[tot] = fir[d]; pf[d] = tot;
}

void dfs(int cur)
{
	for(int i = fir[cur], to; i; i = nex[i])
	{
		to = ver[i];
		if(dp[to]) continue;
		fa[to] = cur;
		dp[to] = dp[cur]+1;
		dfs(to);
	}
}

void setit(int cur, int d)
{
	if(d > 2) return;
	is_ok[cur] = 1;
	for(int i = fir[cur], to; i; i = nex[i])
	{
		to = ver[i];
		setit(to, d+1);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 2, a; i <= n; ++i)
	{
		scanf("%d", &a);
		add_edge(i, a);
		add_edge(a, i);
	}
	dp[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; ++i)
	{
		add_dep(i, dp[i]);
		maxd = max(maxd, dp[i]);
	}
	for(int i = maxd; i; --i)
	{
		for(int j = pf[i], to; j; j = pn[i])
		{
			to = po[j];
			if(is_ok[to]) continue;
			if(fa[fa[to]]) setit(fa[fa[to]], 0);
			else setit(0, 0);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
