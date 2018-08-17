// Ôö¹ãÂ·
#include <queue>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 2e5+7;
const int INF = 0x3f3f3f3f;

int n, m, s, t, maxflow;
int ver[Maxm], edge[Maxm], fir[Maxn], nex[Maxm], tot = -1;
int infc[Maxn], pre[Maxn];

inline void add_edge(int u, int v, int w)
{
	ver[++tot] = v; edge[tot] = w; nex[tot] = fir[u]; fir[u] = tot;
	ver[++tot] = u; edge[tot] = 0; nex[tot] = fir[v]; fir[v] = tot;
}

bool bfs()
{
	queue<int> q;
	q.push(s);
	infc[s] = INF;
	while(q.size())
	{
		int cur = q.front();
		q.pop();
		for(int i = fir[cur], to; i; i = nex[i])
		{
			to = ver[i];
			if(edge[to])
			{
				infc[to] = min(infc[cur], edge[i]);
				pre[to] = i;
				q.push(to);
				if(to == t) return true;
			}
		}
	}
	return false;
}

void tarjan()
{
	int cur = t, e;
	while(cur != s)
	{
		e = pre[e];
		edge[e] -= infc[t];
		edge[e^1] += infc[t];
		cur = ver[e^1];
	}
	maxflow += infc[t];
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1, u, v, w; i <= n; ++i)
	{
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}
	while(bfs()) tarjan();
	printf("%d\n", maxflow);
	return 0;
}
