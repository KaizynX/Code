#include <bits/stdc++.h>

using namespace std;

const int Maxn = 807;
const int INF = 0x3f3f3f3f;

int n, m, w, t[3], ans = -1;
int dw[Maxn], dt[Maxn], vis[Maxn];
typedef pair<int, int> _pair;
vector<_pair> e[Maxn];

struct Node
{
	int dis, id;
	bool operator < (const Node &b) const { return dis < b.dis; }
} dd[Maxn];

template <typename T> inline void read(T &);

inline void dijiskra(int S, int *dis)
{
	memset(vis, 0, sizeof vis);
	priority_queue<_pair> q;
	dis[S] = INF;
	vis[S] = 1;
	q.push(make_pair(dis[S], S));
	while(q.size())
	{
		_pair cur = q.top();
		q.pop();
		int now = cur.second;
		for(int i = 0, to; i < e[now].size(); ++i)
		{
			to = e[now][i].second;
			if(vis[to]) continue;
			if(dis[now]+e[now][i].first > dis[to])
			{
				dis[to] = dis[now]+e[now][i].first;
				q.push(make_pair(dis[to], to));
				vis[to] = 1;
			}
		}
	}
}

int main()
{
	read(n); read(m);
	for(int i = 1, u, v, c; i <= m; ++i)
	{
		read(u); read(v); read(c);
		e[u].push_back(make_pair(c, v));
	}
	read(w);
	for(int i = 0; i < 3; ++i) read(t[i]);

	memset(dw, -1, sizeof dw);
	dijiskra(w, dw);
	memset(dt, -1, sizeof dt);
	for(int i = 0; i < 3; ++i)
		dijiskra(t[i], dt);
	for(int i = 1; i <= n; ++i)
	{
		dd[i].dis = dt[i];
		dd[i].id = i;
	}
	sort(dd+1, dd+n+1);

	for(int i = 1; i <= n; ++i)
	{
		int now = dd[i].id, flag = 0;
		if(now == w) continue;
		for(int j = 0; j < 3; ++j)
			if(now == t[j]) flag = 1;
		if(flag) continue;
		// first, THREE can see hardest
		if(ans != -1 && dt[now] > dt[ans]) break;
		// EARTH can see
		if(dw[now] == -1) continue;
		// EARTH can see easilest && id smallest
		if(ans == -1 || dw[now] > dw[ans] || (dw[now] == dw[ans] && now < ans))
			ans = now;
	}
	printf("%d\n", ans);
	return 0;
}

template <typename T> inline void read(T &x)
{
	char c;
	while(!isdigit((c=getchar())));
	x = c-'0';
	while(isdigit((c=getchar())))
		x = (x<<1)+(x<<3) + c-'0';
}
