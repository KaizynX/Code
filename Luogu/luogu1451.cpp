#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, ans;
int a[Maxn][Maxn], vis[Maxn][Maxn];

void dfs(int x, int y)
{
	vis[x][y] = 1;
	for(int i = 0, nx, ny; i < 4; ++i)
	{
		nx = x+dx[i]; ny = y+dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > m || vis[nx][ny] || a[nx][ny] == 0) continue;
		dfs(nx, ny);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			char c;
			while(!isdigit((c=getchar())));
			a[i][j] = c-'0';
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(a[i][j] && !vis[i][j])
			{
				dfs(i, j);
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
