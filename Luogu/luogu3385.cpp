#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e3+7;
const int Maxm = 6e3+7;
const int INF = 0x3f3f3f3f;

int T, n, m;
int ver[Maxm], w[Maxm], fir[Maxn], nex[Maxm], tot;
int q[Maxn], head, tail;
int vis[Maxn], cnt[Maxn], dis[Maxn];

inline void init()
{
	tot = 0;
	memset(fir, 0, sizeof(int)*(n+1));
	memset(vis, 0, sizeof(int)*(n+1));
	memset(cnt, 0, sizeof(int)*(n+1));
	memset(dis, 0x3f, sizeof(int)*(n+1));
	head = tail = 0;
}

inline void add_edge(int u, int v, int c)
{
	ver[++tot] = v; w[tot] = c; nex[tot] = fir[u]; fir[u] = tot;
}

inline bool SPFA()
{
	q[++tail] = 1;
	vis[1] = 1;
	cnt[1] = 1;
	dis[1] = 0;

	while(head < tail)
	{
		int cur = q[(++head)%Maxn];
		vis[cur] = 0;
		for(int i = fir[cur], to; i; i = nex[i])
		{
			to = ver[i];
			if(dis[cur]+w[i] < dis[to])
			{
				dis[to] = dis[cur]+w[i];
				if(!vis[to])
				{
					q[(++tail)%Maxn] = to;
					vis[to] = 1;
					if(++cnt[to] > n) return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		init();
		for(int i = 1, a, b, c; i <= m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			add_edge(a, b, c);
			if(c >= 0) add_edge(b, a, c);
		}
		puts(SPFA() ? "YE5" : "N0");
	}
	return 0;
}
