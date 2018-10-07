#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int Maxn = 107;

int n, k, s, g;
int m[Maxn][Maxn];
bool vis[Maxn];
queue<pair<int, int> > q;

int main()
{
	scanf("%d%d%d%d", &n, &k, &s, &g);
	if(s == g)
	{
		puts("0");
		return 0;
	}
	for(int i = 0, u, v; i < k; ++i)
	{
		scanf("%d%d", &u, &v);
		m[u][v] = m[v][u] = 1;
	}
	// bfs
	q.push(make_pair(s, 0));
	vis[s] = true;
	pair<int, int> cur;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		for(int i = 1; i <= n; ++i)
		{
			if(vis[i] || !m[cur.first][i]) continue;
			if(i == g)
			{
				printf("%d\n", cur.second);
				return 0;
			}
			vis[i] = true;
			q.push(make_pair(i, cur.second+1));
		}
	}
	puts("-1");
	return 0;
}
