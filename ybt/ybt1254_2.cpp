#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m;
int a[Maxn][Maxn], vis[Maxn][Maxn];
int sx, sy, ex, ey;

struct Node
{
	int x, y, d;
	Node(){}
	Node(int x, int y, int d) : x(x), y(y), d(d) {}
};

void bfs()
{
	queue<Node> q;
	Node cur;
	q.push(Node(sx, sy, 0));
	vis[sx][sy] = 1;
	while(q.size())
	{
		cur = q.front();
		q.pop();
		for(int i = 0, nx, ny; i < 4; ++i)
		{
			nx = cur.x+dx[i]; ny = cur.y+dy[i];
			if(!a[nx][ny] || vis[nx][ny]) continue;
			if(nx == ex && ny == ey)
			{
				cout << cur.d+1 << endl;
				exit(0);
			}
			vis[nx][ny] = 1;
			q.push(Node(nx, ny, cur.d+1));
		}
	}
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
	bfs();
	return 0;
}
