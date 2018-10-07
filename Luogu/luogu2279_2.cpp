#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e3+7;

int n, ans, maxd, fa[Maxn], dp[Maxn], is_ok[Maxn];
vector<int> e[Maxn], d[Maxn];

void build_tree(int cur)
{
	for(int i = 0, to; i < e[cur].size(); ++i)
	{
		to = e[cur][i];
		if(dp[to]) continue;
		fa[to] = cur;
		dp[to] = dp[cur]+1;
		maxd = max(maxd, dp[to]);
		d[dp[to]].push_back(to);
		build_tree(to);
	}
}

void setit(int cur, int d)
{
	if(d > 2) return;
	is_ok[cur] = 1;
	for(int i = 0, to; i < e[cur].size(); ++i)
	{
		to = e[cur][i];
		setit(to, d+1);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 2, a; i <= n; ++i)
	{
		scanf("%d", &a);
		e[i].push_back(a);
		e[a].push_back(i);
	}
	dp[1] = 1;
	d[1].push_back(1);
	build_tree(1);
	for(int i = maxd; i; --i)
	{
		for(int j = 0, to; j < d[i].size(); ++j)
		{
			to = d[i][j];
			if(is_ok[to]) continue;
			if(fa[fa[to]]) setit(fa[fa[to]], 0);
			else setit(0, 0);
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
