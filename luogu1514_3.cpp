#include <iostream>
#include <cstdio>
#include <bitset>
// #define DEBUG

using namespace std;

#ifndef DEBUG
const int Maxn = 507;
#endif
#ifdef DEBUG
const int Maxn = 10;
#endif
const int INF = 1e6 + 9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, ans;
int h[Maxn][Maxn];
pair<int, int> q[Maxn*Maxn];
int head, tail;
int vis[Maxn], useless[Maxn];

struct P
{
	int l, r;

	P(){ l = INF; r = 0; }

	bool operator < (const P &b) const
	{
		return l < b.l;
	}
} p[Maxn];

inline void init(int); // init the pool cur can reach

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &h[i][j]);
	// set the edge
	for(int i = 0; i <= max(n,m)+1; ++i)
		h[i][0] = h[0][i] = h[n+1][i] = h[i][m+1] = INF;
	// init && judge wether there is a approach
	for(int i = 1; i <= m; ++i) 
	{
		init(i);
#ifdef DEBUG
		printf("%d %d %d\n", i, p[i].l, p[i].r);
#endif
	}
	int cnt = 0;
	for(int i = 1; i <= m; ++i)
		if(!vis[i]) ++cnt;
	if(cnt) // can't
	{
		printf("0\n%d\n", cnt);
		return 0;
	}

	// sort(p+1, p+1+m);
	// it's sorted
	/* WRONG
	for(int i = 1, lastl = 0, lastr = 0; i <= m; ++i)
	{
		if(useless[i]) continue;
		if(lastl >= p[i].l) lastr = max(lastr, p[i].r);
		else if(lastl < p[i].l && lastr >= p[i].r) continue;
		else if(lastl < p[i].l && lastr < p[i].r)
		{
			++ans;
			lastl = lastr;
			lastr = p[i].r;
		}
	} */
	int lastl = 1, maxr;
	while(lastl <= m)
	{
		maxr = 0;
		for(int i = 1; i <= m; ++i)
			if(p[i].l <= lastl)
				maxr = max(maxr, p[i].r);
		++ans;
		lastl = maxr + 1;
	}
	printf("1\n%d\n", ans);
	return 0;
}

inline void init(int now)
{
	if(useless[now]) return;
	head = tail = 0;
	q[++tail] = make_pair(1, now);
	int nex_x, nex_y, now_h;
	pair<int, int> cur;
	while(head < tail)
	{
		cur = q[++head];
		for(int d = 0; d < 4; ++d)
		{
			nex_x = cur.first + dx[d];
			nex_y = cur.second + dy[d];
			now_h = h[cur.first][cur.second];
			if(h[nex_x][nex_y] >= now_h) continue;

			if(nex_x == n) 
			{
				vis[nex_y] = true;
				p[now].l = min(p[now].l, nex_y);
				p[now].r = max(p[now].r, nex_y);
			}
			if(nex_x == 1) 
			{
				useless[nex_y] = true;
				if(nex_y < now)
				{
					p[now].l = min(p[now].l, p[nex_y].l);
					p[now].r = max(p[now].r, p[nex_y].r);
				}
			}
			if(!(nex_x == 1 && now > nex_y)) q[++tail] = make_pair(nex_x, nex_y);
		}
	}
}
