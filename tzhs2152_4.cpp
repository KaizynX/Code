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

inline void bfs()
{
	int nex_x, nex_y, x, y;
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
			if(v[nex_x][nex_y] == -1 || v[nex_x][nex_y] > v[x][y]+1)
            {
			    v[nex_x][nex_y] = v[x][y] + 1;
			    q[++tail] = make_pair(nex_x, nex_y);
            }
		}
	}
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
    memset(v, -1, sizeof v);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
        {
			scanf("%d", &a[i][j]);
            if(a[i][j])
            {
                q[++tail] = make_pair(i, j);
                v[i][j] = 0;
            }
        }
	if(a[1][1] || a[n][m])
	{
		puts("0");
		return 0;
	}
    bfs();

#ifdef DEBUG
	putchar('\n');
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			printf("%d ", v[i][j]);
		putchar('\n');
	}
#endif
	int l = 0, r = 0;
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
