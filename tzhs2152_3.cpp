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
int a[Maxn][Maxn], v[Maxn][Maxn];
int now_x, now_y;
pair<int, int> q[Maxq];
int head, tail;
bool vis[Maxn][Maxn];

inline int dis(int x, int y)
{
	return abs(x - now_x) + abs(y - now_y);
}

inline int dfs(int x, int y)
{
	if(v[x][y] != 0x3f3f3f3f) return v[x][y];
	int nex_x, nex_y, res = 0x3f3f3f3f;
	for(int d = 0; d < 4; ++d)
	{
		nex_x = x + dx[d];
		nex_y = y + dy[d];
		if(nex_x < 1 || nex_x > n || nex_y < 1 || nex_y > m) continue;
		if(a[nex_x][nex_y])
		{
			res = 0;
			break;
		}
		if(vis[nex_x][nex_y]) continue;
		vis[nex_x][nex_y] = true;
		res = min(res, dfs(nex_x, nex_y));
	}
#ifdef DEBUG
	printf("%d %d %d\n", x, y, res+1);
#endif
	return v[x][y] = res+1;
}

int judge(int ans)
{
	head = tail = 0;
	memset(vis, 0, sizeof vis);
	q[++tail] = make_pair(1, 1);
	vis[1][1] = true;
	pair<int, int> cur;
	int x, y, nex_x, nex_y;
	while(head < tail)
	{
		cur = q[++head];
		x = cur.first; y = cur.second;
		for(int d = 0; d < 4; ++d)
		{
			nex_x = x + dx[d];
			nex_y = y + dy[d];
			if(nex_x == n && nex_y == m) return true;
			if(nex_x < 1 || nex_x > n || nex_y < 1 || nex_y > m) continue;
			if(a[nex_x][nex_y] || v[nex_x][nex_y] < ans || vis[nex_x][nex_y]) continue;
			vis[nex_x][nex_y] = true;
			q[++tail] = make_pair(nex_x, nex_y);
		}
	}
	return false;
}

int main()
{
	memset(v, 0x3f, sizeof v);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j]) v[i][j] = 0;
		}
	if(a[1][1] || a[n][m])
	{
		puts("0");
		return 0;
	}
	// init v
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(!a[i][j] && !vis[i][j])
			{
				memset(vis, 0, sizeof vis);	
				dfs(i, j);
			}
#ifdef DEBUG
	putchar('\n');
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			printf("%d ", v[i][j]);
		putchar('\n');
	}
#endif
	int l = min(v[1][1], v[n][m]), r = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			r = max(r, v[i][j]);
	while(l < r)
	{
		int mid = (l+r+1) >> 1;
		if(judge(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}


