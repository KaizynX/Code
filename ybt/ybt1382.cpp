#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int Maxm = 1e6+7;
const int INF = 0x3f3f3f3f;

int n, m;
int ver[Maxm], w[Maxm], fir[Maxn], nex[Maxm], tot;
int dis[Maxn];
int q[Maxm], head, tail;

inline void add(int u, int v, int c)
{
	ver[++tot] = v; w[tot] = c; nex[tot] = fir[u]; fir[u] = tot;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v, c; i <= m; ++i)
	{
		scanf("%d%d%d", &u, &v, &c);
		add(u, v, c); add(v, u, c);
	}
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	q[++tail] = 1;
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
	printf("%d\n", dis[n]);
	return 0;
}
