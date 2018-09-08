#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 20;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m;
int a[Maxn][Maxn];
int flip[Maxn][Maxn];
int ans = INF, res[Maxn][Maxn];

inline int query(int x, int y)
{
	int cnt = a[x][y]+flip[x][y];
	for(int d = 0; d < 4; ++d)
	{
		int nx = x+dx[d], ny = y+dy[d];
		if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
		cnt += flip[nx][ny];
	}
	return cnt;
}

inline int check()
{
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(query(i-1, j)&1) flip[i][j] = 1;
	for(int i = 1; i <= m; ++i)
		if(query(n, i)&1) return -1;

	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cnt += flip[i][j];
	return cnt;
}

int main()
{
	while(scanf("%d%d", &n, &m))
	{
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				scanf("%d", &a[i][j]);
		ans = INF;
		for(int i = 0; i < 1<<m; ++i)
		{
			memset(flip, 0, sizeof flip);
			int cur = 0, tmp = i;
			while(tmp)
			{
				flip[1][++cur] = tmp&1;
				tmp >>= 1;
			}
			tmp = check();
			if(tmp == -1) continue;
			if(tmp < ans)
			{
				ans = tmp;
				memcpy(res, flip, sizeof flip);
			}
		}
		if(ans == INF)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j < m; ++j)
				printf("%d ", res[i][j]);
			printf("%d\n", res[i][m]);
		}
	}
	return 0;
}
