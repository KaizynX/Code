#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int Maxn = 2507;
const int dx[] = {-1,0,1,-1,1,-1,0,1};
const int dy[] = {-1,-1,-1,0,0,1,1,1};

int n;
int a[Maxn][Maxn];
bool vis[Maxn][Maxn];

inline void print()
{
	for(int i = 0; i <= n*2; ++i)
	{
		for(int j = 0, x, y; j <= n*2; ++j)
		{
			x = i > n ? n*2-i : i;
			y = j > n ? n*2-j : j;
			putchar(vis[x][y] ? '1' : ' ');
			putchar(' ');
		}
		putchar('\n');
	}
}

inline bool judge(int x, int y)
{
	int cnt = 0;
	for(int d = 0, nx, ny; d < 8; ++d)
	{
		nx = x+dx[d]; ny = y+dy[d];
		if(nx < 0 || nx > n || ny < 0 || ny > n) continue;
		if(vis[nx][ny]) ++cnt;
	}
	return cnt < 2;
}

void dfs(int x, int y)
{
	vis[x][y] = 1;
	if(x == n && y == 0) return;

	int rx = -1, ry;
	for(int d = 0, nx, ny; d < 8; ++d)
	{
		nx = x+dx[d]; ny = y+dy[d];
		if(nx < 0 || nx > n || ny < 0 || ny > n || vis[nx][ny]) continue;
		if((rx == -1 || a[nx][ny] < a[rx][ry]) && judge(nx, ny)) rx = nx, ry = ny;
	}
	dfs(rx, ry);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i)
		for(int j = 0, x, y; j <= n; ++j)
		{
			x = n-i, y = n-j;
			a[i][j] = abs(x*x+y*y-n*n);
		}
	dfs(0, n);
	print();
	return 0;
}
