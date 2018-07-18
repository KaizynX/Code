#include <iostream>
#include <cstdio>
#include <bitset>
#define DEBUG

using namespace std;

#ifndef DEBUG
const int Maxn = 507;
#endif
#ifdef DEBUG
const int Maxn = 10;
#endif
const int INF = 1e6 + 9;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, ans = Maxn;
int h[Maxn][Maxn];
pair<int, int> q[Maxn*Maxn];
int head, tail;
bitset<Maxn> b[Maxn];

inline void init(int); // init the pool cur can reach
void dfs(int, int, bitset<Maxn>);

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &h[i][j]);
	// set the edge
	for(int i = 0; i <= max(n,m)+1; ++i)
		h[i][0] = h[0][i] = h[n+1][i] = h[i][m+1] = INF;
	// init && judge wether there is a approach
	bitset<Maxn> judge;
	for(int i = 1; i <= m; ++i)
	{
		init(i);
#ifdef DEBUG
		cout << b[i].to_string() << endl;
#endif
		judge |= b[i];
	}

	if(judge.count() < m)
	{
		printf("0\n%d\n", n-judge.count());
		return 0;
	}

	judge.reset();
	dfs(1, 0, judge);
	printf("1\n%d\n", ans);
	return 0;
}

void dfs(int cur, int cnt, bitset<Maxn> judge)
{
#ifdef DEBUG
	cout << cur << " " << cnt << " "
	     << judge.to_string() << endl;
#endif
	if(cnt >= ans) return;
	if(judge.count() == m)
	{
		ans = min(ans, cnt);
		return;
	}
	if(cur > m) return;

	// choose this one
	dfs(cur+1, cnt+1, judge | b[cur]);
	// not choose this one
	dfs(cur+1, cnt, judge);
}

inline void init(int now)
{
	head = tail = 0;
	q[++tail] = make_pair(1, now);
	int nex_x, nex_y, now_h;
	pair<int, int> cur;
	while(head < tail)
	{
		cur = q[++head];
		for(int d = 0; d < 4; ++d)
		{
			nex_x = cur.first + dx[d];
			nex_y = cur.second + dy[d];
			now_h = h[cur.first][cur.second];
			if(h[nex_x][nex_y] >= now_h) continue;

			if(nex_x == n) b[now].set(nex_y);
			q[++tail] = make_pair(nex_x, nex_y);
		}
	}
}
