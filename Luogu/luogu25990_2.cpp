#include <iostream>
#include <cstdio>
#include <cstring>
#define DEBUG

using namespace std;

const int Maxn = 2e5 + 7;
const int Maxm = 5e5 + 7;

int n, m;
int k[Maxn], vis[Maxn];
int u[Maxm], v[Maxm], fir[Maxm], nex[Maxm];
pair<int, int> ans, mem[Maxn];

pair<int, int> dfs(int cur, pair<int, int> now)
{
#ifdef DEBUG
	printf("%d %d %d %d\n", cur, now.first, now.second, vis[cur]);
#endif
	if(vis[cur] && now <= mem[cur]) return mem[cur];
	else mem[cur] = now;

	if(!vis[cur])
	{
		now.first += k[cur];
		now.second = max(now.second, k[cur]);
		vis[cur] = true;
		mem[cur] = now;
	}

	for(int i = fir[cur]; i; i = nex[i])
		mem[cur] = max(mem[cur], dfs(v[i], now));

	return mem[cur];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", k+i);
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d%d", u+i, v+i);
		nex[i] = fir[u[i]];
		fir[u[i]] = i;
	}
	
	for(int i = 1; i <= n; ++i)
	{
		// memset(vis, 0, sizeof vis);
		if(!vis[i]) ans = max(ans, dfs(i, make_pair(0, 0)) );
	}

	printf("%d %d\n", ans.first, ans.second);
	return 0;
}

