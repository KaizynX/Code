#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
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
int vis[Maxn][Maxn], useless[Maxn];
int l[Maxn][Maxn], r[Maxn][Maxn];

inline void init(int, int); // init the pool cur can reach

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &h[i][j]);
	// set the edge
	for(int i = 0; i <= max(n,m)+1; ++i)
		h[i][0] = h[0][i] = h[n+1][i] = h[i][m+1] = INF;
	// init l & r
	memset(l, 0x3f, sizeof l);
	// memset(r, 0, sizeof r);
	for(int i = 1; i <= m; ++i)
		l[n][i] = r[n][i] = i;
	// init && judge wether there is a approach
	for(int i = 1; i <= m; ++i) 
	{
		if(useless[i]) continue;
		init(1, i);
#ifdef DEBUG
		printf("%d %d %d\n", i, l[1][i], r[1][i]);
#endif
	}
	int cnt = 0;
	for(int i = 1; i <= m; ++i)
		if(!vis[n][i]) ++cnt;
	if(cnt) // can't
	{
		printf("0\n%d\n", cnt);
		return 0;
	}

	// sort(p+1, p+1+m);
	// it's sorted
	int lastl = 1, maxr;
	while(lastl <= m)
	{
		maxr = 0;
		for(int i = 1; i <= m; ++i)
			if(l[1][i] <= lastl)
				maxr = max(maxr, r[1][i]);
		++ans;
		lastl = maxr + 1;
	}
	printf("1\n%d\n", ans);
	return 0;
}

// memory search
void init(int x, int y)
{
	vis[x][y] = true;
	for(int d = 0, nex_x, nex_y; d < 4; ++d)
	{
		nex_x = x + dx[d];
		nex_y = y + dy[d];
		if(h[nex_x][nex_y] >= h[x][y]) continue;
		if(nex_x == 1) useless[nex_y] = 1;
		if(!vis[nex_x][nex_y]) init(nex_x, nex_y);
		l[x][y] = min(l[x][y], l[nex_x][nex_y]);
		r[x][y] = max(r[x][y], r[nex_x][nex_y]);
	}
}
