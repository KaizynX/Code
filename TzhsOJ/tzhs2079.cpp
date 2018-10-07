#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int Maxn = 107;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, ans, t;
int a[Maxn][Maxn];
queue<pair<int, int> > q;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			char c;
			cin >> c;
			if(c == '.') a[i][j] = 1;
			else if(c == '@')
			{
				a[i][j] = 2;
				q.push(make_pair(i, j));
				ans++;
			}
		}
	cin >> t;
	while(--t)
	{
		unsigned num = q.size();
		pair<int, int> cur;
		int now_x, now_y, nex_x, nex_y;
		while(num--)
		{
			cur = q.front(); q.pop();
			now_x = cur.first;
			now_y = cur.second;
			for(int d = 0; d < 4; ++d)
			{
				nex_x = now_x + dx[d];
				nex_y = now_y + dy[d];
				if(nex_x < 1 || nex_x > n || nex_y < 1 || nex_y > n) continue;
				if(a[nex_x][nex_y] != 1) continue;
				a[nex_x][nex_y] = 2;
				ans++;
				q.push(make_pair(nex_x, nex_y));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

