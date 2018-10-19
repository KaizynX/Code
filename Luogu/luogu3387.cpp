#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 1e5+7;

int n, m, ans;
int ver[Maxm], fir[Maxn], nex[Maxm], tot;
int a[Maxn], w[Maxn], du[Maxn], dfn[Maxn], low[Maxn], col[Maxn], vis[Maxn], _col, _dfn;
int q[Maxn], head, tail;
int f[Maxn];
int cver[Maxm], cfir[Maxn], cnex[Maxm], ctot;

inline void add_edge(int u, int v)
{
	ver[++tot] = v; nex[tot] = fir[u]; fir[u] = tot;
}

inline void add_cedge(int u, int v)
{
	cver[++ctot] = v; cnex[ctot] = cfir[u]; cfir[u] = ctot;
}

void tarjan(int cur)
{
	dfn[cur] = low[cur] = ++_dfn;
	q[++tail] = cur;
	vis[cur] = 1;
	
	for(int i = fir[cur], to; i; i = nex[i])
	{
		to = ver[i];
		if(!dfn[to])
		{
			tarjan(to);
			low[cur] = min(low[cur], low[to]);
		}
		else if(vis[to])
			low[cur] = min(low[cur], dfn[to]);
	}

	if(dfn[cur] == low[cur])
	{
		int sum = 0;
		_col++;
		do
		{
			col[q[tail]] = _col;
			vis[q[tail]] = 0;
			sum += a[q[tail]];
		} while(q[tail--] != cur);
		w[_col] = sum;
	}
}

inline void DAGdp()
{
	for(int i = 1; i <= n; ++i)
		for(int k = fir[i], to; k; k = nex[k])
		{
			to = ver[k];
			if(col[i] != col[to])
			{
				du[col[to]]++;
				add_cedge(col[i], col[to]);
			}
		}

	head = tail = 0;
	for(int i = 1; i <= _col; ++i)
	{
		if(!du[i])
		{
			q[++tail] = i;
			f[i] = w[i];
			ans = max(ans, f[i]);
		}
	}
	while(head < tail)
	{
		int cur = q[++head];
		for(int k = cfir[cur], to; k; k = cnex[k])
		{
			to = cver[k];
			if(--du[to] == 0)
			{
				q[++tail] = to;
				f[to] = max(f[to], f[cur]+w[to]);
				ans = max(ans, f[to]);
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	for(int i = 1, u, v; i <= m; ++i)
	{
		scanf("%d%d", &u, &v);
		add_edge(u, v);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);
	DAGdp();
	printf("%d\n", ans);
	return 0;
}
