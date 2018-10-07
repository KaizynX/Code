#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 16007;
const int INF = 0xffffffff;

int n, ans = INF, a[Maxn];
int tot, ver[Maxn<<1], fir[Maxn], nex[Maxn<<1];
int du[Maxn];

int dfs(int cur, int fa)
{
	int res = a[cur];
	for(int i = fir[cur]; i; i = nex[i])
	{
		if(ver[i] == fa) continue;
		res += dfs(ver[i], cur);
	}
	ans = max(ans, res);
#ifdef DEBUG
	printf("%d %d\n", cur, res);
#endif
	return max(0, res);
}

inline void add(int u, int v)
{
	ver[++tot] = v;
	nex[tot] = fir[u];
	fir[u] = tot;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		ans = max(ans, a[i]);
	}
	for(int i = 1, u, v; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
		du[u]++; du[v]++;
	}
	for(int i = 1; i <= n; ++i)
	{
		if(du[i] == 1)
		{
			dfs(i, 0);
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
