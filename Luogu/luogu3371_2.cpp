#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 5e5+7;
const int INF = 0x3f3f3f3f;

int n, m, S;
int ver[Maxm], w[Maxm], fir[Maxn], nex[Maxm], tot;
int dis[Maxn];
int q[Maxm], head, tail;

inline void add(int u, int v, int c)
{
	ver[++tot] = v; w[tot] = c; nex[tot] = fir[u]; fir[u] = tot;
}

int main()
{
	scanf("%d%d%d", &n, &m, &S);
	for(int i = 1, u, v, c; i <= m; ++i)
	{
		scanf("%d%d%d", &u, &v, &c);
		add(u, v, c);
	}
	fill(dis+1, dis+n+1, INT_MAX);
	dis[S] = 0;
	q[++tail] = S;
	while(head < tail)
	{
		int cur = q[++head];
		for(int i = fir[cur], to, tmp; i; i = nex[i])
		{
			to = ver[i];
			tmp = dis[cur]+w[i];
			if(tmp >= dis[to]) continue;
			dis[to] = tmp;
			q[++tail] = to;
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%d ", dis[i]);
	return 0;
}
