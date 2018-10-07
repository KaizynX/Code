#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 1507;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
/*   0
 * 1 O 3
 *   2
 */
int n, m, sx, sy;
bool ans;
bool a[Maxn][Maxn];
int vis[Maxn][Maxn][3];
// vis[x][y][0] is vis?
// vis[x][y][1] last time vis the value of x
// vis[x][y][2] last time vis the value of y

void dfs(int x, int y)
{
	if(ans) return;
	int xx = (x%n+n)%n, yy = (y%m+m)%m;
	if(vis[xx][yy][0] && (vis[xx][yy][1] != x || vis[xx][yy][2] != y))
	{
		ans = true; return;
	}
	vis[xx][yy][0] = 1; vis[xx][yy][1] = x; vis[xx][yy][2] = y;
	for(int d = 0, nex_x, nex_y; d < 4; ++d)
	{
		nex_x = x + dx[d]; nex_y = y + dy[d];
		xx = (nex_x%n+n)%n; yy = (nex_y%m+m)%m;
		if(!a[xx][yy]) continue;
		if(!vis[xx][yy] || vis[xx][yy][1] != nex_x || vis[xx][yy][2] != nex_y)
			dfs(nex_x, nex_y);
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		// read
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
			{
				char c; cin >> c;
				if(c == '#') a[i][j] = false;
				else if(c == '.') a[i][j] = true;
				else { sx = i; sy = j; a[i][j] = true; }
			}
		// init
		memset(vis, 0, sizeof vis);
		ans = false;
		dfs(sx, sy);
		puts((ans == true ? "Yes" : "No"));
	}
	return 0;
}
