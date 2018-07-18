#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
/**    0
    1 mid  3
       2     **/
const int Maxn = 55;
const int Maxq = 1e5;
const string direction = "NWSE";
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, sx, sy, ex, ey, dir;
bool a[Maxn][Maxn];
bool vis[Maxn][Maxn][4];
int qx[Maxq], qy[Maxq], qd[Maxq], qs[Maxq], head, tail;

inline void q_push(int x, int y, int d, int s)
{
	++tail;
	qx[tail] = x;
	qy[tail] = y;
	qd[tail] = d;
	qs[tail] = s;
}

inline void q_pop(int &x, int &y, int &d, int &s)
{
	++head;
	x = qx[head];
	y = qy[head];
	d = qd[head];
	s = qs[head];
}

int main()
{
	// read
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1, tmp; j <= m; ++j)
		{
			scanf("%d", &tmp);
			if(tmp) { a[i][j] = true; a[i-1][j] = true; a[i][j-1] = true; a[i-1][j-1] = true; }
		}
	char c;
	// Warning!!! scanf a char!!!
	scanf("%d%d%d%d %c", &sx, &sy, &ex, &ey, &c);
	dir = direction.find(c);
	// bfs
	int now_x, now_y, now_d, now_s, nex_x, nex_y, nex_d;
	q_push(sx, sy, dir, 0);
	vis[sx][sy][dir] = true;
	while(head < tail)
	{
		q_pop(now_x, now_y, now_d, now_s);
		// judge
		if(now_x == ex && now_y == ey)
		{
			printf("%d\n", now_s);
			return 0;
		}
		// walk toward 3 steps
		nex_x = now_x; nex_y = now_y;
		for(int k = 1; k <= 3; ++k)
		{
			nex_x += dx[now_d];
			nex_y += dy[now_d];
			// can't walk any longer
			if(nex_x < 1 || nex_y < 1 || nex_x >= n || nex_y >= m) break;
			if(a[nex_x][nex_y]) break;
			if(vis[nex_x][nex_y][now_d]) continue;
			q_push(nex_x, nex_y, now_d, now_s+1);
			vis[nex_x][nex_y][now_d] = true;
		}
		// turn left
		nex_d = (now_d + 1) % 4;
		if(!vis[now_x][now_y][nex_d])
		{
			q_push(now_x, now_y, nex_d, now_s+1);
			vis[now_x][now_y][nex_d] = true;
		}
		// turn right
		nex_d = (now_d - 1 + 4) % 4;
		if(!vis[now_x][now_y][nex_d])
		{
			q_push(now_x, now_y, nex_d, now_s+1);
			vis[now_x][now_y][nex_d] = true;
		}
	}
	// no way
	puts("-1");
	return 0;
}
