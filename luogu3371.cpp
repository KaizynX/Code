#include <queue>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 5e5+7;
const int INF = 0x7f7f7f7f;

int n, m, S, dis[Maxn];
int ver[Maxm], w[Maxm], fir[Maxn], nex[Maxm];

inline void Dijiska()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(dis, 0x7f, sizeof dis);
	dis[S] = 0;
	q.push(make_pair(0, S));
	pair<int, int> cur;
	while(q.size())
	{
		cur = q.top(); q.pop();
		if(dis[cur.second] < cur.first) continue;
		for(int i = fir[cur.second], to, now; i; i = nex[i])
		{
			to = ver[i];
			now = cur.first+w[i];
			if(now >= dis[to]) continue;
			dis[to] = now;
			q.push(make_pair(now, to));
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &S);
	for(int i = 1, u, v; i <= m; ++i)
	{
		scanf("%d%d%d", &u, &v, w+i);
		ver[i] = v;
		nex[i] = fir[u];
		fir[u] = i;
	}
	Dijiska();
	for(int i = 1; i < n; ++i)
		printf("%d ", dis[i] == INF ? INT_MAX : dis[i]);
	printf("%d\n", dis[n] == INF ? INT_MAX : dis[n]);
	return 0;
}
