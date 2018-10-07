// Dinic
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 2e5+7;
const int INF = 0x3f3f3f3f;

int n, m, s, t, maxflow, d[Maxn];
int ver[Maxm], edge[Maxm], fir[Maxn], nex[Maxm], tot = 1;

inline void add_edge(int u, int v, int w)
{
	ver[++tot] = v; edge[tot] = w; nex[tot] = fir[u]; fir[u] = tot;
	ver[++tot] = u; edge[tot] = 0; nex[tot] = fir[v]; fir[v] = tot;
}

bool bfs()
{
    memset(d, 0, sizeof d);
	queue<int> q;
	q.push(s);
    d[s] = 1;
    int cur;
	while(q.size())
	{
        cur = q.front(); q.pop();
        for(int i = fir[cur], to; i; i = nex[i])
        {
            to = ver[i];
            if(d[to] || !edge[i]) continue;
            d[to] = d[cur]+1;
            if(to == t) return true;
            q.push(to);
        }
	}
	return false;
}

int dinic(int cur, int flow)
{
    if(cur == t) return flow;
    int rest = flow;
    for(int i = fir[cur], to, now; i; i = nex[i])
    {
        to = ver[i];
        if(d[to] != d[cur]+1 || !edge[i]) continue;
        now = dinic(to, min(rest, edge[i]));
        if(!now) d[to] = 0;
        else
        {
            edge[i] -= now;
            edge[i^1] += now;
            rest -= now;
        }
    }
    return flow - rest;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 0, u, v, w; i < m; ++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}
    int flow = 0;
	while(bfs())
        while((flow = dinic(s, INF)))
            maxflow += flow;
	printf("%d\n", maxflow);
	return 0;
}
