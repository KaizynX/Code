#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e3+7;
const int Maxm = 1e4+7;
const int INF = 0x3f3f3f3f;

int n, m;
int a[Maxn][Maxn], dis[Maxn], vis[Maxn];

int main()
{
	memset(a, -1, sizeof a);
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v, c; i <= m; ++i)
	{
		scanf("%d%d%d", &u, &v, &c);
		a[u][v] = a[v][u] = c;
	}
	dis[1] = 0; vis[1] = 1;
	for(int i = 2; i <= n; ++i) dis[i] = a[1][i];
	for(int i = 1; i < n; ++i)
	{
		int mini = 0, mind = INF;
		for(int j = 1; j <= n; ++j)
		{
			if(!vis[j] && dis[j] != -1 && dis[j] < mind)
			{
				mini = j;
				mind = dis[j];
			}
		}
		vis[mini] = 1;
		for(int j = 1; j <= n; ++j)
		{
			if(!vis[j] && a[mini][j] != -1 && (dis[j] == -1 || dis[mini]+a[mini][j] < dis[j]))
				dis[j] = dis[mini]+a[mini][j];
		}
	}
	printf("%d\n", dis[n]);
	return 0;
}
