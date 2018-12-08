#include <bits/stdc++.h>

using namespace std;

const int Maxn = 27;
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

int n, m;
int a[Maxn][Maxn], vis[Maxn][Maxn];
int xx[5], yy[5];
// 0 S 1 K 2 E

struct Node
{
	int x, y, t;
	Node(int x, int y, int t): x(x), y(y), t(t) {}
};

int bfs(int sta, int fin)
{
	memset(vis, 0, sizeof vis);
	queue<Node> q;
	q.push(Node(xx[sta], yy[sta], 0));
	vis[xx[sta]][yy[sta]] = 1;
	while(q.size())
	{
		Node cur = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i)
		{
			int nx = cur.x+dx[i], ny = cur.y+dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || !a[nx][ny]) continue;
			if(nx == xx[fin] && ny == yy[fin]) return cur.t+1;
			vis[nx][ny] = 1;
			q.push(Node(nx, ny, cur.t+1));
		}
	}
	return -1;
}

int main()
{
	while(cin >> n >> m)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				char c;
				cin >> c;
				if(c == '#') a[i][j] = 0;
				else a[i][j] = 1;
				if(c == 'S') xx[0] = i, yy[0] = j;
				else if(c == 'K') xx[1] = i, yy[1] = j;
				else if(c == 'E') xx[2] = i, yy[2] = j;
			}
		}
		int res1 = bfs(0, 1), res2 = bfs(1, 2);
		if(res1 == -1 || res2 == -1)
			cout << "Oops! Something went wrong" << endl;
		else cout << res1+res2 << endl;
	}
	return 0;
}
