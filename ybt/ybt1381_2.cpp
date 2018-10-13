#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e3+7;
const int Maxm = 2e4+7;
const int INF = 0x3f3f3f3f;

int n, m;
int ver[Maxm], w[Maxm], fir[Maxn], nex[Maxm], tot;
int dis[Maxn];

inline void add(int u, int v, int c)
{
	ver[++tot] = v; w[tot] = c; nex[tot] = fir[u]; fir[u] = tot;
}

inline void Dijiskra()
{
	memset(dis, 0x3f, sizeof dis);
	typedef pair<int, int> _pair;
	priority_queue<_pair, vector<_pair>, greater<_pair> > q;
	q.push(make_pair(0, 1));
	dis[1] = 0;
	while(q.size())
	{
		_pair cur = q.top();
		q.pop();
		int now = cur.second;
		if(cur.first > dis[now]) continue;
		for(int i = fir[now], to, tmp; i; i = nex[i])
		{
			to = ver[i];
			tmp = cur.first+w[i];
			if(dis[to] > tmp)
			{
				dis[to] = tmp;
				q.push(make_pair(tmp, to));
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v, c; i <= m; ++i)
	{
		scanf("%d%d%d", &u, &v, &c);
		add(u, v, c); add(v, u, c);
	}
	Dijiskra();
	printf("%d\n", dis[n] == INF ? -1 : dis[n]);
	return 0;
}
