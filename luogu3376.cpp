// Edmonds-Karp
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 2e5+7;
const int INF = 0x3f3f3f3f;

int n, m, s, t, maxflow;
int ver[Maxm], edge[Maxm], fir[Maxn], nex[Maxm], tot = 1;
int incf[Maxn], pre[Maxn], v[Maxn];

inline void add_edge(int u, int v, int w)
{
	ver[++tot] = v; edge[tot] = w; nex[tot] = fir[u]; fir[u] = tot;
	ver[++tot] = u; edge[tot] = 0; nex[tot] = fir[v]; fir[v] = tot;
}

bool bfs()
{
    memset(v, 0, sizeof v);
	queue<int> q;
	q.push(s);
    v[s] = true;
	incf[s] = INF;
	while(q.size())
	{
		int cur = q.front();
		q.pop();
		for(int i = fir[cur], to; i; i = nex[i])
		{
			to = ver[i];
			if(!edge[i] || v[to]) continue;
			incf[to] = min(incf[cur], edge[i]);
			pre[to] = i;
			if(to == t) return true;
			q.push(to);
            v[to] = true;
		}
	}
	return false;
}

void update()
{
	int cur = t, e;
	while(cur != s)
	{
		e = pre[cur];
		edge[e] -= incf[t];
		edge[e^1] += incf[t];
		cur = ver[e^1];
	}
	maxflow += incf[t];
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 0, u, v, w; i < m; ++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}
	while(bfs()) update();
	printf("%d\n", maxflow);
	return 0;
}
