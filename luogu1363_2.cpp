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
bool b[Maxn][Maxn]; // can S reach here
int head, tail;
pair<int, int> q[Maxq];
bool out_left_right, out_up_down, in_left_right, in_up_down, to_left, to_right, to_up, to_down;

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
		memset(b, 0, sizeof b);
		out_left_right = out_up_down = to_left = to_right = to_up = to_down = false;
		in_left_right = in_up_down = true;
		// bfs colour the point can reach
		head = tail = 0;
		q[++tail] = make_pair(sx, sy);
		b[sx][sy] = true;
		pair<int, int> cur;
		int nex_x, nex_y;
		while(head < tail)
		{
			cur = q[(++head)%Maxq];
			for(int d = 0; d < 4; ++d)
			{
				nex_x = cur.first + dx[d];
				nex_y = cur.second + dy[d];
				if(nex_x < 0 || nex_y < 0 || nex_x >= n || nex_y >= m) continue;
				if(!a[nex_x][nex_y] || b[nex_x][nex_y]) continue;
				b[nex_x][nex_y] = true;
				q[(++tail)%Maxq] = make_pair(nex_x, nex_y);
			}
		}
		// wether S can reach the edge & wether the edge can connect
		for(int i = 0; i < n; ++i)
		{
			if(b[i][0]) to_left = true;
			if(b[i][m-1]) to_right = true;
			if(a[i][0] && a[i][m-1]) { out_left_right = true; }
		}
		for(int i = 0; i < m; ++i)
		{
			if(b[0][i]) to_up = true;
			if(b[n-1][i]) to_down = true;
			if(a[0][i] && a[n-1][i]) { out_up_down = true; }
		}
#ifdef DEBUG
		cout << to_up << " " << to_down << " " << to_left << " " << to_right << " "
			 << out_left_right << " " << out_up_down << endl;
#endif
		// judge
		if(to_up && to_down && out_up_down
		|| to_left && to_right && out_left_right )
		{
			puts("Yes"); continue;
		}
		// again
		memset(b, 0, sizeof b);
		head = tail = 0;
		q[++tail] = make_pair(sx, sy);
		b[sx][sy] = true;
		while(head < tail)
		{
			cur = q[(++head)%Maxq];
			for(int d = 0; d < 4; ++d)
			{
				nex_x = (cur.first + dx[d] + n) % n; // !!!
				nex_y = (cur.second + dy[d] + m)% m; // !!!
				if(!a[nex_x][nex_y] || b[nex_x][nex_y]) continue;
				b[nex_x][nex_y] = true;
				q[(++tail)%Maxq] = make_pair(nex_x, nex_y);
			}
		}
		for(int i = 0; i < n; ++i)
		{
			if(b[i][0]) to_left = true;
			if(b[i][m-1]) to_right = true;
			if(a[i][0] && a[i][m-1]) { out_left_right = true; }
		}
		for(int i = 0; i < m; ++i)
		{
			if(b[0][i]) to_up = true;
			if(b[n-1][i]) to_down = true;
			if(a[0][i] && a[n-1][i]) { out_up_down = true; }
		}
		if(to_up && to_down && to_left && to_right && out_left_right && out_up_down)
			puts("Yes");
		else puts("No");
#ifdef DEBUG
		cout << to_up << " " << to_down << " " << to_left << " " << to_right << " "
			 << out_left_right << " " << out_up_down << endl;
#endif
	}
	return 0;
}
