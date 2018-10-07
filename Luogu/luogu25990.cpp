#include <iostream>
#include <cstdio>
#define DEBUG

using namespace std;

const int Maxn = 2e5 + 7;
const int Maxm = 5e5 + 7;

int n, m;
int k[Maxn], vis[Maxn], cnt[Maxn];
int u[Maxm], v[Maxm], fir[Maxm], nex[Maxm];
pair<int, int> ans;

pair<int, int> dfs(int cur, pair<int, int> now)
{
#ifdef DEBUG
	printf("%d %d %d\n", cur, vis[cur], cnt[cur]);
#endif
	if(++vis[cur] > cnt[cur] && vis[cur] != 1)
	{
		--vis[cur];
		return now;
	}

	if(vis[cur] == 1)
	{
		now.first += k[cur];
		now.second = max(now.second, k[cur]);
	}

#ifdef DEBUG
	printf("now: %d %d\n", now.first, now.second);
#endif
	pair<int, int> res = now;
	for(int i = fir[cur]; i; i = nex[i])
		res = max(res, dfs(v[i], now));

#ifdef DEBUG
	printf("res: %d %d %d\n", cur, res.first, res.second);
#endif
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", k+i);
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d%d", u+i, v+i);
		++cnt[u[i]];
		nex[i] = fir[u[i]];
		fir[u[i]] = i;
	}
	
	for(int i = 1; i <= n; ++i)
		if(cnt[i]) ans = max(ans, dfs(i, make_pair(0, 0)) );

	printf("%d %d\n", ans.first, ans.second);
	return 0;
}
