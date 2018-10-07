#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define DEBUG

using namespace std;

const int Maxn = 1e3 + 7;
const int Maxq = 1e6;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m;
// f[x][y] reach (x, y) the biggest min threat
int a[Maxn][Maxn], v[Maxn][Maxn], f[Maxn][Maxn];
int now_x, now_y;
pair<int, int> q[Maxq];
int head, tail;
bool vis[Maxn][Maxn];

inline int dis(int x, int y)
{
	return abs(x - now_x) + abs(y - now_y);
}

inline void bfs(int x, int y)
{
	int nex_x, nex_y;
	head = tail = 0;
	q[++tail] = make_pair(x, y);
	v[x][y] = 0;
	pair<int, int> cur;
	while(head < tail)
	{
		cur = q[++head];
		x = cur.first; y = cur.second;
		for(int d = 0; d < 4; ++d)
		{
			nex_x = x + dx[d];
			nex_y = y + dy[d];
			if(nex_x < 1 || nex_x > n || nex_y < 1 || nex_y > m) continue;
			if(a[nex_x][nex_y] || v[nex_x][nex_y] <= v[x][y]) continue;
			v[nex_x][nex_y] = dis(nex_x, nex_y);
			q[++tail] = make_pair(nex_x, nex_y);
		}
	}
}

int dfs(int x, int y)
{
	if(x == 1 && y == 1) return v[x][y];
	if(f[x][y] != -1) return f[x][y];
	int nex_x, nex_y, res = -1;
	for(int d = 0; d < 4; ++d)
	{
		nex_x = x + dx[d];
		nex_y = y + dy[d];
		if(nex_x < 1 || nex_x > n || nex_y < 1 || nex_y > m) continue;
		if(a[nex_x][nex_y] || vis[nex_x][nex_y]) continue;
		vis[nex_x][nex_y] = true;
		res = max(res, dfs(nex_x, nex_y));
		vis[nex_x][nex_y] = false;
	}
	// can't reach (1, 1)
	if(res == -1) return -1;
	f[x][y] = min(res, v[x][y]);
#ifdef DEBUG
	printf("%d %d %d\n", x, y, f[x][y]);
#endif
	return f[x][y];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	if(a[1][1] || a[n][m])
	{
		puts("0");
		return 0;
	}
	// init v
	memset(v, 0x3f, sizeof v);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(a[i][j])
			{
				now_x = i;
				now_y = j;
				bfs(i, j);
			}
	memset(f, -1, sizeof f);
#ifdef DEBUG
	putchar('\n');
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			printf("%d ", v[i][j]);
		putchar('\n');
	}
#endif
	vis[n][m] = true;
	printf("%d\n", dfs(n, m));
	return 0;
}
