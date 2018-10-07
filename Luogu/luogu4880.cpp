#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e5+7;
const int Maxm = 1e6+7;
const int INF = 0x7f7f7f7f;

int n, m, b, e, T;
int dis[Maxn];
int ver[Maxm], w[Maxm], fir[Maxn], nex[Maxm], tot;

struct Move
{
	int t, x;
	Move(){ t = x = 0; }
	bool operator < (const Move &c) const { return t < c.t; }
} a[Maxn];

template <typename T> inline void read(T &x)
{
	char c; T tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	x = c-'0';
	while((c=getchar()) >= '0' && c <= '9')
		x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}

inline void add_edge(int x, int y, int z)
{
	ver[++tot] = y; w[tot] = z; nex[tot] = fir[x]; fir[x] = tot;
}

inline void dijiska()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	pair<int, int> cur;
	memset(dis, 0x3f, sizeof dis);
	dis[b] = 0;
	q.push(make_pair(0, b));
	while(q.size())
	{
		cur = q.top(); q.pop();
		if(dis[cur.second] < cur.first) continue; // visited
		for(int i = fir[cur.second], to; i; i = nex[i])
		{
			to = ver[i];
			if(cur.first+w[i] >= dis[to]) continue;
			dis[to] = cur.first+w[i];
			q.push(make_pair(dis[to], to));
		}
	}
}

int main()
{
	read(n); read(m); read(b); read(e);
	for(int i = 1, x, y, z; i <= m; ++i)
	{
		read(x); read(y); read(z);
		add_edge(x, y, z);
		add_edge(y, x, z);
	}
	read(T);
	for(int i = 1; i <= T; ++i)
		read(a[i].t), read(a[i].x);
	sort(a+1, a+T+1);
	a[0].x = e;
	a[T+1].t = INF;
	dijiska();
	for(int i = 0; i <= T; ++i)
		if(dis[a[i].x] < a[i+1].t) // arrive before it leave
		{
			// ans = min(ans, max(dis[a[i].x], a[i].s));
			printf("%d\n", max(dis[a[i].x], a[i].t));
			break;
		}
	return 0;
}
