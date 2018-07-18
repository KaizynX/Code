#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 1507;
const int Maxq = 1e5;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
/*   0
 * 1 O 3
 *   2
 */
int n, m, sx, sy;
bool a[Maxn][Maxn];
bool vis[Maxn][Maxn];
pair<int, int> last[Maxn][Maxn];
pair<int, int> q[Maxq];
int head, tail;

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
		memset(last, 0, sizeof last);
		head = tail = 0;
		// bfs
		bool flag = false;
		// q[++tail] = last[sx][sy] = make_pair(sx, sy);
		// vis[sx][sy] = true;
		pair<int, int> cur;
		int nex_x, nex_y, xx, yy;
		while(head < tail)
		{
			cur = q[(++head)%Maxq];
			xx = (cur.first%n+n)%n;
			yy = (cur.second%m+m)%m;
			if(vis[xx][yy] && 
			  (last[xx][yy].first != cur.first || last[xx][yy].second != cur.second)) 
			{ flag = true; break; }

			vis[xx][yy] = true;
			last[xx][yy] = make_pair(cur.first, cur.second);

			for(int d = 0; d < 4; ++d)
			{
				nex_x = cur.first + dx[d];
				nex_y = cur.second + dy[d];
				xx = (nex_x%n+n)%n;
				yy = (nex_y%m+m)%m;
				if(!a[xx][yy]) continue;
				if(!vis[xx][yy] || last[xx][yy].first != nex_x || last[xx][yy].second != nex_y)
					q[(++tail)%Maxq] = make_pair(nex_x, nex_y);
			}
		}
		puts((flag == true) ? "Yes" : "No");
	}
	return 0;
}
