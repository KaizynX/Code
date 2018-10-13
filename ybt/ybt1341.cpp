#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;

int n, m;
int du[Maxn], a[Maxn][Maxn];
int res[Maxn], cnt;

void dfs(int cur)
{
	for(int i = 1; i <= n; ++i)
		if(a[cur][i])
		{
			a[cur][i] = a[i][cur] = 0;
			dfs(i);
		}
	res[++cnt] = cur;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v; i <= m; ++i)
	{
		scanf("%d%d", &u, &v);
		a[u][v] = a[v][u] = 1;
		du[u]++; du[v]++;
	}
	int sta = 1;
	for(int i = 1; i <= n; ++i)
		if(du[i]&1) sta = i;
	dfs(sta);
	for(int i = 1; i <= cnt; ++i)
		cout << res[i] << " ";
	return 0;
}
