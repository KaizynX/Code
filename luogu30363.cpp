#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 1e3 + 7;
const int INF = 0x3f3f3f3f;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, k;
int h[Maxn][Maxn];
bool is_hill[Maxn][Maxn];
struct Hill
{
	int x, y, dis;
	Hill(int x = 0, int y = 0, int dis = INF) : x(x), y(y), dis(dis) {}
	bool operator < (const Hill &b) const
	{
		return dis < b.dis;
	}
	bool operator == (const Hill &b) const
	{
		return x == b.x && y == b.y && dis == b.dis;
	}
} hill[Maxn][Maxn];

inline bool judge_hill(int x, int y)
{
	for(int d = 0, nex_x, nex_y; d < 4; ++d)
	{
		nex_x = x + dx[d];
		nex_y = y + dy[d];
		if(nex_x < 1 || nex_x > n || nex_y < 1 || nex_y > m) continue;
		if(h[x][y] < h[nex_x][nex_y]) return false;
	}
	return true;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &h[i][j]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			is_hill[i][j] = judge_hill(i, j);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			if(is_hill[i][j]) 
			{
				hill[i][j] = Hill(i, j, 0);
				continue;
			}
			hill[i][j] = min(hill[i-1][j], hill[i-1][j-1]);
			hill[i][j].dis ++;
		}
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j < m; ++j)
		{
			Hill tmp = hill[i-1][j+1];
			tmp.dis++;
			hill[i][j] = min(hill[i][j], tmp);
		}
	for(int i = 1, x, y; i <= k; ++i)
	{
		scanf("%d%d", &x, &y);
		if(hill[x][y].dis >= INF) puts("Pool Babingbaboom!");
		else printf("%d\n", hill[x][y].dis);
	}
	return 0;
}
