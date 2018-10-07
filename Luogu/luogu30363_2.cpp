#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int Maxn = 1e3 + 7;
const int INF = 0x3f3f3f3f;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, k;
int h[Maxn][Maxn];
int f[Maxn][Maxn];

inline bool judge_hill(int x, int y)
{
	for(int d = 0, nex_x, nex_y; d < 4; ++d)
	{
		nex_x = x + dx[d];
		nex_y = y + dy[d];
		if(nex_x < 1 || nex_x > n || nex_y < 1 || nex_y > m) continue;
		if(h[x][y] <= h[nex_x][nex_y]) return false;
	}
	return true;
}

inline void read(int &x)
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	x = c - '0';
	while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
}

int main()
{
	memset(f, 0x3f, sizeof f);
	// scanf("%d%d%d", &n, &m, &k);
	read(n); read(m); read(k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			// scanf("%d", &h[i][j]);
			read(h[i][j]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(judge_hill(i, j)) f[i][j] = 0;
			else f[i][j] = min(f[i-1][j], f[i-1][j-1]) + 1;
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j < m; ++j)
			f[i][j] = min(f[i][j], f[i-1][j+1] + 1);
	for(int i = 1, x, y; i <= k; ++i)
	{
		// scanf("%d%d", &x, &y);
		read(x); read(y);
		if(f[x][y] >= INF) puts("Pool Babingbaboom!");
		else printf("%d\n", f[x][y]);
	}
	return 0;
}
