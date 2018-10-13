#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, ans = INF;
int a[Maxn][Maxn], vis[Maxn][Maxn];
int sx, sy, ex, ey;

void dfs(int x, int y, int step)
{
	if(x == ex && y == ey)
	{
		ans = min(ans, step);
		return;
	}
	if(step >= ans) return;
	vis[x][y] = 1;
	for(int i = 0, nx, ny; i < 4; ++i)
	{
		nx = x+dx[i]; ny = y+dy[i];
		if(!a[nx][ny] || vis[nx][ny]) continue;
		dfs(nx, ny, step+1);
	}
	vis[x][y] = 0;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			char c;
			cin >> c;
			if(c == 'S') sx = i, sy = j, a[i][j] = 1;
			else if(c == 'T') ex = i, ey = j, a[i][j] = 1;
			else if(c == '.') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	dfs(sx, sy, 0);
	cout << ans << endl;
	return 0;
}
